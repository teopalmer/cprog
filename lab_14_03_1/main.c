// 2 september 2015
#include <stdio.h>
#include <string.h>
#include <ui.h>
#include "defines.h"
#include "stdlib.h"
#include "user_interface.h"
#include "resizing_items.h"
#include "main_funcs.h"

uiEntry *aentry, *nentry, *centry;
uiMultilineEntry *res;
uiEditableCombobox *cbox;
uiWindow *mainwin;
item_t *p = NULL;
int array_size = 0;

char *MH_itoa(int i) {
	char buf[256];
	char *p = &buf[sizeof buf - 1];
	*p = '\0';

	int j = i;
	//  Let us work with negative numbers to avoid problems with abs(INT_MIN)
	if (j > 0) {
		j = -j;
	}

	do {
		p--;
		*p = '0' - j % 10;
		j /= 10;
	} while (j);
	if (i < 0) {
		p--;
		*p = '-';
	}

	// Right size the allocation
	size_t size = (size_t) (&buf[sizeof buf] - p);
	char *dest = malloc(size);
	if (dest) {
		memcpy(dest, p, size);
	}

	return dest;
}

void print_data()
{
	uiMultilineEntrySetText(res, "");
	for (int i = 0; i < array_size; i++)
	{
		//strcpy(char *cstr, my_itoa(p[i].count));
		uiMultilineEntryAppend(res, p[i].article);
		uiMultilineEntryAppend(res, "\n");
		uiMultilineEntryAppend(res, p[i].name);
		uiMultilineEntryAppend(res, "\n");
		uiMultilineEntryAppend(res, MH_itoa(p[i].count));
		uiMultilineEntryAppend(res, "\n");
		uiMultilineEntryAppend(res, "=====================\n");
	}
}

int check_a(str_t article)
{
	int len = strlen(article);
	for (int i = 0; i < len; i++)
	{
		if (check_if_int(article[i]) != ok)
			return input_error;

		if (check_if_upper(article[i]) != ok)
			return input_error;
	}
	return ok;
}

int check_n(str_t name)
{
	int len = strlen(name);
	for (int i = 0; i < len; i++)
	{
		if (check_if_int(name[i]) != ok)
			return input_error;

		if (check_if_char(name[i]) != ok)
			return input_error;
	}
	return ok;
}


int check(str_t article, str_t name, str_t count)
{
	if (strcmp(article, "") == 0 || strcmp(name, "") == 0 || strcmp(count, "") == 0)
	{
		uiMsgBoxError(mainwin, "Error", "Input Error");
		return input_error;
	}

	if (check_a(article) == input_error || check_n(name) == input_error)
	{
		uiMsgBoxError(mainwin, "Error", "Input Error");
		return input_error;
	}

	return ok;
}

void add_onPress(uiButton *b, void *data)
{

	//uiEntry *a, uiEntry *n, uiEntry *c, int *array_size, item_t **p
	char *article = uiEntryText(aentry);

	//printf("%s", article);
	char *name = uiEntryText(nentry);
	char *count = uiEntryText(centry);

	if (check(article, name, count) == input_error)
		return;

	printf("%s %s %s", article, name, count);

	int cc = atoi(count);

	resize_items_array(&p, &array_size, ADD);

	(p[array_size - 1]).article = article;
	(p[array_size - 1]).name = name;
	(p[array_size - 1]).count = cc;

	print_data();

	uiEntrySetText(aentry, "");
	uiEntrySetText(nentry, "");
	uiEntrySetText(centry, "");

	/*(&(*p)[*array_size - 1])->article = article;
    (&(*p)[*array_size - 1])->name = name;
    (&(*p)[*array_size - 1])->count = cc;*/

}


void combo_onPress(uiEditableCombobox *cbox, void *data)
{
	char *key = uiEditableComboboxText(cbox);
	printf("%s", key);
	sort_array(p, array_size, key);
	puts("*");

	print_data();
}

static int onClosing(uiWindow *w, void *data)
{
	uiQuit();
	return 1;
}

static int onShouldQuit(void *data)
{
	uiWindow *mainwin = uiWindow(data);

	uiControlDestroy(uiControl(mainwin));
	return 1;
}

static uiControl *makeBasicControlsPage(void)
{
	uiBox *vbox;
	uiBox *hbox;
	uiBox *abox;
	uiGroup *group;
	uiForm *entryForm;
    uiButton *addb;

    p = NULL;
    array_size = 0;


	vbox = uiNewVerticalBox();
	uiBoxSetPadded(vbox, 1);

	/*uiBoxAppend(hbox,
		uiControl(uiNewButton("Button")),
		0);
	uiBoxAppend(hbox,
		uiControl(uiNewCheckbox("Checkbox")),
		0);

	uiBoxAppend(vbox,
		uiControl(uiNewLabel("This is a label. Right now, labels can only span one line.")),
		0);

	uiBoxAppend(vbox,
		uiControl(uiNewHorizontalSeparator()),
		0);*/

	group = uiNewGroup("");
	uiGroupSetMargined(group, 1);
	uiBoxAppend(vbox, uiControl(group), 1);

	entryForm = uiNewForm();

	addb = uiNewButton("Add");

	aentry = uiNewEntry();
    nentry = uiNewEntry();
    centry = uiNewEntry();

	uiFormSetPadded(entryForm, 1);
	uiGroupSetChild(group, uiControl(entryForm));

	uiFormAppend(entryForm,
		"Article",
		uiControl(aentry),
		0);
	uiFormAppend(entryForm,
		"Name",
		uiControl(nentry),
		0);
	uiFormAppend(entryForm,
		"Count",
		uiControl(centry),
		0);
    uiBoxAppend(vbox,
                uiControl(addb),
                0);

	uiButtonOnClicked(addb, add_onPress, 0);
    hbox = uiNewHorizontalBox();
    uiBoxSetPadded(hbox, 1);
    uiBoxAppend(vbox,
                uiControl(uiNewHorizontalSeparator()),
                0);
    uiBoxAppend(vbox, uiControl(hbox), 0);

    uiBoxAppend(hbox,
                uiControl(uiNewLabel("Sort by:")),
                0);

    abox = uiNewHorizontalBox();
    uiBoxSetPadded(abox, 1);
    uiBoxAppend(vbox, uiControl(abox), 0);

    res = uiNewMultilineEntry();
    uiMultilineEntrySetReadOnly(res, 1);

	uiBoxAppend(abox,
				uiControl(res),
				0);

    cbox = uiNewEditableCombobox();
    uiEditableComboboxAppend(cbox, "Article");
    uiEditableComboboxAppend(cbox, "Name");
    uiEditableComboboxAppend(cbox, "Count");
    uiBoxAppend(hbox, uiControl(cbox), 0);
    uiEditableComboboxOnChanged(cbox, combo_onPress, NULL);

	return uiControl(vbox);
}

// TODO make this not global

int main(void)
{
	uiInitOptions options;
	const char *err;
	uiTab *tab;

	memset(&options, 0, sizeof (uiInitOptions));
	err = uiInit(&options);
	if (err != NULL) {
		fprintf(stderr, "error initializing libui: %s", err);
		uiFreeInitError(err);
		return 1;
	}

	mainwin = uiNewWindow("LR 14", 640, 480, 1);
	uiWindowOnClosing(mainwin, onClosing, NULL);
	uiOnShouldQuit(onShouldQuit, mainwin);

	tab = uiNewTab();
	uiWindowSetChild(mainwin, uiControl(tab));
	uiWindowSetMargined(mainwin, 1);

	uiTabAppend(tab, "Sadulaeva Teona UI7-34B", makeBasicControlsPage());
	uiTabSetMargined(tab, 0, 1);

	uiControlShow(uiControl(mainwin));
	uiMain();
	return 0;
}

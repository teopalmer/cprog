#define EPS 1e-6
#define OK 0
#define ERROR 221
#define YES 1
#define NO 0
int make_array(float **start, float **end, int n);
int compare_arrays(const float *start, const float *startres);
int fill_test_array(float **start, float **end, int n, int case_number);
int test_calc_cubic_ord(float **start, float **end);
int test_calc_cubic_same(float **start, float **end);
int test_calc_cubic_neg(float **start, float **end);
int test_deletion_ord(float **start, float **end);
int test_deletion_same(float **start, float **end);
int test_deletion_neg(float **start, float **end);

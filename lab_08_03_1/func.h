#ifndef MAIN_H
#define MAIN_H
#define OK 0
#define EPS 1e-6
#define ERROR 221
int read_array(float **start, float **end, int *count);
void print_array(float *start, float *end);
float calculate_cubic(float *start, float *end);
int delete_elements(float *start, float *end);
int read_p(int *p);
float find_min(float *start, float *end);
int insert_p(float **start, float **end, int n, int p, int count, float cubic);
#endif


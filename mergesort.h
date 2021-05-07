#ifndef MERGESORT_H
#define MERGESORT_H

#define RECSIZ 80
#define NORECS 456995

typedef enum { INT, FLOAT, STR } type;

/* caller/dispatching functions */
void sort(void *, int, type, char);
void initialize(void *, int, type);
void printarr(void *, int, type);
int sorted(void *, int, type, char);

/* int callee/dispatched functions */
void int_sort(int *, int, int (*)(int, int));
void int_merge(int *, int, int, int (*)(int, int));
void int_initialize(int *, int);
void int_printarr(int *, int);
int int_sorted(int *, int, int (*)(int, int));
int int_lte(int, int);
int int_gte(int, int);

/* float callee/dispatched functions */
void float_sort(float *, int, int (*)(float, float));
void float_merge(float *, int, int, int (*)(float, float));
void float_initialize(float *, int);
void float_printarr(float *, int);
int float_sorted(float *, int, int (*)(float, float));
int float_lte(float, float);
int float_gte(float, float);

/* string callee/dispatched functions */
void str_sort(char **, int, int (*)(char *, char *));
void str_merge(char **, int, int, int (*)(char *, char *));
void str_initialize(char **, int);
void str_printarr(char **, int);
int str_sorted(char **, int, int (*)(char *, char *));
int str_lte(char *, char *);
int str_gte(char *, char *);

#endif

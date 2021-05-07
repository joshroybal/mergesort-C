#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "mergesort.h"

/* void caller/dispatching functions */
void sort(void *arr, int n, type t, char ord)
{
   if (t == INT) {
      if (ord == '<')
         int_sort((int *) arr, n, int_lte);
      else if (ord == '>')
         int_sort((int *) arr, n, int_gte);
   }
   else if (t == FLOAT) {
      if (ord == '<')
         float_sort((float *) arr, n, float_lte);
      else if (ord == '>')
         float_sort((float *) arr, n, float_gte);
   }
   else if (t == STR) {
      if (ord == '<')
         str_sort((char **) arr, n, str_lte);
      else if (ord == '>')
         str_sort((char **) arr, n, str_gte);
   }
}

void initialize(void *arr, int n, type t)
{
   if (t == INT) int_initialize((int *) arr, n);
   if (t == FLOAT) float_initialize((float *) arr, n);
   if (t == STR) str_initialize((char **) arr, n);
}

void printarr(void *arr, int n, type t)
{
   if (t == INT) int_printarr((int *) arr, n);
   if (t == FLOAT) float_printarr((float *) arr, n);
   if (t == STR) str_printarr((char **) arr, n);
}

int sorted(void *arr, int n, type t, char ord)
{
   int result;

   if (t == INT) {
      if (ord == '<') 
         result = int_sorted((int *) arr, n, int_lte);
      else if (ord == '>') 
         result = int_sorted((int *) arr, n, int_gte);
   }
   else if (t == FLOAT) {
      if (ord == '<')
         result = float_sorted((float *) arr, n, float_lte);
      else if (ord == '>')
         result = float_sorted((float *) arr, n, float_gte);
   }
   else if (t == STR) {
      if (ord == '<')
         result = str_sorted((char **) arr, n, str_lte);
      else if (ord == '>')
         result = str_sorted((char **) arr, n, str_gte);
   }
   return(result);
}

/* int callee/dispatched functions */
void int_sort(int *arr, int n, int (*pf)(int, int))
{
   int left, right;

   if (n > 1) {
      left = n / 2;
      right = n - left;
      int_sort(arr, left, pf);
      int_sort(arr + left, right, pf);
      int_merge(arr, left, right, pf);
   }
}

void int_merge(int *arr, int left, int right, int (*pf)(int, int))
{
   int i = 0, j = 0, k = 0;
   int *tmp = (int *) malloc((left + right) * sizeof(int));

   while (j < left && k < right)
      tmp[i++] = (pf(arr[j], arr[left + k]) ? arr[j++] : arr[left + k++]);
   while (j < left)
      tmp[i++] = arr[j++];
   while (k  < right)
      tmp[i++] = (arr + left)[k++];
   memcpy(arr, tmp, (left + right) * sizeof(int));
   free(tmp);
}

void int_initialize(int *arr, int n)
{
   int i;

   for (i = 0; i < n; ++i)
      arr[i] = rand();
}

void int_printarr(int *arr, int n)
{
   int i;

   for (i = 0; i < n; ++i)
      printf("%d\n", arr[i]);
}

int int_sorted(int *arr, int n, int (*pf)(int, int))
{
   int i = 0, result;

   while ((i + 1) < n)
      if (pf(arr[i], arr[i + 1]))
         ++i;
      else
         break;
   if ((i + 1) < n)
      result = 0;
   else
      result = 1;
   return(result);
}

int int_lte(int x, int y)
{
   return(x <= y);
}

int int_gte(int x, int y)
{
   return(x >= y);
}

/* float callee/dispatched functions */
void float_sort(float *arr, int n, int (*pf)(float, float))
{
   int left, right;

   if (n > 1) {
      left = n / 2;
      right = n - left;
      float_sort(arr, left, pf);
      float_sort(arr + left, right, pf);
      float_merge(arr, left, right, pf);
   }
}

void float_merge(float *arr, int left, int right, int (*pf)(float, float))
{
   int i = 0, j = 0, k = 0;
   float *tmp = (float *) malloc((left + right) * sizeof(float));

   while (j < left && k < right)
      tmp[i++] = (pf(arr[j], arr[left + k]) ? arr[j++] : arr[left + k++]);
   while (j < left)
      tmp[i++] = arr[j++];
   while (k  < right)
      tmp[i++] = (arr + left)[k++];
   memcpy(arr, tmp, (left + right) * sizeof(float));
   free(tmp);
}

void float_initialize(float *arr, int n)
{
   int i;

   for (i = 0; i < n; ++i)
      arr[i] = rand()/(float)INT_MAX;
}

void float_printarr(float *arr, int n)
{
   int i;

   for (i = 0; i < n; ++i)
      printf("%f\n", arr[i]);
}

int float_sorted(float *arr, int n, int (*pf)(float, float))
{
   int i = 0, result;

   while ((i + 1) < n)
      if (pf(arr[i], arr[i + 1]))
         ++i;
      else
         break;
   if ((i + 1) < n)
      result = 0;
   else
      result = 1;
   return(result);
}

int float_lte(float x, float y)
{
   return(x <= y);
}

int float_gte(float x, float y)
{
   return(x >= y);
}

/* string callee/dispatched functions */
void str_sort(char **arr, int n, int (*pf)(char *, char *))
{
   int left, right;

   if (n > 1) {
      left = n / 2;
      right = n - left;
      str_sort(arr, left, pf);
      str_sort(arr + left, right, pf);
      str_merge(arr, left, right, pf);
   }
}

void str_merge(char **arr, int left, int right, int (*pf)(char *, char *))
{
   int i = 0, j = 0, k = 0, cnt = 0;
   char **tmp = (char **) malloc((left + right) * sizeof(char *));
   for (cnt = 0; cnt < left + right; ++cnt)
      tmp[cnt] = (char *) malloc((RECSIZ+1) * sizeof(char));

   while (j < left && k < right)
      strcpy(tmp[i++], (pf(arr[j], arr[left+k]) ? arr[j++] : arr[left + k++]));
   while (j < left)
      strcpy(tmp[i++], arr[j++]);
   while (k  < right)
      strcpy(tmp[i++], (arr + left)[k++]);
   for (cnt = 0; cnt < left + right; ++cnt)
      strcpy(arr[cnt], tmp[cnt]);
   for (cnt = left + right - 1; cnt >= 0; --cnt)
      free(tmp[cnt]);
   free(tmp);
}

void str_initialize(char **arr, int n)
{
   int i, j, pos;
   FILE *fp;

   /* open binary file for read */
   if ((fp = fopen("/home/slacker/dat/data.dat", "rb")) == (FILE *) NULL) {
      fprintf(stderr, "error opening file\n");
      exit(1);
   }
   /* read random binary file records into strings array */
   for (i = 0; i < n; ++i) {
      pos = RECSIZ*(int)(NORECS*(rand()/(float)INT_MAX));
      fseek(fp, pos, SEEK_SET);
      fread(arr[i], RECSIZ, 1, fp);
      j = RECSIZ;
      while (j > 0 && arr[i][--j] == ' ');
      if (j > 0)
         arr[i][++j] = '\0';
      else
         arr[i][0] = '\0';
   }  
   fclose(fp); /* close binary file */
}

void str_printarr(char **arr, int n)
{
   int i;

   for (i = 0; i < n; ++i)
      printf("%s\n", arr[i]);
}

int str_sorted(char **arr, int n, int (*pf)(char *, char *))
{
   int i = 0, result;

   while ((i + 1) < n)
      if (pf(arr[i], arr[i + 1]))
         ++i;
      else
         break;
   if ((i + 1) < n)
      result = 0;
   else
      result = 1;
   return(result);
}

int str_lte(char *s1, char *s2)
{
   return(strcmp(s1, s2) <= 0);
}

int str_gte(char *s1, char *s2)
{
   return(strcmp(s1, s2) >= 0);
}

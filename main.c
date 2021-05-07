#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort.h"

#define N 50

int main(int argc, char *argv[])
{
   int i, k;
   float t0, t1;
   int *z;
   float *a;
   char **str;

   if (argc < 2) {
      fprintf(stderr, "Usage: %s n\n", argv[0]);
      return(1);
   }
   k = atoi(argv[1]);
   srand(time(NULL));
   
   /* int tests */
   puts("ascending int");
   z = (int *) malloc(k * sizeof(int));
   initialize(z, k, INT);
   if (k <= N)
      printarr(z, k, INT);
   printf("%d\n", sorted(z, k, INT, '<'));
   t0 = clock();
   sort(z, k, INT, '<');
   t1 = clock();
   if (k <= N)
      printarr(z, k, INT);
   printf("%d\n", sorted(z, k, INT, '<'));
   printf("Elapsed time = %f seconds.\n", (t1 - t0) / CLOCKS_PER_SEC);
   puts("descending int");
   initialize(z, k, INT);
   if (k <= N)
      printarr(z, k, INT);
   printf("%d\n", sorted(z, k, INT, '>'));
   t0 = clock();
   sort(z, k, INT, '>');
   t1 = clock();
   if (k <= N)
      printarr(z, k, INT);
   printf("%d\n", sorted(z, k, INT, '>'));
   printf("Elapsed time = %f seconds.\n", (t1 - t0) / CLOCKS_PER_SEC);   
   free(z);

   /* float tests */
   puts("ascending float");
   a = (float *) malloc(k * sizeof(float));
   initialize(a, k, FLOAT);
   if (k <= N)
      printarr(a, k, FLOAT);
   printf("%d\n", sorted(a, k, FLOAT, '<'));
   t0 = clock();
   sort(a, k, FLOAT, '<');
   t1 = clock();
   if (k <= N)
      printarr(a, k, FLOAT);
   printf("%d\n", sorted(a, k, FLOAT, '<'));
   printf("Elapsed time = %f seconds.\n", (t1 - t0) / CLOCKS_PER_SEC);
   puts("descending float");
   initialize(a, k, FLOAT);
   if (k <= N)
      printarr(a, k, FLOAT);
   printf("%d\n", sorted(a, k, FLOAT, '>'));
   t0 = clock();
   sort(a, k, FLOAT, '>');
   t1 = clock();
   if (k <= N)
      printarr(a, k, FLOAT);
   printf("%d\n", sorted(a, k, FLOAT, '>'));
   printf("Elapsed time = %f seconds.\n", (t1 - t0) / CLOCKS_PER_SEC);   
   free(a);

   /* string tests */
   puts("ascending strings");
   if (k > NORECS)
      k = NORECS;
   str = (char **) malloc(k * sizeof(char *));
   for (i = 0; i < k; ++i)
      str[i] = (char *) malloc((RECSIZ + 1) * sizeof(char));
   initialize(str, k, STR);
   if (k <= N)
      printarr(str, k, STR);
   printf("%d\n", sorted(str, k, STR, '<'));
   t0 = clock();
   sort(str, k, STR, '<');
   t1 = clock();
   if (k <= N)
      printarr(str, k, STR);
   printf("%d\n", sorted(str, k, STR, '<'));
   printf("Elapsed time = %f seconds.\n", (t1 - t0) / CLOCKS_PER_SEC);
   puts("descending strings");
   initialize(str, k, STR);
   if (k <= N)
      printarr(str, k, STR);
   printf("%d\n", sorted(str, k, STR, '>'));
   t0 = clock();
   sort(str, k, STR, '>');
   t1 = clock();
   if (k <= N)
      printarr(str, k, STR);
   printf("%d\n", sorted(str, k, STR, '>'));
   printf("Elapsed time = %f seconds.\n", (t1 - t0) / CLOCKS_PER_SEC);   
   for (i = k-1; i >= 0; --i)
      free(str[i]);
   free(str);
   return(0);
}

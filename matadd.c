#include <stdlib.h>
#define ROWS 3
#define COLS 9

void matadd(int**, int**, int**, int, int);

int main(int argc, char* argv[]) {
   int **A, **B, **C; /* Matrices */
   int i, j; /* indexing */
   int *temp; /* checks columns of matrices for validity */

   /* Allocate A */
   A = (int**)malloc(sizeof(int*) * ROWS);
   if (NULL == A) {
      exit(EXIT_FAILURE);
   }

   /* Fill out A */
   for (i = 0; i < ROWS; i++) {
      /* Allocate next row */
      temp = (int*)malloc(sizeof(int) * COLS);
      if (NULL == temp) {
         exit(EXIT_FAILURE);
      }
      A[i] = temp;

      /* Fill out columns */
      for (j = 0; j < COLS; j++) {
         A[i][j] = COLS + j;
      }
   }

   /* Allocate B */
   B = (int**)malloc(sizeof(int) * ROWS);
   if (NULL == B) {
      exit(EXIT_FAILURE);
   }

   /* Fill out B */
   for (i = 0; i < ROWS; i++) {
      /* Allocate next row */
      temp = (int*)malloc(sizeof(int) * COLS);
      if (NULL == temp) {
         exit(EXIT_FAILURE);
      }
      B[i] = temp;

      /* Fill out columns */
      for (j = 0; j < COLS; j++) {
         B[i][j] = (COLS - j) * ROWS * (-1 * (j % 2));
      }
   }

   /* Allocate C */
   C = (int**)malloc(sizeof(int) * ROWS);
   if (NULL == C) {
      exit(EXIT_FAILURE);
   }

   /* Fill out C */
   for (i = 0; i < ROWS; i++) {
      /* Allocate next row */
      temp = (int*)calloc(COLS, sizeof(int));
      if (NULL == temp) {
         exit(EXIT_FAILURE);
      }
      C[i] = temp;
   }

   /* Function call */
   matadd(C, A, B, ROWS, COLS);

   /* Free matrices */
   for (i = 0; i < ROWS; i++) {
      free(A[i]);
      free(B[i]);
      free(C[i]);
   }
   free(A);
   free(B);
   free(C);

   return EXIT_SUCCESS;
}




/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 */
void matadd(int **C, int **A, int **B, int height, int width)
{
   int i, j; /* used to index into matrices */
   for(i=0; i<height; i++)
   {
      for(j=0; j<width; j++)
      {
         C[i][j] = A[i][j] + B[i][j];
      }
   }
}

/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 * implements loop unrolling level 2
 */
static void matadd2(int **C, int **A, int **B, int height, int width) {
   int i, j;
   int inc = 2;
   for(i=0; i<height; i++)
   {
      j = 0;
      /* 
       * make sure that width - j is divisible by 2 so that the unrolled loop
       * won't segfault
       */
      while (width-j % inc != 0) {
         C[i][j] = A[i][j] + B[i][j];
         j++;
      }
      for(; j<width; j += inc)
      {
         C[i][j] = A[i][j] + B[i][j];
         C[i][j+1] = A[i][j+1] + B[i][j+1];
      }
   }
}

/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 * implements loop unrolling level 4
 */
 static void matadd4(int **C, int **A, int **B, int height, int width) {
   int i, j;
   int inc = 8;
   for(i=0; i<height; i++)
   {
      j = 0;
      /* 
       * make sure that width - j is divisible by 8 so that the unrolled loop
       * won't segfault
       */
      while (width-j % inc != 0) {
         C[i][j] = A[i][j] + B[i][j];
         j++;
      }
      for(; j<width; j += inc)
      {
         C[i][j] = A[i][j] + B[i][j];
         C[i][j+1] = A[i][j+1] + B[i][j+1];
         C[i][j+2] = A[i][j+2] + B[i][j+2];
         C[i][j+3] = A[i][j+3] + B[i][j+3];
         C[i][j+4] = A[i][j+4] + B[i][j+4];
         C[i][j+5] = A[i][j+5] + B[i][j+5];
         C[i][j+6] = A[i][j+6] + B[i][j+6];
         C[i][j+7] = A[i][j+7] + B[i][j+7];
      }
   }
}

/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 * implements loop unrolling level 8
 */
static void matadd8(int **C, int **A, int **B, int height, int width) {
   int i, j;
   int inc = 4;
   for(i=0; i<height; i++)
   {
      j = 0;
      /* 
       * make sure that width - j is divisible by 4 so that the unrolled loop
       * won't segfault
       */
      while (width-j % inc != 0) {
         C[i][j] = A[i][j] + B[i][j];
         j++;
      }
      for(; j<width; j += inc)
      {
         C[i][j] = A[i][j] + B[i][j];
         C[i][j+1] = A[i][j+1] + B[i][j+1];
         C[i][j+2] = A[i][j+2] + B[i][j+2];
         C[i][j+3] = A[i][j+3] + B[i][j+3];
      }
   }
}

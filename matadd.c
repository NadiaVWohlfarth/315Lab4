#include <stdlib.h>
#define ROWS 3
#define COLS 9

int main(int argc, char* argv[]) {
   int[][] A, B, C;
   int i, j;
   int* temp;

   /* Allocate A */
   A = malloc(sizeof(int*) * ROWS);
   if (NULL == A) {
      exit(EXIT_FAILURE);
   }

   /* Fill out A */
   for (i = 0; i < ROWS; i++) {
      /* Allocate next row */
      temp = malloc(sizeof(int) * COLS);
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
   B = malloc(sizeof(int) * ROWS);
   if (NULL == B) {
      exit(EXIT_FAILURE)
   }

   /* Fill out B */
   for (i = 0; i < ROWS; i++) {
      /* Allocate next row */
      temp = malloc(sizeof(int) * COLS);
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
   C = malloc(sizeof(int) * ROWS);
   if (NULL == C) {
      exit(EXIT_FAILURE)
   }

   /* Fill out C */
   for (i = 0; i < ROWS; i++) {
      /* Allocate next row */
      temp = calloc(sizeof(int) * COLS);
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
static void matadd(int **C, int **A, int **B, int height, int width) {
   int i, j; /* used to index into matrices */
}

/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 * implements loop unrolling level 2
 */
/* static void matadd2(int **C, int **A, int **B, int height, int width) {
   int i, j;
} */

/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 * implements loop unrolling level 4
 */
/* static void matadd4(int **C, int **A, int **B, int height, int width) {
   int i, j;
} */

/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 * implements loop unrolling level 8
 */
/* static void matadd8(int **C, int **A, int **B, int height, int width) {
   int i, j;
} */

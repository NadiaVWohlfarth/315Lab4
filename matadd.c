
/*
 * matrix addition
 * inputs:
 *    A, B, C: pointers to height x width matrices
 *    C <- A + B
 */
void matadd(int **C, int **A, int **B, int height, int width)
{
   int i, j; /* used to index into matrices */
   for(i=0, i<height, i++)
   {
      for(j=0, j<width, j++)
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

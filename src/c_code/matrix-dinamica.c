#include <stdio.h>
#include <stdlib.h> // malloc calloc free NULL


int main(){
  int nrows = 2;
  int ncols = 3;
  /******* ALOCAÇAO DE MATRIZ *******/
  int **m = (int**)calloc(nrows, sizeof(int*));
  // Para cada linha da matriz
  for(int i = 0;i < nrows;i++){
    m[i] = (int*) calloc(ncols, sizeof(int));
  }

  /************************************/
  int count = 0;
  printf("&m = %p, m = %p\n\n",&m, m);
  for(int i = 0;i < nrows;i++){

    printf("&m[%d] = %p, m[%d] = %p\n",i, &m[i], i, m[i]);
    for(int j = 0; j< ncols;j++){
      m[i][j] = count++;
      printf("&m[%d][%d] = %p, m[%d][%d] = %d\n\n",
	     i,j,&m[i][j],i ,j, m[i][j]);
     
    }
    puts("");
  }


  return 0;
}

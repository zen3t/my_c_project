#include <stdio.h>
#include <stdlib.h>

void soma_com_vetor_escalar(int v[],int n, int escalar){
  for(int i = 0;i < n;i++){
    v[i] += escalar;
  }


}
void print_vetor(const int *v, int n){
  for(int i = 0;i < n;i++){
    printf("&v[%d] = %p, v[%d] = %d\n" , i, &v[i], i, v[i]);
  }
  puts("");
}

void desaloca_vetor(int **v){
  free(*v);
  v = NULL;
  
}

int main(){
  // alocacao de um vetor estatico(memoria stack) 
  puts("### VETOR ESTATICO");
  int vs[5] = {10,3,21,34,5};
  print_vetor(vs, 5);
  soma_com_vetor_escalar(vs, 5, 9);
  print_vetor(vs, 5);


  puts("VETOR DINAMICO COM CAllOC");
  int *vh = (int *) calloc(5,sizeof(int));
  for(int i = 0;i < 5;i++){
    vh[i] = i * 100;
  }

  print_vetor(vh, 5);
  soma_com_vetor_escalar(vh, 5, 9);
  print_vetor(vh, 5);
  /* free(vh); */
  /* vh = NULL; */
  puts("### ANTES DA FUNCAO DE DESLOCAR VETOR DINAMICO");
  desaloca_vetor(&vh);
  printf("&vh = %p, vh = %d\n" ,&vh, vh);
  puts("### DEPOIS  DA FUNCAO DE DESLOCAR VETOR DINAMICO");
  printf("&vh = %p, vh = %d\n" ,&vh, vh);
  return 0;
}

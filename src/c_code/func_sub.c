
#include <stdio.h>
#include <stdlib.h>
int soma_sub(int x, int y, int *sub){
  int soma = x + y;
  *sub = x - y;
  
  return soma;
  
}

int main(){
  int a = 10;
  int b = 20;
  int c;
  c =  soma_sub(a,b,&c);
  puts("#### A SOMA DA FUNCAO");
  printf("&a = %p, a = %d\n", &a,a);
  printf("&b = %p, b = %d\n", &b,b);
  printf("&c = %p, c = %d\n", &c,c);
  soma_sub(a,b,&c);
  puts("#### A SUB  DA FUNCAO");
  printf("&a = %p, a = %d\n", &a,a);
  printf("&b = %p, b = %d\n", &b,b);
  printf("&c = %p, c = %d\n", &c,c);
  return 0; 
}

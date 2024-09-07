/* Mostre todos os passos do progama abaixo e indentifique o que e impresso.
 */
#include <stdio.h>
#include <stdlib.h>
void func (int *px, int *py){
  px = py;
  *py = (*py) * (*px);
  *px = *px + *py;
}

int main(){
  int x = 10;
  int y = 20;
  scanf("%d", &x);
  scanf("%d", &y);

  func(&x, &y);
  printf("x = %d, y = %d\n", x, y);
  return 0;
}

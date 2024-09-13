#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livro{
  char titulo[100];
  unsigned int num_paginas;
  float preco;
}Livro;

typedef struct _aluno{
  char nome[100];
  int idade;
  Livro *livro_fav;
  
}Aluno;


// construtor para livros
Livro *create_livro(const char *titulo,unsigned int num_paginas,float preco){
  Livro *livro = (Livro*) calloc(1, sizeof(Livro));

  strcpy(livro->titulo,titulo);
  livro->num_paginas = num_paginas;
  livro->preco = preco;
  
  return livro;
}
void destroy_livro(Livro **livro_ref){
  Livro  *livro = *livro_ref;
  free(livro);
  *livro_ref = NULL;
}

Livro *copy_livro(const Livro *livro){
  return create_livro(livro->titulo,livro->num_paginas,livro->preco);
  
}
Aluno *create_aluno(const char *nome, int idade,const Livro *livro_fav){
  
  Aluno *aluno = (Aluno *)calloc(1,sizeof(Aluno));
  strcpy(aluno->nome,nome);
  aluno->idade = idade;
  aluno->livro_fav = copy_livro(livro_fav);
  return aluno;
}
  void print_livro(const Livro *livro){
    printf("Titulo: %s\n", livro->titulo);
    printf("Num paginas: %ld\n", livro->num_paginas);
    printf("Preço: %2.f\n", livro->preco);
  } 
void destroy_aluno(Aluno **aluno_ref){
  
  Aluno *aluno = * aluno_ref;
  destroy_livro(&aluno->livro_fav);
  free(aluno);
  *aluno_ref = NULL;
}

void print_aluno(const Aluno *aluno){
  printf("Nome : %s\n" ,aluno->nome);
  printf("Idade : %d\n" ,aluno->idade);
  puts("LIVRO FAVORITO");
  puts("---------------");
  print_livro(aluno->livro_fav);


}
int main(){
  Livro *livro_poesia = create_livro("potter",300,32);
    
  print_livro(livro_poesia);
  livro_poesia->preco = 10;
  print_livro(livro_poesia);

  Aluno *ze = create_aluno("zeneto",40,livro_poesia);
  print_aluno(ze);


  destroy_livro(&livro_poesia);


  print_aluno(ze);
  destroy_aluno(&ze);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char *semVogal(char *nome);

int main(){
    
  char nome[MAX], *pnome;

  printf("Informe o nome: ");
  gets(nome);

  pnome = semVogal(nome);
  printf("[%s] sem vogal: [%s]\n", nome, pnome);

  return 0;
}

char *semVogal(char *nome) {

  char *aux, *novo = (char *)malloc(MAX);
  aux = novo;
  while (*nome != '\0') {
    switch (*nome) {
      case 'A': case 'E': case 'I': case 'O': case 'U':
      case 'a': case 'e': case 'i': case 'o': case 'u':
         break;
      default:
        *aux = *nome;
        aux++;
    }
    nome++;
  }
  *aux = '\0';
  return novo;
}
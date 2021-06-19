#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int ano;
  int mes;
  int dia;
} data;

data *leData();
void exibeData(data *d, int formato);
int valida(data *d);
long int intervalo(data *d1, data *d2);
int maior(data *d1, data *d2);
int menor(data *d1, data *d2);

int diasMes(int mes);
long int emDias(data *d);

int main() {
  data *d1, *d2;

  printf("Data 1:\n");
  d1 = leData();
  printf("Data 2:\n");
  d2 = leData();

  exibeData(d1, 1);
  exibeData(d2, 3);

  printf("Intervalo em dias eh: %ld\n", intervalo(d1, d2));
  if (maior(d1, d2)) {
      printf("A primeira data eh maior que a segunda!\n");
  } else {
    printf("A segunda data eh maior que a primeira!\n");
  }
  return 0;
}

data *leData() {
  int vez = 0;
  data *d = (data *)malloc(sizeof(data));
  do {
    if (vez > 0) {
      printf("Data Invalida!\n");
    }
    printf("Informe o dia, mes e ano: ");
    scanf("%d %d %d", &d->dia, &d->mes, &d->ano);
    vez++;
  } while(!valida(d));

  return d;
}

void exibeData(data *d, int formato) {
  switch (formato) {
    case 1: printf("%2d-%2d-%4d\n", d->dia, d->mes, d->ano); break;
    case 2: printf("%4d-%2d-%2d\n", d->ano, d->mes, d->dia); break;
    case 3: printf("%2d/%2d/%4d\n", d->dia, d->mes, d->ano); break;
    case 4: printf("%4d/%2d/%2d\n", d->ano, d->mes, d->dia); break;
  }
}

int valida(data *d) {
  if (d->mes < 1 || d->mes > 12) {
    return 0;
  }
  if (d->dia < 1 || d->dia > diasMes(d->mes)) {
    return 0;
  }
  if (d->ano < 0 || d->ano > 3000) {
    return 0;
  }
  return 1;
}

long int intervalo(data *d1, data *d2) {
  if (maior(d1, d2))
    return emDias(d1) - emDias(d2);
  else
    return emDias(d2) - emDias(d1);
}

int maior(data *d1, data *d2) {
  return emDias(d1) > emDias(d2);
}

int menor(data *d1, data *d2) {
  return emDias(d1) < emDias(d2);
}

int diasMes(int mes) {
  int dia = 30;
  switch (mes) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      dia = 31;
      break;
    case 2:
      dia = 29;
      break;
  }
  return dia;
}

long int emDias(data *d) {
  int i;
  long int total;
  total = d->ano * 365 + d->dia;
  for (i=1; i<d->mes; i++) {
    total += diasMes(i);
  }
  return total;
}
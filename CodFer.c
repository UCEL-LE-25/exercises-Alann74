#include <stdio.h>

#define RESOURCES 3;
//NO VA PUNTO Y COMA
//no usaron este valor en ningun lado

void loadResources(int (*distribution)[3], int days);
void printTable(int (*distribution)[3], int days);
void printReport(int (*distribution)[3], int days);

int main(void) {

  int days;
  printf("Ingrese la cantidad de dias: \n");
  //validar que no sean numeros negativos
  scanf("%d", &days);

  int distribution[days][3];

  loadResources(distribution, days);
  printTable(distribution, days);
  printReport(distribution, days);

  return 0;
}

void loadResources(int (*distribution)[3], int days) {
  int water, food, medicine;
  for (int i = 0; i < days; i++) {
    printf("DAY %d\n", i + 1);
    printf("Ingrese la cantidad de agua: \n"); //sacaria el \n para una mejor interaccion con el usuario
    scanf("%d", &water);
    printf("Ingrese la cantidad de comida: \n");
    scanf("%d", &food);
    printf("Ingrese la cantidad de medicinas: \n");
    scanf("%d", &medicine);
    for (int j = 0; j < 3; j++) {
      switch (j) {
      case 0:
        distribution[i][j] = water;
        break;
      case 1:
        distribution[i][j] = food;
        break;

      case 2:
        distribution[i][j] = medicine;
        break;

      default:
        printf("Opcion invalida.");
        break;
      }
    }
  }
}

void printTable(int(*distribution)[3], int days) {
//no se ve que recursos veo
  for (int i = 0; i < days; i++) {
    for (int j = 0; j < 3; j++) {

      printf("%4d |", distribution[i][j]);
    }
    printf("\n");
  }
}
void printReport(int (*distribution)[3], int days) {
  int totalWater = 0, totalFood = 0, totalMedicine = 0;
  for (int i = 0; i < days; i++) {
    for (int j = 0; j < 3; j++) {
            switch (j) {
      case 0:
      totalWater += distribution[i][j];
        break;
      case 1:
      totalFood += distribution[i][j];
        break;
      case 2:
      totalMedicine += distribution[i][j];
        break;
      default:
        printf("Opcion invalida.");
        break;
      }
    }
  }
  //mostrar cantodad total de recursos
  printf("Total de agua: %d\n", totalWater);
  printf("Total de comida: %d\n", totalFood);
  printf("Total de medicinas: %d\n", totalMedicine);

  printf("Promedio de agua por dia: %d\n", totalWater / days);
  printf("Promedio de comida por dia: %d\n", totalFood / days);
  printf("Promedio de medicinas por dia: %d\n", totalMedicine / days);
}
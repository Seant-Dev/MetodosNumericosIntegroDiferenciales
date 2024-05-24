#include <stdio.h>
#include <math.h>

void lectura();
void calculo();
void imprime();

int i, n, grado;
double x[50], y[50];
double sumax, sumay, sumaxy, sumax2, sumax3, sumax4, sumax5, sumax6, sumax2y, sumax3y;

int main() {
    printf("\n\tPrograma de Minimos Cuadrados");
    printf("\n\tProporciona el numero de datos: ");
    scanf("%d", &n);

    printf("\n\tProporciona el Grado del Polinomio (2 o 3): ");
    scanf("%d", &grado);

    lectura();
    calculo();
    imprime();

    return 0;
}

void lectura() {
    for (i = 0; i < n; i++) {
        printf("\n\tX(%d)= ", i + 1);
        scanf("%lf", &x[i]);
    }
    for (i = 0; i < n; i++) {
        printf("\n\tY(%d)= ", i + 1);
        scanf("%lf", &y[i]);
    }
}

void calculo() {
    sumax = 0;
    sumay = 0;
    sumaxy = 0;
    sumax2 = 0;
    sumax3 = 0;
    sumax4 = 0;
    sumax5 = 0;
    sumax6 = 0;
    sumax2y = 0;
    sumax3y = 0;

    for (i = 0; i < n; i++) {
        sumax += x[i];
        sumay += y[i];
        sumaxy += x[i] * y[i];
        sumax2 += pow(x[i], 2);

        if (grado == 2) {
            sumax3 += pow(x[i], 3);
            sumax4 += pow(x[i], 4);
            sumax2y += (pow(x[i], 2)) * y[i];
        } else if (grado == 3) {
            sumax3 += pow(x[i], 3);
            sumax4 += pow(x[i], 4);
            sumax5 += pow(x[i], 5);
            sumax6 += pow(x[i], 6);
            sumax2y += (pow(x[i], 2)) * y[i];
            sumax3y += (pow(x[i], 3)) * y[i];
        }
    }
}

void imprime() {
    printf("\n\tResultados:\n");

    if (grado == 2) {
        printf("\n\t%d\t%lf\t%lf\t%lf", n, sumax, sumax2, sumay);
        printf("\n\t%lf\t%lf\t%lf\t%lf", sumax, sumax2, sumax3, sumaxy);
        printf("\n\t%lf\t%lf\t%lf\t%lf", sumax2, sumax3, sumax4, sumax2y);
    } else if (grado == 3) {
        printf("\n\t%d\t%lf\t%lf\t%lf\t%lf", n, sumax, sumax2, sumax3, sumay);
        printf("\n\t%lf\t%lf\t%lf\t%lf\t%lf", sumax, sumax2, sumax3, sumax4, sumaxy);
        printf("\n\t%lf\t%lf\t%lf\t%lf\t%lf", sumax2, sumax3, sumax4, sumax5, sumax2y);
        printf("\n\t%lf\t%lf\t%lf\t%lf\t%lf", sumax3, sumax4, sumax5, sumax6, sumax3y);
    }
}

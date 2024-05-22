#include <stdio.h>

int main() {
    float k, x[100], Fx[100];
    int n, l, m;
    float a, b, suma, TOTAL, dx;

    printf("\n\t PROGRAMA DEL METODO DE SIMPSON TRES OCTAVOS\n\n\n");
    printf("Dame el valor de N (debe ser un numero impar)\n");
    scanf("%d", &n);

    k = n / 2.0;
    m = n / 2;

    if (k != m) {
        printf("Dame el punto inicial\n");
        scanf("%f", &a);

        printf("Dame el punto final\n");
        scanf("%f", &b);

        printf("Dame los valores de x\n");
        for (l = 0; l < n + 1; l++) {
            scanf("%f", &x[l]);
        }

        printf("Dame los valores de fx \n");
        for (l = 0; l < n + 1; l++) {
            scanf("%f", &Fx[l]);
        }

        dx = (b - a) / n;

        for (l = 1; l < n; l++) {
            Fx[l] = Fx[l] * 3;
        }

        for (l = 0; l < n + 1; l++) {
            suma = suma + Fx[l];
        }

        TOTAL = (3 * dx / 8) * suma;

        printf("\n\nEl resultado es %f\n", TOTAL);
    } else {
        printf("\n\nEl numero que diste no es impar\n");
    }

    return 0;
}

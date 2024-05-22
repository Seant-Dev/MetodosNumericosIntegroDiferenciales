#include<stdio.h>

#define TA 100

int main() {
    int i;
    double A, a, b, f, c = 0, d = 0, deltx, g[TA] = {0}, p[TA] = {0};

    printf("Metodo de Simpson 1/3\n");
    printf("Inserte el numero de fajas:\t");
    scanf("%lf", &f);
    printf("\nInserte el valor de a y b separados por un espacio:\t");
    scanf("%lf %lf", &a, &b);

    deltx = (b - a) / f;

    printf("\nEl valor de delta x es:\t%lf\n\n", deltx);

    g[1] = a;
    for (i = 2; i <= f + 1; i++) {
        g[i] = (deltx + g[i - 1]);
    }

    for (i = 1; i <= f + 1; i++) {
        printf("\nInserte el valor de f(%lf):\t", g[i]);
        scanf("%lf", &p[i]);
    }

    for (i = 2; i < f + 1; i++) {
        if (i % 2 == 0) {
            c += p[i];
        } else {
            d += p[i];
        }
    }

    i = f;
    A = (deltx / 3) * (p[1] + p[i + 1] + (4 * c) + (2 * d));

    printf("\nEl resultado de la integral es:\t%lf\n", A);

    return 0;
}

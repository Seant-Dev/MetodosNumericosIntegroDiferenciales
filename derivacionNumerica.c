#include <stdio.h>
double x, dx, yMenosUno, y, yMasUno, aproximacion, yMenosDos, yMasDos;
int continuar, opcion1, opcion2;

int main() {
    printf("\n\t\t Derivacion numerica");
    printf("\n Este programa calcula la primera o segunda derivada");

    continuar = 0;

    do {
        printf("\n\n ¿En que punto se va a aproximar la derivada?: ");
        scanf("%lf", &x);
        printf(" Proporciona la delta del intervalo: ");
        scanf("%lf", &dx);
        printf("\n Opciones para derivadas\n\n");
        printf(" 1. Primera derivada\n");
        printf(" 2. Segunda derivada\n");
        printf(" 3. Salir\n");
        printf(" Elija una opcion: ");
        scanf("%d", &opcion1);

        if(opcion1 == 1) { // Primera derivada
            printf("\n Eligio Primera Derivada. Elija una Variante: ");
            printf("\n\t 1. Primeras diferencias centrales");
            printf("\n\t 2. Segundas diferencias centrales");
            printf("\n\t 3. Primeras diferencias hacia adelante");
            printf("\n\t 4. Segundas diferencias hacia adelante");
            printf("\n\t 5. Primeras diferencias hacia atras");
            printf("\n\t 6. Segundas diferencias hacia atras");
            printf("\n\t Elija una opción: ");
            scanf("%d", &opcion2);

            if(opcion2 == 1) { // Primeras diferencias centrales
                printf("\nPrimeras diferencias centrales\n");
                printf(" Valor de F(%lf): ", (x-dx));
                scanf("%lf", &yMenosUno);
                printf(" Valor de F(%lf): ", (x+dx));
                scanf("%lf", &yMasUno);
                aproximacion = (yMasUno - yMenosUno) / (2 * dx);
                printf(" La aproximacion de la primera derivada es: %lf", aproximacion);
                printf("\n");
            } else if(opcion2 == 2) { // Segundas diferencias centrales
                printf("\nSegundas diferencias centrales\n");
                printf(" Valor de F(%lf): ", (x-(2*dx)));
                scanf("%lf", &yMenosDos);
                printf(" Valor de F(%lf): ", (x-dx));
                scanf("%lf", &yMenosUno);
                printf(" Valor de F(%lf): ", (x+dx));
                scanf("%lf", &yMasUno);
                printf(" Valor de F(%lf): ", (x+(2*dx)));
                scanf("%lf", &yMasDos);
                aproximacion = (-yMasDos + (8*yMasUno) - (8*yMenosUno) + yMenosDos) / (12 * dx);
                printf(" La aproximacion de la primera derivada es: %lf", aproximacion);
                printf("\n");
            } else if(opcion2 == 3) { // Primeras diferencias hacia adelante
                printf("\nPrimeras diferencias hacia adelante\n");
                printf(" Valor de F(%lf): ", x);
                scanf("%lf", &y);
                printf(" Valor de F(%lf): ", (x + dx));
                scanf("%lf", &yMasUno);
                aproximacion = (yMasUno - y) / dx;
                printf(" La aproximacion de la primera derivada es: %lf", aproximacion);
                printf("\n");
            } else if(opcion2 == 4) { // Segundas diferencias hacia adelante
                printf("\nSegundas diferencias hacia adelante\n");
                printf(" Valor de F(%lf): ", x);
                scanf("%lf", &y);
                printf(" Valor de F(%lf): ", (x + dx));
                scanf("%lf", &yMasUno);
                printf(" Valor de F(%lf): ", (x + 2 * dx));
                scanf("%lf", &yMasDos);
                aproximacion = (-(yMasDos) + (4 * yMasUno) - (3 * y)) / (2 * dx);
                printf(" La aproximacion de la primera derivada es: %lf", aproximacion);
                printf("\n");
            } else if(opcion2 == 5) { // Primeras diferencias hacia atras
                printf("\nPrimeras diferencias hacia atras\n");
                printf(" Valor de F(%lf): ", (x - dx));
                scanf("%lf", &yMenosUno);
                printf(" Valor de F(%lf): ", x);
                scanf("%lf", &y);
                aproximacion = (y - yMenosUno) / dx;
                printf(" La aproximacion de la primera derivada es: %lf", aproximacion);
                printf("\n");
            } else if(opcion2 == 6) { // Segundas diferencias hacia atras
                printf("\nSegundas diferencias hacia atras\n");
                printf(" Valor de F(%lf): ", (x - 2 * dx));
                scanf("%lf", &yMenosDos);
                printf(" Valor de F(%lf): ", (x - dx));
                scanf("%lf", &yMenosUno);
                printf(" Valor de F(%lf): ", x);
                scanf("%lf", &y);
                aproximacion = (3 * y - (4 * yMenosUno) + yMenosDos) / (2 * dx);
                printf(" La aproximacion de la primera derivada es: %lf", aproximacion);
                printf("\n");
            } else {
                printf("\n Opcion no valida");
            }
        } else if(opcion1 == 2) { // Segunda derivada
            printf("\n Eligio Segunda Derivada. Elija una Variante: ");
            printf("\n\t 1. Primeras diferencias centrales");
            printf("\n\t 2. Segundas diferencias centrales");
            printf("\n\t 3. Primeras diferencias hacia adelante (no definido)");
            printf("\n\t 4. Segundas diferencias hacia adelante (no definido)");
            printf("\n\t 5. Primeras diferencias hacia atras (no definido)");
            printf("\n\t 6. Segundas diferencias hacia atras (no definido)");
            printf("\n\t Elija una opción: ");
            scanf("%d", &opcion2);

            if(opcion2 == 1) { // Primeras diferencias centrales
                printf("\nPrimeras diferencias centrales\n");
                printf(" Valor de F(%lf): ", (x - dx));
                scanf("%lf", &yMenosUno);
                printf(" Valor de F(%lf): ", x);
                scanf("%lf", &y);
                printf(" Valor de F(%lf): ", (x + dx));
                scanf("%lf", &yMasUno);
                aproximacion = (yMasUno - 2 * y + yMenosUno) / (dx * dx);
                printf(" La aproximacion de la segunda derivada es: %lf", aproximacion);
                printf("\n");
            } else if(opcion2 == 2) { // Segundas diferencias centrales
                printf("\nSegundas diferencias centrales\n");
                printf(" Valor de F(%lf): ", (x - 2 * dx));
                scanf("%lf", &yMenosDos);
                printf(" Valor de F(%lf): ", (x - dx));
                scanf("%lf", &yMenosUno);
                printf(" Valor de F(%lf): ", x);
                scanf("%lf", &y);
                printf(" Valor de F(%lf): ", (x + dx));
                scanf("%lf", &yMasUno);
                printf(" Valor de F(%lf): ", (x + 2 * dx));
                scanf("%lf", &yMasDos);
                aproximacion = (-yMasDos + 16 * yMasUno - 30 * y + 16 * yMenosUno - yMenosDos) / (12 * dx * dx);
                printf(" La aproximacion de la segunda derivada es: %lf", aproximacion);
                printf("\n");
            } else {
                printf("\n Opcion no valida o no definida");
            }
        } else if(opcion1 == 3) { // Salir
            continuar = 0;
            break;
        } else {
            printf("\n Opcion no valida");
        }

        printf(" ¿Reiniciar Programa?");
        printf("\n Para terminar ingresa 0, para continuar 1: ");
        scanf("%d", &continuar);

    } while(continuar == 1);

    return 0;
}

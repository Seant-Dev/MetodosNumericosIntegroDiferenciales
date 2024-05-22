#include <stdio.h>
#include <math.h>
#define MAX 50
double xInicial, yInicial, xf, h;
double x[MAX], y[MAX], k1[MAX], k2[MAX], k3[MAX], k4[MAX];
int inicializaVariables();
double funcionXY(double x, double y);
double yMasUno(double y, double k1, double k2, double k3, double k4);
void aplicaMetodo(int n);
void imprimeResultados(int n);
int main()
{
    int n;
    printf("\n Este programa resuelve ecuaciones diferenciales de primer orden");
    printf("\n por el metodo de Runge Kutta de grado cuatro");
    n = inicializaVariables();
    aplicaMetodo(n);
    imprimeResultados(n);
    
   // printf("\n El valor de y+1 es: %lf", y[0+1]);
    return 0;
}

void imprimeResultados(int n)
{
    int i;
    
    printf("\n\ti \t   x \t\t    y \t\t    k1 \t\t     k2 \t    k3 \t\t     k4");
    for(i=0; i<=n; i++)
    {
        printf("\n\t%d \t%lf \t%lf \t%lf \t%lf \t%lf \t%lf", i, x[i], y[i], k1[i], k2[i], k3[i], k4[i]);
    }

    printf("\n\n");
}


double yMasUno(double y, double k1, double k2, double k3, double k4)
{
    double resultado;
    //printf("\n valores recibidos:");
    //printf("\n y = %lf", y);
    //printf("\n k1 = %lf", k1);
    //printf("\n k2 = %lf", k2);
    //printf("\n k3 = %lf", k3);
    //printf("\n k4 = %lf", k4);
    resultado = y + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
    //printf("\n el resultado es y = %lf", resultado);
    return resultado;
}


void aplicaMetodo(int n)
{
    double xtemp, ytemp;
    int i;
    
    for(i=0; i<n; i++)
    {
        k1[i] = funcionXY(x[i], y[i]);
        //printf("\n k1 = %lf", k1[i]);
    
        xtemp = x[i] + h/2;
        ytemp = y[i] + k1[i]*h/2;
        k2[i] = funcionXY(xtemp, ytemp);
        //printf("\n k2 = %lf", k2[i]);
    
        ytemp = y[i] + k2[i]*h/2;
        k3[i] = funcionXY(xtemp, ytemp);
       // printf("\n k3 = %lf", k3[i]);
    
        xtemp = x[i] + h;
        ytemp = y[i] + k3[i]*h;
        k4[i] = funcionXY(xtemp, ytemp);
       // printf("\n k4 = %lf", k4[i]);
    
        y[i+1] = yMasUno(y[i], k1[i], k2[i], k3[i], k4[i]);
    }
}


double funcionXY(double x, double y)
{
    double resultado;
    //printf("\n valor recibido en x = %lf", x);
    //printf("\n valor recibido en y = %lf", y);
    resultado = -20*y + 7*exp(-0.5*x);
    //printf("\n el resultado es = %lf", resultado);
    return resultado;
}


int inicializaVariables()
{
    int i, n;
    printf("\n Proporciona las condiciones iniciales: ");
    printf("\n xInicial = ");
    scanf("%lf", &xInicial );
    printf(" yInicial = ");
    scanf("%lf", &yInicial );
    printf(" xf = ");
    scanf("%lf", &xf );
    printf(" h = ");
    scanf("%lf", &h );
    n = (xf-xInicial)/h;
  //  printf("\n indice vale: %d", indice);
  
    x[0] = xInicial;
    y[0] = yInicial;
    for(i=1; i<=n; i++)
    {
        x[i] = x[i-1] + h;
       // printf("\n x[%d] = %lf", i, x[i]);
    }
    return n;
}

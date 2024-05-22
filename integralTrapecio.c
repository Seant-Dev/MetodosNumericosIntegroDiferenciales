#include <stdio.h>
#define MAX 40

typedef float vector[MAX];

void lee_vector(vector a, vector b, int n1);
void llena_x(vector a, int n1, float te1, float dx1);
float trapecio(vector fx1, float dx1, int n1);

int main() {  
    int n, p;
    float r, ax, dx, a, b, te;
    vector x, fx;
    ax = 1;
    printf("Dame el limite inferior a = ");
    scanf("%f", &a);
    te = a;
    printf("Dame el limite superior b = ");
    scanf("%f", &b);
    printf("Dame el numero de fajas n = ");
    scanf("%d", &n);
    p = n + 1;
    dx = (b - a) / n;
    x[0] = a;
    llena_x(x, p, te, dx); 
    printf("\n");
    lee_vector(fx, x, p);
    r = trapecio(fx, dx, n);
    printf("\nEl resultado es = %.6f\n", r);   
    return 0;
}

void lee_vector(vector a, vector b, int n1)  {
    int i;
    printf("Ingrese los valores de F(x)\n");
    for (i = 0; i < n1; i++) {
        printf("x = %.6f     f(x) = ", b[i]);
        scanf("%f", &a[i]);
    }
}

void llena_x(vector a, int n1, float te1, float dx1) {
    int i;
    for (i = 1; i < n1; i++) {
        te1 = te1 + dx1;
        a[i] = te1;
    }
}

float trapecio(vector fx1, float dx1, int n1) {
    int i;
    float sum, res;
    sum = fx1[0] + fx1[n1];
    for (i = 1; i < n1; i++) {
        sum = sum + 2 * fx1[i];
    }
    res = (dx1 / 2) * sum;
    return res;
}

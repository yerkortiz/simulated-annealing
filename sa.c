/*
 * Author: Yerko Ortiz
 * Input: temperatura inicial, temperatura minima, ratio de decrecimiento de temperatura
 * Output: set de soluciones tras cada decremento de temperatura
 * t = temperatura actual
 * t_min = temperatura de enfriamiento
 * delta = rango de cambios locales
 * alpha = ratio de decrecimiento de temperatura
 * n = numero de variables
 * x* = vector de variables que son soluciones
 * y = valor del vector x* evaluado en la funcion
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "rnd_.h"

/* objF 1100 */
double objF(double *x, int n)
{
    double value = 0;
    for(int i = 0; i < n; ++i) {
        if(i > 1) value -= (x[i]*x[i]*x[i]);
        else value += (x[i]*x[i]*x[i]);
    }
    return value;
}
void sA(double t, double t_min, double alpha, int n, double *x, double y, double delta)
{
    int i, j, k;
    double *x_ = malloc(n * sizeof(double));
    double y_, ap;
    for(i = 0; i < n; ++i){
        x[i] = rndF(-1, 0);
        x_[i] = x[i];
    }
    y = objF(x_, n);
    while(t > t_min) {
        //printf("%d%c", (x[i] < 0)? 0:1, (i == n - 1)? '\n':' ');
        for(i = 0; i < 120; ++i) {
            for(j = 0; j < n; ++j) {
                for(k = 0; k < n; ++k) 
                    printf("%lf ", x[k]);
                printf(" %lf\n", y);
                x_[j] = x[j] + rndF(-delta, delta);
                y_ = objF(x_, n);
                if(y_ > y) {
                    x[j] = x_[j];
                    y = y_;
                    continue;
                } else {
                    ap = min(exp((y - y_)/t), 1);
                    if(rndF(0, 1) < ap) {
                        x[j] = x_[j];
                        y = y_;
                        continue;
                    }
                } 
                x_[j] = x[j];
            }
        }
        t *= alpha;
    }
}
int main(int argc, char **argv)
{
    double t = atof(argv[1]), t_min = atof(argv[2]), alpha = atof(argv[3]), delta = atof(argv[4]);
    int n = 4;
    double *x = malloc(n * sizeof(double));
    double y;
    sA(t, t_min, alpha, n, x, y, delta);
    free(x);
    return 0;
}
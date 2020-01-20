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
 * y = valor del vector x evaluado en la funcion
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
        if(i >= 2) value -= (2*(x[i]*x[i]*x[i]));
        value += (x[i]*x[i]*x[i]);
    }
    return value;
}
void sA(double t, double t_min, double alpha, int n, double *x, double y, double delta)
{
    int i, j;
    double *x0 = malloc(n * sizeof(double));
    double *x_ = malloc(n * sizeof(double));
    double y_, ap, y0;
    for(i = 0; i < n; ++i) x0[i] = rndF(-100, 0);
    y0 = objF(x0, n);
    for(i = 0; i < n; ++i) x[i] = x0[i];
    y = y0;
    while(t > t_min) {
        for(i = 0; i < n; ++i) 
                printf("%d%c", (x[i] < 0)? 0:1, (i == n - 1)? '\n':' ');
        for(i = 0; i < 20; ++i) {
            for(j = 0; j < n; ++j) x_[j] = rndF(x[j] - delta, x[j] + delta);
            y_ = objF(x_, n);
            if(y_ > y) {
                for(j = 0; j < n; ++j) x[j] = x_[j];
                y = y_;
            } else {
                for(j = 0; j < n; ++j) x_[j] = rndF((x[j] - 10), (x[j] + 10));
                y_ = objF(x_, n);
                if(y_ > y) {
                    for(j = 0; j < n; ++j) x[j] = x_[j];
                    y = y_;
                } /*else {
                    ap = min(exp((y - y_)/t), 1);
                    if(ap > rndF(0, 1)) {
                        for(j = 0; j < n; ++j) x[j] = x_[j];
                        y = y_;
                    }
                }*/
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
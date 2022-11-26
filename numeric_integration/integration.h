#ifndef UNIVERNUMERICMETHODS_INTEGRATION_H
#define UNIVERNUMERICMETHODS_INTEGRATION_H

#define u64 uint64_t

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

typedef enum IntegrationMethod {
    LEFT_RECTANGLES,
    MIDDLE_RECTANGLES,
    RIGHT_RECTANGLES,
    TRAPEZIUMS,
    PARABOLAS
} IntegrationMethod_t;

void integrate(double a, double b, u64 n);

double f_to_integrate(double x);

int integration(double a, double b, u64 n, IntegrationMethod_t method, double* pResult);

void integrate(double a, double b, u64 n) {

    double result = 0;
    int errorCode = integration(a, b, n, LEFT_RECTANGLES, &result);
    if (errorCode == 0) {
        printf("Left Rectangles: %.4lf\n", result);
    }

    errorCode = integration(a, b, n, MIDDLE_RECTANGLES, &result);
    if (errorCode == 0) {
        printf("Middle Rectangles: %.4lf\n", result);
    }

    errorCode = integration(a, b, n, RIGHT_RECTANGLES, &result);
    if (errorCode == 0) {
        printf("Right Rectangles: %.4lf\n", result);
    }

    errorCode = integration(a, b, n, TRAPEZIUMS, &result);
    if (errorCode == 0) {
        printf("Trapeziums: %.4lf\n", result);
    }

    errorCode = integration(a, b, n * 2, PARABOLAS, &result);
    if (errorCode == 0) {
        printf("Parabolas: %.4lf\n", result);
    }
}

// returns error code
int integration(double a, double b, u64 n, IntegrationMethod_t method, double* pResult) {

    *pResult = 0;
//    step of integration
    double h = (double) (b - a) / (double) n;

    int i;
    double x;

    switch (method) {
        case LEFT_RECTANGLES: {
//            n adds, 1 multiply, accuracy (-)
            for (i = 0, x = a; i <= n - 1; x += h, ++i) {
                *pResult += f_to_integrate(x);
            }
            *pResult *= h;

//            n adds, n multiplies, accuracy (+)
            /*
            for (i = 0, x = a; i <= n - 1; ++i, x += h) {
                *pResult += h * f_to_integrate(x);
            }
            */

            break;
        }
        case MIDDLE_RECTANGLES: {
            for (i = 0, x = a + h / 2.0; i <= n - 1; x += h, ++i) {
                *pResult += f_to_integrate(x);
            }
            *pResult *= h;
            break;
        }
        case RIGHT_RECTANGLES: {
            for (i = 0, x = b; i <= n - 1; x -= h, ++i) {
                *pResult += f_to_integrate(x);
            }
            *pResult *= h;
            break;
        }
        case TRAPEZIUMS: {

            *pResult += (f_to_integrate(a) + f_to_integrate(b)) / 2.0;
            for (i = 1, x = a + h; i <= n - 1; x += h, ++i) {
                *pResult += f_to_integrate(x);
            }
            *pResult *= h;
            break;
        }
        case PARABOLAS: {

            *pResult = f_to_integrate(a) + f_to_integrate(b);
            for (i = 1, x = a + h; i <= n - 1; x += h, ++i) {

                *pResult += (f_to_integrate(x) * (i % 2 == 0 ? 2.0 : 4.0));
            }
            *pResult *= h / 3.0;
            break;
        }
        default: {
            return -1;
        }
    }

    return EXIT_SUCCESS;
}

double f_to_integrate(double x) {
    return sqrt(9 - x * x) / (x * x);
}

#endif //UNIVERNUMERICMETHODS_INTEGRATION_H

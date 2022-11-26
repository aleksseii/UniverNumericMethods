#ifndef UNIVERNUMERICMETHODS_DEMONSTRATION_H
#define UNIVERNUMERICMETHODS_DEMONSTRATION_H

#include "solving_nonlinear_equation/dichotomy_method/dichotomy_method.h"
#include "solving_nonlinear_equation/combined_method/combined_method.h"
#include "numeric_integration/integration.h"

void dichotomy_solving_demo() {
    double x_start = -1.5;
    double x_end = -1.;

    dichotomy_solve(x_start, x_end);
}

void combined_solving_demo() {
    double x_start = -1.5;
    double x_end = -1.;

    combined_solve(x_start, x_end);
}

void integrating_demo() {
    double a = 0.5;
    double b = 3.0;

    u64 n = 5;

    integrate(a, b, (int) ((double) n * 10e6));
}

#endif //UNIVERNUMERICMETHODS_DEMONSTRATION_H

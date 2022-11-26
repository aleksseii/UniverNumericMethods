#ifndef UNIVERNUMERICMETHODS_COMBINED_METHOD_H
#define UNIVERNUMERICMETHODS_COMBINED_METHOD_H

#define EPSILON 0.001

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void combined_solve(double x_start, double x_end);
double combined_f(double x);
double combined_f_derivative(double x);
double combined_f_2nd_derivative(double x);

void combined_solve(double x_start, double x_end) {

    // Point 1 - skip because it is too complicated to realize on computer

    // Point 2:
    if (combined_f(x_start) * combined_f(x_end) > 0) {
        printf("Dichotomy method work is not assured!\n");
        exit(EXIT_FAILURE);
    }

    bool flag = true;
    size_t iteration = 1;

    while (flag) {

        // Point 3:
        double x0;
        double x0_star;


        if (combined_f(x_start) * combined_f_2nd_derivative(x_start) > 0) {
            x0 = x_start;
            x0_star = x_end;
        } else {
            x0 = x_end;
            x0_star = x_start;
        }

        // Point 4:
        double x1_tangent = x0 - (combined_f(x0) / combined_f_derivative(x0));
        double x1_chord = x0_star - (
                (x0 - x0_star) * combined_f(x0_star) / (
                        combined_f(x0) - combined_f(x0_star)
                )
        );

        // Point 5:
        double x1 = (x1_tangent + x1_chord) / 2.;

        // Point 6:
        if (fabs(x1_tangent - x1_chord) < 2 * EPSILON ||
            fabs(combined_f(x1)) < EPSILON) {
            flag = false;
        }

        printf("Iteration number: %llu\n"
               "x-tangent value: %.4lf\n"
               "x-chord value: %.4lf\n"
               "Root value: %.4lf\n"
               "Function value: %.4lf\n\n\n",
               iteration++, x1_tangent, x1_chord, x1, combined_f(x1));

        x_start = x1_tangent;
        x_end = x1_chord;
    }
}

double combined_f(double x) {
    // not using `pow` from "math.h" because of `calculation context change`
    return x * x * x - 0.3664 * x + 2;
}

double combined_f_derivative(double x) {
    // not using `pow` from "math.h" because of `calculation context change`
    return 3 * x * x - 0.3664;
}

double combined_f_2nd_derivative(double x) {
    return 6 * x;
}

#endif //UNIVERNUMERICMETHODS_COMBINED_METHOD_H

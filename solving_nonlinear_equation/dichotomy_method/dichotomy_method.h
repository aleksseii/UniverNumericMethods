#ifndef UNIVERNUMERICMETHODS_DICHOTOMY_METHOD_H
#define UNIVERNUMERICMETHODS_DICHOTOMY_METHOD_H

#include "../util/util.h"

void dichotomy_solve(double x_start, double x_end);
double dichotomy_f(double x);

void dichotomy_solve(double x_start, double x_end) {

    // Point 1 - skip because it is too complicated to realize on computer

    // Point 2:
    if (dichotomy_f(x_start) * dichotomy_f(x_end) > 0) {
        printf("Dichotomy method work is not assured!\n");
        exit(EXIT_FAILURE);
    }

    double x_center;
    double x_center_previous = 0.;
    double f_center;

    bool flag = true;
    size_t iteration = 1;

    while (flag) {

        // Point 3:
        double sum = round_n((x_start + x_end), DECIMALS);
        x_center = round_n(sum / 2, DECIMALS);
        f_center = round_n(dichotomy_f(x_center), DECIMALS);

        // Point 4:
        if (sign(dichotomy_f(x_start)) * sign(f_center) < 0) {
            x_end = x_center;
        } else if (sign(dichotomy_f(x_end)) * sign(f_center) < 0) {
            x_start = x_center;
        } else {
            printf("Something went wrong");
            exit(EXIT_FAILURE);
        }

        // Point 5:
        if (fabs(f_center) < EPSILON || iteration > 1 &&
                                        fabs(x_center - x_center_previous) < EPSILON) {
            flag = false;
        }

        x_center_previous = x_center;

        printf("Iteration number: %llu\n"
               "Root value: %.4lf\n"
               "Function value: %.4lf\n\n\n",
               iteration++, x_center, f_center);
    }
}

double dichotomy_f(double x) {
    // not using `pow` from "math.h" because of `calculation context change`
    return x * x * x - 0.3664 * x + 2;
}

#endif //UNIVERNUMERICMETHODS_DICHOTOMY_METHOD_H

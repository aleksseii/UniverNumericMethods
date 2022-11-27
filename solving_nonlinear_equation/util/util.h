//
// Created by АЛЕКСЕЙ on 28.11.2022.
//

#ifndef UNIVERNUMERICMETHODS_UTIL_H
#define UNIVERNUMERICMETHODS_UTIL_H

#define sign(x) (x > 0 ? 1.0 : (x < 0 ? -1.0 : 0.0))

#define EPSILON 0.001
#define DECIMALS 4
#define u64 uint64_t

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

double round_n(double num, unsigned int n);

double round_n(double num, unsigned int n) {

    u64 coeff = 1;
    for (int i = 0; i < n; ++i) {
        coeff *= 10;
    }

    return round(num * (double) coeff) / (double) coeff;
}

#endif //UNIVERNUMERICMETHODS_UTIL_H

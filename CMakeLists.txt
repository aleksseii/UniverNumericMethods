cmake_minimum_required(VERSION 3.20)
project(UniverNumericMethods C)

set(CMAKE_C_STANDARD 11)

add_executable(UniverNumericMethods main.c solving_nonlinear_equation/dichotomy_method/dichotomy_method.h solving_nonlinear_equation/combined_method/combined_method.h numeric_integration/integration.h demonstration.h)

#include <stdio.h>

double toCelsius(double degreeF) {
    return (degreeF - 32) / 1.8;
}

/*
 * A program that converts 27f to Celsius
 */
void exercise1() {
    double degreeF = 27;
    printf("%.2ff is %.2fc", degreeF, toCelsius(degreeF));
}


double[] getRootsOfQuad(double a, double b, double c) {

}
/*
 * A program that computes the (two) roots of athe quadratic equation
 */
void exercise2() {
    double[] roots = getRootsOfQuad(1.2, 2.3, -3.4);
}


int main() {
    exercise1();
    printf("\n\n");
    exercise2();
    return 0;
}


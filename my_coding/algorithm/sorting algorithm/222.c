#include <stdio.h>
#include <math.h>

double calculateSin(double x, int terms) {
    double result = 0.0;
    int i;

    for (i = 0; i < terms; ++i) {
        int exponent = 2 * i + 1;
        double term = pow(-1, i) * pow(x, exponent) / tgamma(exponent + 1);  // tgamma(n) calculates (n-1)!
        result += term;
    }

    return result;
}

int main() {
    double angleInRadians;
    printf("Enter the angle in radians: ");
    scanf("%lf", &angleInRadians);

    int terms;
    printf("Enter the number of terms to use in the Taylor series: ");
    scanf("%d", &terms);

    double sinValue = calculateSin(angleInRadians, terms);

    printf("Approximate sin(%lf) using %d terms: %lf\n", angleInRadians, terms, sinValue);

    return 0;
}

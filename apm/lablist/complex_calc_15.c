#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

int main() {
    struct Complex c1, c2, sum, diff;

    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &c1.real, &c1.imaginary);

    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &c2.real, &c2.imaginary);

    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;

    diff.real = c1.real - c2.real;
    diff.imaginary = c1.imaginary - c2.imaginary;

    printf("\nSum = %.2f + %.2fi", sum.real, sum.imaginary);
    printf("\nDifference = %.2f + (%.2f)i\n", diff.real, diff.imaginary);

    return 0;
}
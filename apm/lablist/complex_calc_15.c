/* 
Name: Aswin K U 
Roll No: CS06
Date: 12/10/2026

Experiment No : 15
 
Heading: Complex Number Calculator for Engineering Simulations
 
AIM: Develop a program that allows the user to input two complex numbers and calculates their sum and difference. This program could be applied in simulations for electrical engineering or physics problems.

ALGORITHM

1. Start.

2. Define a structure `C` with two members: `real` and `imag`.

3. Define function `getComp()` to read and return the real and imaginary parts of a complex number.

4. Define function `addComp(n1, n2)` to add the real and imaginary parts of two complex numbers and return the sum.

5. Define function `subComp(n1, n2)` to subtract the real and imaginary parts of two complex numbers and return the difference.

6. Define function `disComp(n)` to display the complex number according to the sign of its imaginary part.

7. In the main function, declare four complex number variables `c1`, `c2`, `s`, and `d`.

8. Read the first complex number using `getComp()`.

9. Read the second complex number using `getComp()`.

10. Calculate the sum using `addComp(c1, c2)` and store it in `s`.

11. Calculate the difference using `subComp(c1, c2)` and store it in `d`.

12. Display the first and second complex numbers using `disComp()`.

13. Display the sum and difference using `disComp()`.

14. Stop.

SOURCE CODE
*/
#include <stdio.h>

typedef struct {
    float real;
    float imag;
} C;


C getComp() {
    C num;
    printf("Enter real part: ");
    scanf("%f", &num.real);
    printf("Enter imaginary part: ");
    scanf("%f", &num.imag);
    return num;
}

C addComp(C n1, C n2) {
    C sum;
    sum.real = n1.real + n2.real;
    sum.imag = n1.imag + n2.imag;
    return sum;
}

C subComp(C n1, C n2) {
    C diff;
    diff.real = n1.real - n2.real;
    diff.imag = n1.imag - n2.imag;
    return diff;
}

void disComp(C n) {
    if (n.imag >= 0) {
        printf("%.2f + %.2fi", n.real, n.imag);
    } else {
        printf("%.2f - %.2fi", n.real, -n.imag);
    }
}

int main() {
    C c1, c2, s, d;

    printf("Enter first complex number:\n");
    c1 = getComp();

    printf("\nEnter second complex number:\n");
    c2 = getComp();

    s = addComp(c1, c2);
    d = subComp(c1, c2);

    printf("\nFirst complex number: ");
    disComp(c1);
    printf("\nSecond complex number: ");
    disComp(c2);

    printf("\n\nSum: ");
    disComp(s);

    printf("\nDifference: ");
    disComp(d);
    printf("\n");

    return 0;
}

/*
Output

Enter first complex number:
Enter real part: 4
Enter imaginary part: 2

Enter second complex number:
Enter real part: 8
Enter imaginary part: 6

First complex number: 4.00 + 2.00i
Second complex number: 8.00 + 6.00i

Sum: 12.00 + 8.00i
Difference: -4.00 - 4.00i
*/
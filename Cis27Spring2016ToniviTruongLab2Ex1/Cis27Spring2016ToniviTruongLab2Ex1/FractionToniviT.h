#ifndef FRACTIONTONIVIT_H
#define FRACTIONTONIVIT_H

typedef struct fraction {
	int num;
	int denom;
} Fraction;

Fraction* init(int, int);
Fraction* add(Fraction**, Fraction**);
Fraction* subtract(Fraction**, Fraction**);
Fraction* multiply(Fraction**, Fraction**);
Fraction* divide(Fraction**, Fraction**);
void simplify(Fraction**);
int gcd(int, int);

#endif

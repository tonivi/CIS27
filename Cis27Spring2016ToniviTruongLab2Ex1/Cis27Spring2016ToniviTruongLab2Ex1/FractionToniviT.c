/*
* Project Name : FractionToniviT.cpp
* Discussion :   Fraction Statements
* Written By :   Tonivi Truong
* Date :         2016/25/02
*/

#include <stdlib.h>
#include "FRACTIONTONIVIT.h"

Fraction* init(int num, int denom) {
	Fraction* frac = (Fraction*)malloc(sizeof(Fraction));

	(frac)->num = num;
	(frac)->denom = denom;
	simplify(&frac);

	return frac;
}

Fraction* add(Fraction** f1, Fraction** f2) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	(result)->num = ((*f1)->num * (*f2)->denom) + ((*f2)->num * (*f1)->denom);
	(result)->denom = (*f1)->denom * (*f2)->denom;
	simplify(&result);

	return result;
}

Fraction* subtract(Fraction** f1, Fraction** f2) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	result->num = ((*f1)->num * (*f2)->denom) - ((*f2)->num * (*f1)->denom);
	result->denom = (*f1)->denom * (*f2)->denom;
	simplify(&result);

	return result;
}

Fraction* multiply(Fraction** f1, Fraction** f2) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	result->num = (*f1)->num * (*f2)->num;
	result->denom = (*f1)->denom * (*f2)->denom;
	simplify(&result);

	return result;
}

Fraction* divide(Fraction** f1, Fraction** f2) {
	Fraction* result = (Fraction*)malloc(sizeof(Fraction));

	result->num = (*f1)->num * (*f2)->denom;
	result->denom = (*f1)->denom * (*f2)->num;
	simplify(&result);

	return result;
}

void simplify(Fraction** arg) {
	int gcl;
	if ((*arg)->denom < 0) {
		((*arg)->num) = -(*arg)->num;
		((*arg)->denom) = -(*arg)->denom;
	}
	if ((*arg)->num == 0) {
		(*arg)->denom = 1;
	} else {
		gcl = gcd((*arg)->num, (*arg)->denom);
		(*arg)->num /= gcl;
		(*arg)->denom /= gcl;
	}
	return;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}
/*
* Project Name : Cis27Spring2016ToniviTruongLab2Ex1.cpp
* Discussion :   Main
* Written By :   Tonivi Truong
* Date :         2016/25/02
*/

#include <stdio.h>
#include <stdlib.h>
#include "FractionToniviT.h"
void classInfo();
void menu();
void initMenu(Fraction**, Fraction**);
void createOneFrac(Fraction**, int, int);

int main() {
	classInfo();
	menu();
	return 0;
}

void classInfo() {
	printf("\nCIS 27 - C Programming\n"
		"Laney College\n"
		"Tonivi Truong\n"
		"\nAssignment Information --\n"
		"  Assignment Number:  Lab 02,"
		"\n\t\t      Coding Assignment -- Excercise #1"
		"\n  Written by: \t      Tonivi Truong"
		"\n  Submitted Date:     2016/25/02\n");

	return;
}

void menu() {
	int option;
	Fraction* frac1 = 0;
	Fraction* frac2 = 0;
	Fraction* result = 0;

	do {
		printf("\n************************************"
			"\n*   Menu : Fraction Tonivi Truong   *"
			"\n*   1. Creating/Updating            *"
			"\n*   2. Adding                       *"
			"\n*   3. Subtracting                  *"
			"\n*   4. Multiplying                  *"
			"\n*   5. Dividing                     *"
			"\n*   6. Displaying                   *"
			"\n*   7. Quit                         *"
			"\n************************************"
			"\nSelect an option (1 though 7): ");
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			initMenu(&frac1, &frac2);
			break;
		case 2:
			if (!frac1 || !frac2) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling add() -\n");
				result = add(&frac1, &frac2);
				printf("\n\n  (%d/%d + %d/%d = %d/%d)\n\n", 
					frac1->num, frac1->denom, 
					frac2->num, frac2->denom,
					result->num, result->denom);
			}
			break;
		case 3:
			if (!frac1 || !frac2) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling subtract() -\n");
				result = subtract(&frac1, &frac2);
				printf("\n\n  (%d/%d - %d/%d = %d/%d)\n\n", 
					frac1->num, frac1->denom,
					frac2->num, frac2->denom,
					result->num, result->denom);
			}
			break;
		case 4:
			if (!frac1 || !frac2) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling multiply() -\n");
				result = multiply(&frac1, &frac2);
				printf("\n\n  (%d/%d * %d/%d = %d/%d)\n\n", 
					frac1->num, frac1->denom,
					frac2->num, frac2->denom,
					result->num, result->denom);
			}
			break;
		case 5:
			if (!frac1 || !frac2) {
				printf("\n  Not Allowed Yet - No Proper Data!\n\n");
			} else {
				printf("\n  Calling divide() -\n");
				result = divide(&frac1, &frac2);
				printf("\n\n  (%d/%d / %d/%d = %d/%d)\n\n", 
					frac1->num, frac1->denom,
					frac2->num, frac2->denom,
					result->num, result->denom);
			}
			break;
		case 6:
			printf("\n  Left Operand:");
			if (!frac1) {
				printf("\n    Address/Location: NULL\n");
			} else {
				printf("\n    Address/Location: %p", &frac1);
				printf("\n    Numerator: %d", frac1->num);
				printf("\n    Denominator: %d\n", frac1->denom);
			}

			printf("\n  Right Operand:");
			if (!frac2) {
				printf("\n    Address/Location: NULL");
			} else {
				printf("\n    Address/Location: %p", &frac2);
				printf("\n    Numerator: %d", frac2->num);
				printf("\n    Denominator: %d", frac2->denom);
			}
			printf("\n\n");
			break;
		case 7:
			printf("\n  Feel Nice!");
			break;
		default:
			printf("\n  UH!");
			break;
		}
	} while (option != 7);
	free(frac1);
	free(frac2);
	free(result);
	return;
}

void initMenu(Fraction** f1, Fraction** f2) {
	int num = 0;
	int denom = 0;
	int initOption;

	do {
		printf("\n************************************"
			"\n*   Menu : Creating/Updating        *"
			"\n*   1. Left Operand                 *"
			"\n*   2. Right Operand                *"
			"\n*   3. Both Operand                 *"
			"\n*   4. Displaying Current Operand   *"
			"\n*   5. Quit                         *"
			"\n************************************"
			"\nSelect an option (1 though 5): ");
		scanf_s("%d", &initOption);

		switch (initOption) {
		case 1:
				printf("\n       Updating the left operand -\n\n");
				createOneFrac(f1, num, denom);
			break;
		case 2:
				printf("\n       Updating the right operand -\n\n");
				createOneFrac(f2, num, denom);
			break;
		case 3:
				printf("\n       Updating the left operand -\n\n");
				createOneFrac(f1, num, denom);
				printf("\n       Updating the right operand -\n\n");
				createOneFrac(f2, num, denom);
			break;
		case 4:
			printf("\n       Left Operand:");
			if (*f1 == NULL) {
				printf("\n         Address/Location: NULL\n");
			} else {
				printf("\n         Address/Location: %p", &f1);
				printf("\n         Numerator: %d", (*f1)->num);
				printf("\n         Denominator: %d\n", (*f1)->denom);
			}
			printf("\n       Right Operand:");
			if (*f2 == NULL) {
				printf("\n         Address/Location: NULL\n");
			} else {
				printf("\n         Address/Location: %p", &f2);
				printf("\n         Numerator: %d", (*f2)->num);
				printf("\n         Denominator: %d\n", (*f2)->denom);
			}
			break;
		case 5:
			printf("\n  Returning to Main Menu...");
			break;
		default:
			printf("\n  WRONG OPTION!");
			break;
		}
	} while (initOption != 5);

	return;
}

void createOneFrac(Fraction** frac, int num, int denom) {
	printf("         Enter the numerator: ");
	scanf_s("%d", &num);
	printf("         Enter the denominator: ");
	scanf_s("%d", &denom);

	if (denom == 0) {
		printf("\n    Denom can't be zero! Enter another denominator: ");
		scanf_s("%d", &denom);
	}

	if (*frac == NULL) {
		*frac = init(num, denom);
	} else {
		(*frac)->num = num;
		(*frac)->denom = denom;
		simplify(frac);
	}
	return;
}

/**Comments
My large mistake was that my simplify was wrong.
*/

/**OUTPUT
Left Operand:
Address/Location: 0018FB20
Numerator: -3
Denominator: 7

Right Operand:
Address/Location: 0018FB24
Numerator: 5
Denominator: 12

************************************
*   Menu : Creating/Updating        *
*   1. Left Operand                 *
*   2. Right Operand                *
*   3. Both Operand                 *
*   4. Displaying Current Operand   *
*   5. Quit                         *
************************************
Select an option (1 though 5): 2

Updating the right operand -

Enter the numerator: 4
Enter the denominator: 9

************************************
*   Menu : Creating/Updating        *
*   1. Left Operand                 *
*   2. Right Operand                *
*   3. Both Operand                 *
*   4. Displaying Current Operand   *
*   5. Quit                         *
************************************
Select an option (1 though 5): 4

Left Operand:
Address/Location: 0018FB20
Numerator: -3
Denominator: 7

Right Operand:
Address/Location: 0018FB24
Numerator: 4
Denominator: 9

************************************
*   Menu : Creating/Updating        *
*   1. Left Operand                 *
*   2. Right Operand                *
*   3. Both Operand                 *
*   4. Displaying Current Operand   *
*   5. Quit                         *
************************************
Select an option (1 though 5): 5

Returning to Main Menu...
************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 6

Left Operand:
Address/Location: 0018FC14
Numerator: -3
Denominator: 7

Right Operand:
Address/Location: 0018FC08
Numerator: 4
Denominator: 9


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 2

Calling add() -


(-3/7 + 4/9 = 1/63)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 3

Calling subtract() -


(-3/7 - 4/9 = -55/63)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 4

Calling multiply() -


(-3/7 * 4/9 = -4/21)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 5

Calling divide() -


(-3/7 / 4/9 = -27/28)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 1

************************************
*   Menu : Creating/Updating        *
*   1. Left Operand                 *
*   2. Right Operand                *
*   3. Both Operand                 *
*   4. Displaying Current Operand   *
*   5. Quit                         *
************************************
Select an option (1 though 5): 3

Updating the left operand -

Enter the numerator: 2
Enter the denominator: 11

Updating the right operand -

Enter the numerator: 5
Enter the denominator: 101

************************************
*   Menu : Creating/Updating        *
*   1. Left Operand                 *
*   2. Right Operand                *
*   3. Both Operand                 *
*   4. Displaying Current Operand   *
*   5. Quit                         *
************************************
Select an option (1 though 5): 5

Returning to Main Menu...
************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 6

Left Operand:
Address/Location: 0018FC14
Numerator: 2
Denominator: 11

Right Operand:
Address/Location: 0018FC08
Numerator: 5
Denominator: 101


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 2

Calling add() -


(2/11 + 5/101 = 257/1111)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 3

Calling subtract() -


(2/11 - 5/101 = 147/1111)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 4

Calling multiply() -


(2/11 * 5/101 = 10/1111)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 5

Calling divide() -


(2/11 / 5/101 = 202/55)


************************************
*   Menu : Fraction Tonivi Truong   *
*   1. Creating/Updating            *
*   2. Adding                       *
*   3. Subtracting                  *
*   4. Multiplying                  *
*   5. Dividing                     *
*   6. Displaying                   *
*   7. Quit                         *
************************************
Select an option (1 though 7): 7

 FEELS NICE!
*/
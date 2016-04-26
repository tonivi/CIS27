/*
* Project Name : Cis27Spring2016ToniviTruongLab4Ex1.c
* Discussion :   Polynomials
* Written By :   Tonivi Truong
* Date :         2016/05/04
*/

#include <stdio.h>
#include <stdlib.h>	

struct FractionToniviT {
	int num;
	int denom;
};

struct PolyTermToniviT {
	int exp;
	struct FractionToniviT* coePtr;
};

struct PolyNodeToniviT {
	struct PolyTermToniviT* ptPtr;
	struct PolyNodeToniviT* next;
};

typedef struct FractionToniviT FractionTonivi;
typedef struct PolyTermToniviT PolyTermTonivi;
typedef struct PolyNodeToniviT PolyNodeTonivi;
typedef PolyNodeTonivi* PolyListTonivi;

//Function 
void classInfo(void);
void menu(void);
FractionTonivi* createFraction(void);
FractionTonivi* addFractionToniviT(FractionTonivi*, FractionTonivi*);
FractionTonivi* multiplyFractionToniviT(FractionTonivi*, FractionTonivi*);
int createExponent(void);
int isEmpty(PolyListTonivi);
int getLength(PolyListTonivi);
int getGCD(int, int);
void sortByDegree(PolyListTonivi);
void simplify(FractionTonivi*);
int insertPolyNode(PolyListTonivi*, PolyNodeTonivi*);
int removePolyNode(PolyListTonivi*, int);
void removeFirst(PolyListTonivi*);
void removeLast(PolyListTonivi*);
PolyNodeTonivi* createNodeToniviT(void);
PolyNodeTonivi* createNode2ToniviT(FractionTonivi* c, int e);
PolyTermTonivi* createTermToniviT(void);
PolyTermTonivi* createTerm2ToniviT(FractionTonivi* c, int e);
PolyListTonivi* addPoly(PolyListTonivi, PolyListTonivi);
PolyListTonivi* multiplyPoly(PolyListTonivi, PolyListTonivi);
void displayPoly(PolyListTonivi);
void displayAllPoly(PolyListTonivi, PolyListTonivi, PolyListTonivi);
void createPolyList(PolyListTonivi*);
void creationMenu(PolyListTonivi*, PolyListTonivi*);
void clearingMenu(PolyListTonivi*, PolyListTonivi*, PolyListTonivi*);
void freePolyList(PolyListTonivi*);
void freePolyNode(PolyNodeTonivi*);


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
		"  Assignment Number:  Lab 04,"
		"\n\t\t      Coding Assignment -- Excercise #1"
		"\n  Written by: \t      Tonivi Truong"
		"\n  Submitted Date:     2016/05/04\n");

	return;
}

void creationMenu(PolyListTonivi* poly1, PolyListTonivi* poly2) {
	int option;

	do {
		printf("\n\n  ********************************\n"
			"  * POLYNOMIALS CREATING MENU    *\n"
			"  * 1. Creating left polynomial  *\n"
			"  * 2. Creating right polynomial *\n"
			"  * 3. Back to main menu         *\n"
			"  ********************************\n"
			"   Select an option (1 through 3): ");
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			if (*poly1 != NULL) {
				freePolyList(poly1);
			}
			printf("\n\tCreating Polynomial 1\n");
			createPolyList(poly1);
			break;
		case 2:
			if (*poly2 != NULL) {
				freePolyList(poly2);
			}
			printf("\n\tCreating Polynomial 2\n");
			createPolyList(poly2);
			break;
		case 3:
			printf("\n\tReturn to Main Memu.\n");
			break;
		default:
			printf("\nYou should not be in this class!");
		}
	} while (option != 3);
}

void clearingMenu(PolyListTonivi* poly1, PolyListTonivi* poly2,
	PolyListTonivi* result) {
	int option;

	do {
		printf("\n  **********************************\n"
			"  *    CLEARING MENU                *\n"
			"  * 1. Clear Left Polynomial        *\n"
			"  * 2. CLear Right Polynomial       *\n"
			"  * 3. Clear ResultPolynomial       *\n"
			"  * 4. Return to previous menu      *\n"
			"  ***********************************\n"
			"  Select the option(1 through 4): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			if (*poly1 != NULL) {
				printf("\n    Releasing Left Polynomial -\n");
				freePolyList(poly1);
				printf("      Left Polynomial released.\n");
			} else {
				printf("\n    There are no Polynomials to release!\n");
			}
			break;
		case 2:
			if (*poly2 != NULL) {
				printf("\n    Releasing Right Polynomial -\n");
				freePolyList(poly2);
				printf("      Right Polynomial released\n");
			} else {
				printf("\n    There are no Polynomials to release!\n");
			}
			break;
		case 3:
			if (*result != NULL) {
				printf("\n    Releasing Resulting Polynomial -\n");
				freePolyList(result);
				printf("      Resulting Polynomial released.\n");
			} else {
				printf("\n    There are no Polynomials to release!\n");
			}
			break;
		case 4:
			printf("\n\tReturn to Main Menu.\n");
			break;
		default:
			printf("\n    You should not be in this class!\n");
		}
	} while (option != 4);

	return;
}

void menu() {
	int option;
	PolyListTonivi poly1 = NULL;
	PolyListTonivi poly2 = NULL;
	PolyListTonivi* result = (PolyListTonivi*)calloc(1, sizeof(PolyListTonivi));

	do {
		printf("\n*************************************"
			"\n*    POLYNOMIAL OPERATIONS          *"
			"\n*   1. Creating polynomials         *"
			"\n*   2. Adding polynomials           *"
			"\n*   3. Multiplying polynomials      *"
			"\n*   4. Displaying polynomials       *"
			"\n*   5. Clearing polynomials         *"
			"\n*   6. Quit                         *"
			"\n*************************************"
			"\nSelect an option (1, 2, 3, 4 ,5 or 6): ");
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			printf("\nCreate Menu \n");
			creationMenu(&poly1, &poly2);
			break;
		case 2:
			if (poly1 && poly2 != NULL) {
				if (result != NULL)
					freePolyList(result);
				printf("\n\tCalling addPoly()\n");
				result = addPoly(poly1, poly2);
			} else if (poly1 != NULL) {
				printf("\n\tRight Polynomial is Missing!");
			} else if (poly2 != NULL) {
				printf("\n\tLeft Polynomial is Missing!");
			} else {
				printf("\n\tBoth Polynomials are Missing!");
			}
			break;
		case 3:
			if (poly1 && poly2 != NULL) {
				if (result != NULL)
					freePolyList(result);
				printf("\n\tCalling MultiplyPoly()\n");
				result = multiplyPoly(poly1, poly2);
			} else if (poly1 != NULL) {
				printf("\n\tRight Polynomial is Missing!");
			} else if (poly2 != NULL) {
				printf("\n\tLeft Polynomial is Missing!");
			} else {
				printf("\n\tBoth Polynomials are Missing!");
			}
			break;
		case 4:
			printf("\nDisplaying all polynomials");
			displayAllPoly(poly1, poly2, *result);
			break;
		case 5:
			printf("\nClearing Menu \n");
			clearingMenu(&poly1, &poly2, result);
			break;
		case 6:
			printf("\nHaving Fun! \n");
			break;
		default:
			printf("\nYou should not be in this class!");
		}
	} while (option != 6);

	freePolyList(&poly1);
	freePolyList(&poly2);
	freePolyList(result);
}


/* COMMENTS
The lab was probably the hardest one I've dealt with.
Alot are put together in this one lab.
There are just so much to keep track of for me.
Even though I used calloc, do not like using it
Spent many hours online for help.
Took out:
//typedef FractionTonivi* FractionPtrTonivi;
//typedef PolyTermTonivi* PolyTermPtrTonivi;
//typedef PolyNodeTonivi* PolyNodePtrTonivi;
//typedef PolyListTonivi* PolyListPtrTonivi;
because I had too many errors about it. * felt easier

//int removePolyNode(PolyListPtrTonivi, int)
return 1 as succefully removing, 0 if not.
//PolyListTonivi result = NULL;
//Stuggled with add and multiply with 2 functions,
//so I had asked Nhat for help.
//	Showed Calloc, had help with node2 + term2 + add
//combineLikeTerm example explained in class
*/

/*

CIS 27 - C Programming
Laney College
Tonivi Truong

Assignment Information --
Assignment Number:  Lab 04,
Coding Assignment -- Excercise #1
Written by:         Tonivi Truong
Submitted Date:     2016/05/04

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 7

You should not be in this class!
*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 4

Displaying all polynomials
Left Polynomial Address: 00000000

Right Polynomial Address: 00000000

Resulting Polynomial Address: 00000000

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 1

Create Menu


********************************
* POLYNOMIALS CREATING MENU    *
* 1. Creating left polynomial  *
* 2. Creating right polynomial *
* 3. Back to main menu         *
********************************
Select an option (1 through 3): 1

Creating Polynomial 1

How many terms? 3

Enter the exponent: 2

Enter the numerator: 1
Enter the denominator: 1

Enter the exponent: 1

Enter the numerator: 3
Enter the denominator: 4

Enter the exponent: 0

Enter the numerator: 5
Enter the denominator: 12
1/1x^2 + 3/4x^1 + 5/12x^0


********************************
* POLYNOMIALS CREATING MENU    *
* 1. Creating left polynomial  *
* 2. Creating right polynomial *
* 3. Back to main menu         *
********************************
Select an option (1 through 3): 2

Creating Polynomial 2

How many terms? 4

Enter the exponent: 4

Enter the numerator: 1
Enter the denominator: 1

Enter the exponent: 2

Enter the numerator: -3
Enter the denominator: 7

Enter the exponent: 1

Enter the numerator: 4
Enter the denominator: 9

Enter the exponent: 0

Enter the numerator: 2
Enter the denominator: 11
1/1x^4 -3/7x^2 + 4/9x^1 + 2/11x^0


********************************
* POLYNOMIALS CREATING MENU    *
* 1. Creating left polynomial  *
* 2. Creating right polynomial *
* 3. Back to main menu         *
********************************
Select an option (1 through 3): 3

Return to Main Memu.

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 4

Displaying all polynomials
Left Polynomial Address: 00AFCF80
1/1x^2 + 3/4x^1 + 5/12x^0

Right Polynomial Address: 00B011E0
1/1x^4 -3/7x^2 + 4/9x^1 + 2/11x^0

Resulting Polynomial Address: 00000000

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 2

Calling addPoly()

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 4

Displaying all polynomials
Left Polynomial Address: 00AFCF80
1/1x^2 + 3/4x^1 + 5/12x^0

Right Polynomial Address: 00B011E0
1/1x^4 -3/7x^2 + 4/9x^1 + 2/11x^0

Resulting Polynomial Address: 00B03500
1/1x^4 + 4/7x^2 + 43/36x^1 + 79/132x^0

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 3

Calling MultiplyPoly()

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 4

Displaying all polynomials
Left Polynomial Address: 00AFCF80
1/1x^2 + 3/4x^1 + 5/12x^0

Right Polynomial Address: 00B011E0
1/1x^4 -3/7x^2 + 4/9x^1 + 2/11x^0

Resulting Polynomial Address: 00B03260
1/1x^6 + 3/4x^5 -1/84x^4 + 31/252x^3 + 311/924x^2 + 191/594x^1 + 5/66x^0

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 5

Clearing Menu

**********************************
*    CLEARING MENU                *
* 1. Clear Left Polynomial        *
* 2. CLear Right Polynomial       *
* 3. Clear ResultPolynomial       *
* 4. Return to previous menu      *
***********************************
Select the option(1 through 4): 1

Releasing Left Polynomial -
Left Polynomial released.

**********************************
*    CLEARING MENU                *
* 1. Clear Left Polynomial        *
* 2. CLear Right Polynomial       *
* 3. Clear ResultPolynomial       *
* 4. Return to previous menu      *
***********************************
Select the option(1 through 4): 2

Releasing Right Polynomial -
Right Polynomial released

**********************************
*    CLEARING MENU                *
* 1. Clear Left Polynomial        *
* 2. CLear Right Polynomial       *
* 3. Clear ResultPolynomial       *
* 4. Return to previous menu      *
***********************************
Select the option(1 through 4): 3

Releasing Resulting Polynomial -
Resulting Polynomial released.

**********************************
*    CLEARING MENU                *
* 1. Clear Left Polynomial        *
* 2. CLear Right Polynomial       *
* 3. Clear ResultPolynomial       *
* 4. Return to previous menu      *
***********************************
Select the option(1 through 4): 4

Return to Main Menu.

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 4

Displaying all polynomials
Left Polynomial Address: 00000000

Right Polynomial Address: 00000000

Resulting Polynomial Address: 00000000

*************************************
*    POLYNOMIAL OPERATIONS          *
*   1. Creating polynomials         *
*   2. Adding polynomials           *
*   3. Multiplying polynomials      *
*   4. Displaying polynomials       *
*   5. Clearing polynomials         *
*   6. Quit                         *
*************************************
Select an option (1, 2, 3, 4 ,5 or 6): 6

Having Fun!
Press any key to continue . . .
*/
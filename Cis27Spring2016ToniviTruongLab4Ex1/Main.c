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

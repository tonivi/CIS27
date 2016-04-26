/*
* Project Name : Cis27Spring2016ToniviTruongLab1Ex1.cpp
* Discussion :   Main
* Written By :   Tonivi Truong
* Date :         2016/11/02
*/

#include <stdio.h>
#include <stdlib.h>

void classInfo();
void menu(void);
int* extractUncommonDigitToniviT(int*, int);

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
		"  Assignment Number:  Lab 01,"
		"\n\t\t      Coding Assignment -- Excercise #1"
		"\n  Written by: \t      Tonivi Truong"
		"\n  Submitted Date:     2016/11/02\n");

	return;
}

void menu() {
	int i;
	int option;
	int size;
	int* integers = 0;
	int* finalAry = 0;

	do {
		printf("\n********************************************\n"
			"*       MENU                               *\n"
			"* 1. Calling extractUncommonDigitToniviT() *\n"
			"* 2. Quit                                  *\n"
			"********************************************\n"
			"Select an option (1 or 2): ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			printf("\n How many integers? ");
			scanf_s("%d", &size);
			integers = (int*)malloc(size * sizeof(int));

			for (i = 0; i < size; i++) {
				printf("    Enter integer #%d: ", i + 1);
				scanf_s("%d", &integers[i]);
			}

			printf("\n  The original array: \n");
			for (i = 0; i < size; i++) {
				printf("    %d\n", integers[i]);
			}

			printf("\n  Calling extractUncommonDigitToniviT() -\n");
			finalAry = extractUncommonDigitToniviT(integers, size);

			printf("\n  Displaying after returning the array"
				" -- The uncommon digits: ");

			if (finalAry != 0) {
				printf("\n    There is/are %d uncommon digit(s)", finalAry[0]);
				for (int i = 1; i < finalAry[0] + 1; i++) {
					printf("\n      %d", *(finalAry + i));
				}
			} else {
				printf("\n   There is/are no uncommon digit(s)");
			}
			break;
		case 2:
			printf("\n  Fun Excercise ...");
			free(integers);
			free(finalAry);
			break;
		default:
			printf("\n  WRONG OPTION!");
			break;
		}
	} while (option != 2);

	return;
}

int* extractUncommonDigitToniviT(int* ary, int size) {
	int temp;
	int i, j;
	int digitAry[10] = { 0 };
	int occur = 0;
	int* uncommon = 0;
	int** digit = (int**)malloc(size*sizeof(int*));

	for (i = 0; i < size; i++) {
		*(digit + i) = (int*)calloc(10, sizeof(int));
	}

	for (i = 0; i < size; i++) {
		temp = *(ary + i) < 0 ? -(*(ary + i)) : *(ary + i);

		do {
			*(*(digit + i) + temp % 10) = 1;
			temp /= 10;
		} while (temp != 0);
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < size; j++) {
			digitAry[i] += *(*(digit + j) + i);
		}
	}

	for (i = 0; i < 10; i++) {
		if (digitAry[i] == 1) {
			occur++;
		}
	}

	uncommon = (int*)malloc((occur+1)*sizeof(int));
	*uncommon = occur;

	if (occur != 0) {
		for (i = 0, j = 1; i < 10; i += 2) {
			if (digitAry[i] == 1) {
				uncommon[j] = i;
				j++;
			}
		}
		for (i = 1; i < 10; i += 2) {
			if (digitAry[i] == 1) {
				uncommon[j] = i;
				j++;
			}
		}
		return uncommon;
	} else {
		return 0;
	}
}

/** OUTPUT
CIS 27 - C Programming
Laney College
Tonivi Truong

Assignment Information --
Assignment Number:  Lab 01,
Coding Assignment -- Excercise #1
Written by:         Tonivi Truong
Submitted Date:     2016/11/02

********************************************
*       MENU                               *
* 1. Calling extractUncommonDigitToniviT() *
* 2. Quit                                  *
********************************************
Select an option (1 or 2): 1

How many integers? 3
Enter integer #1: 32965
Enter integer #2: -275721
Enter integer #3: 3028063

The original array:
32965
-275721
3028063

Calling extractUncommonDigitToniviT() -

Displaying after returning the array -- The uncommon digits:
There is/are 5 uncommon digit(s)
0
8
1
7
9
********************************************
*       MENU                               *
* 1. Calling extractUncommonDigitToniviT() *
* 2. Quit                                  *
********************************************
Select an option (1 or 2): 1

How many integers? 4
Enter integer #1: 32965
Enter integer #2: -275721
Enter integer #3: 3028063
Enter integer #4: 10789

The original array:
32965
-275721
3028063
10789

Calling extractUncommonDigitToniviT() -

Displaying after returning the array -- The uncommon digits:
There is/are no uncommon digit(s)
********************************************
*       MENU                               *
* 1. Calling extractUncommonDigitToniviT() *
* 2. Quit                                  *
********************************************
Select an option (1 or 2): 2

Fun Excersize ...
**/
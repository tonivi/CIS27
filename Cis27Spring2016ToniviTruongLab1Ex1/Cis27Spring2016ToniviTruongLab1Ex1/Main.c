/*
* Project Name : Cis27Spring2016ToniviTruongLab1Ex1.c
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
	printf("CIS 27 - C Programming\n"
		"Laney College\n"
		"\n"
		"\nAssignment Information --\n"
		"  Assignment Number:  Lab 01,"
		"\n\t\t      Coding Assignment -- Excercise #1"
		"\n  Written by: \t      Tonivi Truong"
		"\n  Submitted Date:     2016/11/02\n");

	return;
}

void menu() {
	int option;
	int size;
	int* integers = 0;
	int* finalAry = 0;
	int i;


	do {
		printf("\n\n"
			" MENU \n"
			" 1. Calling extractUncommonDigitToniviT()  \n"
			" 2. Quit                                   \n"
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

			if (finalAry != (int*)1) {
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
	int** digit = (int**)malloc(size * sizeof(int*));

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

	uncommon = (int*)malloc(occur * sizeof(int) + 1);
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
		return (int*)1;
	}
}
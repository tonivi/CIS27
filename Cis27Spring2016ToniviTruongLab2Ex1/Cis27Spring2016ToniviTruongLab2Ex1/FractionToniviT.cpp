/*
* Project Name : FractionToniviT.cpp
* Discussion :   FractionMenu
* Written By :   Tonivi Truong
* Date :         2016/25/02
*/

#include "FractionToniviT.h"

void menu() {
	int i;
	int option;
	int size;
	int* integers = 0;
	int* finalAry = 0;

	do {
		printf("\n*********************************"
			"\n*              MENU              *"
			"\n*   1. Initializing              *"
			"\n*   2. Adding                    *"
			"\n*   3. Subtracting               *"
			"\n*   4. Multiplying               *"
			"\n*   5. Dividing                  *"
			"\n*   6. Printing                  *"
			"\n*   7. Quit                      *"
			"\n*********************************";
		"Select an option (1 though 7): ");
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
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			printf("\n  Fun Excercise ...");
			free(integers);
			free(finalAry);
			break;
		default:
			printf("\n  WRONG OPTION!");
			break;
		}
	} while (option != 7);

	return;
}
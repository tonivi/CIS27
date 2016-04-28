/*
* Project Name : Cis27Spring2016ToniviTruongLab3Ex1.cpp
* Discussion :   Linked List & Nodes
* Written By :   Tonivi Truong
* Date :         2016/10/03
*/

#include <stdio.h>
#include <stdlib.h>
struct FractionToniviT {
	int num;
	int denom;
};

struct FractionNodeToniviT {
	struct FractionToniviT* data;
	struct FractionNodeToniviT* next;
};

typedef struct FractionToniviT FractionTonivi;
typedef struct FractionNodeToniviT FractionNodeTonivi;
typedef FractionNodeTonivi* FractionNodePtrTonivi;
typedef FractionNodeTonivi* FractionListTonivi;
typedef FractionNodeTonivi* FractionListPtrTonivi;
typedef FractionTonivi* FractionPtrTonivi;

FractionTonivi* createFraction(void);
FractionNodeTonivi* createNode(void);
void removeMenu(FractionNodeTonivi**);
void insertMenu(FractionNodeTonivi**);
void classInfo(void);
void menu(void);

int getGCD(int, int);
void simplify(FractionTonivi*);
int isEmpty(FractionNodeTonivi*);
void displayList(FractionNodeTonivi*);
void displayNode(FractionNodePtrTonivi);
int getLength(FractionNodeTonivi*);

void insertFirst(FractionNodeTonivi**, FractionNodeTonivi*);
void insertAt(FractionNodeTonivi**, FractionNodeTonivi*, int);
void insertLast(FractionNodeTonivi**, FractionNodeTonivi*);

void removeFirst(FractionNodeTonivi**);
void removeAt(FractionListTonivi*, int n);
void removeLast(FractionNodeTonivi**);

void freeNodeToniviT(FractionNodePtrTonivi);
void freeListToniviT(FractionNodePtrTonivi*);




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
		"  Assignment Number:  Lab 03,"
		"\n\t\t      Coding Assignment -- Excercise #1"
		"\n  Written by: \t      Tonivi Truong"
		"\n  Submitted Date:     2016/10/03\n");

	return;
}

void menu() {
	FractionNodeTonivi* list = NULL;
	int option;
	do {
		printf("\n*************************************"
			"\n*    Linked List Menu: Fraction     *"
			"\n*   1. Display Current List         *"
			"\n*   2. Inserting                    *"
			"\n*   3. Removing                     *"
			"\n*   4. Quit                         *"
			"\n*************************************"
			"\nSelect an option (1, 2, 3, or 4): ");
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			printf("\nDisplaying Current List: \n");
			displayList(list);
			break;
		case 2:
			insertMenu(&list);
			break;
		case 3:
			removeMenu(&list);
			break;
		case 4:
			printf("\nFractions and Linked Lists!");
			break;
		default:
			printf("\nYou should not be in this class!");
		}
	} while (option != 4);
	freeListToniviT(&list);
}

void insertMenu(FractionNodeTonivi** node) {
	int list;
	int insertOption;
	do {
		printf("\n*************************"
			"\n*    Inserting Menu     *"
			"\n*   1. As first node    *"
			"\n*   2. After n-th code  *"
			"\n*   3. As last node     *"
			"\n*   4. Displaying       *"
			"\n*   5. Quit             *"
			"\n*************************"
			"\nSelect an option (1, 2, 3, 4, or 5): ");
		scanf_s("%d", &insertOption);
		switch (insertOption) {
		case 1:
			printf("\n     Calling insertFirstToniviT() -\n");
			insertFirst(node, createNode());
			printf("\n     Node inserted at first position.\n");
			break;
		case 2:
			printf("\n     Calling insertAtToniviT() -\n");
			printf("\n     Enter the index to insert after: ");
			scanf_s("%d", &list);
			printf("\n     Inserting node after position %d", list);
			insertAt(node, createNode(), list + 1);
			printf("\n     Node inserted at position %d", list + 1);
			break;
		case 3:
			printf("\nInserting as last node ...\n");
			insertLast(node, createNode());
			printf("\nNode inserted at last position.");
			break;
		case 4:
			printf("\nDisplaying: \n");
			displayList(*node);
			break;
		case 5:
			printf("\nRetuning to main menu");
			break;
		default:
			printf("\nYou should not be in this class!");
			break;
		}
	} while (insertOption != 5);
}
void removeMenu(FractionNodeTonivi** node) {
	int removeOption;
	do {
		printf("\n*************************"
			"\n*    Removing Menu      *"
			"\n*   1. First node       *"
			"\n*   2. n-th code        *"
			"\n*   3. Last node        *"
			"\n*   4. Displaying       *"
			"\n*   5. Quit             *"
			"\n*************************"
			"\nSelect an option (1, 2, 3, 4, or 5): ");
		scanf_s("%d", &removeOption);
		switch (removeOption) {
		case 1:
			if (!isEmpty(*node)) {
				printf("\n  Calling removeFirstToniviT() -\n");
				removeFirst(node);
				printf("\n  Node removed at first position.\n  ");
			} else {
				printf("\n  Can't remove from an empty list!\n");
			}
			break;
		case 2:
			if (!isEmpty(*node)) {
				printf("\n  Calling removeAtToniviT() -\n");
				printf("\n  Enter the index to be removed: ");
				scanf_s("%d", &removeOption);
				removeAt(node, removeOption);
				printf("\n  Node removed at index %d.\n  ", removeOption);
			} else {
				printf("\n  Can't remove from an empty list!\n");
			}
			break;
		case 3:
			if (!isEmpty(*node)) {
				printf("\n  Calling removeLastToniviT() -\n");
				removeLast(node);
				printf("\n  Node removed at last position.\n  ");
			} else {
				printf("\n  Can't remove from an empty list!\n");
			}
			break;
		case 4:
			printf("\nDisplaying: \n");
			displayList(*node);
			break;
		case 5:
			printf("\nRetuning to main menu");
			break;
		default:
			printf("\nYou should not be in this class!");
			break;
		}
	} while (removeOption != 5);
}

void removeLast(FractionNodeTonivi** node) {
	FractionNodePtrTonivi curr = *node;
	FractionNodePtrTonivi prev = NULL;

	if ((*node)->next == 0) {
		free((*(node))->data);
		free(*node);
		*node = NULL;
	} else {
		while (curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		free(prev->next);
		prev->next = NULL;
	}

	return;
}

void insertAt(FractionNodeTonivi** head, FractionNodeTonivi* node, int n) {
	FractionNodeTonivi* current;
	int i;

	if (n <= 0) {
		insertFirst(head, node);
	} else if (n > getLength((*head))) {
		insertLast(head, node);
	} else {
		current = *head;
		for (i = 0; i < n - 1; i++) {
			current = current->next;
		}
		insertFirst(&(current->next), node);
	}
}

void insertLast(FractionListPtrTonivi* list, FractionNodePtrTonivi node) {
	FractionNodePtrTonivi tmpPtr = *list;

	if (tmpPtr == 0) {
		*list = node;
	} else {
		while (tmpPtr->next != 0) {
			tmpPtr = tmpPtr->next;
		}
		tmpPtr->next = node;
	}

	return;
}

void freeListToniviT(FractionListPtrTonivi* list) {
	FractionNodePtrTonivi tmpPtr;

	while ((*list) != NULL) {
		tmpPtr = *list;
		*list = (*list)->next;
		free(tmpPtr);
	}

	return;
}


void removeFirst(FractionNodeTonivi** list) {
	FractionNodePtrTonivi tmpPtr;

	if (*list != 0) {
		tmpPtr = *list;
		*list = (*list)->next;
		free(tmpPtr->data);
		free(tmpPtr);
	}

	return;
}

void freeFractionNode(FractionNodeTonivi* myNodeAddr) {
	free(myNodeAddr->data);
	free(myNodeAddr);
	return;
}

void insertFirst(FractionListPtrTonivi* list, FractionNodePtrTonivi node) {
	if (*list != NULL)
		node->next = *list;
	*list = node;

	return;
}

struct FractionToniviT* createFraction() {
	struct FractionToniviT* tmpPtr = NULL;
	int tmp;
	tmpPtr = (struct FractionToniviT*) malloc(sizeof(struct FractionToniviT));
	printf("\n  Enter the numerator: ");
	scanf_s("%d", &tmp);
	tmpPtr->num = tmp;

	printf("  Enter the denominator: ");
	scanf_s("%d", &tmp);
	tmpPtr->denom = tmp;

	while (tmp == 0) {
		printf("Can't set to zero! Enter a new denominator: ");
		scanf_s("%d", &tmp);
		tmpPtr->denom = tmp;
	}
	simplify(tmpPtr);
	return tmpPtr;
}

FractionNodeTonivi* createNode() {
	FractionNodeTonivi* node;

	node = (FractionNodeTonivi*)malloc(sizeof(FractionNodeTonivi));
	node->data = createFraction();
	node->next = NULL;

	return node;
}

int isEmpty(FractionNodeTonivi* list) {
	return (list) == NULL ? 1 : 0;
}

int getLength(FractionNodeTonivi* list) {
	int length = 0;
	while (list != NULL) {
		length++;
		list = (list)->next;
	}
	return length;
}

void displayList(FractionNodeTonivi* list) {
	if (!list) {
		printf("\nEMPTY LIST ... \n\n");
	} else {
		while ((list) != NULL) {
			printf(" %d/%d", list->data->num, list->data->denom);
			list = (list)->next;
		}
	}
}

void removeAt(FractionListTonivi* myListAddr, int n) {
	FractionNodePtrTonivi previous;
	FractionNodePtrTonivi current;
	int count;

	if (n >= getLength(*myListAddr)) {
		removeLast(myListAddr);
	} else if (n <= 1) {
		removeFirst(myListAddr);
	} else {
		previous = NULL;
		current = *myListAddr;
		count = 1;

		while (count < n) {
			count++;
			previous = current;
			current = current->next;
		}
		previous->next = current->next;
		freeFractionNode(current);
	}
}

int getGCD(int num, int denom) {
	return (denom != 0) ? getGCD(denom, num % denom) : num;
}

void simplify(FractionTonivi* fraction) {
	int gcd;

	if ((fraction)->denom < 0) {
		((fraction)->num) = -(fraction)->num;
		((fraction)->denom) = -(fraction)->denom;
	}

	if ((fraction)->num == 0) {
		(fraction)->denom = 1;
	} else {
		gcd = getGCD((fraction)->num, (fraction)->denom);
		(fraction)->num /= gcd;
		(fraction)->denom /= gcd;
	}
	return;
}

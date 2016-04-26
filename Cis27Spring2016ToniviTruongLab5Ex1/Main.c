/*
* Project Name : Cis27Spring2016ToniviTruongLab5Ex1.c
* Discussion :   Radix Sort
* Written By :   Tonivi Truong
* Date :         2016/26/04
*/

#include <stdio.h>
#include <stdlib.h>	

typedef struct Queue Queue;

struct Queue {
	int queueSize;
	int currentSize;
	int front;
	int rear;
	int* digitAry;
};

void menu(void);
void classInfo(void);
void enqueue(int, Queue*);
int isEmpty(Queue*);
int isFull(Queue*);
void empty(Queue*);
void print(Queue*);
void sort(int*, int);
void radixSortArray(int*, int);

void enqueue(int value, Queue* q) {
	if (isFull(q)) {
		printf("\nThe queue is FULL!\n");
	} else {
		if (q->rear == (q->queueSize - 1)) {
			q->rear = 0;
		} else {
			q->rear++;
		}
		q->currentSize++;
		q->digitAry[q->rear] = value;
	}

	return;
}

int isEmpty(Queue* q) {
	if (q->currentSize)
		return 0;
	else
		return 1;
}

int isFull(Queue* q) {
	if (q->currentSize == q->queueSize)
		return 1;
	else
		return 0;
}

void empty(Queue* q) {
	q->front = q->queueSize - 1;
	q->rear = q->queueSize - 1;
	q->currentSize = 0;

	return;
}

int main() {
	classInfo();
	menu();
	return 0;
}

void classInfo() {
	printf("\nCIS 27 - C Programming"
		"\nLaney College"
		"\nTonivi Truong"
		"\nAssignment Information --"
		"\n  Assignment Number:  Lab 05,"
		"\n\t\t      Coding Assignment -- Excercise #1"
		"\n  Written by: \t      Tonivi Truong"
		"\n  Submitted Date:     2016/26/04\n");

	return;
}

void print(Queue* q) {
	int i;

	for (i = 0; i < q->currentSize; i++) {
		printf("[%d]  ", q->digitAry[i]);
	}
	return;
}

void menu() {
	int option;
	int size;
	int value;
	int i;
	Queue* q = (Queue*)malloc(sizeof(Queue));

	do {
		printf("\n********************************\n"
			"*     Menu - Radix Sort        *\n"
			"* 1. Creating/Updating series  *\n"
			"* 2. Calling sortRadixTonivi   *\n"
			"* 3. Displaying Series         *\n"
			"* 4. Quit                      *\n"
			"********************************\n"
			" Select an option (1 through 4): ");
		scanf_s("%d", &option);
		switch (option) {
		case 1:
			printf("\n\tCreating/Updating series");
			printf("\n   Enter the size: ");
			scanf_s("%d", &size);
			while (size <= 0) {
				printf("   Enter the size: ");
				scanf_s("%d", &size);
			}
			q->queueSize = size;
			q->digitAry = (int*)malloc(sizeof(int)*q->queueSize);
			empty(q);
			printf("\n");
			for (i = 0; i < q->queueSize; i++) {
				printf("   Enter the valueue: ");
				scanf_s("%d", &value);
				enqueue(value, q);
			}
			break;
		case 2:
			if (q->queueSize > 0) {
				printf("\n  Series before sort:\n  ");
				print(q);
				printf("\nCalling sortRadixTonivi()");
				printf("\n  Series after sort:\n  ");
				radixSortArray(q->digitAry, q->queueSize);
				print(q);
				printf("\n");
			} else {
				printf("\n  Please create series!!\n");
			}
			break;
		case 3:
			printf("\nDisplaying series\n");
			if (q->queueSize > 0) {
				print(q);
				printf("\n");
			} else {
				printf("\n  No series to display!!\n");
			}
			break;
		case 4:
			printf("Good Job !");
			break;
		default:
			printf("\nWrong Option!");
		}
	} while (option != 4);
}

void sort(int* ary, int n) {
	int* tmp;
	int digits[10] = { 0 };
	int max = 0;
	int lsd = 1;
	int i;

	tmp = (int*)malloc(sizeof(int) * n);

	while (max / lsd > 0) {
		for (i = 0; i < n; i++) {
			if (ary[i] > max)
				max = ary[i];
		}
		for (i = 0; i < n; i++)
			digits[ary[i] / lsd % 10]++;
		for (i = 1; i < 10; i++)
			digits[i] += digits[i - 1];
		for (i = n - 1; i >= 0; i--)
			tmp[--digits[ary[i] / lsd % 10]] = ary[i];
		for (i = 0; i < n; i++)
			ary[i] = tmp[i];
		lsd *= 10;
	}
	free(tmp);
}

void radixSortArray(int* ary, int size) {
	int neg[10];
	int pos[10];
	int i, j = 0, k = 0, l = 0;

	for (i = 0; i < size; i++) {
		if (ary[i] < 0) {
			neg[j] = ary[i];
			neg[j] = -neg[j];
			j++;
		} else {
			pos[k] = ary[i];
			k++;
		}
	}

	sort(neg, j);
	sort(pos, k);

	l = j - 1;
	for (i = 0; i < j; i++) {
		ary[i] = neg[l];
		ary[i] = ary[i] - (neg[l] * 2);
		l -= 1;
	}
	l = 0;
	for (i = j; i < size; i++) {
		ary[i] = pos[l++];
	}
}

/*Comments
I looked online for sources and used the array
while trying to incorporate negatives
a different way than a reverse radix sort.
I believe I need to initialize a loop for the zero
elements as shown in output
*/

/*Output

CIS 27 - C Programming
Laney College
Tonivi Truong
Assignment Information --
Assignment Number:  Lab 05,
Coding Assignment -- Excercise #1
Written by:         Tonivi Truong
Submitted Date:     2016/26/04

********************************
*     Menu - Radix Sort        *
* 1. Creating/Updating series  *
* 2. Calling sortRadixTonivi   *
* 3. Displaying Series         *
* 4. Quit                      *
********************************
Select an option (1 through 4): 1

Creating/Updating series
Enter the size: 10

Enter the valueue: -11
Enter the valueue: -22
Enter the valueue: -66
Enter the valueue: -77
Enter the valueue: -99
Enter the valueue: 11
Enter the valueue: 22
Enter the valueue: 66
Enter the valueue: 99
Enter the valueue: 0

********************************
*     Menu - Radix Sort        *
* 1. Creating/Updating series  *
* 2. Calling sortRadixTonivi   *
* 3. Displaying Series         *
* 4. Quit                      *
********************************
Select an option (1 through 4): 2

Series before sort:
[-11]  [-22]  [-66]  [-77]  [-99]  [11]  [22]  [66]  [99]  [0]
Calling sortRadixTonivi()
Series after sort:
[-99]  [-77]  [-66]  [-22]  [-11]  [11]  [22]  [66]  [99]  [0]

********************************
*     Menu - Radix Sort        *
* 1. Creating/Updating series  *
* 2. Calling sortRadixTonivi   *
* 3. Displaying Series         *
* 4. Quit                      *
********************************
Select an option (1 through 4): 3

Displaying series
[-99]  [-77]  [-66]  [-22]  [-11]  [11]  [22]  [66]  [99]  [0]

********************************
*     Menu - Radix Sort        *
* 1. Creating/Updating series  *
* 2. Calling sortRadixTonivi   *
* 3. Displaying Series         *
* 4. Quit                      *
********************************
Select an option (1 through 4): 4
*/
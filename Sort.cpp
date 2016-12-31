//
// Created by Grady on 2017/1/1.
//

#include <cstdio>
#include "LinkListProblem.h"
#include "Sort.h"

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;

	return;
}


void PrintArray(int *a, int length) {
	for (int i = 0; i < length; ++i) {
		printf("%d, ", a[i]);
	}
	printf("\n");
}


void SortTest(sort_f sort_func) {
	int a[] = {6, 4, 1, 98, 654, 21, 0, 14, 98, 4, 64};
	printf("before sort: \n");
	PrintArray(a, LENGTH(a));
	sort_func(a, LENGTH(a));
	printf("After sort: \n");
	PrintArray(a, LENGTH(a));
}


/* repeat until no swap */
void BubbleSort(int *a, int length) {
	bool swapped;
	int n = length;
	do {
		swapped = false;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] > a[i]) {
				swap(&a[i - 1], &a[i]);
				swapped = true;
			}
		}
		n = n -1;  //每一个循环之后，最后一个元素一定是排好序的。
	} while (swapped);

}

/* 做了更好的优化 */
void BubbleSort2(int *a, int length) {
	int n = length;
	while (n > 0) {
		int newn = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] > a[i]) {
				swap(&a[i - 1], &a[i]);
				newn = i;
			}
		}
		n = newn;
	}
}



//void InsertionSort(int *a, int length) {
//	int j = 0;
//	for (int i = 1; i < length; ++i) {
//		for (j = i-1; j >= 0; --j) {
//			if (a[j] > a[i]) {
//				a[j+1] = a[j];
//			}
//		}
//		a[j+1] = a[i];
//	}
//}

//
// Created by Grady on 2017/1/1.
//

#ifndef JUSTP_SORT_H
#define JUSTP_SORT_H

typedef void sort_f(int[], int);

void BubbleSort(int a[], int length);
void PrintArray(int a[], int length);
void InsertionSort(int a[], int length);

void SortTest(sort_f sort_func);

#endif //JUSTP_SORT_H

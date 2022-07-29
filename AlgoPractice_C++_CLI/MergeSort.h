#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
using namespace std;

void merge(int* arr, int l, int mid, int r) {
    int s1 = mid - l + 1;
    int s2 = r - mid;

    int* a1 = new int[s1];
    int* a2 = new int[s2];

    for (int i = 0; i < s1; i++) {
        a1[i] = arr[l + i];
    }

    for (int i = 0; i < s2; i++) {
        a2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < s1 && j < s2) {
        if (a1[i] <= a2[j]) {
            arr[k] = a1[i];
            k++; i++;
        }
        else {
            arr[k] = a2[j];
            k++; j++;
        }
    }

    while (i < s1) {
        arr[k] = a1[i];
        k++; i++;
    }

    while (j < s2) {
        arr[k] = a2[j];
        k++; j++;
    }

    delete[]a1;
    delete[]a2;
}

void mergeSort(int* arr, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int mergeSort_main()
{
    int arr[] = { 7,2,8,3,5,3,7,9,2,1,11,22 };

    mergeSort(arr, 0, 11);

    for (int i = 0; i < 12; i++) {
        cout << arr[i] << " ";
    }

    return 1;
}

#endif
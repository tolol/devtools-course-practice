// Copyright 2014 Paul Eduard

#include "include/merge-sort.h"
#include <vector>
#include <climits>

const int INFINITY = INT_MAX;

static void Merge(int mas[], int left, int m, int right) {
    int n1 = m-left+1;
    int n2 = right-m;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; ++i) {
        L[i] = mas[left+i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = mas[m+i+1];
    }
    int k = left, i = 0, j = 0;
    while ((i < n1) && (j < n2)) {
        if (L[i] <= R[j]) {
            mas[k++] = L[i];
            i++;
        } else {
            mas[k++] = R[j];
            j++;
        }
    }
    while (i < n1) mas[k++] = L[i++];
    while (j < n2) mas[k++] = R[j++];
    delete []L;
    delete []R;
}

int Merge_Sort(int mas[], int l, int r) {
    if (mas == 0) return -1;
    if (l >= r) return 0;
    int middle = (l+r)/2;
    Merge_Sort(mas, l, middle);
    Merge_Sort(mas, middle+1, r);
    Merge(mas, l, middle, r);
    return 0;
}

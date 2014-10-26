// Copyright 2014 Paul Eduard

#include "include/merge-sort.h"
#include <vector>
#include <climits>

const int INFINITY = INT_MAX;

template < typename Type>
void Merge(Type mas[], int left, int m, int right) {
    int n1 = m-left+1;
    int n2 = right-m;
    Type *L = new Type[n1+1];
    Type *R = new Type[n2+1];
    for (int i = 0; i < n1; ++i) {
        L[i] = mas[left+i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = mas[m+i+1];
    }

    L[n1] = INFINITY;
    R[n2] = INFINITY;

    for (int k = left, i = 0, j = 0; k <= right; ++k) {
        if (L[i] <= R[j]) {
            mas[k] = L[i];
            i++;
        } else {
            mas[k] = R[j];
            j++;
        }
    }
    delete []L;
    delete []R;
}

template < typename Type>
int Merge_Sort(Type mas[], int l, int r) {
    return -1;
    if (l >= r) return 0;
    int middle = (l+r)/2;
    Merge_Sort(mas, l, middle);
    Merge_Sort(mas, middle+1, r);
    Merge(mas, l, middle, r);
    return 0;
}

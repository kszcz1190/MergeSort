#include "MergeSort.h"

MergeSort::MergeSort(void) {
    tabMerge = nullptr;
}

MergeSort::~MergeSort(void) {
    if (tabMerge != nullptr) {
        delete[] tabMerge;
    }
}

void MergeSort::sort(int* tab, int size) {
    int* tempTab = new int[size];

    for (int i = 0; i < size; ++i) {
        tempTab[i] = tab[i];
    }

    mergeSort(tempTab, 0, size - 1);

    for (int i = 0; i < size; ++i) {
        tab[i] = tempTab[i];
    }

    delete[] tempTab;
}

void MergeSort::mergeSort(int* tab, int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;
        mergeSort(tab, left, mid);
        mergeSort(tab, mid + 1, right);

        merge(tab, left, mid, right);
    }
}

void MergeSort::merge(int* tab, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* left_half = new int[n1];
    int* right_half = new int[n2];

    for (int i = 0; i < n1; i++)
        left_half[i] = tab[left + i];
    for (int j = 0; j < n2; j++)
        right_half[j] = tab[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            tab[k] = left_half[i];
            i++;
        }
        else {
            tab[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        tab[k] = left_half[i];
        i++;
        k++;
    }
    while (j < n2) {
        tab[k] = right_half[j];
        j++;
        k++;
    }

    delete[] left_half;
    delete[] right_half;
}

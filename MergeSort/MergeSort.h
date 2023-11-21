#ifndef MERGESORT_H
#define MERGESORT_H


class MergeSort {
private:
    void mergeSort(int* tab, int left, int right); // int* tab - wskaznik do tablicy
                                                    // left - indeks poczatku sortowanego fragmentu
                                                        // right - indeks konca sortowanego fragmentu
    void merge(int* tab, int left, int middle, int right); // scalanie dwoch posortowanych fragmentow tablicy
    //

    int* tabMerge;

public:
    MergeSort(void);
    ~MergeSort(void);

    void sort(int* tab, int size);
};

#endif // MERGESORT_H

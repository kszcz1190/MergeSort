#include <iostream>
#include "MergeSort.h"

using namespace std;

int main() {
    MergeSort mergeSort;
    const int size = 9;
    int tabMerge[size];

    for (int i = 0; i < size; i++) {
        int value;
        cout << "Podaj wartosc " << i + 1 << ": ";
        cin >> value;
        tabMerge[i] = value;
    }

    mergeSort.sort(tabMerge, size);

    cout << "Posortowane wartosci:";
    for (int i = 0; i < size; i++) {
        cout << " " << tabMerge[i];
    }
    cout << endl;

    return 0;
}

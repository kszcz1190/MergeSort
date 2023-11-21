#include "gtest/gtest.h"
#include "pch.h"
#include "MergeSort.h"

#include <cstdlib>
#include <ctime>

using namespace std;

TEST(MergeSortTest, AlreadySortedTest) {    // algorytm zachowuje tablicê niezmienion¹, gdy ona jest ju¿
											// posortowana rosn¹co,
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	MergeSort mergeSort;

	mergeSort.sort(arr, size);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(arr[i], i + 1);
	}

}


TEST(MergeSortTest, ReverseSortedTest)  //algorytm potrafi posortowaæ tablicê, która jest posortowana w
										//odwrotnej kolejnoœci,
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int size = sizeof(arr) / sizeof(arr[0]); to jest jeden ze sposobów na uzyskanie wielkoœci tablicy
	MergeSort mergeSort;

	mergeSort.sort(arr, 9);

	for (int i = 0; i < 9; i++) {
		EXPECT_LE(arr[i - 1], arr[i]); //LE - less or equal
	}
}

TEST(MergeSortTest, RandomArrayTest)  //algorytm sortowania liczb losowych
{
	const int size = 10;
	int arr[size];

	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand();
	}

	MergeSort mergeSort;

	mergeSort.sort(arr, size);

	for (int i = 1; i < size; i++)
	{
		EXPECT_LE(arr[i - 1], arr[i]);
	}

}


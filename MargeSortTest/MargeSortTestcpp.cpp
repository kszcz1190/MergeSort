#include "gtest/gtest.h"
#include "pch.h"
#include "MergeSort.h"

#include <cstdlib>
#include <ctime>

using namespace std;

TEST(MergeSortTest, AlreadySortedTest) {    // algorytm zachowuje tablic� niezmienion�, gdy ona jest ju�
											// posortowana rosn�co,
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);

	MergeSort mergeSort;

	mergeSort.sort(arr, size);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(arr[i], i + 1);
	}

}


TEST(MergeSortTest, ReverseSortedTest)  //algorytm potrafi posortowa� tablic�, kt�ra jest posortowana w
										//odwrotnej kolejno�ci,
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	//int size = sizeof(arr) / sizeof(arr[0]); to jest jeden ze sposob�w na uzyskanie wielko�ci tablicy
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


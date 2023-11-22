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

TEST(MergeSortTest, NegativeNumbersTest) //algorytm sortuje tablice tylko z liczbami ujemnymi, 
{
	int arr[] = { -12, -3, -6, -7, -1, -34, -87, -19, -22 };
	
	MergeSort mergeSort;

	mergeSort.sort(arr, 9);

	for (int i = 0; i < 9; i++) {
		EXPECT_LE(arr[i - 1], arr[i]); //LE - less or equal
	}
}

TEST(MergeSortTest, NegativeAndPositiveNumbersTest) //algorytm sortuje tablice z liczbami ujemnymi i dodatnimi 
{
	int arr[] = { 12, -3, 6, -7, -1, 34, -87, -19, 22 };

	MergeSort mergeSort;

	mergeSort.sort(arr, 9);

	for (int i = 0; i < 9; i++) {
		EXPECT_LE(arr[i - 1], arr[i]); //LE - less or equal
	}
}

TEST(MergeSortTest, EmptyArrayTest) //algorytm sortuje pust¹ tablicê 
{
	const int size = 0;
	int* arr = nullptr; //deklaruje wskaŸnik do typu int i inicjalizuje go wartoœci¹ nullptr (pustym wskaŸnikiem).

	MergeSort mergeSort;

	mergeSort.sort(arr, size);

	delete [] arr;
}

TEST(MergeSortTest, OneElementArrayTest) // sprawdzenie czy algorytm nie zmienia tablicy która zawiera jeden element
{
	const int size = 1;
	int arr[size] = {21};

	int copyOriginalArray[size];

	for (int i = 0; i < size; ++i) {
		copyOriginalArray[i] = arr[i];
	}

	MergeSort mergeSort;

	mergeSort.sort(arr, size);

	for (int i = 0; i < size; i++) {
		EXPECT_EQ(copyOriginalArray[i], arr[i]);
	}
}

TEST(MergeSortTest, DuplicateNumbersTest) // algorytm sortuje tablice z duplikatami
{
	const int size = 5;
	int arr[size] = { 3,3,2,1,2 };

	MergeSort mergeSort;
	mergeSort.sort(arr, size);

	for (int i = 1; i < size; i++) {
		EXPECT_LE(arr[i - 1], arr[i]);
	}
}

TEST(MergeSortTest, NegativeDuplicateNymbers) // algorytm sortuje tablicê ujemn¹ z duplikatami

{
	const int size = 7;
	int arr[size] = { -6,-2,-1,-2,-2,-1,-3};

	MergeSort mergeSort;
	mergeSort.sort(arr, size);

	for (int i = 1; i < size; i++) {
		EXPECT_LE(arr[i - 1], arr[i]);
	}
}

TEST(MergeSortTest, NegativePositiveDuplicateNumbers) //  sortuje tablice z liczbami ujemnymi, dodatnimi
													  //oraz duplikatami
{
	const int size = 10;
	int arr[size] = { 10,-9,8,-7,6,-5,4,-7,10,9};

	MergeSort mergeSort;
	mergeSort.sort(arr, size);

	for (int i = 1; i < size; i++) {
		EXPECT_LE(arr[i - 1], arr[i]);
	}
}

TEST(MergeSortTest, TwoElementAscending) //  sortuje tablice z dwoma elementami rosn¹cymi 

{
	const int size = 2;
	int arr[size] = { 9,10};

	MergeSort mergeSort;
	mergeSort.sort(arr, size);

	for (int i = 1; i < size; i++) {
		EXPECT_LE(arr[i - 1], arr[i]);
	}
}

TEST(MergeSortTest, OverHundredElements) // sortowanie ponad 100 elementów
{
	const int size = 120;
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

TEST(MergeSortTest, OverHundredDuplicateNegativePositiveElements) //ponad 100 elementów które mog¹ byæ duplikatami, ujemne oraz dodatnie
{
	int arr[] = {- 3, 7, -15, 8, 21, -9, 14, -3, 6, 28, -15, 42, -9, 8, 6, -21, 13, 19, -42, 7, -28,
					35, 14, -6, 9, -13, 3, -19, 42, 28, -35, 15, -8, 9, 21, -14, -6, 3, -21, -8, 19, 42,
					-28, -7, 15, -42, 35, -13, 6, -9, 8, 14, -3, -35, 21, -19, 28, 7, 13, -15, -6, 9, 3,
					-42, 8, -9, 15, 35, -28, 14, -13, 42, -21, -19, 6, -8, 21, 7, 28, -15, 3, -35, -42, 9,
					-14, 19, 8, -13, 6, -15, -3, 35, 21, -42, 14, -9, -28, 7, 15, -19, 3, 9, -6, 42, -8,
					-21, 13, 28, 35, -14, -15, 6, -9, -42, 8, 19, -3, 7, 21, 15, -28, 13, -35, 42, -6, 9,
					-19, 8, 14, -13, 3, 35, -21, -42, 6, -9, 28, 15, -8, 19, -3, -14, 42, -7, 13, -35, 21,
					9, 14, -6, -19, 3, -28, -42, 8, 35, -15, 21, -9, -13, 7, 6, -8, 28, 42, -3, -14, 15,
					-19, 9, -21, 35, -42};

	int size = sizeof(arr) / sizeof(arr[0]);

	MergeSort mergeSort;

	mergeSort.sort(arr, size);
	for (int i = 1; i < size; i++)
	{
		EXPECT_LE(arr[i - 1], arr[i]);
	}

}






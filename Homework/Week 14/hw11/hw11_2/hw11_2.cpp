/*
 * Title: hw9_2.cpp
 * Abstract: A program that displays the performance of three different
 * sorting algorithms (= heap sort, merge sort, and quick sort) on the screen.
 * Author: Ethan Herndon
 * ID: 4669
 * Date: 12/2/2020
 */

 //References:
 //1. Quick Sort: https://www.geeksforgeeks.org/quick-sort/?ref=lbp
 //2. Heap Sort: https://www.geeksforgeeks.org/heap-sort/?ref=lbp
 //3. Merge Sort: https://www.geeksforgeeks.org/merge-sort/
 //4. Chrono http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/  && https://www.geeksforgeeks.org/chrono-in-c/
 //5. This program has been modified from my older SRJC program https://github.com/HerndonE/CST-370-Algorithms/blob/master/Notes/Demos/algorithmsEx.cpp


#include <iostream>
#include <cstdlib>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;


int SIZE;

void cpy( int from[], int to[], int numItems);
int partition(int a[], int left, int right);
void quicksort(int list[], int start, int end);
void merge(int list[], int start, int end);
void mergesort(int list[], int start, int end);
void heapsort(int list[], int numItems);
void convertToHeap(int list[], int numItems);
int parent(int k);
int leftChild(int k);
int rightChild(int k);
bool isleaf(int k, int numItems);
void reheapifyDown(int list[], int numItems);
float printQuickSort(int list[], int start, int end);
float printHeapSort(int list[], int start, int end);
float printMergeSort(int list[], int start, int end);

void random(int *arr, int n){
    for(int i = 0; i < n; i++){
        int rnd = rand() % n;
        arr[i] = rnd;
    }
}

int main()
{
    cout << "Enter input size: ";
    cin >> SIZE;
    cout << endl;

	int * mainlist = new int [SIZE];
	random(mainlist, SIZE);

	cout << "===================== Execution Time ====================" << endl;

	int * heapArr = new int[SIZE];
    cpy(mainlist, heapArr, SIZE);
    double heapSortEx = printHeapSort(heapArr, 0, SIZE - 1);
    delete [] heapArr;
    cout << fixed <<  heapSortEx << setprecision(6) << " milliseconds" << endl;

    int * mergeArr = new int[SIZE];
    cpy(mainlist, mergeArr, SIZE);
    double mergeSortEx = printMergeSort(mergeArr, 0, SIZE - 1);
    delete [] mergeArr;
    cout << fixed << mergeSortEx <<  setprecision(6) << " milliseconds" <<  endl;

    int * quickArr = new int[SIZE];
    cpy(mainlist, quickArr, SIZE);
    double quickSortEx = printQuickSort(quickArr, 0, SIZE - 1);
    delete [] quickArr;
    cout << fixed << quickSortEx <<  setprecision(6) << " milliseconds" << endl;

    cout << "=========================================================" << endl;
}

void cpy(int from[], int to[], int numItems){
	for (int count = 0; count < numItems; count++){
		to[count] = from[count];
	}
}

/*****************************************************************

			HEAP SORT

*****************************************************************/

void heapsort(int list[], int numItems)
{


	int numUnsorted = numItems;

	convertToHeap(list, numItems);
	while (numUnsorted > 1){
		numUnsorted--;
		std::swap(list[0], list[numUnsorted]);
		reheapifyDown(list, numUnsorted);
	}
}

void convertToHeap(int list[], int numItems)
{
	for (int i = 1; i < numItems; i++){
		int k = i;
		while (k != 0 && list[k] > list[parent(k)]){
			std::swap(list[k], list[parent(k)]);
			k = parent(k);
		}
	}
}

int parent(int k)
{
	return (k - 1) / 2;
}

int leftChild(int k)
{
	return 2 * k + 1;
}

int rightChild(int k)
{
	return 2 * k + 2;
}


bool isleaf(int k, int numItems)
{
	return leftChild(k) >= numItems;
}

void reheapifyDown(int list[], int numItems)
{
	int current = 0;
	int bigChildIndex;
	bool heapOK = false;


	while (!heapOK && !isleaf(current, numItems)){
		bigChildIndex = leftChild(current);
		if (rightChild(current) < numItems && list[rightChild(current)] > list[bigChildIndex]){
			bigChildIndex = rightChild(current);
		}

		if (list[current] < list[bigChildIndex]){
			std::swap(list[current], list[bigChildIndex]);
			current = bigChildIndex;
		} else {
			heapOK = true;
		}
	}
}

/*****************************************************************

			MERGE SORT

*****************************************************************/

void merge(int arr[], int l, int m, int r){
    int left = m - l + 1;
    int right = r - m;

    int * n1 = new int[left];
    int * n2 = new int[right];

    for(int i = 0; i < left; i++) n1[i] = arr[l + i];
    for(int j = 0; j < right; j++) n2[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while(i < left && j < right){
        if(n1[i] <= n2[j]){
            arr[k] = n1[i]; i++;
        } else {
            arr[k] = n2[j]; j++;
        }
        k++;
    }

    while(i < left){
        arr[k] = n1[i]; i++; k++;
    }
    while(j < right){
        arr[k] = n2[j]; j++; k++;
    }
}

void mergesort(int list[], int start, int end){
    if(start >= end) return;
    int m = ( start + end - 1) / 2;
    mergesort(list, start, m);
    mergesort(list, m + 1, end);
    merge(list, start, m, end);
}


/*****************************************************************

			QUICKSORT

*****************************************************************/


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

float printQuickSort(int list[], int left, int right){
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cout << "Quick sort: ";
	quicksort(list, 0, SIZE - 1);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start).count()) * 1e-3;
}

float printHeapSort(int list[], int left, int right){
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cout << "Heap sort: ";
	heapsort(list, SIZE);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start).count()) * 1e-3;
}


float printMergeSort(int list[], int left, int right){
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cout << "Merge sort: ";
	mergesort(list, 0, SIZE - 1);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start).count()) * 1e-3;
}

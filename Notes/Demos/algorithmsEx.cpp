#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



const int SIZE = 10;

void print(clock_t elapsed, const int list[], int numItems);
void cpy(const int from[], int to[], int numItems);
void fill(int list[], int numItems);
bool alreadyexists(int list[], int count, int x);
int partition(int a[], int left, int right);
void quicksort(int list[], int start, int end);
void bubblesort(int list[], int numItems);
void bubblesort2(int list[], int numItems);
void selectionsort(int list[], int numItems);
void insertionsort(int list[], int numItems);
void merge(int list[], int start, int end);
void mergesort(int list[], int start, int end);
void heapsort(int list[], int numItems);
void convertToHeap(int list[], int numItems);
int parent(int k);
int leftChild(int k);
int rightChild(int k);
bool isleaf(int k, int numItems);
void reheapifyDown(int list[], int numItems);


int main()
{
	srand(time(0));
	int mainlist[SIZE];
	int list[SIZE];
	fill(mainlist, SIZE);
	clock_t start, stop;

	std::cout << "done filling" << std::endl;
/*
	copy(mainlist, list, SIZE);
	std::cout << "bubble   : ";
	start = clock();
	bubblesort(list, SIZE);
	stop = clock();
	print(stop - start, list, SIZE);


	copy(mainlist, list, SIZE);
	std::cout << "bubble 2 : ";
	start = clock();
	bubblesort2(list, SIZE);
	stop = clock();
	print(stop - start, list, SIZE);

	copy(mainlist, list, SIZE);
	start = clock();
	std::cout << "selection: ";
	selectionsort(list, SIZE);
	stop = clock();
	print(stop - start, list, SIZE);

	copy(mainlist, list, SIZE);
	start = clock();
	std::cout << "insertion: ";
	insertionsort(list, SIZE);
	stop = clock();
	print(stop - start, list, SIZE);

	copy(mainlist, list, SIZE);
	start = clock();
	std::cout << "merge    : ";
	mergesort(list, 0, SIZE-1);
	stop = clock();
	print(stop - start, list, SIZE);

	copy(mainlist, list, SIZE);
	std::cout << "heap     : ";
	start = clock();
	heapsort(list, SIZE);
	stop = clock();
	print(stop - start, list, SIZE);
*/
	cpy(mainlist, list, SIZE);
	print(stop - start, list, SIZE);
	cout << "quicksort: ";
	start = clock();
	quicksort(list, 0, SIZE - 1);
	stop = clock();
	print(stop - start, list, SIZE);

}



void fill(int list[], int numItems){
        int x;
       	for (int count = 0; count < numItems; count++){
	    do {
	       x = rand() % 100;
	    } while (alreadyexists(list, count, x));
            list[count] = x;
	}
}


bool alreadyexists(int list[], int count, int x){
  for (int i = 0; i < count; i++){
    if (list[i] == x) {
      return true;
    }
  }
  return false;
}


void print(clock_t elapsed, const int list[], int numItems){
  	for (int count = 0; count < numItems; count++) {
  	std::cout << list[count] << " ";
  }
  std::cout << std::endl;
//	std::cout << "time elapsed: " << elapsed/CLOCKS_PER_SEC << std::endl;
//	std::cout << "time elapsed: " << elapsed << std::endl;
}



void cpy(const int from[], int to[], int numItems){
	for (int count = 0; count < numItems; count++){
		to[count] = from[count];
	}
}







/*****************************************************************

			BUBBLE SORT 1

*****************************************************************/


void bubblesort(int list[], int numItems) {
	int i, j;

	for (i = 0; i < (numItems - 1); i++) {
		for (j = numItems - 1; j > i; j--) {
			if (list[j] < list[j - 1]) {
				std::swap(list[j], list[j - 1]);
			}
		}
	}
}








/*****************************************************************

			BUBBLE SORT 2

*****************************************************************/




void bubblesort2(int list[], int numItems) {
	int i, j;
	bool didswap = true;

	i = 0;
	while (i < numItems -1 && didswap){
		didswap = false;
		for (j = numItems - 1; j > i; j--) {
			if (list[j] < list[j - 1]) {
				std::swap(list[j], list[j - 1]);
				didswap = true;
			}
		}

		i++;
	}
}






/*****************************************************************

			SELECTION SORT

*****************************************************************/


void selectionsort(int list[], int numItems) {
	int i, j, index;
	int largest;

	if (numItems != 0) {
		for (i = numItems - 1; i > 0; i--) {
			largest = list[0];
			index = 0;
			for (j = 1; j <= i; j++) {
				if (list[j] > largest) {
					largest = list[j];
					index = j;
				}
			}
			std::swap(list[i], list[index]);
		}
	}
}





/*****************************************************************

			INSERTION SORT

*****************************************************************/



void insertionsort(int list[], int numItems) {

	int j;

	for (int i = 1; i < numItems; i++) {
		j = i;
		while (list[j] < list[j-1] && j > 0) {
			std::swap(list[j], list[j - 1]);
			j--;
		}
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



void mergesort(int list[], int start, int end)
{
	if (start < end){
		mergesort(list, start, (start+end)/2);
		mergesort(list, (start+end)/2 + 1, end);
		merge(list, start, end);
	}
}



void merge(int list[], int start, int end)
{
	// int* temp = new int[end + 1];
	int temp[SIZE];
	int mid = (start + end) / 2;

	int count = start;
	int left = start;
	int right = mid + 1;
	while ((left <= mid) && right <= end){
		if (list[left] <= list[right]){
			temp[count] = list[left];
			left++;
		} else {
			temp[count] = list[right];
			right++;
		}
		count++;
	}
	while (left <= mid){
		temp[count] = list[left];
		count++;
		left++;
	}
	while (right <= end){
		temp[count] = list[right];
		count++;
		right++;
	}
	for (count = start; count <= end; count++){
		list[count] = temp[count];
	}
	// delete [] temp;
}






/*****************************************************************

			QUICKSORT

*****************************************************************/

/*
void quicksort(int list[], int left, int right)
{
	cout << "left = " << left << ", right = " << right << endl;
  if (left < right) {
      int pivot = partition(list, left, right);
      quicksort(list, left, pivot-1);
      quicksort(list, pivot+1, right);
  }
}



int partition(int list[], int left, int right)
{
  int pivot = list[left];
  while (true)
    {
      while (list[left] < pivot) {
	left++;
      }

      while (list[right] > pivot) {
	right--;
      }

      if (left < right)	{
	  std::swap(list[left], list[right]);
	  cout << "swapping" << list[left] << " and " << list[right] << endl;

      } else {
	  return right;
      }
    }
}





*/

void quicksort(int list[], int left, int right){

	cout << "left = " << left << ", right = " << right << endl;
	print(0, list, SIZE);
	int pivot;
	if (left < right) {
		int storeleft = left;
		int storeright = right;
		pivot = list[(left + right) / 2];
		while (left < right) {
			while (left < right && list[left] < pivot) {
				left++;
			}

			while (right > left && list[right] > pivot) {
				right--;
			}

			if (left < right) {
				std::swap(list[left], list[right]);
				cout << "swapping" << list[left] << " and " << list[right] << endl;
			}
		}
		quicksort(list, storeleft, right);
		quicksort(list, right+1, storeright);
	}
}


/*

void quicksort(int arr[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      // partition
      print(0, arr, SIZE);
      	cout << "left = " << left << ", right = " << right << endl;

      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
				cout << "swapping" << arr[i] << " and " << arr[j] << endl;

                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };

      // recursion
      if (left < j)
            quicksort(arr, left, j);
      if (i < right)
            quicksort(arr, i, right);
}


	*/

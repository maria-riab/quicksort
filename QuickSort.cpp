// QuickSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
void quicksort(int* array, int low, int high);
int partition(int low, int high, int* array);
void swap(int* first_val, int* second_val);

int main()
{
	int array[10] = { 45,10,23,64,68,77,31,22,97,3 };

	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	quicksort(array, 0, 10);
	for (int i = 0; i < 10; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

// high is the end character, aka the size of array, since max element is n - 1
void quicksort(int* array, int low, int high)
{
	if (low < high) {
		int j = partition(low, high,array);
		quicksort(array, low, j);
		quicksort(array, j+1, high);
	}

}

int partition(int low, int high, int* array) {
	int pivot = array[low];

	int i = low;
	int j = high;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] <= pivot);
		do 
		{
			j--;
		} while (array[j] > pivot);
	
		if (i < j) swap(array[i], array[j]);
	}
	swap(array[low], array[j]);
	return j; // partitioning position (new pivot);
}
void swap(int* first_val, int* second_val) {
	int temp = *first_val;
	*first_val = *second_val;
	*second_val = temp;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


#include <iostream>
#include <cassert>

using namespace std;


int BubbleSort(int Array[], size_t Size) {

	bool Swapped;

	do {

		Swapped = false;

		for (int i = 0; i < Size - 1; i++) {			// This function sets a bool variable to false, and goes through side-by-side pairs of every element in the
														// array. It swaps the second of each pair if it detects the first is greater than it, and sets the bool to
			if (Array[i] > Array[i + 1]) {				// true. Because the bool is only changed if the pair argument is true, it gets "stuck" in a true state until
														// the end of the loop where the while can see that at least once in the current loop a swap occured. It will
				swap(Array[i], Array[i + 1]);			// only exit out of the loop if a full sweep of the elements is performed without a single swap.
				Swapped = true;

			}

			cout << Array[i] << ", ";					// I wanted to make sure the array was truly being sorted correctly and that i didn't mess up the
														// assert() somehow, so i set it up to print the elements of the array as it sorts through them.
		}

		cout << endl;

	} while (Swapped == true);

	return Array[Size];
}

void AssertArray(int Array[], int Order[], size_t Size) {

	for (int i = 0; i < Size; i++) {
														// It seems you can't directly compare arrays to eachother in asserts so i made a
		assert(Array[i] == Order[i]);					// small function to iterate through each element to compare them all instead.

	}

}


int main()
{

	int IntArray[20]{ 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };
	int CorrectOrder[20]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 53, 61, 67, 71, 83, 89, 97 };
	size_t ArraySize = sizeof(IntArray) / sizeof(IntArray[0]);

	BubbleSort(IntArray, ArraySize);

	AssertArray(IntArray, CorrectOrder, ArraySize);

}

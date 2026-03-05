
#include <iostream>
#include <cassert>

using namespace std;


void BubbleSort(int Array[], size_t Size) {

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
		
		}

	} while (Swapped == true);

}

void AssertArray(int Array[], int Order[], size_t Size) {

	for (int i = 0; i < Size; i++) {
														// It seems you can't directly compare arrays to eachother in asserts so i made a
		assert(Array[i] == Order[i]);					// small function to iterate through each element to compare them all instead.
		
	}

}

int BinarySearch(int Array[], int Target, int Length) {

	int Start = 0;

	while (Length != 0) {

		if (Array[Start + Length / 2] == Target) {				// This function repeatedly finds the middle value in a sorted array, then checks if it is equal the
			return Start + Length / 2;							// target, and if it is not it checks whether it's smaller or larger than it and adjusts where it next
		}														// starts the search and how many elements remain after that new point. Eventually the loop will either
		if (Array[Start + Length / 2] > Target) {				// land on the index containing the target, or divide the length down to 0 (really 0.5 rounded down),
			Length /= 2;										// which indicates to it that it mustn't exist and the while loop ends and leads to return -1.
		}
		else if (Array[Start + Length / 2] < Target) {
			Start += Length / 2 + 1;
			Length -= Length / 2 + 1;
		}

	} 

	return -1;
}


int main()
{

	int IntArray[20]{ 67, 13, 3, 89, 43, 2, 19, 71, 5, 61, 97, 7, 37, 31, 17, 11, 83, 53, 23, 29 };
	int CorrectOrder[20]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 43, 53, 61, 67, 71, 83, 89, 97 };
	size_t ArraySize = sizeof(IntArray) / sizeof(IntArray[0]);

	BubbleSort(IntArray, ArraySize);

	AssertArray(IntArray, CorrectOrder, ArraySize);

	assert(BinarySearch(IntArray, 11, ArraySize) == 4);
	assert(BinarySearch(IntArray, 23, ArraySize) == 8);
	assert(BinarySearch(IntArray, 97, ArraySize) == 19);
	assert(BinarySearch(IntArray, 88, ArraySize) == -1);

}

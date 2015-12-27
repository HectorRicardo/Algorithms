#include <iostream>
using namespace std;

/** begin is the index of the first element of the first half of the array,
 * medium is the index of the last element of the first half of the array,
 * end is the index of the last element of the second half of the array */
 
void merge(int array[], int begin, int med, int end) {
	
	int length_left = med - begin + 1;
	int temp_left[length_left];
	
	int length_right = end - med;
	int temp_right[length_right];
	
	// this is to make the filling of the temp arrays more efficient
	// in just one pass, we fill both arrays
	for (int i = 0; i < length_right; ++i) {
		temp_left[i] = array[begin + i]; // begin is the first element of the first half of array we're considering
		temp_right[i] = array[(med + 1) + i]; // med + 1 is the first element of the second half
	}
	
	// maybe we missed the last element of the first half (if the length of the array is odd).
	temp_left[length_left - 1] = array[med];
	
	int left_i = 0; // index of temp_left
	int right_i = 0; // index of temp_right
	int i = begin; // index of array
	
	while (left_i < length_left && right_i < length_right) {
		if (temp_left[left_i] < temp_right[right_i]) {
			array[i] = temp_left[left_i];
			++left_i;
		} else {
			array[i] = temp_right[right_i];
			++right_i;
		}
		++i;
	}
	
	while (left_i < length_left) {
		array[i] = temp_left[left_i];
		++left_i;
		++i;
	}
	
	while (right_i < length_right) {
		array[i] = temp_right[right_i];
		++right_i;
		++i;
	}
}

void mergesort(int array[], int begin, int end) {
	if (end > begin) { // if array contains at least one element
		// all indexes are inclusive
		int med = begin + (end - begin) / 2;
		mergesort(array, begin, med);
		mergesort(array, med + 1, end);
		merge(array, begin, med, end);
	}
}

void mergesort(int array[], int length) {
	mergesort(array, 0, length - 1);
}

void print_array(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	int array[50];
	int length;
	cout << "Length of array? ";
	cin >> length;
	for (int i = 0; i < length; ++i) {
		cin >> array[i];
	}
	print_array(array, length);
	mergesort(array, length);
	print_array(array, length);
	return 0;
}

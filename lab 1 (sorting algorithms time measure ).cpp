#include <iostream>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include <chrono>
#include <fstream>
using namespace std;
using namespace chrono;

void Swap(int*, int* );
void Bubble(int*, int);
void Selection(int*, int);
void Insertion(int*, int );

int main(){
	srand(time(NULL));
	ofstream SDLab1Table;
	SDLab1Table.open("Domashno1B.csv", ios::app);
	SDLab1Table << endl << ";" << "Време (милисекунди) за алгоритми за сортировка" << endl;
	SDLab1Table << "Брой елементи в масива" << ";" << "Пряка селекция" << ";" << "Пряко вмъкване" << ";" << "Мехурче" << ";" << endl;

	for (int amount_elements = 10000; amount_elements <= 100000; amount_elements += 10000) { // Loop to get different arrays with different amounts of elements
		int* original_array = new int[amount_elements]; // Create an array for the random values
		// Generate  numbers from 1 to the amount and fill the array:
		for (int i = 0; i < amount_elements; i++) {	original_array[i] = rand() % amount_elements + 1; }
		
		// Create a copy of the array
		int* copy_array = new int[amount_elements]; 
		copy(original_array, original_array + amount_elements, copy_array);

		// Measure the time for Selection
		auto begin = high_resolution_clock::now();
		Selection(copy_array, amount_elements);
		auto end = high_resolution_clock::now();
		auto duration_1 = duration_cast<milliseconds>(end - begin);

		copy(original_array, original_array + amount_elements, copy_array);

		// Measure the time for Insertion
		begin = high_resolution_clock::now();
		Insertion(copy_array, amount_elements);
		end = high_resolution_clock::now();
		auto duration_2 = duration_cast<milliseconds>(end - begin);

		copy(original_array, original_array + amount_elements, copy_array);

		// Measure the time for Bubble
		begin = high_resolution_clock::now();
		Bubble(copy_array, amount_elements);
		end = high_resolution_clock::now();
		auto duration_3 = duration_cast<milliseconds>(end - begin);

		SDLab1Table << amount_elements << ';' << duration_1.count() << ';' << duration_2.count() << ';' << duration_3.count();
		SDLab1Table << endl;

		if (copy_array != nullptr) {
			delete[] copy_array;
			copy_array = nullptr;
		}
		if (original_array != nullptr) {
			delete[] original_array;
			original_array = nullptr;
		}
	}
	SDLab1Table.close();
	return 0;
}

void Swap( int* a, int* b){
	int copy = *a;
	*a = *b;
	*b = copy;
}

void Selection( int* number_array,  int n){
	int i, j, minValue_index;

	for (i = 0; i < n - 1; i++) { // loop through without the last 
		// find the minimum value
		minValue_index = i;
		for (j = i + 1; j < n; j++){
			if (number_array[j] < number_array[minValue_index]) { minValue_index = j; }
		}
		// swap the found minimum element with the first element  
		Swap(&number_array[minValue_index], &number_array[i]);
	}
}

void Insertion(int* number_array, int n){
	int i, j, current_number;
	for (i = 1; i < n; i++){
		current_number = number_array[i];
		j = i - 1;

		/* shift elements, bigger than the current value, to 1 position ahead
		of their current position */
		while (j >= 0 && number_array[j] > current_number)
		{
			number_array[j + 1] = number_array[j];
			j--;
		}
		number_array[j + 1] = current_number;
	}
}

void Bubble( int* number_array,  int n){
	int i = 0;
	bool inversion_present = true;
	while (inversion_present) {
		inversion_present = false;

		for (int j = 1; j < n - i; j++) {
			if (number_array[j - 1] > number_array[j]) {
				Swap(&number_array[j], &number_array[j + 1]);
				inversion_present = true;
			}
		}
		i++;
	}			
}

#include <iostream>
#include <functional>

enum type {less, greater};	//SortRule

template <typename T, type e>
void bubblesort(T arr[], int n) {
	int passages = 0;
	bool swapped = false;
	std::function<bool(T, T)> predicate;

	switch (e) {
		case greater:
			predicate = [](T x, T y) {return x > y ? true : false; };
		break;
		case less:
			predicate = [](T x, T y) {return x < y ? true : false; };
		break;
	}

	for (int i = 0; i < n - 1; i++) { //SortAlgorithm
		swapped = false;
		passages++;
		for (int j = 0; j < n - i - 1; j++) {
			if (predicate(arr[j], arr[j + 1])) {
				T temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				swapped = true;
				passages++;
			}
		}
		if (!swapped) break;
	}

	for (int i = 0; i < n; i++) { //PrintMassive
		std::cout << arr[i] << ", ";
	}
	std::cout << "(" << passages << ")" << std::endl;
}

int main() {
	{
		int arr[] = { 41, 58, 64, 85, 73, 22 };
		bubblesort<int, greater>(arr, 6);
	}
	{
		int arr[] = { 35, 48, 44, 55, 22, 18 };
		bubblesort<int, greater>(arr, 6);
	}
	{
		int arr[] = { 40, 56, 71, 94, 26, 10 };
		bubblesort<int, less>(arr, 6);
	}
	{
		int arr[] = { 35, 51, 58, 28, 76, 11 };
		bubblesort<int, less>(arr, 6);
	}
}
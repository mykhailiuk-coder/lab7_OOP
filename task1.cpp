#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

template <typename T>
void getMax(T arr[], int size) {

    int maxIndex = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
	cout << "Max: " << arr[maxIndex] << endl;
    cout << "Array size: " << size;
}

void getMaxChar(const char* arr[], int size) {
	int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (strcmp(arr[i], arr[maxIndex]) > 0)
            maxIndex = i;
    }
	cout << "\nChar max: " << arr[maxIndex] << endl;
	cout << "Array size: " << size;
}
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void selectionSortChar(const char* arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (strcmp(arr[j], arr[minIndex]) < 0) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			swap(arr[i], arr[minIndex]);
		}
	}
}

template <typename T>
void printArr(T arr[], int n) {
	cout << "\nUnsorted array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <typename T>
class Stack {
private:
    vector<T> elements; 

public:
    void addElement(const T& value) {
        elements.push_back(value);
    }

    void deleteElement() {
        if (!isEmpty()) {
            elements.pop_back();
        }
        else {
            cout << "Error: empty stack" << endl;
        }
    }

    T top() const {
        if (!isEmpty()) {
            return elements.back();
        }
        else {
            throw out_of_range("Error: empty stack");
        }
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main()
{
    while (true) {
        int task;
        cout << "Input task(1, 2, 3, 4): ";
        cin >> task;
        if (task == 1) {
            double arr[] = { 2.3, 3.1, 1.8, 5.1, 8.2 };
			printArr(arr, 5);
            getMax(arr, 5);
            const char* arr2[] = { "a", "b", "e", "d" };
			printArr(arr2, 4);
            getMaxChar(arr2, 4);
			cout << "\n\n";
        }
        if (task == 2) {
			int arr[] = { 5, 2, 9, 1, 5, 6 };
			printArr(arr, 6);
			const char* arr3[] = { "banana", "apple", "orange", "grape" };
			printArr(arr3, 4);
			int n = sizeof(arr) / sizeof(arr[0]);
			selectionSort(arr, n);
			cout << "Sorted array: ";
			for (int i = 0; i < n; i++)
				cout << arr[i] << " ";
			cout << endl;
			int n2 = sizeof(arr3) / sizeof(arr3[0]);
			selectionSortChar(arr3, n2);
            
			cout << "Sorted char array: ";
			for (int i = 0; i < n2; i++)
				cout << arr3[i] << " ";
			cout << "\n\n";
        }
        if (task == 3) {
			Stack<int> stack;
			stack.addElement(1);
			stack.addElement(2);
			stack.addElement(3);
			stack.addElement(4);
			cout << "Top element: " << stack.top() << endl;
			cout << "Stack size: " << stack.size() << endl;
			stack.deleteElement();
			cout << "Top element after deletion: " << stack.top() << endl;
			cout << "Stack size after deletion: " << stack.size() << endl;
        }

    }
    return 0;
}
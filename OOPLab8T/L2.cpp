#include <iostream>
#include <cstring>

template <typename T>
int partition(T* array, int low, int high) {
    T pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (array[j] <= pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return i + 1;
}

template <typename T>
void quicksort(T* array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);

        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

template <>
int partition<char*>(char** array, int low, int high) {
    char* pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (strcmp(array[j], pivot) <= 0) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[high]);
    return i + 1;
}

template <>
void quicksort<char*>(char** array, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(array, low, high);

        quicksort(array, low, pivotIndex - 1);
        quicksort(array, pivotIndex + 1, high);
    }
}

void task2() {
    int intArray[] = { 3, 2, 4, 8, 6, 9, 1, 7 };
    int intSize = sizeof(intArray) / sizeof(int);
    quicksort(intArray, 0, intSize - 1);

    std::cout << "Sorted intArray: ";
    for (int i = 0; i < intSize; ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    const char* stringArray[] = { "Banana", "Grape", "Orange", "Cherry", "Mango" };
    int stringSize = sizeof(stringArray) / sizeof(const char*);
    quicksort(stringArray, 0, stringSize - 1);

    std::cout << "Sorted stringArray: ";
    for (int i = 0; i < stringSize; ++i) {
        std::cout << stringArray[i] << " ";
    }
    std::cout << std::endl;
}


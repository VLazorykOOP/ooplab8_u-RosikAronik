#include <iostream>
#include <cstring>

template <typename T>
int sequentialSearch(const T* array, int size, const T& key) {
    int lastIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (array[i] == key) {
            lastIndex = i;
        }
    }

    return lastIndex;
}

template <>
int sequentialSearch<const char*>(const char* const* array, int size, const char* const& key) {
    int lastIndex = -1;

    for (int i = 0; i < size; ++i) {
        if (strcmp(array[i], key) == 0) {
            lastIndex = i;
        }
    }

    return lastIndex;
}

void task1() {
    int intArray[] = { 1, 2, 3, 4, 5, 3, 6, 7, 8 };
    int intKey = 5;
    int intIndex = sequentialSearch(intArray, 9, intKey);
    std::cout << "Index of last occurrence of " << intKey << " in intArray: " << intIndex << std::endl;

    const char* stringArray[] = { "Banana", "Grape", "Orange", "Cherry", "Mango" };
    const char* stringKey = "Cherry";
    int stringIndex = sequentialSearch(stringArray, 5, stringKey);
    std::cout << "Index of last occurrence of \"" << stringKey << "\" in stringArray: " << stringIndex << std::endl;

   
}

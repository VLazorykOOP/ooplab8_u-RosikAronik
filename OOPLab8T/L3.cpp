#include <iostream>

template <typename T>
class MyArray {
private:
    T* data;  
    int size;

public:
    MyArray() : data(nullptr), size(0) {}
    
    MyArray(int arraySize) : size(arraySize) {
        data = new T[size];
    }

    MyArray(const MyArray& other) : size(other.size) {
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~MyArray() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    T& operator[](int index) {
        return data[index];
    }

    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            delete[] data;

            size = other.size;
            data = new T[size];

            for (int i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    MyArray operator+(const MyArray& other) const {
        MyArray result(size + other.size);

        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i];
        }

        for (int i = 0; i < other.size; ++i) {
            result.data[size + i] = other.data[i];
        }

        return result;
    }

    MyArray& operator+=(const MyArray& other) {
        int newSize = size + other.size;
        T* newData = new T[newSize];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        for (int i = 0; i < other.size; ++i) {
            newData[size + i] = other.data[i];
        }

        delete[] data;
        data = newData;
        size = newSize;

        return *this;
    }

    MyArray operator-(const MyArray& other) const {
        MyArray result(size);

        for (int i = 0; i < size; ++i) {
            result.data[i] = data[i] - other.data[i];
        }

        return result;
    }

    MyArray& operator-=(const MyArray& other) {
        if (size != other.size) {

            return *this;
        }

        for (int i = 0; i < size; ++i) {
            data[i] -= other.data[i];
        }

        return *this;
    }
};

void task3() {

    MyArray<int> array1(5);
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;
    array1[3] = 4;
    array1[4] = 5;

    MyArray<int> array2(5);
    array2[0] = 6;
    array2[1] = 7;
    array2[2] = 8;
    array2[3] = 9;
    array2[4] = 10;

    MyArray<int> array3 = array1 + array2;

    for (int i = 0; i < array3.getSize(); ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    array3 -= array1;

    for (int i = 0; i < array3.getSize(); ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

   
}

#ifndef MYVECTOR_H
#define MYVECTOR_H

template <typename T>
class MyVector {
private:

    T* data;
    int size;
    int capacity;

public:

    MyVector() :data(nullptr), size(0), capacity(0) {}

    ~MyVector() { delete[] data; }

    void push_back(const T& data) {
        if (size = capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;

            T* newData = new T[capacity];

            for (int i = 0; i < size; i++) {
                newData[i] = data[i]
            }

            delete[] data;
            data = newData;
        }

        data[size++] = value;
    }

    T retrieveInfoAtIndex(int index) const {
        return data[index];
    }

    int getSize() const {
        return size;
    }

};
#endif 

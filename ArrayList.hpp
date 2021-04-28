#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;


template <typename T>
class ArrayList : public List<T> {
    private:
        // an array that contains the elements
        T* buffer;

        // the maximum number of elements in the list
        int maxSize;

        // copy the values from the argument list to `this`
        void copy(const ArrayList<T>&);

        // swap the elements at the given positions
        void swap(int, int);

        // different sort algorithms to sort the elements in the list
        void bubbleSort();
        void selectionSort();
        void insertionSort();

    public:
        // constructor with the maximum size as the argument
        ArrayList(int = 100);

        // copy constructor
        ArrayList(const ArrayList<T>&);

        // overloaded assignment operator
        ArrayList<T>& operator=(const ArrayList<T>&);

        // destructor
        virtual ~ArrayList();

        // add the argument to the end of the list
        virtual void append(const T&) override;

        // remove all elements in the list
        virtual void clear() override;

        // return the element at the given position (argument)
        virtual T getElement(int) const override;

        // return the current length of the list
        virtual int getLength() const override;

        // return the maximum size of the list
        int getMaxSize() const;

        // insert the given element (argument 2) at
        // the given position (argument 1)
        virtual void insert(int, const T&) override;

        // determine if the list currently empty
        virtual bool isEmpty() const override;

        // determine if the list currently full
        bool isFull() const;

        // remove the element at the given position (argument)
        virtual void remove(int) override;

        // replace the element at the given position (argument 1) with
        // the value given (argument 2)
        virtual void replace(int, const T&) override;

        // sort the elements in the list using the algorithm (argument 1)
        //      1 --> bubble sort
        //      2 --> selection sort
        //      3 --> insertion sort
        void sort(int);
};

template <typename T>
void ArrayList<T>::bubbleSort() {
	cout << "try" << endl;
   int n = this->length;
   int j = n-1;
   for( int i = 0; i<n-1 ; i++){
	  while (j>i){
			cout << "try" << endl;
		   if(buffer[j].k< buffer[j-1].k){
			   swap(j,j-1);
			}
		   j--;
	   }
   }

}

template <typename T>
void ArrayList<T>::selectionSort() {Array
	int n = this->length;
	int j = n-1;
	int t = 0;


	for ( int i = 0 ; i< n-1; i++){
		cout << "222222" << endl;
		t = i;

		while(j>i){
			if (buffer[t]>buffer[j]){
				t = j ;
				}
			j--;
		}
		if (i!= t){
			buffer[i] = buffer[t];
		}
	}
}

template <typename T>
void ArrayList<T>::insertionSort() {
    // TODO
}

template <typename T>
void ArrayList<T>::swap(int i, int j) {
    T temp = buffer[i];
    buffer[i] = buffer[j];
    buffer[j] = temp;
}

template <typename T>
void ArrayList<T>::sort(int algo) {
    if (algo == 1) {

        bubbleSort();
    }
    else if (algo == 2) {
        selectionSort();
    }
    else if (algo == 3) {
        insertionSort();
    }
}

template <typename T>
ArrayList<T>::ArrayList(int i) {
    this->length = 0;
    maxSize = i;
    buffer = new T[maxSize];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rightObj) {
    clear();
    copy(rightObj);
    return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
    clear();
}

template <typename T>
void ArrayList<T>::append(const T& elem) {
    if (isFull()) {
        cout << "ERROR: list is full\n";
    }
    else {
        if (buffer == nullptr) {
            buffer = new T[maxSize];
        }

        buffer[this->length] = elem;
        this->length++;
    }
}

template <typename T>
void ArrayList<T>::clear() {
    if (buffer != nullptr) {
        delete[] buffer;
    }
    buffer = nullptr;
    this->length = 0;
}

template <typename T>
void ArrayList<T>::copy(const ArrayList<T>& copyObj) {
    this->length = copyObj.length;
    maxSize = copyObj.maxSize;
    buffer = new T[maxSize];

    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[i];
    }
}

template <typename T>
T ArrayList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
        throw -1;
    }

    return buffer[position];
}

template <typename T>
int ArrayList<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayList<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
void ArrayList<T>::insert(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else if (isFull()) {
        cout << "ERROR: list is full\n";
    }
    else {
        for (int i = this->length; i > position; i--) {
            buffer[i] = buffer[i - 1];
        }
        
        buffer[position] = elem;
        this->length++;
    }
}

template <typename T>
bool ArrayList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayList<T>::isFull() const {
    return this->length == maxSize;
}

template <typename T>
void ArrayList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        for (int i = position; i < this->length - 1; i++) {
            buffer[i] = buffer[i + 1];
        }

        this->length--;
    }
}

template <typename T>
void ArrayList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        cout << "ERROR: position out of bounds\n";
    }
    else {
        buffer[position] = elem;
    }
}

#endif

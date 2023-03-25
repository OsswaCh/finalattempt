#include <iostream>
#include "queuee.h"

template <typename t>
queuee<t>::queuee() {
	values = new double[10];
	maxSize = 10;
	front = 0;
	rear = -1;
	counter = 0;
}

template <typename t>
queuee<t>::queuee(int size) {
	values = new double[size];
	maxSize = size;
	front = 0;
	rear = -1;
	counter = 0;
}



template <typename t>
bool queuee<t>:: isEmpty() {
	if (counter) return false;
	else
		return true;
}

template <typename t>
bool queuee<t>::isFull() {
	if (counter==maxSize) return true;
	else
		return false;
}

template <typename t>
bool queuee<t>:: Enqueue(t x) {
	if (isFull()) {
		std::cout << "Error";
		return false;
	}
	else {
		rear = (rear + 1) % maxSize;
		*(values + rear) = x;
		counter++;
		return true;

	}
}

template <typename t>
bool queuee<t>::Dequeue(t& x) {
	if (isEmpty()) {
		std::cout << "empty queue";
		return false;
	}
	else {
		x = *(values + front);
		front = (front + 1) % maxSize;
		counter--;
		return true;
	}
}


	
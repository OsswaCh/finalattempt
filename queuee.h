#pragma once
template <typename t>

class queuee
{
private: 
	int front;
	int rear;
	int counter;
	int maxSize;
	t* values;

public:
	queuee();
	queuee(int size );
	bool Enqueue(t );
	bool Dequeue(t& );
	bool isEmpty();
	bool isFull();

};


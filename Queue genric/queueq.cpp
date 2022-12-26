#include <iostream>
#include <string>
#include "queueq.h"

using namespace std;

template <class Type>
queueq<Type>::queueq(int n){
	maxSize = n; arr = new int[maxSize];
	front = 0; rear = -1; count = 0;
}

template <class Type>
queueq<Type>::queueq(const queueq<Type> &obj){
	front = obj.front;
	rear = obj.rear;
	maxSize = obj.maxSize;
	count = obj.count;
	arr = new int[maxSize];
	for (int i = 0; i < maxSize; i++)
		arr[i] = obj.arr[i];
}

template <class Type>
queueq<Type>::~queueq(){
	maxSize = front = rear = count = 0;
	delete[] arr;
}

template <class Type>
void queueq<Type>::enqueue(Type d){
	if(queueIsFull()) cout << "Queue is Full" << endl;
	else{ 
		rear = (rear+1) % maxSize;
		arr[rear] = d; count++;
	}
}

template <class Type>
void queueq<Type>::dequeue(Type &d){
	if(queueIsEmpty()) cout << "Queue is Empty" << endl;
	else{ 
		d = arr[front]; count--;
		front = (front+1) % maxSize;
	}
}

template <class Type>
void queueq<Type>::queueFront(Type &d) const{
	if (queueIsEmpty()) cout << "Queue is Empty" << endl;
	else d = arr[front];
}
template <class Type>
bool queueq<Type>::queueIsEmpty() const{
	return (count == 0);
}

template <class Type>
bool queueq<Type>::queueIsFull() const{
	return (count == maxSize);
}

template <class Type>
int queueq<Type>::queueLength() const{
	return count;
}


#include "queueq.cpp"

template <class Type>
int minIndex (queueq<int> &q, int sortedIndex){
	int min_index = -1;
	int min_val = INT_MAX;
	
	for(int i=0; i<q.queueLength(); i++){
		int curr;
		q.dequeue(curr);
		
		if(curr <= min_val && i <= sortedIndex){
			min_index = i;
			min_val = curr;
		}
		q.enqueue(curr);
	}
	return min_index;
}

template <class Type>
int insertMinToRear(queueq<int> &q, int min_index){
	int min_val;
	for(int i = 0; i < q.queueLength(); i++){
		int curr;
		q.dequeue(curr);
		if (i != min_index)
			q.enqueue(curr);
		else
			min_val = curr;
	}
	q.enqueue(min_val);
}

template <class Type>
void sortQueue(queueq<int> &q)
{
    for (int i = 0; i < q.queueLength(); i++)
    {
        int min_index = minIndex(q, q.queueLength()-i);
        insertMinToRear(q, min_index);
    }
}


int main(){
	queueq<int> q(4);
	q.enqueue(11);
	q.enqueue(5);
	q.enqueue(4);
	q.enqueue(21);
	
}

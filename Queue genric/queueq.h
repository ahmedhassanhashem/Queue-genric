template <class Type>

class queueq{
	private :
		Type *arr;
		int front, rear, count, maxSize;
	public :
		queueq(int n = 128);
		queueq(const queueq<Type> &);
		~queueq();
		void enqueue(Type);
		void dequeue(Type &);
		void queueFront(Type &) const;
		bool queueIsEmpty() const;
		bool queueIsFull() const;
		int queueLength() const;
};

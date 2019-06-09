/******************
* Geoff Overfield *
*   Queue Data    *
*    Structure    *
******************/

#ifndef QUEUE
#define QUEUE

template <class T>
struct Node
{
	public:
		T data;
		Node *next;
		Node();
		~Node();
	private:
		bool priority = false;
};

template <class T>
Node<T>::~Node()
{
}

class Queue
{
	public:
		Queue();
		~Queue();
		void Insert(T);
		void Delete(Node<T> &);
		void Display();
		bool IsEmpty();
	private:
		Node<T> *front;
		Node<T> *tail;
};

Queue<T>::Queue()
{
	front = NULL;
	tail = null;
}

Queue<T>::~Queue()
{
	while(!IsEmpty())
		Delete(front);
}

void Queue<T>::Insert(T x)
{
	Node<T> newNode = new Node();
	newNode->data = x;
	if (front == NULL)
		front = newNode;
	else
	{
		Node<T> temp = front;
		while(temp)
			temp = temp->next;
		temp->next = newNode;
		tail = newNode;
		temp = NULL;
		delete temp;
	}
}

template <class T>
void Queue<T>::Delete(Node<T> &node)
{
	Node<T> temp = new Node();
	if (node->priority == true)
	{
		temp = node;
		Node<T> temp2 = new Node();
		temp2 = front;
		while (temp2->next != node)
			temp2 = temp2->next;
		temp2->next = node->next;
		node->next = front;
		front = node;
		temp2 = NULL;
		delete temp2;
	}

	temp = front->next;
	front = NULL;
	delete front;
	front = temp;
	temp = NULL;
	delete temp;
}

template <class T>
Void Queue<T>::Display()
{
	Node<T> temp = new Node();
	temp = front;
	int i = 1;
	while (temp)
	{
		cout << Place in Queue:\t\t << i << endl;
		cout << Information in Node:\t\t << temp->data << endl;
		cout << Memory Address of Node:\t\t << &temp << endl;
	}

	temp = NULL;
	delete temp;
}

template <class T>
Bool Queue<T>::IsEmpty()
{
	return front == NULL;
}

#endif

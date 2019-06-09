{\rtf1\ansi\ansicpg1252\cocoartf1561\cocoasubrtf600
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 /********************\
* Geoff Overfield *\
*    Queue Data   *\
*      Structure      *\
********************/\
\
#ifndef QUEUE\
#define QUEUE\
\
template <class T>\
struct Node\
\{\
	public:\
		T data;\
		Node *next;\
		Node();\
		~Node();\
	private:\
		bool priority = false;\
\};\
\
template <class T>\
Node<T>::~Node()\
\{\
\}\
\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 template <class T>\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 class Queue\
\{\
	public:\
		Queue();\
		~Queue();\
		void Insert(T);\
		void Delete(Node<T> &);\
		void Display();\
		bool IsEmpty();\
	private:\
		Node<T> *front;\
		Node<T> *tail;\
\};\
\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 template <class T>\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 Queue<T>::Queue()\
\{\
	front = NULL;\
	tail = null;\
\}\
\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 template <class T>\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 Queue<T>::~Queue()\
\{\
	while(!IsEmpty())\
		Delete(front);\
\}\
\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 template <class T>\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 void Queue<T>::Insert(T x)\
\{\
	Node<T> newNode = new Node();\
	newNode->data = x;\
	if (front == NULL)\
		front = newNode;\
	else\
	\{\
		Node<T> temp = front;\
		while(temp)\
			temp = temp->next;\
		temp->next = newNode;\
		tail = newNode;\
		temp = NULL;\
		delete temp;\
	\}\
\}\
\
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0
\cf0 template <class T>\
void Queue<T>::Delete(Node<T> &node)\
\{\
	Node<T> temp = new Node();\
	if (node->priority == true)\
	\{\
		temp = node;\
		Node<T> temp2 = new Node();\
		temp2 = front;\
		while (temp2->next != node)\
			temp2 = temp2->next;\
		temp2->next = node->next;\
		node->next = front;\
		front = node;\
		temp2 = NULL;\
		delete temp2;\
	\}\
\
	temp = front->next;\
	front = NULL;\
	delete front;\
	front = temp;\
	temp = NULL;\
	delete temp;\
\}\
\
template <class T>\
Void Queue<T>::Display()\
\{\
	Node<T> temp = new Node();\
	temp = front;\
	int i = 1;\
	while (temp)\
	\{\
		cout << \'93Place in Queue:\\t\\t << i MM endl;\
		cout << \'93Information in Node:\\t\\t\'94 << temp->data << endl;\
		cout << \'93Memory Address of Node:\\t\\t << &temp << endl;\
	\}\
\
	temp = NULL;\
	delete temp;\
\}\
\
template <class T>\
Bool Queue<T>::IsEmpty()\
\{\
	return front == NULL;\
\}\
\
#endif}
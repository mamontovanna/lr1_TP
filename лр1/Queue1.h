#pragma once

#include"Queue.h"

class sonQueuePublic :public parQueue
{
public:
	int myfunc();//������� �� �������
};

class sonQueuePrivate :private parQueue
{
public:
	int myfunc();//������� �� �������
	int pop();
	void push(int el);
	void copy(sonQueuePrivate& Q);
	void merge(sonQueuePrivate& Q1);
	void print();
	bool isEmpty(); //�������� �� �������������
};

class sonQueueProtected : protected parQueue
{
public:
	int myfunc();//������� �� �������
	int pop();
	void push(int el);
	void copy(sonQueueProtected& Q);
	void merge(sonQueueProtected& Q1);
	void print();
	bool isEmpty(); //�������� �� �������������
};
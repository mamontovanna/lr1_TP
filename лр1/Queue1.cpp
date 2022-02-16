#include<iostream>
#include"Queue1.h"
#include"Queue.h"
using namespace std;
//#14. ������� �������� ��������������� ��� ��������� � �������� ���������� �������.

int sonQueuePrivate::myfunc()
{
	setlocale(LC_ALL, "Rus");
	Unit* last = get_last();
	int arf;//������� �������������� ��������� � ���. ���������� �������
	int sum = 0;//����� ��������� � ���. ���������� �������
	int cnt = 0;//������� �������� �������
	int k = 0;
	if (size == 0)
	{
		cout << "������� �����!" << endl;
	}
	else
		while (last != nullptr)
		{
			if (k % 2 == 1)
			{
				sum += last->data;
				cnt++;
			}
			last = last->prev;
			k++;
		}
	arf = sum / cnt;
	return arf;
}

int sonQueuePrivate::pop() { return parQueue::pop(); }
void sonQueuePrivate::push(int el) { return parQueue::push(el); }
void sonQueuePrivate::copy(sonQueuePrivate& Q1) { return parQueue::copy(Q1); }
void sonQueuePrivate::print() { return parQueue::print(); }
void sonQueuePrivate::merge(sonQueuePrivate& Q1) { return parQueue::merge(Q1); }
bool sonQueuePrivate::isEmpty() { return parQueue::isEmpty(); }



int sonQueueProtected::myfunc()
{
	setlocale(LC_ALL, "Rus");
	Unit* last = get_last();
	int arf;//������� �������������� ��������� � ���. ���������� �������
	int sum = 0;//����� ��������� � ���. ���������� �������
	int cnt = 0;//������� �������� �������
	int k = 0;
	if (size == 0)
	{
		cout << "������� �����!" << endl;
	}
	else
		while (last != nullptr)
		{
			if (k % 2 == 1)
			{
				sum += last->data;
				cnt++;
			}
			last = last->prev;
			k++;
		}
	arf = sum / cnt;
	return arf;
}
int sonQueueProtected::pop() { return parQueue::pop(); }
void sonQueueProtected::push(int el) { return parQueue::push(el); }
void sonQueueProtected::print() { return parQueue::print(); }
void sonQueueProtected::merge(sonQueueProtected& Q1) { return parQueue::merge(Q1); }
void sonQueueProtected::copy(sonQueueProtected& Q1) { return parQueue::copy(Q1); }
bool sonQueueProtected::isEmpty() { return parQueue::isEmpty(); }


int sonQueuePublic::myfunc()
{
	setlocale(LC_ALL, "Rus");
	Unit* last = get_last();
	int arf;//������� �������������� ��������� � ���. ���������� �������
	int sum = 0;//����� ��������� � ���. ���������� �������
	int cnt = 0;//������� �������� �������
	int k = 0;
	if (size == 0)
	{
		cout << "������� �����!" << endl;
	}
	else
		while (last != nullptr)
		{
			if (k % 2 == 1)
			{
				sum += last->data;
				cnt++;
			}
			last = last->prev;
			k++;
		}
	arf = sum / cnt;
	return arf;
}


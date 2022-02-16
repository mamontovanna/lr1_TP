#include<iostream>
#include "Queue.h"
using namespace std;



parQueue::parQueue()
{
	size = 0;
	last = nullptr;
}
parQueue::~parQueue()
{
	while (size > 0)
	{
		Unit* tmp = last;
		last = tmp->prev;
		delete tmp;
		size--;
	}
}

Unit* parQueue::get_last()
{
	return last;
}

void parQueue::push(int el)
{
	Unit* new_unit = new Unit;//�������� ������ ��� ����� �������
	new_unit->prev = last;// ����� ������� ������ � ���� � �������� ��������� �� ���������� ������� ����� "�������" ���������� ��������
	last = new_unit;//����������� ������� ���������� ���������
	last->data = el; //����������� ������
	size++;//����������� ���������� ���������
}
	
	
int parQueue::pop()//��������
{
	Unit* tmp = last;
	int del = 0;//�������� ���������� ��������

	if (tmp->prev == nullptr)//���� � ������� ������ ���� �������, �.� ��������� �� ���������� ������� �������
	{
		del = tmp->data;
		delete last;
		last = nullptr;
		size--;
	}
	else
	{
		while (tmp->prev->prev!=nullptr)
		{
			tmp = tmp->prev;
		}
		del = tmp->prev->data;
		delete tmp->prev;
		tmp->prev = nullptr;
		size--;
	}
	return del;
}

void parQueue::copy(parQueue& Q)
{
	setlocale(LC_ALL, "Rus");
	int* buf = new int[Q.size];//������� ������-�����
	Unit* elQueue = Q.last;// ����� ����������-�������
	for (int i=Q.size - 1; i >= 0; i--)
	{
		buf[i] = elQueue->data;//� �������� ������ ������� �������� �������, ������� �������� �����������
		elQueue = elQueue->prev;//��������� � ���������� ��������
	}
	for (int i = 0; i < Q.size; i++)
	{
		this->push(buf[i]);
	}
	delete[] buf;
	cout << "����������� ������� ���������!" << endl;
}

void parQueue::merge(parQueue& Q1)
{
	setlocale(LC_ALL, "Rus");
	int* buf1 = new int[Q1.size];//������� ������-�����
	Unit* elQueue1 = Q1.last;// ����� ����������-�������
	for (int i = Q1.size - 1; i >= 0;i--)
	{
		buf1[i] = elQueue1->data;
		elQueue1 = elQueue1->prev;
	}
	for (int i = 0; i < Q1.size; i++)
	{
		this->push(buf1[i]);
	}
	delete[] buf1;
	cout << "������� �������� ���������!" << endl;
}

void parQueue::print()
{
	Unit* tmp = last;
	while (tmp->prev != nullptr)
	{
		cout << tmp->data << "   "; //�������� ��������� � �����, ���� ��������� �� ���������� ������� �� ����� ������� 
		tmp = tmp->prev;
	}
	cout << tmp->data << endl;//����� ���������� �������� ��������, �.�. � ���������� ����� �� �� ������ ������� ��� ��-�� ������� tmp->prev != nullptr
	
}

bool parQueue::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


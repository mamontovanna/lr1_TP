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
	Unit* new_unit = new Unit;//выделяем память под новый элемент
	new_unit->prev = last;// новый элемент хранит в себе в качестве указателя на предыдущий элемент адрес "старого" последнего элемента
	last = new_unit;//добавленный элемент становится последним
	last->data = el; //присваиваем данные
	size++;//увеличиваем количество элементов
}
	
	
int parQueue::pop()//удаление
{
	Unit* tmp = last;
	int del = 0;//значение удаляемого элемента

	if (tmp->prev == nullptr)//если в очереди только один элемент, т.е указатель на предыдущий элемент нулевой
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
	int* buf = new int[Q.size];//создаем массив-буфер
	Unit* elQueue = Q.last;// новая переменная-очередь
	for (int i=Q.size - 1; i >= 0; i--)
	{
		buf[i] = elQueue->data;//в буферный массив заносим элементы очереди, которая подлежит копированию
		elQueue = elQueue->prev;//переходим к следующему элементу
	}
	for (int i = 0; i < Q.size; i++)
	{
		this->push(buf[i]);
	}
	delete[] buf;
	cout << "Копирование очереди завершено!" << endl;
}

void parQueue::merge(parQueue& Q1)
{
	setlocale(LC_ALL, "Rus");
	int* buf1 = new int[Q1.size];//создаем массив-буфер
	Unit* elQueue1 = Q1.last;// новая переменная-очередь
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
	cout << "Слияние очередей завершено!" << endl;
}

void parQueue::print()
{
	Unit* tmp = last;
	while (tmp->prev != nullptr)
	{
		cout << tmp->data << "   "; //значение выводятся с конца, пока указатель на предыдущий элемент не будет нулевым 
		tmp = tmp->prev;
	}
	cout << tmp->data << endl;//вывод последнего элемента отдельно, т.к. в предыдущем цикле мы не сможем вывести его из-за условия tmp->prev != nullptr
	
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


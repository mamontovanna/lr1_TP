#pragma once

using namespace std;
typedef struct Unit// структура элемента очереди Unit
{
	int data=1;//значение
	Unit* prev = 0;//указатель на предыдущий элемент
}Unit;

class parQueue//родительский класс "Очередь"
{

private:
	Unit* last = 0;//указатель на конец очереди
protected:
	int size = 0;//размер очереди

public:
	parQueue();
	~parQueue();

	Unit* get_last();//взятие конца очереди
	void push(int el);//добавление элемента
	int pop();//удаление элемента
	void copy(parQueue &Q);//копирование очуреди
	void merge(parQueue &Q1); //слияние двух очередей
	void print();//вывод очереди на консоль
	bool isEmpty(); //проверка на заполненность
};

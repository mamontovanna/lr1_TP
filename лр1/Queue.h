#pragma once

using namespace std;
typedef struct Unit// ��������� �������� ������� Unit
{
	int data=1;//��������
	Unit* prev = 0;//��������� �� ���������� �������
}Unit;

class parQueue//������������ ����� "�������"
{

private:
	Unit* last = 0;//��������� �� ����� �������
protected:
	int size = 0;//������ �������

public:
	parQueue();
	~parQueue();

	Unit* get_last();//������ ����� �������
	void push(int el);//���������� ��������
	int pop();//�������� ��������
	void copy(parQueue &Q);//����������� �������
	void merge(parQueue &Q1); //������� ���� ��������
	void print();//����� ������� �� �������
	bool isEmpty(); //�������� �� �������������
};

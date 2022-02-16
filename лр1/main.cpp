#include<iostream>
#include <locale>
#include "Queue.h"
#include "Queue1.h"
using namespace std;
//#14. Подсчет среднего арифметического для элементов с нечетным порядковым номером.

template<class T>
void chosen_class(T *q, int n_q)//шаблонная функция для работы с классом
{
	setlocale(LC_ALL, "Rus");
	int c;
	int flag = 1;
	int value;//значение элемента, который введет пользователь
	int index = 0;//номер очереди, с которой работаем
	int count = 1; //кол-во очередей, с которыми работает пользователь
	int res = 0; //переменная
	int chosen_q; //номер выбранной очереди

	while (flag == 1)
	{
		cout << "1 - Добавление элемента очереди" << endl;
		cout << "2 - Извлечение элемента очереди" << endl;
		cout << "3 - Вывод очереди на экран" << endl;
		cout << "4 - Подсчет среднего арифметического для элементов с нечетным порядковым номером" << endl;
		cout << "5 - Создание копии очереди" << endl;
		cout << "6 - Слияние двух очередей" << endl;
		cout << "7 - Выбор иной очереди" << endl;
		cout << "8 - С какой очередью я сейчас работаю?" << endl;
		cout << "0 - Вернуться к выбору класса-наследника" << endl;
		cout << "Введите номер желаемого пункта  -> ";
		cin >> c;

		switch (c)
		{
		case 1:
			system("cls");
			cout << "Введите значение: ";
			cin >> value;
			q[index].push(value);
			cout << "Значение добавлено в очередь.\n " << endl;
			break;
			
		case 2:
			if (q[index].isEmpty())
			{
				cout << "Очередь уже пуста, извлекать нечего.\n " << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				value = q[index].pop();
				cout << "Извлеченный элемент: " << value << endl;
				cout << "\n";
			}
			break;

		case 3:
			if (q[index].isEmpty())
			{
				cout << "Очередь пуста, выводить нечего.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				q[index].print();
				cout << "\n";
			}
			break;
		case 4:
			if (q[index].isEmpty())
			{
				cout << "Очередь пуста, задание выполнить невозможно.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				system("cls");
				res = q[index].myfunc();
				cout << "Среднее арифметическое для элементов с нечетным порядковым номером:  " << res << endl;
				cout << "\n";
			}
		case 5:
			if (q[index].isEmpty())
			{
				cout << "Очередь пуста, копировать нечего.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				if (count == n_q)
				{
					cout << "Невозможно создать копию очереди, так как количество очередей достигло максимума.\n" << endl;
					system("pause");
					break;
				}

				system("cls");
				q[count].copy(q[index]);
				cout << "Очередь успешно скопирована. Теперь существует две равных очереди.\n" << endl;
				count++; //теперь у нас есть как минимум две очереди с индексами 0 и 1...
			}
			break;
		case 6:
			if (count == 1)
			{
				cout << "Существует только одна очередь.\n" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "С какой очередью произвести слияние?" << endl;
				cin >> chosen_q;

				if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
				{
					cout << "Некорректное значение!\n" << endl;
					system("pause");
					break;
				}

				if (q[chosen_q].isEmpty())
				{
					cout << "Невозможно произвести слияние, так как вторая очередь пуста.\n" << endl;
					system("pause");
					break;
				}
				system("cls");
				q[index].merge(q[chosen_q]);
				//теперь существует как минимум три очереди с индексами 0, 1, 2...
				cout << "\n";
			}
			break;
		case 7: 
			system("cls");
			cout << "Сейчас вы работаете с очередью №" << index << endl;
			cout << "Введите номер очереди (от 0 до " << n_q - 1 << ") , на которую хотите переключиться: ";
			cin >> chosen_q;

			if ((chosen_q < 0) || (chosen_q >= n_q) || (chosen_q == index))
			{
				cout << "Некорректное значение или количество очередей превышено!\n" << endl;
				system("pause");
			}
			else
			{
				index = chosen_q;
				count++;
				system("cls");
				cout << "Вы переключились на очередь №" << index << endl;
				cout << "\n";
			}
			break;
		case 8:
			system("cls");
			cout << "Вы сейчас работаете с очередью №" << index << endl;
			cout << "\n";
			break;
		case 0:
			cout << "\n";
			flag = 0;
			break;

		}
	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	int num_q; //переменная количества очередей
	int c;
	int flag = 1;

	sonQueuePrivate* q1 = NULL;
	sonQueueProtected* q2 = NULL;
	sonQueuePublic* q3 = NULL;

	cout << "Введите количество очередей: " << endl;
	cin >> num_q;
	system("cls");

	cout << "Выберите, с каким дочерним классом Вы будете работать: " << endl;

	while (flag == 1)
	{
		cout << "1 - Приватный" << endl;
		cout << "2 - Защищенный" << endl;
		cout << "3 - Публичный" << endl;
		cout << "0 - Выход из программы" << endl;
		cout << "-> ";
		cin >> c;
		switch (c)
		{
		case 1:
			q1 = new sonQueuePrivate[num_q];
			system("cls");
			chosen_class(q1, num_q);
			delete[] q1;
			break;
		case 2:
			q2 = new sonQueueProtected[num_q];
			system("cls");
			chosen_class(q2, num_q);
			delete[] q2;
			break;
		case 3:
			q3 = new sonQueuePublic[num_q];
			system("cls");
			chosen_class(q3, num_q);
			delete[] q3;
			break;
		case 0:
			flag = 0;
			break;
		default:
			system("cls");
			cout << "Некорректный ввод!" << endl;
			break;
		}
	}
	return 0;
}

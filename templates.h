//дек
#pragma once
#include <iostream>
using namespace std;

template <class T = Long_int, int size = 10> 
class Item // шаблон одной записи, хранящей указатель на объект T и порядковый номер записи
{
public:
	int num; // порядковый номер записи
	T *info; // указатель на объект вложенного класса
	Item *next, *prev; // указатели на след. и пред. записи
	Item(); // для создания списка
	Item(T &b);
	//Item *get_next() { return next; } // вернуть указатель на след.
	//Item *get_prev() { return prev; } // вернуть указатель на предыдущ
	//int get_num() { return num; }
	//T *get_info() { return info; }
	void set_info(T &b);// записать новую инфу в объект - запись
	void get_info(T &b);// записать инфу из записи в объект b
	~Item();
};

template <class T, int size>
Item <T, size> :: Item()
{
	num = 0;
	info = 0; // присвоение ссылки
	next = 0;
	prev = 0;
}

template <class T, int size>
Item <T, size> :: Item(T &b) // при создании записи подаётся ссылка на объект
{
	info = &b; // присвоение ссылки
	next = 0;
	prev = 0;
	num = 1;
}

template <class T, int size>
void Item <T, size> :: set_info(T &b) 
{ 
	info = &b; 
}

template <class T, int size>
void Item <T, size> :: get_info(T &b) 
{ 
	b = *info; 
}

template <class T, int size>
Item <T, size> :: ~Item()
{
}

template <class T = Long_int, int size = 10>
class Dack : public Item <T, size>
{
protected:
	int top;
	Item <T, size> *beg, *end; //указатели на начало и конец списка
public:
	Dack <T, size>();
	~Dack();
	void push(Item &elem); // добавить в конец
	void pop_from_beg(); // убрать с начала: начало теперь next, prev у next теперь NULL
	void pop_from_end(); // убрать с конца
	Item <T, size> *get_beg(); // получить значение указателя на первый элемент
	Item <T, size> *get_end(); // получить значение указателя на последний элемент
	int get_top();
	Item <T, size> *output_item(int number); //вернуть адрес записи по номеру/
};

template <class T, int size>
Dack <T, size> :: Dack() : Item()
{
	beg = end = 0;
	top = 0;
}

template <class T, int size>
void Dack <T, size> :: push(Item &elem) // добавить в конец
{ // создали запись в мэйне
	if (top >= size) //если дек заполнен
		throw std::exception("Maximum count of nodes!");
	top++;
	elem.next = 0; // след. - нулл 
	elem.prev = end; // предыд - тот, что был последним
	if (elem.prev)
		elem.prev->next = &elem;
	if (!beg && !end)
		beg = &elem;
	end = &elem; // теперь это - посл элемент 
	if (elem.prev)
		elem.num = elem.prev->num + 1;
}

template <class T, int size>
void Dack <T, size> :: pop_from_beg() // убрать с начала: начало теперь next, prev у next теперь NULL
{
	Item <T, size> *a = beg;
	if (beg)
	{
		if (beg->next)
		{
			beg->next->prev = 0;
		} // prev у next теперь NULL
		beg = beg->next; // начало теперь next
		beg->prev = 0;
		delete a;
		top--;
	}
	if (beg)
	{
		a = beg;
		while (a)
		{
			(a->num)--;
			a = a->next;
		}
	}
}

template <class T, int size>
void Dack <T, size> :: pop_from_end() // убрать с конца
{
	Item <T, size> *a = end;
	if (end)
	{
		if (end->prev)
		{
			end->prev->next = 0; // next у prev теперь NULL
		}
		end = end->prev; // конец теперь prev
		end->next = 0;
		delete a;
		top--;
	}
}

template <class T, int size>
Item <T, size> * Dack <T, size> :: get_beg() // получить значение указателя на первый элемент
{
	return beg;
}

template <class T, int size>
Item <T, size> * Dack <T, size> :: get_end() // получить значение указателя на последний элемент
{
	return end;
}

template <class T, int size>
int Dack <T, size> :: get_top() 
{ 
	return top;
}

template <class T, int size>
Item <T, size> * Dack <T, size> :: output_item(int number) //вернуть адрес записи по номеру/
{
	Item <T, size> *a = beg;
	while (a)
	{
		if (a->num == number)
			break;
		a = a->next;
	}
	return a;
}

template <class T, int size> 
Dack <T, size> :: ~Dack()
{
	Item <T, size> *a, *b;
	a = beg;
	while (a) // пока начальный элемент не пуст (существует)
	{
		b = a->next;
		delete a;
		a = b;
		top--;
	}
}

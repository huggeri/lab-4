 //дек
#pragma once
#include <iostream>
using namespace std;

template <typename T = Long_int, int size = 10>
class Dack
{
public:
	class Item // шаблон одной записи, хранящей указатель на объект T и порядковый номер записи
	{
	protected:
		friend class Dack;
		int num; // порядковый номер записи
		T *info; // указатель на объект вложенного класса
		Item *next, *prev; // указатели на след. и пред. записи
	public:
		Item(T &b);
		~Item();

		inline void set_info(T &b);// записать новую инфу в объект - запись
		inline void get_info(T &b);// записать инфу из записи в объект b
		inline T *show_info() const;
		inline Item *get_next() const;
		inline Item *get_prev() const;
		inline int get_num() const;
	};
	Dack <T, size>();
	~Dack();

	void push(Item &elem); // добавить в конец
	void pop_from_beg(); // убрать с начала: начало теперь next, prev у next теперь NULL
	void pop_from_end(); // убрать с конца
	inline Item *get_beg(); // получить значение указателя на первый элемент
	inline Item *get_end(); // получить значение указателя на последний элемент
	inline int get_top() const;
	Item *peek(int number);
protected:
	int top;
	Item *beg, *end; //указатели на начало и конец списка
};

template <typename T, int size>
Dack <T, size>::Item::Item(T &b) // при создании записи подаётся ссылка на объект
{
	info = &b; // присвоение ссылки
	next = 0;
	prev = 0;
	num = 1;
}

template <typename T, int size>
inline void Dack <T, size>::Item::set_info(T &b)
{
	info = &b;
}

template <typename T, int size>
inline void Dack <T, size>::Item::get_info(T &b)
{
	b = *info;
}

template <typename T, int size>
inline T * Dack <T, size>::Item::show_info() const
{
	return info;
}

template <typename T, int size>
inline typename Dack <T, size>::Item * Dack <T, size>::Item::get_next() const
{
	return next;
}

template <typename T, int size>
inline typename Dack <T, size>::Item * Dack <T, size>::Item::get_prev() const
{
	return prev;
}

template <typename T, int size>
inline int Dack <T, size>::Item::get_num() const
{
	return num;
}

template <typename T, int size>
Dack <T, size>::Item::~Item()
{
}

template <typename T, int size>
Dack <T, size>::Dack()
{
	beg = end = 0;
	top = 0;
}

template <typename T, int size>
void Dack <T, size>::push(Item &elem) // добавить в конец
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

template <typename T, int size>
void Dack <T, size>::pop_from_beg() // убрать с начала: начало теперь next, prev у next теперь NULL
{
	Item *a = beg;
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

template <typename T, int size>
void Dack <T, size>::pop_from_end() // убрать с конца
{
	Item *a = end;
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

template <typename T, int size>
inline typename Dack <T, size>::Item *get_beg() // получить значение указателя на первый элемент
{
	return beg;
}

template <typename T, int size>
inline typename Dack <T, size>::Item *get_end() // получить значение указателя на последний элемент
{
	return end;
}

template <typename T, int size>
inline int Dack <T, size>::get_top() const
{ 
	return top;
}

template <typename T, int size>
typename Dack <T, size>::Item * Dack <T, size>::peek(int number) //вернуть адрес записи по номеру/
{
	Item *a = beg;
	while (a)
	{
		if (a->num == number)
			break;
		a = a->next;
	}
	return a;
}

template <typename T, int size>
Dack <T, size>::~Dack()
{
	Item *a, *b;
	a = beg;
	while (a) // пока начальный элемент не пуст (существует)
	{
		b = a->next;
		delete a;
		a = b;
		top--;
	}
}

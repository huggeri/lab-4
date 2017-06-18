#include "templates.h" 
#include "Long_int.h"

void main()
{
	const int size = 11;
	Dack <Long_int, size> C;
	int i = 1;
	Long_int obj;
	Dack <Long_int, size>::Item *first = new Dack <Long_int, size>::Item(obj);

	while (true)
	{
		char *str = "-12345";
		Long_int obj1(str);
		obj = obj1;
		Dack <Long_int, size>::Item *temp = new Dack <Long_int, size>::Item(obj);
		first = temp;
		try
		{
			C.push(*first);
		}
		catch (const exception &e)
		{
			cout << e.what() << endl;
			delete first;
			break;
		}
	}
	
	i = 1;
	while (i <= C.get_top())
	{
		Dack <Long_int, size>::Item *p = C.peek(i);
		if (p)
		{
			cout << p->get_num() << "\t" << p->get_prev() << "\t" << *(p->show_info()) << "\t" << p->get_next() << "\t" << endl;
		}
		i++;
	}
	cout << endl;

	C.pop_from_beg();
	i = 1;
	while (i <= C.get_top())
	{
		Dack <Long_int, size>::Item *p = C.peek(i);
		if (p)
		{
			cout << p->get_num() << "\t" << p->get_prev() << "\t" << *(p->show_info()) << "\t" << p->get_next() << "\t" << endl;
		}
		i++;
	}	
	cout << endl;

	C.pop_from_end();
	i = 1;
	while (i <= C.get_top())
	{
		Dack <Long_int, size>::Item *p = C.peek(i);
		if (p)
		{
			cout << p->get_num() << "\t" << p->get_prev() << "\t" << *(p->show_info()) << "\t" << p->get_next() << "\t" << endl;
		}
		i++;
	}
	cout << endl;

	char *str1234 = "3452345";
	Long_int obj1234(str1234);
	Dack <Long_int, size>::Item *temp = new Dack <Long_int, size>::Item(obj1234);
	C.push(*temp);
	i = 1;
	while (i <= C.get_top())
	{
		Dack <Long_int, size>::Item *p = C.peek(i);
		if (p)
		{
			cout << p->get_num() << "\t" << p->get_prev() << "\t" << *(p->show_info()) << "\t" << p->get_next() << "\t" << endl;
		}
		i++;
	}
	cout << endl;
// другой тип данных
	Dack <double, 12> C1;
	Dack <double, 12>::Item *first1;

	while (true)
	{
		double b = 3.5;
		Dack <double, 12>::Item *temp1 = new Dack <double, 12>::Item (b);
		first1 = temp1;
		try
		{
			C1.push(*first1);
		}
		catch (const exception &e)
		{
			cout << e.what() << endl;
			delete first1;
			break;
		}
	}

	i = 1;
	while (i <= C1.get_top())
	{
		Dack <double, 12>::Item *p1;
		p1 = C1.peek(i);
		if (p1)
		{
			cout << p1->get_num() << "\t" << p1->get_prev() << "\t" << *(p1->show_info()) << "\t" << p1->get_next() << "\t" << endl;
		}
		i++;
	}
	cout << endl;

	C1.pop_from_beg();
	i = 1;
	while (i <= C1.get_top())
	{
		Dack <double, 12>::Item *p1 = C1.peek(i);
		if (p1)
		{
			cout << p1->get_num() << "\t" << p1->get_prev() << "\t" << *(p1->show_info()) << "\t" << p1->get_next() << "\t" << endl;
		}
		i++;
	}
	cout << endl;

	C1.pop_from_end();
	i = 1;
	while (i <= C1.get_top())
	{
		Dack <double, 12>::Item *p1 = C1.peek(i);
		if (p1)
		{
			cout << p1->get_num() << "\t" << p1->get_prev() << "\t" << *(p1->show_info()) << "\t" << p1->get_next() << "\t" << endl;
		}
		i++;
	}
	cout << endl;

	double b123 = 6.5;
	Dack <double, 12>::Item *temp123 = new Dack <double, 12>::Item(b123);
	C1.push(*temp123);

	i = 1;
	while (i <= C1.get_top())
	{
		Dack <double, 12>::Item *p1 = C1.peek(i);
		if (p1)
		{
			cout << p1->get_num() << "\t" << p1->get_prev() << "\t" << *(p1->show_info()) << "\t" << p1->get_next() << "\t" << endl;
		}
		i++;
	}
}

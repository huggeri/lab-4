#include "templates.h" 
#include "Long_int.h"

void main()
{
	const int size = 11;
	Dack <Long_int, size> C;
	int i = 1;
	Long_int obj;
	Item <Long_int, size> *first;

	while (true)
	{
		char *str = "-12345";
		Long_int obj1(str);
		obj = obj1;
		Item <Long_int, size> *temp = new Item <Long_int, size>(obj);
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
		Item <Long_int, size> *p = C.output_item(i);
		if (p)
		{
			cout << p->num << "\t" << p->prev << "\t" << *(p->info) << "\t" << p->next << "\t" << endl;
		}
		i++;
	}
	cout << endl;

	C.pop_from_beg();
	i = 1;
	while (i <= C.get_top())
	{
		Item <Long_int, size> *p = C.output_item(i);
		if (p)
		{
			cout << p->num << "\t" << p->prev << "\t" << *(p->info) << "\t" << p->next << "\t" << endl;
		}
		i++;
	}	
	cout << endl;

	C.pop_from_end();
	i = 1;
	while (i <= C.get_top())
	{
		Item <Long_int, size> *p = C.output_item(i);
		if (p)
		{
			cout << p->num << "\t" << p->prev << "\t" << *(p->info) << "\t" << p->next << "\t" << endl;
		}
		i++;
	}
	cout << endl;

// другой тип данных
	//Dack <double, 12> C1;
	//Item <double, 12> *first1;

	//while (true)
	//{
	//	double b = 3.5;
	//	Item <double, 12> *temp1 = new Item <double, 12> (b);
	//	first1 = temp1;
	//	try
	//	{
	//		C1.push(*first1);
	//	}
	//	catch (const exception &e)
	//	{
	//		cout << e.what() << endl;
	//		delete first1;
	//		break;
	//	}
	//}

	//i = 1;
	//while (i <= C1.get_top())
	//{
	//	Item <double, 12> *p1 = C1.output_item(i);
	//	if (p1)
	//	{
	//		cout << p1->num << "\t" << p1->prev << "\t" << *(p1->info) << "\t" << p1->next << "\t" << endl;
	//	}
	//	i++;
	//}
	//cout << endl;

	//C1.pop_from_beg();
	//i = 1;
	//while (i <= C1.get_top())
	//{
	//	Item <double, 12> *p1 = C1.output_item(i);
	//	if (p1)
	//	{
	//		cout << p1->num << "\t" << p1->prev << "\t" << *(p1->info) << "\t" << p1->next << "\t" << endl;
	//	}
	//	i++;
	//}
	//cout << endl;

	//C1.pop_from_end();
	//i = 1;
	//while (i <= C1.get_top())
	//{
	//	Item <double, 12> *p1 = C1.output_item(i);
	//	if (p1)
	//	{
	//		cout << p1->num << "\t" << p1->prev << "\t" << *(p1->info) << "\t" << p1->next << "\t" << endl;
	//	}
	//	i++;
	//}
	//cout << endl;
}

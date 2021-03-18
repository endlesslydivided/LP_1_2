#include "Varparm.h"
#include "stdafx.h"
#include "Call.h"

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬ Часть из лабораторной работы номер 7 ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬
	
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

#define THROW1 "Create: превышен размер имени словаря"
#define THROW2 "Create: превышен размер максимальной ёмкости словаря"
#define THROW3 "AddEntry: переполнение словаря"
#define THROW4 "AddEntry: дубилирование идентификатора"

struct Entry
{
	int id;
	char name[ENTRYNAMEMAXSIZE];
};
struct Instance
{
	char name[DICTNAMEMAXSIZE];
	int maxsize;
	int size;
	Entry* dictionary;
};

void AddEntry(Instance& inst, Entry ed) //Память стека
{
	if (inst.size == inst.maxsize)
	{
		throw THROW3;
	}
	else
	{
		for (int i = 0; i < inst.size; i++)
		{
			if (ed.id == inst.dictionary[i].id)
			{
				throw THROW4;
			}
		}
		inst.dictionary[inst.size].id = ed.id;
		strcpy_s(inst.dictionary[inst.size].name, ed.name);
		inst.size++;
	}
}
Instance Create(char* name, int size) //Память стека
{
	if (strlen(name) > DICTNAMEMAXSIZE)
	{
		throw THROW1;//Применение структурной обработки исключений
	}
	if (size > DICTMAXSIZE)
	{
		throw THROW2;
	}
	Instance* e = new Instance; //Память из кучи
	e->maxsize = size;
	e->size = 0;
	strcpy_s(e->name, name);
	e->dictionary = new Entry[size];
	return *e;
}

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	using namespace Varparm;
	using namespace Call;
	int i_1 = 2, i_2 = 3, i_3 = 4;
	int result;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	result = ivarparm(2, 0);
	std::cout << "Значение функции ivarparm с параметрами 2: " << result << std::endl;
	result = ivarparm(2, 3, 0);
	std::cout << "Значение функции ivarparm с параметрами 2,3: " << result << std::endl;
	result = ivarparm(2, 3, 4, 0);
	std::cout << "Значение функции ivarparm с параметрами 2,3,4: " << result << std::endl;
	result = ivarparm(2, 3, 4, 5, 6, 7, 8, 0);
	std::cout << "Значение функции ivarparm с параметрами 2,3,4,5,6,7,8: " << result << std::endl << std::endl;

	result = svarparm(2, 0);
	std::cout << "Значение функции svarparm с параметрами 2: " << result << std::endl;
	result = svarparm(2, 3, 0);
	std::cout << "Значение функции svarparm с параметрами 2,3: " << result << std::endl;
	result = svarparm(2, 3, 4, 0);
	std::cout << "Значение функции svarparm с параметрами 2,3,4: " << result << std::endl;
	result = svarparm(2, 3, 4, 5, 6, 7, 8, 0);
	std::cout << "Значение функции svarparm с параметрами 2,3,4,5,6,7,8: " << result << std::endl << std::endl;

	result = fvarparm(2.1, FLT_MAX);
	std::cout << "Значение функции fvarparm с параметрами 2.1: " << result << std::endl;
	result = fvarparm(2.1, 3.1, FLT_MAX);
	std::cout << "Значение функции fvarparm с параметрами 2.1 , 3.1: " << result << std::endl;
	result = fvarparm(2.1, 3.1, 4.1, FLT_MAX);
	std::cout << "Значение функции fvarparm с параметрами 2.1 , 3.1 , 4.1: " << result << std::endl;
	result = fvarparm(2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, FLT_MAX);
	std::cout << "Значение функции fvarparm с параметрами 2.1 , 3.1 , 4.1 , 5.1 , 6.1 , 7.1 , 8.1 : " << result << std::endl << std::endl;

	result = dvarparm(2.1, FLT_MAX);
	std::cout << "Значение функции dvarparm с параметрами 2.1: " << result << std::endl;
	result = dvarparm(2.1, 3.1, FLT_MAX);
	std::cout << "Значение функции dvarparm с параметрами 2.1 , 3.1: " << result << std::endl;
	result = dvarparm(2.1, 3.1, 4.1, FLT_MAX);
	std::cout << "Значение функции dvarparm с параметрами 2.1 , 3.1 , 4.1: " << result << std::endl;
	result = dvarparm(2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, FLT_MAX);
	std::cout << "Значение функции dvarparm с параметрами 2.1 , 3.1 , 4.1 , 5.1 , 6.1 , 7.1 , 8.1 : " << result << std::endl << std::endl;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	result = cdevl(i_1, i_2, i_3);	
	std::cout << "Значение функции cdevl с параметрами 2,3,4: " << result << std::endl;
	result = cstd(i_1, i_2, i_3);
	std::cout << "Значение функции cstd с параметрами 2,3,4: " << result << std::endl;
	result = cfst(i_1, i_2, i_3);
	std::cout << "Значение функции cfst с параметрами 2,3,4: " << result << std::endl << std::endl;

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	char teachers[DICTNAMEMAXSIZE] = { "Преподаватели" };
	Instance d1 = Create(teachers, 7);
	Entry e1 = { 1,"Гладкий" };
	AddEntry(d1, e1);

//▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬

	result = defaultparm(3, 6, 9);
	std::cout << "Среднее арифметическое чисел 3,6,9,5,7: " << result << std::endl;


}


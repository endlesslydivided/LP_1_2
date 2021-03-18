#include <iostream>
#include "FST.h"
#include <clocale>
#define SIZE_STR 9
//begin	->	b
//□		->	s
//abs	->	a
//calc	->	c
//;		->	m
//pr	->	p
//return->	r
//end	->	e




void main()
{
	setlocale(LC_ALL, "Russian");
	const char* str[SIZE_STR] = { "bmracmem","bmsrsacmsem", "bmssrapmssem", "bmrapmssem", "bmrapmacmem", "bmsssssssrsssssssacmacmacmem", "bmrsapmsem", "bmrsapme","bmracmrem"};
	for (int iter = 0; iter < SIZE_STR; iter++)
	{
		FST::FST myFST(str[iter], 8,
			FST::NODE(1, FST::RELATION('b', 1)),
			FST::NODE(1, FST::RELATION('m', 2)),
			FST::NODE(4, FST::RELATION('s', 2), FST::RELATION('a', 4), FST::RELATION('e', 6), FST::RELATION('r', 3)),
			FST::NODE(2, FST::RELATION('s', 2), FST::RELATION('a', 4)),
			FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('p', 5)),
			FST::NODE(1, FST::RELATION('m', 2)),
			FST::NODE(1, FST::RELATION('m', 7)),
			FST::NODE()
		);

		if (FST::execute(myFST))
		{
			std::cout << "Цепочка " << myFST.string << " распознана." << std::endl;
		}
		else
		{
			std::cout << "Цепочка " << myFST.string << " не распознана." << std::endl;
		}
	}
	system("pause");
}
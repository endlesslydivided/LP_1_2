#pragma once
#include <iostream>
#include"stdafx.h"
namespace FST
{
	struct RELATION
	{
		char symbol; // символ перехода
		short nnode; // номер смежной вершины
		RELATION(
			char c = 0x00,
			short ns = NULL
		);
	};

	struct NODE
	{
		short n_relation; // ко-во инцидентных рёбер
		RELATION* relations; // рёбра
		NODE();
		NODE(short n,
			RELATION rel, ...
		);
	};

	struct FST
	{
		char* string; //цепочка
		short position; //позиция в цепочке
		short nstates; //кол-во состояний
		NODE* nodes; //граф перехода
		short* rstates; //возможные состояния
		FST(char* s,
			short ns,
			NODE n, ...
		);
	};

	struct CHECK_FST
	{
		int str_line;
		int position;
	};

	bool step(FST& fst, short* rstates); // разбор одного символа
	bool execute(FST& fsts);  //распонование цепочки
}
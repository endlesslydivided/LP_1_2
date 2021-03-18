#include "Dictionary.h"

namespace Dictionary
{
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
		Instance* e = new Instance; //Память из куч и
		e->maxsize = size;
		e->size = 0;
		strcpy_s(e->name, name);
		e->dictionary = new Entry[size];
		return *e;
	}

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
	void DelEntry(Instance& inst, int id) //Память стека
	{
		for (int d = 0; d < inst.size; d++)
		{
			if (inst.dictionary[d].id == id)
			{
				for (d; d < inst.size - 1; d++)
				{
					inst.dictionary[d] = inst.dictionary[d + 1];
				}
				inst.size--;
				return;
			}
		}
		throw THROW6;
	}
	Entry GetEntry(Instance& inst, int id) //Память стека
	{
		Entry e{ 0,"\0" };
		for (int d = 0; d < inst.size; d++)
		{
			if (inst.dictionary[d].id == id)
			{
				Entry e = inst.dictionary[d];
				return e;
			}
		}
		throw THROW5;
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) //Память стека
	{
		int d_element = 0;
		for (int d = 0; d < inst.size; d++)
		{
			if (inst.dictionary[d].id == id)
			{
				d_element = d;
			}
			if (inst.dictionary[d].id == new_ed.id && new_ed.id != id)
			{
				throw  THROW8;
			}
		}
		if (d_element)
		{
			inst.dictionary[d_element].id = new_ed.id;
			strcpy_s(inst.dictionary[d_element].name, new_ed.name);
			return;
		}
		throw THROW7;
	}
	void Delete(Instance& d) //Память стека
	{
		*d.name = NULL;
		d.maxsize = 0;
		d.size = 0;
		Entry* e = d.dictionary;
		delete[] e;
		d.dictionary = NULL;
	}

	void Print(Instance d) //Память стека
	{
		printf("------------- %s -------------\n", d.name);
		for (int p = 0; p < d.size; p++)
		{
			printf("%i %s \n", d.dictionary[p].id, d.dictionary[p].name);
		}
	}
}
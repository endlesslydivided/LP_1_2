#include "stdafx.h"
#include "Call.h"

namespace Call
{
	int _cdecl cdevl(int& i_1, int& i_2, int& i_3)
	{
		return i_1 * i_2 * i_3;
	}
	int _stdcall cstd(int& i_1, int i_2, int i_3)
	{
		return i_1 * i_2 * i_3;
	}
	int _fastcall cfst(int i_1, int i_2, int i_3)
	{
		return i_1 * i_2 * i_3;
	}
}
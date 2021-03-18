#pragma once

namespace Call
{
	int _cdecl cdevl(int &i_1, int& i_2, int& i_3);
	int _stdcall cstd(int &i_1, int i_2, int i_3);
	int _fastcall cfst(int i_1, int i_2, int i_3);

}
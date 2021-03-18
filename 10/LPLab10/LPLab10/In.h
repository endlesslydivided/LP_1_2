#pragma once
#define IN_MAX_LEN_TEXT 1024*1024	
#define IN_CODE_ENDL '\n'


#define IN_CODE_TABLE {\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::T, IN::F, IN::F,	IN::I, IN::F, IN::F/*15*/,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*31*/,\
	IN::T,	IN::T, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*47*/,\
	/*0*/IN::T,	IN::F, /*2*/IN::T, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*63*/,\
	IN::F,	/*A*/IN::T, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::T,	IN::F, IN::F, /*K*/IN::T, IN::F,IN::F, IN::F, IN::F/*79*/,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::T, IN::I,	'!', IN::F, IN::F, IN::F,  IN::F, IN::F, IN::F/*95*/,\
	IN::F,/*a*/IN::T, IN::F, IN::F, /*d*/IN::T,/*e*/IN::T, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F, /*l*/IN::T,IN::F, /*n*/IN::T, /*o*/IN::T/*111*/,\
	IN::F,	IN::F, /*r*/IN::T, IN::F, IN::F,	IN::F, /*v*/IN::T, IN::F,/*x*/ IN::T,IN::F, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F/*127*/,\
																													\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*143*/,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*159*/,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*175*/,\
	IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*191*/,\
/*À*/'-',IN::F, IN::F, IN::F, IN::F,IN::F, IN::F, IN::F, IN::F,	IN::F, /*Ê*/IN::T,IN::F, IN::T, IN::F, IN::T, IN::T/*207*/,\
	IN::F,  IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::F, IN::T,	IN::F, IN::F, IN::F/*223*/,\
/*à*/IN::T,	IN::F, /*â*/IN::T, IN::F, /*ä*/IN::T,/*å*/IN::T, IN::F, IN::F, IN::T,IN::T,/*ê*/ IN::T, /*ë*/IN::T, IN::F, /*í*/IN::T,/*î*/IN::T, IN::F/*239*/,\
/*ð*/IN::T,/*ñ*/IN::T, IN::T, IN::F, IN::F,IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F, IN::F,	IN::F, IN::F, IN::F/*255*/\
					}

namespace In
{
	struct IN
	{
		enum {T = 1024, F = 2048, I = 4096};
		int size;
		int lines;
		int ignor;
		unsigned char* text;
		int code[256] = IN_CODE_TABLE;
	};
	IN getin(wchar_t infile[]);
}
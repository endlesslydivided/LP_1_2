#include "stdafx.h"

using namespace std;

int add(int x, int y) { return x + y; };
//003917C0 - адрес функции
int(*f)(int, int);

int main()
{
	setlocale(LC_ALL, "Rus");

	//4
	bool trueOne = true;
	bool falseOne = false;
	bool *trueOneAdress = &trueOne;
	bool* falseOneAdress = &falseOne;

	//5
	char letter = 'A';
	char* letterAdress = &letter;

	//6
	wchar_t letterWhar = L'\x0041';
	wchar_t* letterWharAdress = &letterWhar;

	//7
	short numberShortPostive = 9 + 10;
	short numberShortNegative = -(9 + 10) ;
	short* numberShortPostiveAdress = &numberShortPostive;
	short* numberShortNegativeAdress = &numberShortNegative;
	/*
	Decimal = 19:
	19 / 16 = 1 (rest = 3);
	HEX = 0 0013;
	-HEX = 1 ffed;
	*/

	//8
	short MAXshort = SHRT_MAX;
	short MINshort = SHRT_MIN;
	/*
	HEX shortMax: 0 7F FF
	HEX shortMin: 1 80 00
	DEC shortMax: 32767
	DEC shortMin:-32768
	*/
	short* MAXshortAdress = &MAXshort;
	short* MINshortAdress = &MINshort;

	//9
	unsigned short MAXunsignedShort = USHRT_MAX;
	unsigned short MINunsignedShort = 0;
	/*
	HEX shortMax: 0 FF FF
	HEX shortMin: 0 00 00
	DEC shortMax: 32767
	DEC shortMin:-32768 
	*/
	unsigned short* MAXunsignedShortAdress = &MAXunsignedShort;
	unsigned short* MINunsignedShortAdress = &MINunsignedShort;

	//10
	int numberIntPostive = 10 + 10;
	int numberIntNegative = -(10 + 10);
	int* numberIntPostiveAdress = &numberIntPostive;
	int* numberIntNegativeAdress = &numberIntNegative;
	/*
	Decimal = 20:
	20 / 16 = 1 (rest = 4);
	HEX = 0 00 00 00 14;
	-HEX = 1 ff ff ff ec;
	*/

	//11
	int MAXint = INT_MAX;
	int MINint = INT_MIN;
	/*
	HEX intMax: 0 7F FF FF FF
	HEX intMin: 1 80 00 00 00
	DEC intMax: 2147483647
	DEC intMin:-2147483648
	*/
	int* MAXintAdress = &MAXint;
	int* MINintAdress = &MINint;

	//12
	unsigned int MAXunsignedInt = UINT_MAX;
	unsigned int MINunsignedInt = 0;
	/*
	HEX intMax: 0 FF FF FF FF
	HEX intMin: 0 00 00 00 00
	DEC intMax: 4294967295
	DEC intMin: 0
	*/
	unsigned int* MAXunsignedIntAdress = &MAXunsignedInt;
	unsigned int* MINunsignedIntAdress = &MINunsignedInt;

	//13
	long numberLongPostive = 11 + 10;
	long numberLongNegative = -(11 + 10);
	long* numberLongPostiveAdress = &numberLongPostive;
	long* numberLongNegativeAdress = &numberLongNegative;
	/*
	Decimal = 20:
	21 / 16 = 1 (rest = 5);
	HEX = 0 00 00 00 15;
	-HEX = 1 ff ff ff eb;
	*/

	//14
	long MAXlong = LONG_MAX;
	long MINlong = LONG_MIN;
	/*
	HEX longMax: 0 7F FF FF FF
	HEX longMin: 1 80 00 00 00
	DEC longMax: 2147483647
	DEC longMin:-2147483648
	*/
	long* MAXlongAdress = &MAXlong;
	long* MINlongAdress = &MINlong;

	//15
	unsigned long MAXunsignedLong = ULONG_MAX;
	unsigned long MINunsignedLong = 0;
	/*
	HEX longMax: 0 FF FF FF FF
	HEX longMin: 0 00 00 00 00
	DEC longMax: 4294967295
	DEC longMin: 0
	*/
	unsigned long* MAXunsignedlongAdress = &MAXunsignedLong;
	unsigned long* MINunsignedlongAdress = &MINunsignedLong;

	//16
	float numberFloatPostive = 1.0 + 10;
	float numberFloatNegative = -(1.0 + 10);
	float* numberFloatPostiveAdress = &numberFloatPostive;
	float* numberFloatNegativeAdress = &numberFloatNegative;
	/*
	Decimal = 11.0:
	*/
	/*11.0 = 1011 -> 1,011(+3) -> 0 10000010 01100000000000000000000 = 0100 0001 0011 0000 0000 0000 0000 0000 = 41 30 00 00(HEX)
	*/

	//17
	float numberONE_INFINITE = pow(1.3,10000);
	float numberMINUS_ONE_INFINITE = -(pow(1.3, 10000));
	float numberMINUS_ONE_INDEFINITE = numberONE_INFINITE / numberMINUS_ONE_INFINITE;
	float* numberONE_INFINITEAdress = &numberONE_INFINITE;
	float* numberMINUS_ONE_INFINITEAdress = &numberMINUS_ONE_INFINITE;
	float* numberMINUS_ONE_INDEFINITEAdress = &numberMINUS_ONE_INDEFINITE;
	/*
	INFINITY:    7F 80 00 00
	-INFINITY:   FF 80 00 00
	-INDEFINITE: FF C0 00 00
	*/
	//18
	double numberDoublePostive = 1.0 + 10;
	double numberDoubleNegative = -(1.0 + 10);
	double* numberDoublePostiveAdress = &numberDoublePostive;
	double* numberDoubleNegativeAdress = &numberDoubleNegative;

	char* letterAdressPLUS3 = letterAdress + 3;
	wchar_t* letterWharAdressPLUS3 = letterWharAdress + 3;
	short* numberShortPostiveAdressPLUS3 = numberShortPostiveAdress + 3;
	short* numberShortNegativeAdressPLUS3 = numberShortNegativeAdress + 3;
	int* numberIntPostiveAdressPLUS3 = numberIntPostiveAdress + 3;
	int* numberIntNegativeAdressPLUS3 = numberIntNegativeAdress + 3;
	float* numberFloatPostiveAdressPLUS3 = numberFloatPostiveAdress + 3;
	float* numberFloatNegativeAdressPLUS3 = numberFloatNegativeAdress + 3;
	double* numberDoublePostiveAdressPLUS3 = numberDoublePostiveAdress + 3;
	double* numberDoubleNegativeAdressPLUS3 = numberDoubleNegativeAdress + 3;
	/*
	CHAR*:         41  
	WCHAR_T*:      41 00 (0x012FFAAC)
	SHORT*:        13 00 (NEGATIVE: ed ff)
	INT*:          14 00 00 00 (NEGATIVE:ec ff ff ff)
	FLOAT*:        00 00 30 41  (NEGATIV: 00 00 30 c1)
	DOUBLE*:       00 00 00 00 00 00 26 40 (NEGATIVE:00 00 00 00 00 00 26 c0)
	*/
	/*
	CHAR* +3:      СС 
	WCHAR_T* +3:   СС 
	SHORT* +3:     13 00 (NEGATIVE: ed ff)
	INT* +3:       14 00 00 00 (NEGATIVE:ec ff ff ff)
	FLOAT* +3:     00 00 30 41  (NEGATIV: 00 00 30 c1)
	DOUBLE* +3:    00 00 00 00 00 00 26 40 (NEGATIVE:00 00 00 00 00 00 26 c0)
	*/
	

	//19
	f = add;
	int resultAdd = f(10, 11);
	printf("Сумма равна:%i \a\n", resultAdd);
	printf("Размер указателя на функцию - %d байта\n", sizeof(f));
	
	/*
	Размер указателя на функцию равен 4 байта.
	*/

	//20
	char &Rletter = letter;
	wchar_t &RletterWhar = letterWhar;
	short &RnumberShortPostive = numberShortPostive;
	int &RnumberIntPostive = numberIntPostive;
	float &RnumberFloatPostive = numberFloatPostive;
	double &RnumberDoublePostive = numberDoublePostive;
	
/*
CHAR&:        0x00effbab     
WCHAR_T&:     0x00effb90    
SHORT&:       0x00effb78 
INT&:         0x00effae8 
FLOAT&:       0x00eff9c8
DOUBLE&:      0x00eff94c 
*/
	return 0;

/*
1.Фундаментальные типы - это базовые типы, которые могут хранить стандартные необходимые значения:символы, числа с фиксированной и плавающей точкой, булевы значения и т.д.
2.Фундаментальные типы: int, float,double,short,char,bool,wchar_t,long
3.sizeof()
5.Для переменной типа bool отводится 1 байт
6.Для переменной типа char отводится 1 байт
7.Для переменной типа wchar_t отводится 2 байта
8.Для переменной типа short отводится 2 байта
9.Для переменной типа int или long отводится 4 байта
10.Для переменной типа unsigned short отводится 2 байта
11.Для переменной типа unsigned int или unsigned long отводится 4 байт
12.Для переменной типа float отводится 4 байт
13.Для переменной типа double отводится 8 байт
14.Стандарт представления чисел с плавающей точкой позволяет хранить переменные с определённой точностью
15.1.#INF - положительная бесконечность, 1.#IND - положительная неопределённость.
16.Ссылка и указатель занимают 4 байта в памяти
17.Инвертированные значение положительных чисел в 16-представлении являются их отрицательными значениями. На знак числа указывает минус перед его шестнадцатеричным представлением
18.LE - прямой порядок следования байт
*/
}
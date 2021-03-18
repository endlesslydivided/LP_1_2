#include "stdafx.h" 

using namespace std;

char lf[] = "KovalevAlex2002";

/*KovalevAlex2002*/

/*4B 6f 76 61 6C 65 76   41 6C 65 78   32 30 30 32*/
/*004B 006f 0076 0061 006C 0065 0076 	 0041 006C 0065 0078   0032 0030 0030 0032*/
/* 004B 006F 0076 0061 006C 0065 0076    0041 006C 0065 0078    0032 0030 0030 0032 */

char rf[] = "КовалевАлександр2002";

/*КовалевАлександр2002*/

/*CA EE E2 E0 EB E5 E2    C0 EB E5 EA F1 E0 ED E4 F0    32 30 30 32*/
/*D09A D0BE D0B2 D0B0 D0BB D0B5 D0B2	 D090 D0BB D0B5 D0BA D181 D0B0 D0BD	D0B4 D180	0032 0030 0030 0032*/
/*041A 043E 0432 0430 043B 0435 0432     0410 043B 0435 043A 0441 0430 043D 0434 440	 0032 0030 0030 0032*/

/*041A = 1041(10) = 1101 0000 1001 1010(2) = D09A*/
/*043Е = 1082(10) = 1101 0000 1011 1110(2) = D0BE*/

char lr[] = "Ковалев2002Alex";

/*Ковалев2002Alex*/

/*CA EE E2 E0 EB E5 E2   32 30 30 32   41 6C 65 78 */
/*D09A D0BE D0B2 D0B0 D0BB D0B5 D0B2    0032 0030 0030 0032    0041 006C 0065	0078 */
/* 041A 043E 0432 0430 043B 0435 0432    0032 0030 0030 0032    0041 006C 0065 0078 */

wchar_t Llp[] = L"KovalevAlex2002";
wchar_t Lrf[] = L"КовалевАлександр2002";
wchar_t Llr[] = L"Ковалев2002Alex";

char* UpperW1251(char* source);

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian");
	char source[] = "1sdfПВАНйцгшщз2345";
	char destination[20] ;
	strcpy_s(destination,source);
	UpperW1251(destination);

	cout << destination << endl;

	system("pause");
	return 0;
}

char* UpperW1251(char* destination)
{
	
	const int length = strlen(destination);
	for (int i = 0; i < length; i++)
	{
		if (destination[i] >= 57 || destination[i] <= 48)
		{
			destination[i] = destination[i] - 32;
		}
	}
	return destination;
}
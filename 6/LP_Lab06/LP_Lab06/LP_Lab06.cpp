#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;


#define MAX 100

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

typedef unsigned int index;
typedef char  country[MAX];
typedef char  settlement[MAX];
typedef char  street[MAX];


struct Date
{
	day dd;
	month mm;
	year yyyy;

};
bool operator < (Date date1, Date date2)
{
	return ((date1.yyyy < date2.yyyy) || (date1.yyyy == date2.yyyy && date1.mm < date2.mm) || (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd));
}
bool operator > (Date date1, Date date2)
{
	return (!((date1.yyyy < date2.yyyy) || (date1.yyyy == date2.yyyy && date1.mm < date2.mm) || (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd < date2.dd)));
}
bool operator == (Date date1, Date date2)
{
	return (date1.yyyy == date2.yyyy && date1.mm == date2.mm && date1.dd == date2.dd);
}

struct Post_Adress
{
	index ind;
	country con;
	settlement set;
	street st;	
};
bool operator == (Post_Adress post1, Post_Adress post2)
{
	return (post1.ind == post2.ind && !strcmp(post1.con, post2.con) && !strcmp(post1.set, post2.set) && !strcmp(post1.st, post2.st));
}
int operator += (Post_Adress post1, int p)
{
	return post1.ind += p;
}
int main()
{
	setlocale(LC_ALL, "Rus");

	Date date1 = {7,1,1980};
	Date date2 = {7,2,1993};
	Date date3 = {7,1,1980};

	printf("Работа со структурой 'Date':\n");

		
	if (date1 < date2) cout << "Истина" << endl;
	else cout << "Ложь" << endl;


	if (date1 > date2) cout << "Истина" << endl;
	else cout << "Ложь" << endl;

	if (date1 == date2) cout << "Истина" << endl;
	else cout << "Ложь" << endl;

	if (date1 == date3) cout << "Истина" << endl;
	else cout << "Ложь" << endl;

	Post_Adress adress1 = { 213130,"Беларусь","Минск","Свердлова"};
	Post_Adress adress2 = { 213130,"Россия","Москва","Новый Арбат" };
	Post_Adress adress3 = { 213130,"Беларусь","Минск","Свердлова" };


	printf("Работа со структурой 'Post_Adress':\n");

	if (adress1 == adress2) cout << "Адреса идентичны" << endl;
	else cout << "Адреса различаются" << endl;

	if (adress3 == adress1) cout << "Адреса идентичны" << endl;
	else cout << "Адреса различаются" << endl;

	cout << "Индекс №1:" << adress1.ind << endl;
	adress1 += 123456;
	cout << "Индекс №1 (изменённый):" << adress1.ind;
}
#include <iostream>
#include <iomanip>
using namespace std;

int leap_year(int);
int whichday(int, bool);

int main()
{
	setlocale(LC_ALL, "Russian");
	int date, choose, day, month, check = 0; bool onezero;
	int closing[3] = {31,0,12};
	do
	{
		if (check > 0)
		{
			printf("Введена неправильная дата!\n");
		}
		printf("Введите дату в формате ДДММГГГГ: "); cin >> date;
		onezero = leap_year(date);
		day = ((date % 100000000) / 1000000), month = ((date % 1000000) / 10000);
		check = 1;
	} while (date <= 0 || closing[2]< month <closing[3] || (day > 31 && month % 2 != 0) || (day > 30 && month % 2 == 0 && month !=8) || ((day > 28 && month == 2 && !onezero) || (day > 29 && month == 2 && onezero)) || date > 999999999 || month == 0 || day == 0);

	do
	{
		printf("\nВыберите необходимую функцию: ");
		printf("\n1- Високосный ли этот год?\n2- Какой день это по порядку в году?\n0- Выход\n"); cin >> choose;
		switch (choose)
		{
		case 1:
			if (onezero)
			{
				printf("Это високосный год.\n");
			}
			else
			{
				printf("Это обычный год. \n ");
			}
			break;
		case 2: 
			day = whichday(date, onezero);
			printf("Это %i-й день в году.\n ", day); break;
		case 0: break;
		}
	} while (choose != 0);
	system("pause");
	return 0;
}

int leap_year(int date)
{
	if ((date % 10000) % 4 != 0)
	{
		return 0;
	}
	else
	{
		if ((date % 10000) % 100 == 0 && (date % 10000) % 400 != 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

int whichday(int date, bool onezero)
{
	int day = ((date % 100000000) / 1000000);
	int quantity_month = ((date % 1000000) / 10000) - 1;
	if (onezero)
	{
		for (quantity_month; quantity_month > 0; quantity_month--)
		{
			if (quantity_month == 8)
			{
				day += 31;
			}
			else if (quantity_month == 2)
			{
				day += 29;
			}
			else if (quantity_month % 2 == 0)
			{
				day += 30;
			}
			else if (quantity_month % 2 != 0)
			{
				day += 31;
			}
		}
	}
	else
	{
		for (quantity_month; quantity_month > 0; quantity_month--)
		{
			if (quantity_month == 8)
			{
				day += 31;
			}
			else if (quantity_month == 2)
			{
				day += 28;
			}
			else if (quantity_month % 2 == 0)
			{
				day += 30;
			}
			else if (quantity_month % 2 != 0)
			{
				day += 31;
			}
		}
	}
	return day;
}



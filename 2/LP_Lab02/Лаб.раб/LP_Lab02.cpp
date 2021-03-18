#include "stdafx.h"


int sum(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
using namespace std;

int main()
{
	cout << "sum(2,3) = " << sum(2, 3) << endl;
	cout << "sub(2,3) = " << sub(2, 3) << endl;
	cout << "mul(2,3) = " << mul(2, 3) << endl;

	system("pause");
	return 0;
}
#include "Varparm.h"
#include "stdafx.h"

namespace Varparm
{
	int ivarparm(int i, ...)
	{
		int* pointer = &i;
		int result = 1;
		for (int iter = 1; *(pointer + iter) != NULL; iter++)
		{
			result *= *(pointer + iter);
		}
		if (result == 1) return 0;
		return result;
	}
	int svarparm(short s, ...)
	{
		int* pointer = (int*)&s;
		int result = 1;
		for (int iter = 1; *(pointer + iter) != NULL; iter++)
		{
			result *= *(pointer + iter);
		}
		if (result == 1) return 0;
		return result;
	}
	double fvarparm(float f, ...)
	{
		double* pointer = (double*)(&f + 1);
		double result = f;
		for (int iter = 0; *(pointer + iter) != FLT_MAX; iter++) result += *(pointer + iter);
		return result;
	}
	double dvarparm(double d, ...)
	{
		double* pointer = (double*)(&d + 1);
		double result = d;
		for (int iter = 0; *(pointer + iter) != FLT_MAX; iter++) result += *(pointer + iter);
		return result;
	}
	int defaultparm(int a, int b, int c, int d, int e)
	{
		return (a + b + c + d + e) / d;
	}
}
#pragma once

namespace Varparm 
{
	int ivarparm(int i, ...);
	int svarparm(short s, ...);
	double fvarparm(float f, ...);
	double dvarparm(double d, ...);
	int defaultparm(int a, int b, int c, int d = 5, int e = 7);
}
#include"mathutils.h"
#include"vec2.h"

#include<cassert>
#include<iostream>

using namespace std;

int main()
{
	/*
	cout << min(3,1) << endl;

	vec2 test;
	test.x = 5;
	test.y = 20;
	
	vec2 testB;
	testB.x = 13;
	testB.y = 4;

	vec2 result = test + testB;

	vec2 num;
	num.x = 0;
	num.y = 0;

	num += test;

	bool eq = num == test;
	bool ieq = num == testB;
	*/

	//==CLOSED==

	// 1. Common Arithmetic Operators

	vec2 a{ 2,5 };
	vec2 b{ 4,8 };
	vec2 result;
	result = a - b;
	result = 2 * a;
	result = b / 2;
	result = b;
	//result = -result;

	

	// 2. Common Logical Operators

	bool eq = result == b;
	bool ieq = result != b;

	//==OPEN==

	// 1. Compound Assignment Operators
	a += b;
	a -= b;
	b *= 3;
	b /= 3;

	// 2. Subscript Operator

	b[1];

	// 3. Utility Functions
	vec2 d{ 2,3 };
	vec2 c{ 7,5 };
	// Magnitude
	mag(c);

	// Normal
	vec2 normalizeC = nrm(c);
	cout << normalizeC.x << "," << normalizeC.y << endl;

	// Dot
	cout << dot(c, d) << endl;


	while(true){}
}
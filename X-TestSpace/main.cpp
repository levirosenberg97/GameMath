#include"mathutils.h"
#include"vec2.h"
#include"vec3.h"
#include "mat3.h"

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

	//// 1. Common Arithmetic Operators

	//vec2 a{ 2,5 };
	//vec2 b{ 4,8 };
	//vec2 result;
	//result = a - b;
	//result = 2 * a;
	//result = b / 2;
	//result = b;
	////result = -result;

	//

	//// 2. Common Logical Operators

	//bool eq = result == b;
	//bool ieq = result != b;

	////==OPEN==

	//// 1. Compound Assignment Operators
	//a += b;
	//a -= b;
	//b *= 3;
	//b /= 3;

	//// 2. Subscript Operator

	//b[1];

	//// 3. Utility Functions
	//vec2 d{ 2,3 };
	//vec2 c{ 7,5 };
	//// Magnitude
	//mag(c);

	//// Normal
	//vec2 normalizeC = nrm(c);
	//cout << normalizeC.x << "," << normalizeC.y << endl;

	//// Dot
	//cout << dot(c, d) << endl;

	//vec3 a{ 2,2,1 };
	//vec3 b{ 2,2,1 };
	//vec3 result;
	//bool eq;


	//result = a + b;
	//cout << result.x << ", " <<result.y <<", "<< result.z << endl;
	//
	//result = a - b;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = a * 2;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = 3 * a;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = a / 2;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = -a;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//eq = a == result;
	//cout << eq << endl;

	//result -= a;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result += a;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = -result;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result *= 4;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result /= 2;
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = { 0,1,0 };

	//cout << mag(result) << endl;

	//result = { 1,1,1 };
	//vec3 normaliz = nrm(result);
	//cout << normaliz.x << ", " << normaliz.y << ", " << normaliz.z << endl;

	//a = { 1,1,0 };
	//b = { 1,0,0 };
	//cout << dot(a, b) << endl;

	//cout << dist(a, b) << endl;

	//result = min(a, b);
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//result = max(a, b);
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	//b = { 1,2,0 };
	//vec3 c = { 8,2,8 };

	//result = clmp(c, a, b);
	//cout << result.x << ", " << result.y << ", " << result.z << endl;

	mat3 I = mat3::identity();
	mat3 Z = mat3::zero();
	mat3 A = { 1,2,3,4,5,6,7,8,9 };
	vec3 v = { 1,2,3 };


	assert(I + Z == I);
	assert(Z + I == I);
	assert(I - Z == I);
	assert(A*I == A);
	assert(A*I == A);
	assert(I*v == v);

	mat3 T = scale(vec2{ 1,2 });
	T = T * rotate(90);
	T = T * translate(vec2{ 3,0 });
 	assert((T[2] == vec3{ 0,6,1 }));

	while(true){}
}
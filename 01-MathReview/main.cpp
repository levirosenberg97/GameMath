#include "mathutils.h"
#include<iostream>

using namespace std;

int main()
{
	//==CLOSED==


	//1. Double Function

	float value = dbl(23);

	cout << value << endl;

	//2. Cube Function
	value = cube(3);

	cout << value << endl;

	//3. Degrees to Radians
	value = degToRad(180);

	cout << value << endl;

	//4. Radians to Degrees

	cout << radToDeg(4.712389) << endl;


	//==OPEN==

	//1. Basic Quadratic

	cout << quad(5) << endl;

	//2. Linear Blend

	cout << lin(0, 10, 1) << endl;

	//3. Distance

	cout << dist(5, 5, 7, 7) << endl;

	//==CHALLENGE==

	//1. Plane-Point Distance

	cout << ppDis(2, -2, 5, 8, 4, -4, 3) << endl;

	//2.Cubic Bezier
	cout << cbez(5,.8,.3,.2,.3) << endl;

	//3.Quadratic

	cout << quadNeg(1, -3, -4) << endl;

	cout << quadPos(1, -3, -4) << endl;

	while (true){}
}
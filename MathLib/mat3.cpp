#include "mat3.h"


float determinant(const mat3 & A)
{
	float det = 0;
	for (int i = 0; i < 3; i++)
	{
		det = det + (A.mm[0][i] * (A.mm[1][(i + 1) % 3] * A.mm[2][(i + 2) % 3] - A.mm[1][(i + 2) % 3] * A.mm[2][(i + 1) % 3]));
	}
	return det;
}

mat3 inverse(const mat3 & A)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			((A.mm[(j + 1) % 3][(i + 1) % 3] * A.mm[(j + 2) % 3][(i + 2) % 3]) - (A.mm[(j + 1) % 3][(i + 2) % 3] * A.mm[(j + 2) % 3][(i + 1) % 3])) / determinant(A);
		}
	}
}

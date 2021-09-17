#include <iostream>
#include "matrix.h"

using namespace matrix;
int main()
{
	Matrix* matrix = nullptr;
	int C, R;
	std::cout << "Enter number of lines in matrix " << std::endl;
	do {
		if (get(R) < 0)
			return 1;//eof
		if (R <= 0) std::cout << "The number of lines cannot be negative or zero! " << std::endl;
	} while (R <= 0);

	std::cout << "Enter number of columns in matrix " << std::endl;
	do {
		if (get(C) < 0)
			return 1;//eof
		if (C <= 0) std::cout << "The number of columns cannot be negative or zero! " << std::endl;
	} while (C <= 0);
	try {
		matrix = new Matrix;
	}
	catch (std::bad_alloc& ba)
	{
		return 1; //allocation error
	}
	if (inputMatrix(matrix, R, C) < 0)
	{
		deletion(matrix, R);
		return 1;
	}
	print(matrix);
	if (formVector(matrix) < 0)
	{
		deletion(matrix, R);
		return 1;
	}
	deletion(matrix, R);
	return 0;
}	
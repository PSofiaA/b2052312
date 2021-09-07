#pragma once 
namespace matrix
{
	struct Node {
		int column;
		double element;
		struct Node* next;
	};
	struct Matrix {
		int TotalRows;
		int TotalColumns;
		Node** line;
	};
	template <typename Type>
	int get(Type& x)
	{
		while (true)
		{
			std::cin >> x;
			if (std::cin.eof())
				return -1;
			else if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(32767, '\n');
				std::cout << "Input error. Try again\n";
			}			
			else
				return 0;
		}
	}
	
	int inputNode(Node*& n, double element, int C);
	int inputMatrix(Matrix* m, int R, int C);
	void print(Matrix* m);
	void deletion(Matrix* m, int R);
	double arithmetical_mean(Matrix* m, int R);
	double func_ci(Matrix* m, int R);
	int formVector(Matrix* m);
	void printV(double* vector, int R);
}
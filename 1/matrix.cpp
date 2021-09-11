#include <iostream>
#include "matrix.h"

namespace matrix
{
	void printV(double* vector, int R)
	{
		for (int i = 0; i < R; i++)
		{
			std::cout << i + 1 << "st element--> " << vector[i] << std::endl;
		}
		std::cout << std::endl;
	}
	int inputNode(Node*& n, double element, int C)
	{
		try
		{
			n = new Node();
			n->column = C;
			n->element = element;
			n->next = nullptr;
			return 0;//all fine
		}
		catch (std::bad_alloc& ba)
		{
			return -1; //allocation error
		}
	}
	int inputMatrix(Matrix* m, int R, int C)
	{
		m->TotalColumns = C;
		m->TotalRows = R;
		try
		{
			m->line = new Node * [R]();
		}
		catch (std::bad_alloc& ba)
		{
			return -1; //allocation error
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				std::cout << "Line " << i + 1 << " Enter element for " << j + 1 << "st column ->> " << std::endl;
				double el;
				if (get(el) < 0)
					return -2;
				if (el != 0) //особенность разреженной матрицы в том что записываются только ненулевые элементы
				{
					Node* ptr = nullptr;
					if (inputNode(ptr, el, j) != 0)
					{
						deletion(m, i + 1);
						return -1;
					}
					if (!m->line[i])
						m->line[i] = ptr;
					else
					{
						Node* tmp = m->line[i];
						while (tmp->next)
						{
							tmp = tmp->next;
						}
						tmp->next = ptr;
					}
				}

			}
		}
		return 0;
	}

	void print(Matrix* m)
	{
		for (int i = 0; i < m->TotalRows; i++)
		{
			std::cout << "Line " << (i + 1) << "->> ";
			Node* tmp = m->line[i];
			int x = 0;
			for (int j = 0; j < m->TotalColumns; j++)
			{
				if (tmp && tmp->column == x)
				{
					std::cout << tmp->element << "  ";
					tmp = tmp->next;
				}
				else
				{
					std::cout << "0" << "  ";
				}
				x++;
			}
			std::cout << std::endl;
		}
	}
	void deletion(Matrix* m, int R)
	{
		for (int i = 0; i < R; i++)
		{
			Node* tmp = m->line[i];
			Node* tmp2 = nullptr;
			while (tmp)
			{
				tmp2 = tmp;
				tmp = tmp->next;
				delete tmp2;
			}
		}

		delete[]m->line;
		delete m;
	}
	double arithmetical_mean(Matrix* m, int R)
	{
		double sum = 0, res = 0;
		Node* tmp = m->line[R];
		while (tmp)
		{
			sum += tmp->element;
			tmp = tmp->next;
		}
		res = sum / m->TotalColumns;
		return res;
	}
	double func_ci(Matrix* m, int R)
	{
		double res = 0, max = 0;
		Node* tmp = m->line[R];
		if (tmp && tmp->column == 0) //первый элемент ненулевой (ищем максимум
		{
			while (tmp)
			{
				if (res < tmp->element)
					res = tmp->element;
				tmp = tmp->next;
			}
		}
		else if (tmp) //первый элемент нулевой
		{
			res = tmp->element;
			tmp = tmp->next;
		}
		std::cout << res << std::endl;
		return res;
	}
	int formVector(Matrix* m)
	{
		int R = m->TotalRows;
		int C = m->TotalColumns;
		double numerator, denominator;
		double* vector = nullptr;
		try {
			vector = new double[R];
		}
		catch (std::bad_alloc& ba)
		{
			deletion(m, R);
			return -1; //allocation error
		}
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				Node* tmp = m->line[i];
				while (tmp) {
					numerator = arithmetical_mean(m, i);
					denominator = func_ci(m, i);
					vector[i] = numerator / denominator;
					tmp = tmp->next;
				}
			}
		printV(vector, R);
		delete[] vector;
		return 0;
	}
}

#pragma once
#include "Header.h"

//swaps the contents of 2 integers
inline void swap(int&i, int&j)
{
	int temp = i;
	i = j;
	j = temp;

}

//rotates table in place
void rotate(int table[TABLE][TABLE]) //https://www.youtube.com/watch?v=Jtu6dJ0Cb94 for details (not mine)
{
	int last = TABLE - 1;
	int TNOL = TABLE / 2;

	int level = 0;
	while (level < TNOL)
	{
		for (int i = level; i < last; ++i)
		{
			swap(table[level][i], table[i][last]);
			swap(table[level][i], table[last][last - i + level]);
			swap(table[level][i], table[last - i + level][level]);
		}
		++level;
		--last;
	}
	last = TABLE - 1;
}


//flips solution horizontally
void FML(int table[TABLE][TABLE]) //flip matrix horizontally and not the other FML meaning
{
	std::cout << "table before" << std::endl;
	Table_stuff::out(table);
	for (int i = 0; i < TABLE / 2; ++i)
	{

	}

}

//checks if solution is unique or not
//unique: not a mirror and/or rotataion of a previous one
bool unique()
{
//TODO

	return true;
}
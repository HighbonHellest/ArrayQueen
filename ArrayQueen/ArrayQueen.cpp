// ArrayQueen.cpp : Defines the entry point for the console application.
//

/*TODO:
Solve:basic
Solve:backtmed (rotated)
Solve:advanced(mirrored and rotated)
proper SOC (separation of concerns)
proper OCP (open - close principle)

*/
/*
megoldás ötlet. Leteszek egy királynőt. összeszámolom a lehetséges, maradék helyeket ahová tehetek még.
ez n darab. -> a táblának van n darab örököse. Mind az összes örökösre leteszek egy királynőt.
vissza az elejére.

addig amíg: le nincs téve a 8 királynő vagy nincs több hely


solving idea. place one queen, take into account all of the remaining places where a queen can be placed.
that's N number. -> the table has N number of "inherited". To all of these child tables put down a queen.
back to square 1.
as long as there are no places left, OR all queens have been placed

*/

#include "stdafx.h"
#include "Header.h"


namespace Table_stuff
{
	//swaps the contents of 2 integers
	void swap(int&i, int&j)
	{
		int temp = i;
		i = j;
		j = temp;

	}

	

	//class for a table. Holds it's conents.
	struct my_table
	{
		int table[TABLE][TABLE];
		int last = TABLE - 1;
		int TNOL = TABLE / 2;
		void rotate() //https://www.youtube.com/watch?v=Jtu6dJ0Cb94 for details (not mine)
		{
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
		//XY is the palce of the QUEEN!!!!
	};


	//gives properties to the table \\ probably should use class(){0} tbh
	void fill(my_table &A)
	{
		//int count = 0;
		for (int i = 0; i < TABLE; ++i)
		{
			for (int j = 0; j < TABLE; ++j)
			{
				A.table[i][j] = FREE;
			//	++count;
			}
		}
		//count = 0;
	};

	//sets contents of a table to 0
	void reset(int A[TABLE][TABLE])
	{
		for (int i = 0; i < TABLE; ++i)
		{
			for (int j = 0; j < TABLE; ++j)
			{
				A[i][j] = FREE;
				//++count;
			}
		}
	};
	//table copy
	//copies A into B, returns B
	auto CopyTable(int A[TABLE][TABLE], int B[TABLE][TABLE])
	{
		for (int i = 0; i < TABLE; ++i)
		{
			for (int j = 0; j < TABLE; ++j)
			{
				B[i][j] = A[i][j];
			}
		}

	}

	//solves the queen problem for a specific placement of 1 or more queens || D is the number of queens that are down
	void solve_for(int A[TABLE][TABLE], int D = 0)
	{
		int Q = 0;
		//std::cout << "belépek";
		//lehetséges lépések listája
		//list of possible placements
		std::list <std::pair<int, int>> possible_placements;

		//look for new depth placenets.
		for (int i = 1; i <= TABLE; ++i)
		{

			for (int j = 1; j <= TABLE; ++j)
			{
				if (A[i-1][j-1] == FREE)
				{

					possible_placements.emplace_back(i,j);				
				}			
				if (A[i - 1][j - 1] == QUEEN)
				{
					//std::cout << "itt";
					Q++;
				}
			}
		}
		
		//if non found go back
		if (possible_placements.size() == 0)
		{	
			//std::cout << "asd";
			if (Q == TABLE)
			{
				std::cout << Q << " queens have been found" << std::endl;
				out(A);
			}
			
			return;
		}
		int temp[TABLE][TABLE];
		//take the possibe step
		for (auto it = possible_placements.begin(); it != possible_placements.end(); ++it)
		{
			//create and manage temp table, so that next cycle gets a clean table
			
			
			CopyTable(A, temp);
			//hit @ value of it

			HIT(temp, *it);
			solve_for(temp);


		}





	};
	//---solv f end
	


	

}
	

	int main()
	{
		auto start = std::chrono::steady_clock::now();
		Table_stuff::my_table *table = new Table_stuff::my_table();
		

		Table_stuff::fill(*table);
		



		// a 0 a sorok az 1 az oszolopok
		//									pos   0: ,pos  1:
		/*HIT(table->table,std::pair<int,int>(      8,       8 ));*/



		int tab[8][8];
		fillh(tab);
		tab[0][2] = QUEEN;
		tab[1][5] = QUEEN;
		tab[2][7] = QUEEN;
		tab[3][0] = QUEEN;
		tab[4][3] = QUEEN;
		tab[5][6] = QUEEN;
		tab[6][4] = QUEEN;
		tab[7][1] = FREE;
		//Table_stuff::out(tab);

		//Table_stuff::solve_for(tab);
	

		Table_stuff::solve_for(table->table);

		auto end = std::chrono::steady_clock::now();
		auto diff = end - start;
		std::cout << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;

		std::cout << "waiting for input to end";
		std::getchar();

		return 0;
	}


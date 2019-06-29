#pragma once
#include "Header.h"

//bugfixed
void hit_left(int table[TABLE][TABLE], std::pair<int, int> XY)
{
	
	if (std::get<1>(XY) <= 0)
	{
		return;
	}
	else
	{

	
		
		//az 1 az columns, a 0 a rows.
		if(table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] != QUEEN)
			table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] = HITTED;
		//::Table_stuff::out(table);
		//std::cout << "put to:" << std::get<0>(XY) -1 << " " << std::get<1>(XY)-1 << std::endl;
		hit_left(table ,{ std::get<0>(XY), --std::get<1>(XY) }); //balra ütés
	}

};



//ütéspédda 3,2 -> a 2. sorban, üti a 3. helyet
//hit eg. 3,2 -> 2. row 3. column
void hit_down(int table[TABLE][TABLE],  std::pair<int, int> XY) // works as intended don't touch it!
{


	if (std::get<0>(XY) > TABLE)
	{
		return;
	}
	else
	{
		if (table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] != QUEEN)
			table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] = HITTED;
		//::Table_stuff::out(table);
		//std::cout << "put to:" << std::get<0>(XY) -1 << " " << std::get<1>(XY)-1 << std::endl;
		hit_down(table,{ ++std::get<0>(XY), std::get<1>(XY) });
	}

};

//X
void hit_up_right(int table[TABLE][TABLE], std::pair<int, int >XY) //looks good 
{
	if (std::get<0>(XY) <= 0 || std::get<1>(XY) < 0 || std::get<0>(XY) > TABLE || std::get<1>(XY) > TABLE)
	{
		return;
	}
	else
	{
		if (table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] != QUEEN)
			table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] = HITTED;
		hit_up_right(table,{ --std::get<0>(XY), ++std::get<1>(XY) });
	}

};
void hit_up_left(int table[TABLE][TABLE], std::pair<int, int> XY)
{
	if (std::get<0>(XY) <= 0 || std::get<1>(XY) <= 0)
	{
		return;
	}
	else
	{
		if (table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] != QUEEN)
			table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] = HITTED;
		hit_up_left(table,{ --std::get<0>(XY), --std::get<1>(XY) });
	}
}
void hit_down_right(int table[TABLE][TABLE], std::pair<int, int>XY)
{
	if (std::get<0>(XY) > TABLE || std::get<1>(XY) > TABLE)
	{
		return;
	}
	else
	{
		if (table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] != QUEEN)
			table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] = HITTED;
		//::Table_stuff::out(table);
		//std::cout << "put to:" << std::get<0>(XY) -1 << " " << std::get<1>(XY)-1 << std::endl;
		hit_down_right(table,{ ++std::get<0>(XY), ++std::get<1>(XY) });
	}
}
void hit_down_left(int table[TABLE][TABLE], std::pair<int, int>  XY)
{
	if ((std::get<0>(XY) < 1 || std::get<0>(XY) > TABLE) || std::get<1>(XY) < 1)
	{
		return;
	}
	else
	{
		if (table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] != QUEEN)
			table[std::get<0>(XY) - 1][std::get<1>(XY) - 1] = HITTED;
		hit_down_left(table,{ ++std::get<0>(XY), --std::get<1>(XY) });
	}
}

//X and + united
void hit_cross(int table[TABLE][TABLE], std::pair<int, int> XY)
{
	hit_up_left(table, XY); //good | does not cause stack corruption
	
	hit_up_right(table, XY); //good
	hit_down_left(table, XY); //good
	hit_down_right(table, XY);  //good

};
void hit_lines(int table[TABLE][TABLE], std::pair<int, int> XY) // works as intended don't touch it!
{
	//az 1 az oszolopok, a 0 a sorok. a csalás az az, hogy egyből a tábla méretre állítom
	//így nem kell függvényt írni arra, hogy jobbra is legyen ütés.
	//működik!
	auto temp = XY;
	temp.second = TABLE;
	hit_left(table, temp);
	//----------------------------------------------------

	temp = XY;
	temp.first = 1;
	hit_down(table, temp);
}
//all
void HIT(int table[TABLE][TABLE], std::pair<int, int> XY)
{
	
	///seems good
	hit_lines(table, XY);
	
	///causes stack corruption error
	hit_cross(table,XY);
	
	
	//királynő helyezése UTOLJÁRA
	//placing the queen as LAST
   	table[std::get<0>(XY)-1][std::get<1>(XY)-1] = QUEEN;

}


void fillh(int table[TABLE][TABLE])
{
	int count = 0;
	for (int i = 0; i < TABLE; ++i)
	{
		for (int j = 0; j < TABLE; ++j)
		{
			table[i][j] = HITTED;
			++count;
		}
	}
	count = 0;
};
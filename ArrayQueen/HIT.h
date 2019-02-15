#pragma once
#include "Header.h"
#include <tuple>


#define TABLE  8
#define QUEEN 81
#define FREE 48
#define HITTED 104

	//x = oszlop, y = sor belfelso sarokbol origo.
	//---------basic stuff-------------

namespace Table_stuff
{

	void hit_left(struct my_table &table, std::tuple<int, int> XY)
	{
		/*if ( std::get<0>(XY) < 0 || std::get<1>(XY) < 0)
		{
			throw "Bad_argument_exception";
		}
		else
		{
			for (int i = std::get<0>(XY); i >= 0; --i)
			{

			}
		}*/

	};

	/*void hit_right( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};

	void hit_up( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};
	void hit_down( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};
	void hit_upleft( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};
	void hit_upright( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};
	void hit_dleft( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};
	void hit_dright( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
	};
	//-----------consolidated------------
	void hitupd( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}

		hit_up(table, XY);
		hit_down(table, XY);
	};

	void hlr( my_table &table, std::pair<int,int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
		hitleft(table, XY);
		hit_right(table, XY);

	};

	void hitX( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}

		hit_up(table, XY);
		hit_upright(table, XY);
		hit_dleft(table, XY);
		hit_dright(table, XY);
	};
	//---------final------------
	void HIT( my_table &table, std::pair<int, int> XY)
	{
		if (XY.first < 0 || XY.second < 0)
		{
			throw "Bad_argument_exception";
		}
		hitupd(table, XY);
		hlr(table, XY);
		hitX(table, XY);
	};


	*/
}
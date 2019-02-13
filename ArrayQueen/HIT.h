#pragma once
#include "Header.h"


namespace table_stuff
{
	//---------basic stuff-------------
	void hit_left(struct my_table *table)
	{

	};
	void hit_right(struct my_table *table)
	{

	};
	void hit_up(struct my_table *table)
	{

	};
	void hit_down(struct my_table *table)
	{

	};
	void hit_upleft(struct my_table *table) {};
	void hit_upright(struct my_table *table) {};
	void hit_dleft(struct my_table *table) {};
	void hit_dright(struct my_table *table) {};
	//-----------consolidated------------
	void hitupd(struct my_table *table)
	{
		hit_up(table);
		hit_down(table);
	};

	void hlr(struct my_table *table)
	{
		hit_left(table);
		hit_right(table);

	};

	void hitX(struct my_table *table)
	{
		hit_up(table);
		hit_upright(table);
		hit_dleft(table);
		hit_dright(table);
	};
	//---------final------------
	void HIT(struct my_table *table)
	{
		hitupd(table);
		hlr(table);
		hitX(table);
	};

	
}
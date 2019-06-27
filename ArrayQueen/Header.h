#pragma once

#include "iostream"
#include "vector"
#include <utility>
#include <tuple>
#include <cstdlib>
#include <list> 
#include <iterator> 
#include <array>
#include <chrono>
#include <thread>

//defines
#define TABLE  8
#define QUEEN 81
#define FREE 48
#define HITTED 104

namespace Table_stuff 
{
	void out(int A[TABLE][TABLE])
	{

		for (int i = 0; i < TABLE; ++i)
		{
			for (int j = 0; j < TABLE; ++j)
			{
				if (A[i][j] < 10)
				{

					std::cout << "[ " << (char)A[i][j] << "]";
				}
				else
				{

					std::cout << "[" << (char)A[i][j] << "]";
				}

			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

	};
}

#include "Hit_funcitons.hpp"

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
#include <fstream>
//defines
#define TABLE 4
#define TABLE_M 0;
#define QUEEN 81
#define FREE 48
#define HITTED 104

namespace Table_stuff 
{
	std::ofstream myfile;


	void out(int A[TABLE][TABLE], int d = -1)
	{

		for (int i = 0; i < TABLE; ++i)
		{
			for (int j = 0; j < TABLE; ++j)
			{
				if (j == 0)
				{
					for(int dc=0; dc<d; ++dc)
					std::cout << " ";
				}
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
	


	void out2(int A[TABLE][TABLE])
	{
		/*
		 ofstream myfile;
		 myfile.open ("example.txt");
		 myfile << "Writing this to a file.\n";
		 myfile.close();
		*/
		
		
		

		for (int i = 0; i < TABLE; ++i)
		{
			for (int j = 0; j < TABLE; ++j)
			{
				if (A[i][j] < 10)
				{

					myfile << "[ " << (char)A[i][j] << "]";
				}
				else
				{

					myfile << "[" << (char)A[i][j] << "]";
				}

			}
			myfile << std::endl;
		}
		myfile << std::endl;
		

	};
}

#include "Hit_funcitons.hpp"

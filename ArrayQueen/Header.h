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
	void out2(int A[TABLE][TABLE])
	{
		/*
		 ofstream myfile;
		 myfile.open ("example.txt");
		 myfile << "Writing this to a file.\n";
		 myfile.close();
		*/
		std::ofstream myfile;
		myfile.open("kimenet.txt", std::fstream::app);
		

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
		myfile.close();

	};
}

#include "Hit_funcitons.hpp"

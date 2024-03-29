#include "pch.h"
#include "Cards.h"
#include <iostream>
#include <fstream>
int main()
{
	std::ifstream Problems;
	Problems.open("Test.txt.");
	if (!(Problems.is_open()))
	{
		std::cout << "Test.txt is missing!";
		return false;
	}
	std::string inp;
	std::getline(Problems, inp);
	Cards Test(inp);
	while (Problems.good())
	{
		Test.Solve();
		std::getline(Problems, inp);
		Test.reset(inp);
	}
	return true;
}


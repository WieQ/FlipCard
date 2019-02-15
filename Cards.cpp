#include "pch.h"
#include "Cards.h"

Cards::Cards(std::string inpt) : size(cards.size()),cards(inpt)
{
	HowManyOne = 0;
	count = 0;
	size = cards.size();
	otp = new int[size];
	//counting How many one there is. 
	for (size_t i = 0; i < size; ++i)
		if (cards[i] == '1')
			HowManyOne++;
}

Cards::~Cards()
{
	if (otp != nullptr)
		delete[] otp;
}
//Reseting Cards and setting up new problem to solve
void Cards::reset(std::string inpt)
{
	HowManyOne = 0;
	count = 0;
	cards.clear();
	cards = inpt;
	size = cards.size();
	delete[] otp;
	otp = new int[size];
	for (size_t i = 0; i < size; ++i)
		if (cards[i] == '1')
			HowManyOne++;
}
//Solving problem
void Cards::Solve()
{
	
	while ( (!(IsSolved())) && (!(NoSolution())))
	{
		for (size_t i = 0; i < size; ++i)
		{
			
			if (cards[i] == '1')
			{
				cards[i] = '.';
				otp[count++] = i;
				if (i > 0 && cards[i - 1] == '0')
					cards[i - 1] = '1';
				if (i + 1 < size)
				{
					switch (cards[i + 1])
					{
					case '0':
						cards[i + 1] = '1';
						break;
					case '1':
						cards[i + 1] = '0';
						break;
					}
				}
				break;
			}
		}
	}
	if (IsSolved())
		for (size_t i = 0; i < size; ++i)
			std::cout << otp[i] << " ";
	else if (NoSolution())
		std::cout << "no solution";
	std::cout << std::endl;
}


// return true if solved.
bool Cards::IsSolved()
{
	bool solved = true;
	for (size_t i = 0; i < size; ++i)
		if (cards[i] != '.')
			solved = false;
	return solved;
}

//return true if there is no solution.
bool Cards::NoSolution()
{
	if (HowManyOne % 2 == 1)
	{
		for (size_t i = 0; i < size; ++i)
			if (cards[i] == '1')
				return false;
	}
	return true;
}
#ifndef CARDS_H_
#define CARDS_H_

#include <iostream>
#include <string>

class Cards
{
private:
		//String Size
		size_t size;
		//String to solve
		std::string cards;
		//Output 
		int * otp;
		//Support int to count output
		int count;
		//How many 1 is there in String
		int HowManyOne;
public:
	Cards(std::string inpt);
	Cards(const Cards& c) {};
	Cards& operator=(const Cards& c) {};
	~Cards();
	//Function for Solving Cards
	void Solve();
	//Fuction returning true if Cards are solved
	bool IsSolved();
	//Function returning true if there is no solution
	bool NoSolution();
	//Fuction which reset cards and setting up new one
	void reset(std::string inpt);
};

#endif
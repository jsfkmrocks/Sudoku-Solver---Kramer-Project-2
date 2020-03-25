#include <iostream>
#include "stack.h"
using namespace std;

//Globals
const uint16_t
	value_mask = 0x000f,
	valid_mask = 0x1ff0,
	is_filled_in = 0x8000,
	is_0_valid = 0x2000;

Stack<int> mystack;

//Function Prototypes
bool isValid(uint16_t cell, uint16_t i);
void markInvalid (uint16_t &cell, uint16_t i);
bool FindBest(uint16_t board2[9][9]);

int main()
{
	uint16_t board[9][9];
	char ch;
	int d;

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cin >> ch;
			if(ch == '.')
			board[r][c] = 0;
			else
			board[r][c] = is_filled_in | (ch-'0');
		}
	}

	//testing
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cout << (board[r][c] &value_mask);
		}
		cout << endl;
	}

	cout <<endl;

	FindBest(board);

    d = mystack.pop();

    cout << d << endl;


	return 0;
}






//Functions

bool isValid(uint16_t cell, uint16_t i)
{
	return ((cell &(is_0_valid >> i)!=0));
}

void markInvalid (uint16_t &cell, uint16_t i)
{
	cell = cell & ~(is_0_valid >> i);
}

//Algorithm 1


//Algorithm 2

bool FindBest(uint16_t board2[9][9])
{
	int low, count, rBest, cBest;

	//Procedure Lines 2-4
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			if (board2[r][c] == 0)
			{
					board2[r][c] = board2[r][c] | valid_mask;
			}
		}
	}

	//Procedure Lines 5-15
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
            if(board2[r][c] &is_filled_in)
            {
                for(int rows=0; rows<9; rows++)
                {
                    markInvalid(*&board2[rows][c], c);
                }
                for(int columns=0; columns<9; columns++)
                {
                    markInvalid(*&board2[r][columns], r);
                }
                if(r<3 && c<3)
                {
                    for(int rows=0; rows<3; rows++)
                    {
                        for(int columns=0; columns<3; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<6 && c<3)
                {
                    for(int rows=3; rows<6; rows++)
                    {
                        for(int columns=0; columns<3; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<9 && c<3)
                {
                    for(int rows=6; rows<9; rows++)
                    {
                        for(int columns=0; columns<3; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<3 && c<6)
                {
                    for(int rows=0; rows<3; rows++)
                    {
                        for(int columns=3; columns<6; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<3 && c<9)
                {
                    for(int rows=0; rows<3; rows++)
                    {
                        for(int columns=6; columns<9; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<6 && c<6)
                {
                    for(int rows=3; rows<6; rows++)
                    {
                        for(int columns=3; columns<6; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<6 && c <9)
                {
                    for(int rows=3; rows<6; rows++)
                    {
                        for(int columns=6; columns<9; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<9 && c<6)
                {
                    for(int rows=6; rows<9; rows++)
                    {
                        for(int columns=3; columns<6; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
                else if(r<9 && c<9)
                {
                    for(int rows=6; rows<9; rows++)
                    {
                        for(int columns=6; columns<9; columns++)
                        {
                            markInvalid(*&board2[rows][columns], r);
                        }
                    }
                }
            }
		}
	}

	//Procedure Lines 16-24
//	low = 10;
//	for (int r = 0; r < 9; r++)
//	{
//		for (int c = 0; c < 9; c++)
//		{
//			/* Count one bits in board[r][c]*/
//			if (count < low)
//			{
//				low = count;
//				rBest = r;
//				cBest = c;
//			}
//		}
//	}

	//Procedure Lines 25-27
	if (low = 10)
	{
		return false;
	}

	//Procedure Lines 28-29
	board2[rBest][cBest] = board2[rBest][cBest] | is_filled_in;
	mystack.push(rBest);
	mystack.push(cBest);

	return true;
}


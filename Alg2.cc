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
                    markInvalid(&board2[rows][c], c)
                }
                for(int columns=0; columns<9; columns++)
                {
                    markInvalid(&board2[r][columns], r)
                }
                if(int r<3 && int c<3)
                {
                    for(int rows=0; rows<3; rows++)
                    {
                        for(int columns=0; columns<3; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<6 && int c<3)
                {
                    for(int rows=3; rows<6; rows++)
                    {
                        for(int columns=0; columns<3; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<9 && int c<3)
                {
                    for(int rows=6; rows<9; rows++)
                    {
                        for(int columns=0; columns<3; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<3 && int c<6)
                {
                    for(int rows=0; rows<3; rows++)
                    {
                        for(int columns=3; columns<6; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<3 && int c<9)
                {
                    for(int rows=0; rows<3; rows++)
                    {
                        for(int columns=6; columns<9; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<6 && int c<6)
                {
                    for(int rows=3; rows<6; rows++)
                    {
                        for(int columns=3; columns<6; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<6 && int c <9)
                {
                    for(int rows=3; rows<6; rows++)
                    {
                        for(int columns=6; columns<9; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<9 && int c<6)
                {
                    for(int rows=6; rows<9; rows++)
                    {
                        for(int columns=3; columns<6; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
                        }
                    }
                }
                else if(int r<9 && int c<9)
                {
                    for(int rows=6; rows<9; rows++)
                    {
                        for(int columns=6; columns<9; columns++)
                        {
                            markInvalid(&board2[rows][columns], )
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
	board2[rBest][cBest] = board2[rBest][cBest] | is_filled_in
	teststack.push(rBest, cBest);

	return true;
}

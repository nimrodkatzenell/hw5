#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
char** addNames(int* pMaxSize, int* pNumNames);
bool createScore(int** scores, int size);
int** initBoard(int level, int* size);
void multiplicationTableTest(int** board, int size, int* points);
int getRandomNumber(int size);
int* intscore(int size);
int main()
{
	srand(time(NULL));
	/*
	int max=30;
	int numname = 0;
	int** scores;
	int** board;
	int* size;
	int level;
	char** names = addNames(&max,&numname);

	for (int i = 0; i < numname; i++)
	{
		cout << "\nMath level of" << names[i];
		cin >> level;
		board = initBoard(level, size);
		multiplicationTableTest(board, *size, scores[i]);
	}*/
	/*int* size;
	int* p;
	int a = 6;
	p = &a;
	size = &a;
	int** board= initBoard(1, size);
	multiplicationTableTest(board, *size, p);
	*/
	
	
}
int* intscore(int size)
{
	//sets all the scores to 100
	int* scores = new int[size];
	for (int i = 0; i < size; i++)
	{
		
		scores[i] = 100;
	}
	return scores;
}

bool createScore(int** scores, int size)
{
	
	if (!scores)
	{
		cout << "ERROR out of memory!\n";
		return true;
	}
	else
	{
		return false;
	}
}


void multiplicationTableTest(int** board, int size, int* points)
{
	int numq, r, c, index = 0,score=0,answer,minscore;

	if (size == 6)
	{
		numq = 6 * 6 * 0.2;
		minscore = 10;
	}
	else if (size == 8)
	{
		numq = 8 * 8 * 0.3;
		minscore = 5;
	}
	else if (size == 10)
	{
		numq = 10 * 10 * 0.4;
		minscore = 3;
	}
	int* answers = new int[numq];
	while (index < numq)
	{
		r = getRandomNumber(size);
		c = getRandomNumber(size);
		if (board[r][c] != NULL && r > 0 && c > 0)
		{
			answers[index] = board[r][c];
			board[r][c] = NULL;
			index++;
		}

	}
	
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] != NULL)
			{
				cout << board[i][j] << "\t";
			}
			else
			{
				cout << "_\t";
			}
		}
		cout << endl;
	}
	cout << "enter answers:\n";
	for (int i = 0; i < numq; i++)
	{
		cin >> answer;
		if (answers[i] != answer)
		{
			score -= minscore;
		}
		
	}
	*points = minscore;
	delete[] answers;



}
char** addNames(int* pMaxSize, int* pNumNames)
{

	char** Names = new char* [*pMaxSize];
	char* Name = new char[30];
	cout << "Enter a name: ";
	cin.getline(Name, 30);

	while (Name[0] != '\0')
	{
		if (*pNumNames >= *pMaxSize)
		{
			*pMaxSize *= 2;
			char** Temp = new char* [*pMaxSize];
			for (int i = 0; i < *pNumNames; i++)
			{
				Temp[i] = Names[i];
			}
			delete[] Names;
			Names = Temp;
		}
		Names[*pNumNames] = Name;
		*pNumNames += 1;
		Name = new char[30];
		cout << "Enter a name: ";
		cin.getline(Name, 30);
	}
	delete[] Name;
	return Names;
}


int getRandomNumber(int size)
{
	return rand() % (size);
}


int** initBoard(int level, int* size)
{

	if (level == 1)
	{
		*size = 6;
		int** board = new int* [*size];
		for (int i = 0; i < *size; i++)
		{
			board[i] = new int[*size];
		}
		for (int i = 0; i < *size; i++)
		{
			for (int j = 0; j < *size; j++)
			{
				board[i][j] = (i + 1) * (j + 1);
			}
		}
		return board;

	}
	else if (level == 2)
	{
		*size = 8;
		int** board = new int* [*size];
		for (int i = 0; i < *size; i++)
		{
			board[i] = new int[*size];
		}
		for (int i = 0; i < *size; i++)
		{
			for (int j = 0; j < *size; j++)
			{
				board[i][j] = (i + 1) * (j + 1);
			}
		}
		return board;
	}
	else if (level == 3)
	{
		*size = 10;
		int** board = new int* [*size];
		for (int i = 0; i < *size; i++)
		{
			board[i] = new int[*size];
		}
		for (int i = 0; i < *size; i++)
		{
			for (int j = 0; j < *size; j++)
			{
				board[i][j] = (i + 1) * (j + 1);
			}
		}

		return board;
	}



}

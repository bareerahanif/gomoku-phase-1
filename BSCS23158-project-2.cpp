#include<iostream>
#include<conio.h>
#include<fstream>
#include<time.h>
using namespace std;

#define Capacity 50

void TurnChange(int &Turn)
{
	Turn = (Turn + 1) % 2;
}
void UpdateBoard(char Board[][Capacity], int ri, int ci, char aiksym)
{
	Board[ri][ci] = aiksym;
}
bool IsValidPosition(int ri, int ci, int Dim, char Board[][Capacity])
{
	return ((ri >= 0 && ci >= 0) && (ri < Dim && ci < Dim) && (Board[ri][ci] == '-'));
}
void SelectPosition(int &ri, int &ci)
{
	cin >> ri >> ci;
	ri--;
	ci--;
}
void DisplayMsg(char aiknaam[], char aiksym)
{
	cout << endl << "Symbol: " << aiksym << endl << aiknaam << "'s Turn[ri,ci]: " << endl;
}
void PrintBoard(char Board[][Capacity], int Dim)
{
	system("cls");
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			cout<< Board[ri][ci]<<" ";
		}
		cout << endl;
	}
}
void init(char Board[][Capacity],int &Dim,char PName[][30], int& Turn)
{
	ifstream Rdr("INIT.txt");
	Rdr >> Dim;
	for (int ri = 0; ri < Dim; ri++)
	{
		for (int ci = 0; ci < Dim; ci++)
		{
			Rdr >> Board[ri][ci];
		}
	}

	cout << "Player 1's Name: ";
	cin >> PName[0];
	cout << "Player 2's Name: ";
	cin >> PName[1];

	Turn = rand() % 2;

}
int main()
{
	srand(time(0));
	char Board[Capacity][Capacity];
	int Dim;
	int ri, ci;
	char PName[2][30];
	char PSym[2] = { 'x','o' };
	int Turn;

	init(Board, Dim, PName, Turn);
	do
	{
		PrintBoard(Board, Dim);
		DisplayMsg(PName[Turn], PSym[Turn]);
		do
		{
			SelectPosition(ri, ci);
		} while (!IsValidPosition(ri, ci, Dim, Board));
		UpdateBoard(Board, ri, ci, PSym[Turn]);
		TurnChange(Turn);
	} while (true);
	
	
	

	return 0;
}
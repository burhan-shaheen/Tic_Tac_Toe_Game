#include<iostream>
#define SIZE 3
#define MAX 9
using namespace std;
class ticTacToe
{
	char pos[SIZE][SIZE];
	char temp[MAX];
	char players[2] = { 'X','O' };
	int check = 1;//bario k liye yaani player 1 and player 2
	int count = 0;//For boxes and do while loop
	int adrs;//Address from 1 to 9
public:
	ticTacToe()
	{
		for (int i = 0; i < SIZE; i++)
			for (int j = 0; j < SIZE; j++)
				pos[i][j] = ' ';
	}
	int setter();//For input
	bool valid();//Checking validation of position
	void player();//For putting X and O in pos array
	int windraw();//for winning of player one of Draw
	int windraw1();//for winning of player two of Draw
	void getter();//For Output

};
int ticTacToe::setter()
{
	int p1, p2;
	do
	{
		do
		{
			system("CLS");
			getter();
			cout << "\tPlayer 1 : X \n\n";
			cout << "\tPlayer 2 : O \n\n";
			cout << "Player " << check << " (Position)  :  ";
			cin>> adrs;//entering position
			if ((adrs > 0) && (adrs <= 9))
				if (valid())//Position validation
				{
					cout << "Box is Already Fill\n\n";
					system("pause");
				}
				else
				{
					player();//Player1 k liye sab operation hony lagy ha Pos is liye Q k Array ma pos per X para ha
					p1 = windraw();//Function call for checking that if You win then return 1
					if (p1 == 1)
						return p1;//return 1 if Player 1 won the match
					break;
				}
			else
			{
				cout << "\nWrong Choice \n";
				system("pause");
			};
		} while (true);
		if (check == 2)
			check -= 1;
		else
			check++;
		count++;
		if (count == 9)
		{
			break;
		}
			do
			{
				system("CLS");
				getter();
				cout << "\tPlayer 1 : X \n\n";
				cout << "\tPlayer 2 : O \n\n";
				cout << "Player " << check << " (Position)  :  ";
				cin>> adrs;//entering position
				if ((adrs > 0) && (adrs <= 9))
					if (valid())//Position validation
					{
						cout << "Box is Already Fill\n\n";
						system("pause");
					}
					else
					{
						player();//Player1 Or Player2 k liye sab operation hony lagy ha Pos is liye Q k Array ma pos per X para ha
						p2=windraw1();//Function call for checking that if You win then return 0
						if (p2 == 0)
							return p2;//Return 0 if Player 2 win the match
						break;
					}
				else
				{
					cout << "\nWrong Choice \n";
					system("pause");
				}
			} while (true);
			if (check == 2)
				check -= 1;
			else
				check++;
			count++;

	} while (count < 9);
}
void ticTacToe::player()
{
	switch (adrs)
	{
	case 1://First Row and First Column
		pos[0][0] = players[check - 1];
		temp[adrs - 1] = pos[0][0];//jo pos array k andar ho ga wo temp ko dai jaye ga maslan X or O
		break;
	case 2://First Row and Second Column
		pos[0][1] = players[check - 1];
		temp[adrs - 1] = pos[0][1];
		break;
	case 3://First Row and Third Column
		pos[0][2] = players[check - 1];
		temp[adrs - 1] = pos[0][2];
		break;
	case 4://Second Row and First Column
		pos[1][0] = players[check - 1];
		temp[adrs - 1] = pos[1][0];
		break;
	case 5://Second Row and Second Column
		pos[1][1] = players[check - 1];
		temp[adrs - 1] = pos[1][1];
		break;
	case 6://Second Row and Third Column
		pos[1][2] = players[check - 1];
		temp[adrs - 1] = pos[1][2];
		break;
	case 7://Third Row and First Column
		pos[2][0] = players[check - 1];
		temp[adrs - 1] = pos[2][0];
		break;
	case 8://Third Row and Second Column
		pos[2][1] = players[check - 1];
		temp[adrs - 1] = pos[2][1];
		break;
	case 9://Third Row and Third Column
		pos[2][2] = players[check - 1];
		temp[adrs - 1] = pos[2][2];
		break;
	}


}
int ticTacToe::windraw1()
{
	int p2;
	if (pos[0][0] == 'O' && pos[0][1] == 'O' && pos[0][2] == 'O')
		return p2 = 0;
	else if (pos[1][0] == 'O' && pos[1][1] == 'O' && pos[1][2] == 'O')
		return p2 = 0;
	else if (pos[2][0] == 'O' && pos[2][1] == 'O' && pos[2][2] == 'O')
		return p2 = 0;
	else if (pos[0][0] == 'O' && pos[1][0] == 'O' && pos[2][0] == 'O')
		return p2 = 0;
	else if (pos[0][1] == 'O' && pos[1][1] == 'O' && pos[2][1] == 'O')
		return p2 = 0;
	else if (pos[0][2] == 'O' && pos[1][2] == 'O' && pos[2][2] == 'O')
		return p2 = 0;
	else if (pos[0][0] == 'O' && pos[1][1] == 'O' && pos[2][2] == 'O')
		return p2 = 0;
	else if (pos[0][2] == 'O' && pos[1][1] == 'O' && pos[2][0] == 'O')
		return p2 = 0;
}
int ticTacToe::windraw()
{
	int p1;
	if (pos[0][0] == 'X' && pos[0][1] == 'X' && pos[0][2] == 'X')
		return p1 = 1;
	else if (pos[1][0] == 'X' && pos[1][1] == 'X'  && pos[1][2] == 'X')
		return p1 = 1;
	else if (pos[2][0] == 'X' && pos[2][1] == 'X' && pos[2][2] == 'X')
		return p1 = 1;
	else if (pos[0][0] == 'X' && pos[1][0] == 'X' && pos[2][0] == 'X')
		return p1 = 1;
	else if (pos[0][1] == 'X' && pos[1][1] == 'X' && pos[2][1] == 'X')
		return p1 = 1;
	else if (pos[0][2] == 'X' && pos[1][2] == 'X' && pos[2][2] == 'X')
		return p1 = 1;
	else if (pos[0][0] == 'X' && pos[1][1] == 'X' && pos[2][2] == 'X')
		return p1 = 1;
	else if (pos[0][2] == 'X' && pos[1][1] == 'X' && pos[2][0] == 'X')
		return p1 = 1;
}
bool ticTacToe::valid()
{
	if (temp[adrs - 1] == 'X' || temp[adrs - 1] == 'O')
		return true;
	else
		return false;
}
void ticTacToe::getter()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << "  "<<pos[i][j];
			if (j < 2)
				cout << "\t|";
			if (j == 2)
				cout << endl;

		}
		if (i < 2)
			cout << "________|_______|_______\n";
	}
	cout << "  \t|  \t|  \n\n";
}
int main()
{
	int p1;
	char ch;
	do
	{
		ticTacToe obj;
		p1 = obj.setter();
		if (p1 == 1)
			cout << "PLayer 1 ,Congratulation YOu Won the Match \n\n";
		else if (p1 == 0)
			cout << "PLayer 2 ,Congratulation YOu Won the Match \n\n";
		else
			cout << "Match Draw\n\n";
		obj.getter();
		cout << "Do you Want to Play Again :[ Y for Yes  and  N for No ] : ";
		cin >> ch;
		if (toupper(ch) == 'N')
			break;
	} while (true);
	system("pause");
}
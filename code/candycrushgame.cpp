//#include<iostream>
//#include<iomanip>
//#include<time.h>
//#include<string>
//#include<chrono>
//#include<thread>
//#include<windows.h>
//#include<algorithm>
//using namespace std;
//const int row_size = 10;
//const int column_size = 10;
//char candy_table[row_size][column_size];
//string player1;
//int score = 0;
//char random_candy()
//{
//	int candy;
//	candy = rand() % 6;
//	if (candy == 0)
//		return '@';
//	else if (candy == 1)
//		return '%';
//	else if (candy == 2)
//		return '&';
//	else if (candy == 3)
//		return '#';
//	else if (candy == 4)
//		return '$';
//	else if (candy == 5)
//		return '*';
//}
//void table()
//{
//
//	for (int i = 0; i < row_size; i++)
//	{
//		for (int j = 0; j < column_size; j++)
//		{
//			candy_table[i][j] = random_candy();
//		}
//	}
//}
//void player_record()
//{
//	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(color, 10);
//	cout << "PLAYER:";
//	SetConsoleTextAttribute(color, 15);
//	cout << player1 << endl;
//	SetConsoleTextAttribute(color, 13);
//	cout << "SCORE:";
//	SetConsoleTextAttribute(color, 15);
//	cout << score << endl;
//}
//void printtable()
//{
//	player_record();
//	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(color, 11);
//	cout << "-" << setfill('-') << setw(46) << "-" << endl;
//	SetConsoleTextAttribute(color, 14);
//	cout << "Column|";
//	for (int i = 0; i < column_size; i++)
//	{
//		SetConsoleTextAttribute(color, 11);
//		cout << "-" << i << "-|";
//	}
//	cout << endl;
//	cout << "-" << setfill('-') << setw(46) << "-" << endl;
//	for (int i = 0; i < row_size; i++)
//	{
//		SetConsoleTextAttribute(color, 13);
//		cout << "ROW-";
//		SetConsoleTextAttribute(color, 11);
//		cout << "|" << i << "|";
//		for (int j = 0; j < column_size; j++)
//		{
//			switch (candy_table[i][j])
//			{
//			case '#':SetConsoleTextAttribute(color, 10); break;
//			case '%':SetConsoleTextAttribute(color, 11); break;
//			case '@':SetConsoleTextAttribute(color, 15); break;
//			case '&':SetConsoleTextAttribute(color, 14); break;
//			case '$':SetConsoleTextAttribute(color, 12); break;
//			case '*':SetConsoleTextAttribute(color, 13); break;
//			}
//			cout << " " << candy_table[i][j];
//			SetConsoleTextAttribute(color, 11);
//			cout << " |";
//		}
//		cout << endl;
//	}
//	cout << "-" << setfill('-') << setw(46) << "-" << endl;
//	SetConsoleTextAttribute(color, 12);
//	cout << "TO EXIT FROM GAME PRESS :";
//	SetConsoleTextAttribute(color, 11);
//	cout<< " 99                  |" << endl;
//	SetConsoleTextAttribute(color, 11);
//	cout << "-" << setfill('-') << setw(46) << "-" << endl;
//}
//void shift_down(int r, int c)
//{
//	for (int i = r; i >= 0; i--)
//	{
//		std::this_thread::sleep_for(std::chrono::milliseconds(30));
//		candy_table[i][c] = candy_table[i - 1][c];
//	}
//	candy_table[0][c] = random_candy();
//	printtable();
//}
//void swape_candy1(int r, int c, int r1, int c1)
//{
//	swap(candy_table[r][c], candy_table[r1][c1]);
//}
//void gamecheck1(int r, int c, int r1, int c1)
//{
//	swape_candy1(r, c, r1, c1);
//	for (int i = 0; i < row_size; i++)
//	{
//		for (int j = 0; j < column_size; j++)
//		{
//			while (candy_table[r][c] == candy_table[r - 1][c] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				r = r - 1;
//				if (candy_table[r][c] != candy_table[r - 1][c])
//				{
//					break;
//				}
//			}
//			while (candy_table[r][c] == candy_table[r + 1][c] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				r = r + 1;
//				if (candy_table[r][c] != candy_table[r + 1][c])
//				{
//					break;
//				}
//
//			}
//			while (candy_table[r][c] == candy_table[r][c - 1] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				c = c - 1;
//				if (candy_table[r][c] != candy_table[r][c - 1])
//				{
//					break;
//				}
//			}
//			while (candy_table[r][c] == candy_table[r][c + 1] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				c = c + 1;
//				if (candy_table[r][c] != candy_table[r][c + 1])
//				{
//					break;
//				}
//			}
//			while (candy_table[r][c] == candy_table[r + 1][c + 1] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				r = r + 1;
//				c = c + 1;
//				if (candy_table[r][c] != candy_table[r + 1][c + 1])
//				{
//					break;
//				}
//			}
//			while (candy_table[r][c] == candy_table[r - 1][c - 1] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				r = r - 1;
//				c = c - 1;
//				if (candy_table[r][c] != candy_table[r - 1][c - 1])
//				{
//					break;
//				}
//			}
//			while (candy_table[r][c] == candy_table[r - 1][c + 1] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				r = r - 1;
//				c = c + 1;
//				if (candy_table[r][c] != candy_table[r - 1][c + 1])
//				{
//					break;
//				}
//			}
//			while (candy_table[r][c] == candy_table[r + 1][c - 1] && r >= 0 && c >= 0)
//			{
//				shift_down(r, c);
//				score++;
//				r = r + 1;
//				c = c - 1;
//				if (candy_table[r][c] != candy_table[r + 1][c - 1])
//				{
//					break;
//				}
//			}
//		}
//	}
//	
//}
//
//int main()
//{
//	int row1 = 1, column1 = 1, row2 = 1, column2 = 1;
//	srand(time(0));
//	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
//	cout << "Enter player  Name:";
//	getline(cin, player1);
//	table();
//	while (row1 != 99 || column1 != 99 || row2 != 99 || column2 != 99)
//	{
//		system("cls");
//		printtable();
//		SetConsoleTextAttribute(color, 11);
//		cout << "Enter row # for candy you want to remove from series :";
//		cin >> row1;
//		if (row1 == 99)break;
//		cout << "Enter column # for candy you want to remove from series :";
//		cin >> column1;
//		if (column1 == 99)break;
//		SetConsoleTextAttribute(color, 12);
//		cout << "Enter row # for candy you want to crush :";
//		cin >> row2;
//		if (row2 == 99)break;
//		cout << "Enter column # for candy you want to crush :";
//		cin >> column2;
//		if (column2 == 99)break;
//		gamecheck1(row1, column1, row2, column2);
//	}
//	player_record();
//	SetConsoleTextAttribute(color, 14);
//	cout << "Thanks for playing!" << endl;
//	system("pause");
//	return 0;
//}
//

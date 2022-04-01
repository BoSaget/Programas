#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy (int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(hcon, Pos);
}

int main()
{
	gotoxy(5, 5);
	cout << "Hola";
}

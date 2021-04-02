#include<iostream>
using namespace std;
int h = 0;
void Input(char** map, int size)
{
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
		{
			map[i][j] = ' ';
		}
	}
}
void Output(char** map, int size)
{
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == size - 1) || (j == 0 && i == size - 1) || (i == size - 1 && j == size - 1))
				cout << "   ";
			else if (i == 0 || i == size - 1)
				cout << char(64 + j) << " ";
			else if (j == 0 || j == size - 1)
			{
				if (i < 10)
					cout << i << "  ";
				else
					cout << i << " ";
			}
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void Output(char** map, int size, char** shoot)
{
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == size - 1) || (j == 0 && i == size - 1) || (i == size - 1 && j == size - 1))
				cout << "   ";
			else if (i == 0 || i == size - 1)
				cout << char(64 + j) << " ";
			else if (j == 0 || j == size - 1)
			{
				if (i < 10)
					cout << i << "  ";
				else
					cout << i << " ";
			}
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == size - 1) || (j == 0 && i == size - 1) || (i == size - 1 && j == size - 1))
				cout << "   ";
			else if (i == 0 || i == size - 1)
				cout << char(64 + j) << " ";
			else if (j == 0 || j == size - 1)
			{
				if (i < 10)
					cout << i << "  ";
				else
					cout << i << " ";
			}
			else
				cout << shoot[i][j] << " ";
		}
		cout << endl;
	}
}
void Ship(char** map)
{
	int x;
	char y;
	for (int i = 0;i < 10;i++)
	{
		cout << "Укажите координаты корабля (буква, цифра): ";
		cin >> y >> x;
		map[x][int(y - 64)] = '@';
	}
}
void ShipRand(char** map)
{
	srand(time(NULL));
	int x, y;
	int k = 0;
	while (k < 10)
	{
		x = rand() % (1 - 16) + 1;
		y = rand() % (1 - 16) + 1;
		if (map[x][y] == ' ')
		{
			map[x][y] = '&';
			map[x][y + 1] = '=';
			map[x][y - 1] = '=';
			map[x + 1][y] = '=';
			map[x + 1][y + 1] = '=';
			map[x + 1][y - 1] = '=';
			map[x - 1][y] = '=';
			map[x - 1][y + 1] = '=';
			map[x - 1][y - 1] = '=';
			k++;
		}
		else
			continue;
	}
}
void ShootP(char** pc, char** shoot, int& k)
{
	int x;
	char y;
	cout << "Ваш выстрел (буква, цифра)\n";
	cin >> y >> x;
	if (pc[x][int(y - 64)] == '&')
	{
		shoot[x][int(y - 64)] = '&';
		k++;
	}
	else
	{
		shoot[x][int(y - 64)] = 'x';
	}
	if (k == 10)
		h = 1;
}
void ShootC(char** map, int& l)
{
	int x, y;
	x = rand() % (1 - 16) + 1;
	y = rand() % (1 - 16) + 1;
	if (map[x][y] == '@')
	{
		map[x][y] = 'X';
		map[x][y + 1] = '=';
		map[x][y - 1] = '=';
		map[x + 1][y] = '=';
		map[x + 1][y + 1] = '=';
		map[x + 1][y - 1] = '=';
		map[x - 1][y] = '=';
		map[x - 1][y + 1] = '=';
		map[x - 1][y - 1] = '=';
		l++;
	}
	else
		map[x][y] = 'x';
	if (l == 10)
		h = 1;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	//create arrays
	int const size = 17;
	char** map = new char* [size];
	for (int i = 0;i < size;i++)
		map[i] = new char[size];
	char** pc = new char* [size];
	for (int i = 0;i < size;i++)
		pc[i] = new char[size];
	char** shoot = new char* [size];
	for (int i = 0;i < size;i++)
	{
		shoot[i] = new char[size];
	}
	//end
	Input(map, size);
	Input(pc, size);
	Input(shoot, size);
	Output(map, size);
	int k = 0;
	int l = 0;
	int* ptrk = &k;
	int* ptrl = &l;
	cout << endl;
	Ship(map);
	ShipRand(pc);
	Output(map, size, shoot);
	while (h != 1)
	{
		ShootP(pc, shoot, k);
		Output(map, size, shoot);
		if (h == 1)
			continue;
		ShootC(map, l);
		Output(map, size, shoot);
	}
	//delete arrays
	for (int i = 0;i < size;i++)
		delete[]map[i];
	delete[]map;
	for (int i = 0;i < size;i++)
		delete[]pc[i];
	delete[]pc;
	for (int i = 0;i < size;i++)
		delete[]shoot[i];
	delete[]shoot;
	return 0;
}
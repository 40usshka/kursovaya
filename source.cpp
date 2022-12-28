#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include "Header.h"
using namespace::std;

void output(int** p, int n) //vivod marritsi
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

int** input(int** g, int n) //zapolnenie vruchnuyu
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			g[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			system("cls");
			g[i][j] = 8;
			cout << "8 - mesto zapisi" << endl;
			output(g, n);
			cout << "»";
			cin >> g[i][j];
			cout << endl;
		}
	}
	return g;
}
int** input_auto(int** g, int n) //avto zapolnenie
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				g[i][j] = 0;
			}
			else
			{
				g[i][j] = rand() % 2;
			}
			g[j][i] = g[i][j];
		}
	}
	return g;
}

int** input_auto_euler(int** g, int n) // zapolnenie matritsi s eylerovim tsiklom
{
	int two = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (g[i][j] == 1) sum++;

			if ((g[i][j] == 0) && (i != j)) two = j;
		}
		if (sum % 2 == 1)
		{
			g[i][two] = 1;
			g[two][i] = g[i][two];
		}
	}
	return g;
}

int** euler(int** g, int n) //algoritm poiska eylerova tsikla
{
	int i, j;
	int start, pos = 0, p, k, LIFO[100], C[2][100];
	start = 0;
	int temp = 0;
	int one = 0;

	ofstream FILE("Euler_cycle.txt");

	FILE << "Matritsa smezhnosti:" << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			FILE << g[i][j] << " ";
		}
		FILE << endl;
	}

	cout << endl;

	LIFO[0] = start; // vnosim v stek start vershinu
	k = 1; // positsiya vershini steka
	while (k != 0)
	{
		p = 0;
		// Nakhodim vershinu s minimalnym nomerom i smezhnuyu s vershinoy nomer kotoroy v steke

		for (i = 0; i < n; i++)

			if (g[LIFO[k - 1]][i] == 1)
			{
				p = 1;
				break;
			}
		if (p != 0)
		{
			LIFO[k] = i; //zanosim vershinu v stek
			//pomechaem rebro kak proydennoe
			g[LIFO[k - 1]][i] = 2;
			g[i][LIFO[k - 1]] = 2;
			k++; // sdvig pozitsii steka
		}
		else
		{
			// vinosim obratnoe rebro
			C[0][pos] = LIFO[k - 1];
			C[1][pos] = LIFO[k - 2];
			pos++;
			k--;
		}
	}

	// vivod resultata
	for (i = 0; i < pos - 1; i++)
		cout << C[0][i] << " " << C[1][i] << endl;
	// zapis v fale
	FILE << "Eylerov tsikl:" << endl;

	for (i = 0; i < pos - 1; i++) {
		FILE << C[0][i] << " " << C[1][i] << endl;
	}
	FILE.close();
	return 0;
}

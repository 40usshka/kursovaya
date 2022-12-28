#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include "Header.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	int n, i, j, z;

	while (true)
	{
		main_menu();
		menu_enter_matrix();
		cin >> n;
		while (n < 3)
		{
			note();
			cin >> n;
		}
		int check = 0;
		int** G, ** Gtemp, ** GG;
		G = (int**)malloc(n * sizeof(int*));
		for (i = 0; i < n; i++)
		{
			G[i] = (int*)malloc(n * sizeof(int));
		}

		Gtemp = (int**)malloc(n * sizeof(int*));
		for (i = 0; i < n; i++)
		{
			Gtemp[i] = (int*)malloc(n * sizeof(int));
		}

		GG = (int**)malloc(n * sizeof(int*));
		for (i = 0; i < n; i++)
		{
			GG[i] = (int*)malloc(n * sizeof(int));
		}

		while (true)
		{
			int choose;
			system("cls");
			main_menu();
			if (check == 1)
			{
				cout << endl;
				mat();
				cout << endl;
				output(Gtemp, n);
				cout << endl;
			}

			if (check == 2)
			{
				cout << endl;
				mat();
				cout << endl;
				output(GG, n);
				cout << endl;
				mat_euler();
				cout << endl;
				output(Gtemp, n);
				cout << endl;

			}
			if (check < 1) {
				cout << endl;
				menu_empty_matrix();
			}

			cin >> choose;

			if (choose == 1) // rychnoe zapolnenie
			{
				G = input(G, n);

				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						Gtemp[i][j] = G[i][j];
						GG[i][j] = G[i][j];
					}
				}

				check = 1;
				system("pause");
				continue;
			}

			if (choose == 2) //avtomaticheskoe zapolnenie
			{
				G = input_auto(G, n);

				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						Gtemp[i][j] = G[i][j];
						GG[i][j] = G[i][j];
					}
				}

				check = 1;
				system("pause");
				continue;
			}

			if (choose == 3) // poisk eylerova tsikla
			{

				int start, pos = 0, p, k, choosen /*LIFO[100], C[2][100]*/;
				start = 0;
				int temp = 0;
				int one = 0;
				int z = 0;
				int* LIFO;
				int** C;
				LIFO = (int*)malloc((n + 1) * sizeof(int));
				C = (int**)malloc(n * sizeof(int*));
				for (i = 0; i < n; i++)
				{
					C[i] = (int*)malloc(2 * sizeof(int));
				}
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
						if (G[i][j] == 1) one++;
					if (one % 2 == 1) {
						z = 1;
						menu3();
						cin >> choosen;
						if (choosen == 1)
						{
							system("pause");
							temp = 1;
							break;
						}
						else if (choosen == 2)
						{
							goto END;
						}
						else if (choosen == 3)
						{
							input_auto_euler(G, n);

							for (i = 0; i < n; i++)
							{
								for (j = 0; j < n; j++)
								{
									Gtemp[i][j] = G[i][j];
								}
							}

							z = 1;
							check = 2;
							break;
						}
					}
				}
				if (temp == 1)
				{
					break;
				}
				if (z == 0)
				{
					menu_euler_viv();
					euler(G, n);
				}
				system("pause");
				continue;
				free(LIFO);
				free(C);
			}

			if (choose == 4) // perezapusk 
			{
				break;
			}

			if (choose == 5) // vihod
			{
				goto END;
			}
		}
		system("cls");
		continue;
		free(G);
		free(Gtemp);
		free(GG);
	}
END:
	return 0;
}


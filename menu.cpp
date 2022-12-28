#include <iostream>
using namespace::std;

void main_menu() //vivod menu
{
	cout << endl << "1. Zapolnit matritsu smezhnosti vruchnuyu" << endl << "2. Zapolnit matritsu smezhnosti avtomaticheski" << endl << "3. Poisk eylerova tsikla v grafe" << endl << "4. Perezapusk programmy" << endl << "5. Vykhod iz programmy" << endl;
}

void menu3() //menu posle proverki grafa
{
	cout << "Graf ne soderzhit Eylerov tsikl. Zapolnit matritsu smezhnosti zanovo? " << endl << "1. Da" << endl << "2. Net. zavershit rabotu programmy" << endl << "3. Net. sdelat matritsu eylerovoy!" << endl << "»";
}

void menu_empty_matrix() //matritsi net
{
	cout << "Vy eshche ne vveli matritsu smezhnosti." << endl;
}

void menu_enter_matrix() //vvod poryadka
{
	cout << "Vvedite poryadok matritsy smezhnosti: ";
}

void menu_euler_true() // vivod esli est eylerov tsikl
{
	cout << "Graf yavlyayetsya Eylerovym i soderzhit eylerov tsikl!" << endl;
}

void menu_euler_viv() //vivod eylerova tsikla
{
	cout << endl << "Eylerovyy tsikl: ";
}

void mat_euler() // vivod izmenennoy matritsi
{
	cout << endl << "Matritsa s eylerovym tsiklom: ";
}

void mat() // vivod ishodnoy matritsi
{
	cout << endl << "Iskhodnaya matritsa:";
}

void note() //vivod esli malenkaya razmernost
{
	cout << endl << "Matritsa ne mozhet byt eylerovoy. esli poryadok menshe 3!" << endl << "Vvedite poryadok zanovo: ";
}

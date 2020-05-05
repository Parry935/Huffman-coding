// Pepaś Dominik - 11:00

#include "pch.h"
#include "Head.h"
#include "Drzewo.h"
#include <string>
#include <exception>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int returnCode = 0;

	string nazwa_pliku_in;
	vector <int> tab_czestotliwosc;
	vector <char> tab_znakow;
	vector <double> tab_prawdo;

	try
	{
		cout << "Podaj nazwe pliku z ktorego chcesz odczytac dane: " << endl;
		cin >> nazwa_pliku_in;
		cout << endl;
		odczyt_z_pliku(nazwa_pliku_in, tab_czestotliwosc, tab_znakow);
	}

	catch (const exception &e)
	{
		returnCode = 1;
		cout << e.what();
	}

	if (returnCode == 0)
	{
		oblicz_prawdopodobienstwo(tab_prawdo, tab_czestotliwosc, tab_znakow);

		huffman(tab_prawdo, tab_znakow);
	}

	getchar();
	cin.ignore();
	return returnCode;
}



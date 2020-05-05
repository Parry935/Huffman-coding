#include "pch.h"
#include "Head.h"
#include "Drzewo.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int huffman(vector<double> tab_prawdo, vector<char> tab_znakow)
{
	vector<int>kod;

	mojakolejka_drzewo kp_drzewo; //stworzenie kolejki priorytetowej dla wêz³ów

	mojakolejka_wynik kp_wynik; //stworzenie kolejki priorytetowej dla kodu wynikowego

	//dodanie do kolejki priorytetowej znaków i okreœlonych dla nich prawdopodobieñstw
	for (int i = 0; i < tab_prawdo.size(); i++)
	{
		drzewo *wezel = new drzewo;

		wezel->znak = tab_znakow[i];
		wezel->prawdopodobienstow = tab_prawdo[i];
		kp_drzewo.push(*wezel);

	}

	drzewo *wezel = new drzewo;

	//stworzenie drzewa wed³ug kodowania huffmana

	while (kp_drzewo.size() != 1)
	{

		drzewo *rodzic = new drzewo;
		drzewo *odczytanie_lewy = new drzewo;
		drzewo *odczytanie_prawy = new drzewo;

		rodzic->left = odczytanie_lewy;
		rodzic->right = odczytanie_prawy;

		odczytanie_lewy->top = rodzic;
		odczytanie_prawy->top = rodzic;

		*odczytanie_lewy = kp_drzewo.top();

		kp_drzewo.pop();

		*odczytanie_prawy = kp_drzewo.top();
		
		kp_drzewo.pop();

		rodzic->prawdopodobienstow = odczytanie_lewy->prawdopodobienstow + odczytanie_prawy->prawdopodobienstow;

		kp_drzewo.push(*rodzic);

		if (kp_drzewo.size() == 1)
		{
			wezel = rodzic;
		}
	}


	drzewo *korzen = new drzewo;

	//przejscie do lewego liœcia

	lewe_liscie(wezel, korzen, kod, kp_wynik);


	//wypisanie wyników z kolejki priorytetowej wyników

	while (!kp_wynik.empty())
	{
		wynik odczytanie = kp_wynik.top();
		kp_wynik.pop();
		cout << odczytanie.znak << " ";

		for (int i = 0; i < odczytanie.wynik_kod.size(); i++)
			cout << odczytanie.wynik_kod[i];

		cout << endl;
	}

	return 0;
}


void oblicz_prawdopodobienstwo(vector<double>& tab_prawdo, vector<int>& tab_czestotliwosc, vector<char>& tab_znakow)
{
	int suma = 0;
	double prawdopodobienstwo = 0;

	for (int i = 0; i < tab_czestotliwosc.size(); i++)
		suma += tab_czestotliwosc[i];


	for (int i = 0; i < tab_czestotliwosc.size(); i++)
	{
		prawdopodobienstwo = double(tab_czestotliwosc[i]) / double(suma);
		tab_prawdo.push_back(prawdopodobienstwo);
	}

}

void odczyt_z_pliku(string nazwa_pliku_in, vector<int>& tab_czestotliwosc, vector<char>& tab_znakow)
{
	fstream file;
	file.open(nazwa_pliku_in.c_str(), ios::in);
	if (!file.good()) {
		throw MyRuntimeExceptions::FileOpenException("Nie mozna otworzyc pliku wejsciowego");
	}

	char znak;
	int liczba;

	while (!file.eof())
	{
		file >> znak;
		tab_znakow.push_back(znak);

		file >> liczba;
		tab_czestotliwosc.push_back(liczba);
	}
}



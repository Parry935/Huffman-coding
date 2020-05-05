#ifndef DRZEWO_H
#define DRZEWO_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//stworzenie struktury pojedyñczego wêz³a w drzewie

struct drzewo
{
	drzewo *top = nullptr;
	drzewo *left = nullptr;
	drzewo *right = nullptr;
	double prawdopodobienstow = 0;
	char znak = NULL;
	bool zaliczony = false;

};

//sortowanie w kolejce priorytetowej wêz³ów wed³ug prawdopodobieñstwa

struct porownanie_drzewo
{
	bool operator() (drzewo &wezel_1, drzewo &wezel_2)
	{
		return wezel_1.prawdopodobienstow > wezel_2.prawdopodobienstow;
	}

};

//stworzenie struktury pojedyñczego wyniku

struct wynik
{
	vector<int> wynik_kod;
	char znak = NULL;
};

//sortowanie w kolejce priorytetowej wynikow wed³ug znaków

struct porownanie_wynik
{
	bool operator() (wynik &obiekt_1, wynik &obiekt_2)
	{
		return obiekt_1.znak > obiekt_2.znak;
	}

};

//nadanie nazwy kolejce priorytetowej wêz³ów
typedef priority_queue <drzewo, vector <drzewo>, porownanie_drzewo> mojakolejka_drzewo;

//nadanie nazwy kolejce priorytetowej wyników
typedef priority_queue <wynik, vector <wynik>, porownanie_wynik> mojakolejka_wynik;

//funkcja za pomoc¹ której przechodzimy do lewego dziecka od rodzica
void idz_do_lewego(drzewo *&wezel, drzewo *&korzen);

//funkcja za pomoc¹ której przechodzimy do prawego dziecka od rodzica
void idz_do_prawego(drzewo *&wezel, drzewo *&korzen);

//funkcja za pomoc¹ której wracamy do rodzica
void nawroc(drzewo *&wezel, drzewo *&korzen);

//funkcja odczytuj¹ca znaki i kod po lewych liœciach
void lewe_liscie(drzewo *wezel, drzewo *korzen, vector<int> kod, mojakolejka_wynik & kp_wynik);

//funkcja odczytuj¹ca znaki i kod po prawych liœciach
int prawe_liscie(drzewo *wezel, drzewo *korzen, vector<int> kod, mojakolejka_wynik & kp_wynik);

#endif

#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

//obs³uga wyj¹tków

namespace MyRuntimeExceptions
{

	class FileOpenException : public std::runtime_error 
	{
	public:

		FileOpenException() : runtime_error("Nie mozna otworzyc pliku") {
		}

		FileOpenException(string msg) : runtime_error(msg.c_str()) {
		}
	};
}

//funkcja tworz¹ca drzewo wed³ug kodowania huffmana
int huffman(vector<double> tab_prawdo, vector<char> tab_znakow);

//funkcja obliczaj¹ca prawdopodobieñstwo posczególnych znaków na podstawie ich czêstotliwoœci wystêpowania
void oblicz_prawdopodobienstwo(vector<double>& tab_prawdo, vector<int>& tab_czestotliwosc, vector<char>& tab_znakow);

//funkcja odczytuj¹ca dane wejœciowe z pliku tekstowego
void odczyt_z_pliku(string nazwa_pliku_in, vector<int>& tab_czestotliwosc, vector<char>& tab_znakow);

#endif

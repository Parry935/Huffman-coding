#include "pch.h"
#include "Head.h"
#include "Drzewo.h"
#include <iostream>
#include <vector>

using namespace std;


void idz_do_lewego(drzewo *&wezel, drzewo *&korzen)
{
	korzen = wezel;
	wezel = wezel->left;
	wezel->top = korzen;

}

void idz_do_prawego(drzewo *&wezel, drzewo *&korzen)
{
	korzen = wezel;
	wezel = wezel->right;
	wezel->top = korzen;
}

void nawroc(drzewo *&wezel, drzewo *&korzen)
{
	wezel = wezel->top;
	korzen = wezel->top;
}

void lewe_liscie(drzewo * wezel, drzewo * korzen, vector<int> kod, mojakolejka_wynik & kp_wynik)
{
	while (wezel->left != nullptr && wezel->zaliczony != true)
	{
		idz_do_lewego(wezel, korzen);
		kod.push_back(0); //dodanie odpowiednego kodu gdy przechodzimy do lewego wêz³a

		if (wezel->znak != NULL) //jeœli w wêŸle wystêpuje znak
		{
			wynik zapis;  //zapis kodu i znaku do obiektu i dodanie go do kolejki priorytetowej

			zapis.znak = wezel->znak;

			for (int i = 0; i < kod.size(); i++)
				zapis.wynik_kod.push_back(kod[i]);

			kp_wynik.push(zapis);

			nawroc(wezel, korzen);
			kod.pop_back();

			wezel->zaliczony = true;
			prawe_liscie(wezel, korzen, kod, kp_wynik); //jeœli koñczymy na znaku to powracamy i idziemy do prawego wêz³a
		}
	}
}

int prawe_liscie(drzewo * wezel, drzewo * korzen, vector<int> kod, mojakolejka_wynik & kp_wynik)
{
	idz_do_prawego(wezel, korzen);
	kod.push_back(1); //dodanie odpowiednego kodu gdy przechodzimy do prawego wêz³a

	if (wezel->znak != NULL) //jeœli w wêŸle wystêpuje znak
	{
		wynik zapis; //zapis kodu i znaku do obiektu i dodanie go do kolejki priorytetowej

		zapis.znak = wezel->znak;

		for (int i = 0; i < kod.size(); i++)
			zapis.wynik_kod.push_back(kod[i]);

		kp_wynik.push(zapis);

		nawroc(wezel, korzen);
		kod.pop_back(); 

		while (wezel->zaliczony == true && wezel->top != nullptr) //jeœli koñczymy na znaku to powracamy do wêz³a którego prawe dziecko nie zosta³o odwiedzone
		{
			nawroc(wezel, korzen);
			kod.pop_back();
		}

		if (wezel->zaliczony == true && wezel->top == nullptr) //jeœli prawe i lewe dziecko zosta³o odwiedzone oraz znajdujemy siê w korzeniu wtedy zakoñcz rekurencje
			return 0;


		wezel->zaliczony = true;
		prawe_liscie(wezel, korzen, kod, kp_wynik); //przejdz do prawego dziecka

	}

	else
		lewe_liscie(wezel, korzen, kod, kp_wynik); // jeœli w wêŸle nie wystêpuje znak przejdz do lewego dziecka

}




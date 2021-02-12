using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include "pelaaja1.h"
#include  "split.h"
#include <algorithm>
#include"t6.h"


bool vertaa6(t6tilasto a, t6tilasto b)
{
	//sorttaa erotuksen laskevaan järjestykseen, yhtäsuuret erotukset sukunimen mukaan aakkosjärjestykseen
	return (a.erotus > b.erotus) ||
		((a.erotus == b.erotus) && (a.nimi < b.nimi));


}
//ottaa pelaajat.txt:sta splitterillä pelaajan nimen ja halutut pisteet talteen "t6tilasto" objektiin, pushbakkaa sen "tilasto" vectoriin,
//sorttaa vectorin sisällön ja lopuksi tulostus
void t6()
{
	vector <t6tilasto> tilasto;
	string nimi;
	fstream rf;
	rf.open("Pelaajat.txt", ios_base::in);
	//toi i laskuri vaan sitä varten, ettei ota sitä ensimmäistä otsikkoriviä mukaan
	int i = 0;
	while (getline(rf, nimi))
	{
		if (i != 0)
			tilasto.push_back(split6(nimi, '\t'));

		i++;
	}
	sort(tilasto.begin(), tilasto.end(), vertaa6);
	for (t6tilasto s : tilasto)
	{
		cout <<"nimi: "<<s.nimi<< ", (HPA - PPA)= " << s.erotus   << endl;
	}

}
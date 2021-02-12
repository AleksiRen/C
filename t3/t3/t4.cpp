using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include "pelaaja1.h"
#include  "split.h"
#include <algorithm>



//vertaa pelaajia ekaksi seuran ja sen jälkeen nimen perusteella, tarvitaan sorttaamiseen alempana
bool vertaa4(pelaaja1 a, pelaaja1 b)
{
	return (a.Seura < b.Seura) ||
		((a.Seura == b.Seura) && (a.nimi < b.nimi));

		
}
//tekee tekstistä pelaaja1 olioita split3 funktion avulla, sen jälkeen sorttaa ne ja lopuksi tulostus
void t4()
{

	vector <pelaaja1> nimet;
	string nimi;
	fstream rf;
	//toi i laskuri vaan sitä varten, ettei ota sitä ensimmäistä otsikkoriviä mukaan
	//ja iffillä (line 33) kaikki muut paitsi eka rivi mukaan
	int i = 0;
	rf.open("Pelaajat.txt", ios_base::in);
	while (getline(rf, nimi))
	{

		if (i != 0)
		nimet.push_back(split3(nimi, '\t'));
		i++;
	}

	//sorttaa pelaajat seuran ja nimen perusteella vertaa4- funktion avulla
	sort(nimet.begin(), nimet.end(), vertaa4);

	for (pelaaja1 s : nimet)
	{
		cout <<"nimi: "<< s.nimi<<", seura: "<< s.Seura << endl;
	}



}




#include <vector>
#include <string>
#include <iostream>
#include"split.h"
#include"pelaaja1.h"
#include"t6.h"

//t6 splitteri
t6tilasto split6(const std::string & s, char delim)
{
	//ottaa koko tekstirivin tieto kerrallaan talteen vectoriin
	t6tilasto y;
	unsigned int i = 0;
	vector<string> tiedot;
	unsigned pos = s.find(delim);
	while (pos != std::string::npos)
	{
		std::string token = s.substr(i, pos - i);
		//nimi += " " + token;
		tiedot.push_back(token);
		i = ++pos;
		pos = s.find(delim, pos);

	}
	//tuo sit� varten, kun se eka rivi on niit� otsikkoja tiedoille, eik� int parse toimi siin� "+-" otsikossa.
	try { stoi(tiedot[3]); }
	catch (...) { return y; }
	//asettaa t6tilasto-oliolle nimen ja HPA-PPA erotuksen ja palauttaa olion
	y.nimi = tiedot[0];
	y.erotus = stoi(tiedot[6]) - stoi(tiedot[7]);

	return y;

}
//t4/t5 splitteri
pelaaja1 split3(const std::string & s, char delim)
{
	//Toi hakee kaikki tiedot jokaiselle pelaajalle, mutta olisin voinut asettaa pelaaja1:lle 
	//halutessani vain nimen ja seuran esim t4:ssa tarvittavien tietojen mukaan
	pelaaja1 t;
	unsigned int i = 0;
	vector<string> tiedot;
	unsigned pos = s.find(delim);
	while (pos != std::string::npos)
	{
		std::string token = s.substr(i, pos - i);
		//nimi += " " + token;
		tiedot.push_back(token);
		i = ++pos;
		pos = s.find(delim, pos);

	}
	//Tuo alempana oleva try catch sit� varten, kun se eka rivi on niit� otsikkoja tiedoille,
	//eik� int parse toimi siin� "+-" otsikossa. Koodissa ainakin tuossa t5.cpp otan sitten kaikki muut
	//rivit paitsi ton virheellisen ekan talteen. Ei ollut v�ltt�m�tt� kovin fiksu ratkaisu, mutta koska oon huomannut ett� mulla on muutama suurehko
	//aukko ihan koodin perusrakenteidenkin ymm�rt�misess�, niin en nyt ala sit� miettim��n t�ss� kohtaa. My�skin toi structi on aika alkeellinen, mutta pyrin
	//saamaan edes jonkinn�k�isen ratkaisun tehty�
	try { stoi(tiedot[3]); }
	catch (...) { return t; }

	t.nimi = tiedot[0];
	t.Seura = tiedot[1];
	t.PP = tiedot[2];
	t.plusmiinus = stoi(tiedot[3]);
	t.YV = tiedot[4];
	t.AV = tiedot[5];
	t.HPA = stoi(tiedot[6]);
	t.PPA = stoi(tiedot[7]);
	t.Aika = tiedot[8];
	t.YVA = tiedot[9];
	t.AVA = tiedot[10];
	t.AV2A = tiedot[11];
	return t;

}


//t3 splitteri
std::string split(const std::string & s, char delim)
{
	//laittaa toiseen tabulaattoriin, eli seuraan saakka tavaraa stringiin ja palauttaa saadun stringin
	unsigned int i = 0;
	std::string nimi;
	//y = 0 ja y++ joka kierroksella, joten hakee vain toiseen tabulaattoriin saakka teksti�/rivi
	unsigned y = 0;
	unsigned pos = s.find(delim);
	while (y < 2 && pos != std::string::npos)
	{
		
		std::string token = s.substr(i, pos - i);
		nimi += " " + token;
		i = ++pos;
		pos = s.find(delim, pos);
		y++;

	}

	return nimi;

}

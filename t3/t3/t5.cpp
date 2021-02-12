using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include "pelaaja1.h"
#include  "split.h"
#include <algorithm>

//vertailee pelaajien plusmiinusta ja jos plusmiinus on saman arvoinen, laittaa nimen mukaan aakkosj�rjestykseen
bool vertaa5(pelaaja1 a, pelaaja1 b)
{
	return (a.plusmiinus > b.plusmiinus) ||
		((a.plusmiinus == b.plusmiinus) && (a.nimi < b.nimi));



}

void t5()
{
	vector <pelaaja1> nimet;
	string nimi;
	fstream rf;
	rf.open("Pelaajat.txt", ios_base::in);
	//toi i laskuri vaan sit� varten, ettei ota sit� ensimm�ist� otsikkorivi� mukaan
	//ja iffill� (line 32) kaikki muut paitsi eka rivi mukaan
	int i = 0;
	while (getline(rf, nimi))
	{
		if(i != 0)
		nimet.push_back(split3(nimi, '\t'));

		i++;
	}
	sort(nimet.begin(), nimet.end(),vertaa5);
	for (pelaaja1 s : nimet)
	{
		cout << "nimi: " << s.nimi << ", +-: " << s.plusmiinus << endl;
	}

}

#include "pelaaja1.h"
#include "split.h"

void t2() 
{
	//laittaa rivi kerrrallaan tavaraa pelaajat.txt tiedostosta nimet- vectoriin ja 
	//tulostaa ne lopuksi vectorista. Pelaaja1.h:ssa on structi, jota k‰ytet‰‰n seuraavissa teht‰viss‰
	vector <string> nimet;
	string teksti;
	fstream rf;
	rf.open("Pelaajat.txt", ios_base::in);
	int koko = rf.gcount();
	

	while (getline(rf, teksti))
	{
		nimet.push_back(teksti);
	}

	for (string s : nimet)
	{
		cout << s << endl;
	}


}
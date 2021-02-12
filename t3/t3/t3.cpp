#include "pelaaja1.h"
#include "split.h"
#include <algorithm>


//En tehnyt pelaaja1 olioita t�ss� viel�, kun tarvitsi hakea pelk�t nimet, joten tuossa
//haetaan toiseen tabulaattoriin asti riveist� tekstit vectoriin, eli nimet ja seurat.
//split.cpp:ssa on k�ytetty splitteri
void t3() 
{
	vector <string> nimet;
	string nimi;
	fstream rf;
	rf.open("Pelaajat.txt", ios_base::in);
	while (getline(rf, nimi))
	{
		nimet.push_back(split(nimi, '\t'));
		
	}
	sort(nimet.begin(), nimet.end());
	for (string s : nimet)
	{
		cout << s << endl;
	}

}
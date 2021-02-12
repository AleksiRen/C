#pragma once
#include <string>
#include <iostream>
#include <string>
using namespace std;


//En lˆyt‰nyt keinoa kutsua funtiota pelk‰st‰‰n luotavan objektin luokassa, jos nyt ymm‰rsin oikein mit‰ t‰ss‰ haettiin. 
//Ymm‰rt‰‰kseni, child objektit kutsuvat aina base objektin konstruktoria ennen omaansa, 
//joten en usko sen olevan mahdollista, jos base classin konstruktori sis‰lt‰‰ funktiokutsun, oli se sitten virtual tai ei.
//Ellei sitten base objektiin jollain keinolla saa erikseen koodattua m‰‰rittely‰,
//josta se saisi selville onko sit‰ kutsuttu child luokassa ja n‰in j‰tt‰isi sen kutsumatta

//Tuossa alla koitin laittaa saman nimisen function molempiin luokkiin virtual ja ei virtual muodossa, 
//mutta kyll‰h‰n se t‰ll‰ tavoin tehdyll‰ koodilla v‰kisin kutsuu sit‰ kantaluokan kostruktoria ja samalla siell‰ olevaa funktiota

class eka
{
//protected, jotta child classit voivat k‰yt‰‰ sit‰ suoraan

protected:
	//string moi;
	int moi;

public:
	eka() { cout << "defaultti tuli"; }
	eka(int x) : moi(x)
	{

		ff();
		f();
		cout << "tehd‰‰n eka" << endl;
	}

	~eka()
	{
		cout << "tuhottu eka" << endl;
	}
	void tulosta()
	{
		cout << moi << endl;
	}
	//videoesimerkin testaamista varten
	//int p()
	virtual	int p()
	{
		return moi; 
	}

	virtual void f() { cout << "funktio f kutsuttu ekassa "<<endl; }
	void ff() {
		cout << "funk ff kutsuttu ekassa"<<endl;
	}
};

class toka :public eka
{
	//private:
	//string hei;
	int hei;

public:

	toka(int x, int y) : eka(x), hei(y)
	{
		ff();
		f();
		cout << "tehd‰‰n toka" << endl;
	}

	~toka()
	{
		cout << endl << "tuhottu toka" << endl;
	}
	void f() { cout << "funktio f kutsuttu tokassa"<<endl ; }
	void ff() { cout << "funk ff kutsuttu tokassa"<<endl ; }

	int p()
	{
		return moi + hei;
	}
};
void t1() {
	//	eka e("eka");
	toka t(1, 2);
	//videoesimerkin testaamista
	eka *ep = &t;
	cout << "p(): "<<ep->p()<<endl;
}
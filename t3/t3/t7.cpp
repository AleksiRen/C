#include <iostream>
#include <vector>
#include<string>

using namespace std;

//Tää jäi vähän vaiheeseen, joten jätin noi kommentit paikalleen, 
//jotta muistan paremmin omaa ajatuksenkulkua myöhemmin, kun rupeen käymään koodia läpi
class ObjA {
public:
	string name;
	vector<int*> objects;
public:
	ObjA() {};
	ObjA(string n) : name(n) {
	}

	void add(int n) {
		if (objects.capacity() < 512)
			objects.reserve(512);
		objects.push_back(new int(n));
	}
	void print() {
		for (int * val : objects)
			cout <<name <<" Value: " << *val << "\n";
	}
	
	void setValue(int index, int val) {
		*objects[index] = val;
	}
	void setName(string n) {
		name = n;
	}
	//deletoimista varten. En ollut aluksi ihan varma tulisiko tässä nyt poistaa koko array, jossa poistettavat on sisällä, mutta
	//https://stackoverflow.com/questions/26695393/c-and-when-to-use-delete oli aika samanlainen tapaus, joten tein samalla periaatteella ton cleanupin,
	//jolla saa deletoitua objectsin pointtereiden osoittamat 
	//void cleanup()
	//{
	//	for (int * val :objects)
	//	{
	//		delete val;
	//	}

	//}
	//Ilmeisesti tuon voisikin hoitaa destructorilla
	~ObjA()
	{
		for (int * val : objects)
		{
			//cout << name<< ": tuhotaan: " << val << endl;
			delete val;
			
		}
		cout << "ObjA " << name << " objects sisalto tuhottu"<< endl;
	}

};

//ymmärtääkseni oa2 ja oa3 käytänössä asetetaan osoittamaan sinne, mihin oa osoittaa. Objects vektorin arvot ovat siis samat
//kaikissa kolmessa, koska oa2 ja oa3 osoittavat oa:n arvoihin. Jos kaikkissa kolmessa
//täytettäisiin vektorit uusilla arvoilla, kuten oa:ssa, koodin pitäisi toimia. Arvot luultavasti kuitenkin saisi suoraan kopioitua oa2:een ja oa3:een 
//koodissa tehdyllä tavalla, jos osaisi asettaa ne oikeisiin muistipaikkoihin...

//update1
//Nuo oa2 ja oa3 on oa:sta kopioituja omia objektejaan muuten, mutta koska objects:sta kopioidaan pointterit, eikä itse arvoja,
//ne kaikki osoittaa samaan paikkaan
//En oo ihan varma vielä mitä toi vector<int*> oikeasti tarkoittaa. Sinne voi työntää arvoja ihan perusmuodossa, mutta se näyttää ne kuitenkin pointtereina?

//update2
//Ahaa eli sinne ei voinutkaan työntää arvoja perusmuodossa vaan ne piti laittaa (new int(n)). 
//https://www.quora.com/What-is-new-int-in-C
//Tässä nyt vasta aloin ymmärtämään mitä se dynaaminen muistinvaraus käytännössä tarkoittaa, vaikka se on tullut ainakin sata kertaa eteen jo aiemmin.
//Se new int() palauttaa siis osoitteen ja sinne objectsiin tallentuu kai pointterit niihin dynaamisesti allocoituihin integereihin, 
//jotka oikeasti sijaitsevat jossain päin heappia.
//Eli jos nuo oa2 ja oa3 kopioidaan oa:sta, ne saavat pointterit samoihin heapissa sijaitseviin intteihin, jotka allocoitiin oa:ta tehdessä.
//En kyllä vieläkään tiedä miten oa2 ja oa3 saisivat omat arvonsa heappiin muuten kuin allocoimalla ne samoin kuin oa:lle, joten teen sen nyt niin,
//ja opin toivottavasti mallivastauksista vähän lisää

int t7() {
	ObjA oa("Eka");
	for (int i = 0; i < 5; i++) {
		oa.add(i);
	}
	cout << "oa: \n";
	oa.print();
	//Miten tuo konstruktori toimii kun sille antaa argumentiksi valmiin luokan?
	//Tässä taitaakin olla kyseessä copyconstructori
	//ObjA oa2(oa);
	//oa2.setName("Toka");
	ObjA oa2("Toka");
	for (int i = 0; i < 5; i++) {
		oa2.add(i);
	}
	cout << "oa2: \n";
	oa2.print();

	//tässä vaan oa:sta kopio?
	//ObjA oa3;	
	//oa3 = oa;
	ObjA oa3("Kolmas");
	for (int i = 0; i < 5; i++) {
		oa3.add(i);
	}
	//oa3.setName("Kolmas");
	cout << "oa3: \n";
	oa3.print();

	oa.setValue(0, 100);
	oa2.setValue(1, 200);
	oa3.setValue(2, 300);

	cout << "oa: \n";
	oa.print();

	cout << "oa2: \n";
	oa2.print();

	cout << "oa3: \n";	
	oa3.print();

	//deletointi
	//oa.cleanup();
	//oa2.cleanup();
	//oa3.cleanup();

	//cout << "kolmas muisti" << (void*)&oa3.objects[0] << " kolmas eka obj: " << oa3.objects[0]<< endl;
	//cout << "toka muisti" << (void*)&oa2.objects[0] << " toine eka obj: " << oa2.objects[0] << endl;
	//cout << "eka muisti" << (void*)&oa.objects[0] << " eka eka obj: " << oa.objects[0] << endl;

	return 0;
}

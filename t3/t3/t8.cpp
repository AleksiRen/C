#include<vector>
#include <string>
#include<iostream>;
#include <map>;
using namespace std;

void t8()
{
	char c;
	cout << "anna teksti: ";
	//oli toisella kurssilla saman tyyppinen tehtävä ja siinä käytin dictionarya pythonilla,
	//joten mappi vaikutti ihan hyvältä valinnalta tähän
	std::map<char, int> m = {};
	vector<char> keys;
	//toi cin.get() taitaa ottaa kaikki merkit huomioon, mutta se tuskin haittaa
	while (cin.get(c))
	{
		//entteri breakkaa
		if (c == '\n')
			break;
		
		//jos mapista löytyy vuorossa oleva kirjain, lisätään sen esiintymiskertojen määrää yhdellä
		map<char, int>::iterator it = m.find(c);
		if (it != m.end())
		{
			it->second++;
		}

		//muutoin lisätään mappiin kyseinen kirjain ja ykkönen kirjainten lukumääräksi
		else
		{
			//ei ota välilyöntejä huomioon
			if(c != ' ')
			m.insert(pair<char, int>(c, 1));
		}

	
	}

	//mapin tulostus
	for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << it->first << "=" << it->second<<", ";

	}

}


#include<vector>
#include <string>
#include<iostream>;
#include <map>;
using namespace std;

void t8()
{
	char c;
	cout << "anna teksti: ";
	//oli toisella kurssilla saman tyyppinen teht�v� ja siin� k�ytin dictionarya pythonilla,
	//joten mappi vaikutti ihan hyv�lt� valinnalta t�h�n
	std::map<char, int> m = {};
	vector<char> keys;
	//toi cin.get() taitaa ottaa kaikki merkit huomioon, mutta se tuskin haittaa
	while (cin.get(c))
	{
		//entteri breakkaa
		if (c == '\n')
			break;
		
		//jos mapista l�ytyy vuorossa oleva kirjain, lis�t��n sen esiintymiskertojen m��r�� yhdell�
		map<char, int>::iterator it = m.find(c);
		if (it != m.end())
		{
			it->second++;
		}

		//muutoin lis�t��n mappiin kyseinen kirjain ja ykk�nen kirjainten lukum��r�ksi
		else
		{
			//ei ota v�lily�ntej� huomioon
			if(c != ' ')
			m.insert(pair<char, int>(c, 1));
		}

	
	}

	//mapin tulostus
	for (map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
		cout << it->first << "=" << it->second<<", ";

	}

}


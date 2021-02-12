#pragma once
#pragma once
#include <string>
#include <vector>
#include <fstream>
#include<iostream>
using namespace std;

//t2n structi pelaajia varten, k‰ytet‰‰n aika monessa teht‰v‰ss‰. Laitoin teht‰vien mukaan muutaman arvon intiksi
struct pelaaja1
{
	string nimi;
	string Seura;
	string PP;
	int plusmiinus;
	string YV;
	string AV;
	int HPA;
	int PPA;
	string Aika;
	string YVA;
	string YV2A;
	string AVA;
	string AV2A;
};





















class pelaaja
{
public:
	string nimi;
	string Seura;
	string PP;
	string plusmiinus;
	string YV;
	string AV;
	string HPA;
	string PPA;
	string Aika;
	string YVA;
	string YV2A;
	string AVA;
	string AV2A;

public:
	pelaaja(string nimix) { nimi = nimix; }
	//nimi = nimix;
	//Seura = Seurax;
	//PP = PPx;
	//plusmiinus = plusmiinusx;
	//YV = YVx;
	//AV = AVx;
	//HPA = HPAx;
	//PPA = PPAx;
	//Aika = Aikax;
	//YVA = YVAx;
	//YV2A = YV2Ax;
	//AVA = AVAx;
	//AV2A = AV2Ax;
	/*pelaaja(string nimix, string Seurax, string PPx, string plusmiinusx, string YVx,
		string AVx, string HPAx, string PPAx, string Aikax, string YVAx, string YV2Ax, string AVAx, string AV2Ax) {}*/
};
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Krajina
{
	string nazov;
	int pocetStrelenychG=0;
	int pocetInkasovanychG=0;
	int pocetBodov=0;

public:
	Krajina(string pnazov);
	~Krajina();
	void setPocetStrelenychG(int pPocetStrelenychG);
	void setPocetInkasovanychG(int pPocetInkasovanychG);
	void setPocetBodov(int pPocetBodov);
	int getPocetStrelenychG();
	int getPocetInkasovanychG();
	int getPocetBodov();
	string getNazov();

};


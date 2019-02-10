#include "Krajina.h"



Krajina::Krajina(string pnazov)
{
	nazov = pnazov;
}


Krajina::~Krajina()
{
}

void Krajina::setPocetStrelenychG(int pPocetStrelenychG)
{
	pocetStrelenychG = pocetStrelenychG + pPocetStrelenychG;
}

void Krajina::setPocetInkasovanychG(int pPocetInkasovanychG)
{
	pocetInkasovanychG = pocetInkasovanychG + pPocetInkasovanychG;
}

void Krajina::setPocetBodov(int pPocetBodov)
{
	pocetBodov = pocetBodov + pPocetBodov;
}

int Krajina::getPocetStrelenychG()
{
	return pocetStrelenychG;
}

int Krajina::getPocetInkasovanychG()
{
	return pocetInkasovanychG;
}

int Krajina::getPocetBodov()
{
	return pocetBodov;
}

string Krajina::getNazov()
{
	return nazov;
}

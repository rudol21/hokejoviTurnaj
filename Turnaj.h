#pragma once
#include "Krajina.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

class Turnaj
{
	vector <Krajina*> timyTurnaja;
public:
	Turnaj();
	~Turnaj();
	void nacitajTimy(const char* menoSuboru);
	void startTurnaja();
	void vyhodnotenie();
	

};


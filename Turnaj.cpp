#include "Turnaj.h"

#include <iomanip>

Turnaj::Turnaj()
{
	srand(time(NULL));
}


Turnaj::~Turnaj()
{
	for (auto &p : timyTurnaja)
	{
		delete p;
	}
	timyTurnaja.clear();
}

void Turnaj::nacitajTimy(const char * menoSuboru)
{
	string krajina;
	ifstream cin(menoSuboru);

	while (cin >> krajina)
	{
		timyTurnaja.push_back(new Krajina(krajina));
	}
}

void Turnaj::startTurnaja()
{
	int timI;
	int timJ;
	string subor;
	fstream zapisovac("suborNaZapis.txt");
	for (int i = 0; i < 5; i++)
	{
		for (int j = i+1; j < 6; j++)
		{
			timI = rand() % 10;
			timJ = rand() % 10;
			cout << timyTurnaja[i]->getNazov() << " " << timI << ":" << timJ << " " << timyTurnaja[j]->getNazov()<<endl;
			zapisovac << timyTurnaja[i]->getNazov() << ":" << timyTurnaja[j]->getNazov() << endl << timI << ":" << timJ << endl;

			if (timI < timJ)
			{
				timyTurnaja[j]->setPocetBodov(2);
			}
			if (timI > timJ)
			{
				timyTurnaja[i]->setPocetBodov(2);
			}
			if (timI == timJ)
			{
				timyTurnaja[i]->setPocetBodov(1);
				timyTurnaja[j]->setPocetBodov(1);
			}
			timyTurnaja[i]->setPocetStrelenychG(timI);
			timyTurnaja[j]->setPocetStrelenychG(timJ);
			timyTurnaja[i]->setPocetInkasovanychG(timJ);
			timyTurnaja[j]->setPocetInkasovanychG(timI);


		}
	}
	zapisovac.close();
}

bool wayToSort(Krajina *s1, Krajina *s2) { return s1->getPocetBodov() > s2->getPocetBodov(); };
void Turnaj::vyhodnotenie()
{	
		sort(timyTurnaja.begin(), timyTurnaja.end(), wayToSort);
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 5; i++)
			{
				if (timyTurnaja[i]->getPocetBodov() == timyTurnaja[i + 1]->getPocetBodov())
				{
					vector <Krajina*> pom;
					if (timyTurnaja[i]->getPocetStrelenychG() < timyTurnaja[i + 1]->getPocetStrelenychG())
					{
						pom.push_back(timyTurnaja[i]);
						timyTurnaja[i] = timyTurnaja[i + 1];
						timyTurnaja[i + 1] = pom[0];
					}
				}
			}
		}

		for (int i = 0; i < 6; i++)
		{
			cout <<setw(10) << left << timyTurnaja[i]->getNazov() <<"  "<< timyTurnaja[i]->getPocetStrelenychG() << "-" << timyTurnaja[i]->getPocetInkasovanychG() << " /" << timyTurnaja[i]->getPocetBodov()<<endl;
		}
}

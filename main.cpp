#include "Krajina.h"
#include "Turnaj.h"

int main(int argc, char * argv[])
{
	Turnaj *t = new Turnaj();
	t->nacitajTimy("suborNaCitanie.txt");
	t->startTurnaja();
	t->vyhodnotenie();
	delete t;
}
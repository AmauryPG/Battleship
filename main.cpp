#include "bateau.h"
#include "AIfacile.h"
#include "Usager.h"


int main()
{
	srand((unsigned)time(0));
	/*Test de la classe usager*/
	Usager ludo;
	ludo.imprimeTableau();
	ludo.placer();
	/*Test de la classe AIfacile*/
//	AIfacile comp;
//	comp.placer();
//	comp.imprimeTableau();
	/*
	for (int i = 0; i < 20; i++)
	{
		comp.tirer(x,y);
	}
	comp.imprimeTableau();
	//	system("pause");
	*/
	return 0;
}
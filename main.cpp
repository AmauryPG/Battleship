#include "bateau.h"
#include "AIfacile.h"


int main()
{
	srand((unsigned)time(0));
	AIfacile comp;
	comp.placeBateau(comp.getBateau(1));
	//comp.placeBateau(comp.getBateau(2));
	comp.placeBateau(comp.getBateau(3));
	comp.placeBateau(comp.getBateau(4));
	comp.placeBateau(comp.getBateau(5));
	comp.imprimeTableau();
	/*
	for (int i = 0; i < 20; i++)
	{
		comp.tire();
	}
	comp.imprimeTableau();
	*/
	return 0;
}
#include "bateau.h"
#include "AIfacile.h"


int main()
{
//	int x, y;
	srand((unsigned)time(0));
	AIfacile comp;
	comp.placer();
	comp.imprimeTableau();
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
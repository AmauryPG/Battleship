#include "bateau.h"
#include "AIfacile.h"


int main()
{
	srand((unsigned)time(0));
	AIfacile comp;
	comp.placer();
	comp.imprimeTableau();
	for (int i = 0; i < 20; i++)
	{
		comp.tirer();
	}
	comp.imprimeTableau();
	//	system("pause");
	return 0;
}
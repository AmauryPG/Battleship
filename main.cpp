#include "bateau.h"
#include "AImoyen.h"
#include "AIavancer.h"

#define VIDE	-1
#define ECHEC	-2
#define TOUCHE	-3

int main()
{
	int x, y;
	AImoyen ai; 

	ai.placer();

	ai.imprimer();

	return 0;
}
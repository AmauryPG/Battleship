#include "bateau.h"
#include "AImoyen.h"
#include "AIavancer.h"

#define VIDE	-1
#define ECHEC	-2
#define TOUCHE	-3

int main()
{
	int x, y;
	AIavancer ai; 

	ai.tirer(x, y);

	return 0;
}
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

	for (int i = 0; i < 5; i++)
	{
		ai.tirer(x, y);

		cout << x << " : " << y << endl;
	}

	return 0;
}
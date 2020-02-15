#include "bateau.h"
#include "AImoyen.h"

#define VIDE	-1
#define ECHEC	-2
#define TOUCHE	-3

int main()
{
	AImoyen ai;

	ai.placer();

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			switch (ai.m_jeu[x][y])
			{
			case VIDE:
				cout << " - ";
				break;
			case ECHEC:
				cout << " E ";
				break;
			case TOUCHE:
				cout << " T ";
				break;
			default:
				cout << " " << ai.m_jeu[x][y] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}
#pragma once
#include "AIfacile.h"
#include "Usager.h"

class Jeu
{
	int x, y;
	int nbVieJoueur1;
	int nbVieJoueur2;
	Usager joueur1;
	AIfacile joueur2;

public:
	Jeu();
	~Jeu();

	void jouer();
};
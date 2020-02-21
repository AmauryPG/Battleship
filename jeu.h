#pragma once
#include "AIfacile.h"

class Jeu
{
	int x, y;
	int nbVieJoueur1;
	int nbVieJoueur2;
	AIfacile joeur1;
	AIfacile joueur2;

public:
	Jeu();
	~Jeu();

	void jouer();
};
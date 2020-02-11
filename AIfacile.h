#pragma once
#include "bateau.h"

#define largeur 10
#define hauteur 10

struct AireDeJeu
{
	int tableau[10][10];
};
class AIfacile
{
	Bateau bateau1;
	Bateau bateau2;
	Bateau bateau3;
	Bateau bateau4;
	Bateau bateau5;
	AireDeJeu jeu;


public:
	AIfacile();
	void imprimeTableau();
	bool placeBateau(Bateau& b);
	bool tire();
	Bateau& getBateau(int num);

};

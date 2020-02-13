#pragma once
#include "bateau.h"




class AIfacile
{
	Bateau bateaux[5];

public:
	AireDeJeu jeu;
	AireDeJeu ecran;
	AIfacile();
	void imprimeTableau();
	virtual void placeBateau();
	virtual void tire();
};

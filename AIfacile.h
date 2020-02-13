#pragma once
#include "bateau.h"

class AIfacile
{
	
	Bateau bateaux[5];
	AireDeJeu jeu;
	AireDeJeu ecran;

public:
	AIfacile();
	void imprimeTableau();
	virtual void placeBateau();
	virtual void tire();
	

};

#pragma once
#include "bateau.h"

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
	virtual bool placeBateau(Bateau& b);
	virtual bool tire();
	Bateau& getBateau(int num);
	void couleBateau();
	

};

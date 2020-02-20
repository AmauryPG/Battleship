#pragma once
#include "bateau.h"
#include "Joueur.h"

class AIfacile : public Joueur
{
	/*
	Bateau bateaux[5];
	int jeu[10][10];
	int ecran[10][10];
	*/

public:
	AIfacile();
	void imprimeTableau();
	virtual void placer();
	virtual void tirer(int &x, int &y);


};
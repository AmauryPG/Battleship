#pragma once
#include "bateau.h"
#include "Joueur.h"

<<<<<<< Updated upstream
class AIfacile
{
	
	Bateau bateaux[5];
	AireDeJeu jeu;
	AireDeJeu ecran;
=======
class AIfacile: public Joueur
{
	/*
	Bateau bateaux[5];
	int jeu[10][10];
	int ecran[10][10];
	*/
>>>>>>> Stashed changes

public:
	AIfacile();
	void imprimeTableau();
<<<<<<< Updated upstream
	virtual void placeBateau();
	virtual void tire();
=======
	virtual void placer();
	virtual void tirer();
>>>>>>> Stashed changes
	

};

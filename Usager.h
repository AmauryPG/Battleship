#pragma once
#include "Joueur.h"
class Usager : public Joueur
{

public:
	Usager();
	void imprimeTableau();
	void tirer(int &x, int &y);
//	void autoPlacer();
	void placer();
};
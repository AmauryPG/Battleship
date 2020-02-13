#pragma once
#include "bateau.h"

#define NORD  0
#define EST   1
#define SUD   2
#define OUEST 3

class Joueur {
protected:
	int m_jeu[10][10];
	int m_ecran[10][10];
	
	Bateau m_bateau[4];
	/*
	*	nom			|	index	|	taille
	*patrol boat		0			2
	*submarin			1			3
	*destroyer			2			3
	*battleship			3			4
	*carrier			4			5
	*/

public:
	virtual void tirer();
	virtual void placer();
};

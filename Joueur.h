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
	Joueur()
	{
		//patrol boat
		m_bateau[0].setTaille(2);
		m_bateau[0].InitialPointDeVie();

		//submarin
		m_bateau[1].setTaille(3);
		m_bateau[1].InitialPointDeVie();

		//destroyer
		m_bateau[2].setTaille(3);
		m_bateau[2].InitialPointDeVie();

		//battleship
		m_bateau[3].setTaille(4);
		m_bateau[3].InitialPointDeVie();

		//carrier
		m_bateau[4].setTaille(5);
		m_bateau[4].InitialPointDeVie();
	}

	~Joueur();

	virtual void tirer() = 0;
	virtual void placer() = 0;
};

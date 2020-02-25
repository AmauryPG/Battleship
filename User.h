#pragma once

#include "bateau.h"
#include "Joueur.h"
#include <iostream>

using namespace std;

class User : public Joueur{

public:

	User();
	~User();

	int ChoisirDirection();
	AncrageBateau ChoisirAncrage();
	void PlacerBateau(Bateau, int);
	
	void InitCarte();
	void displayCarte();

	void tirer(int &x, int &y);
	void placer();

private:
	
	

};
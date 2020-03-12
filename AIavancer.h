#pragma once 
#include "Joueur.h"

class AIavancer : public Joueur{
private:
	int m_distribution[10][10];
	int m_enemie[10][10];
	 
	bool PriorisationZoneTouche();
	bool AnalyseDirection();
	bool RechercheExhaustif(int longueur);

	void chercherMeilleurCase(int& x, int& y);
	 
public:
	AIavancer();

	~AIavancer();

	void imprimer();

	void affichageTableau(int tableau[10][10]);

	void PreAnalyse(const int tableau[10][10]);

	void tirer(int& x, int& y);
	void placer();
};

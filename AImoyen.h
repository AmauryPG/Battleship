#pragma once

#include "Joueur.h"

class AImoyen : public Joueur {
private:
	int m_prochainX = -1, m_prochainY = -1;
	int m_toucheX = 4, m_toucheY = 4;
	int m_sequence = 0;
	bool m_chasse = false;

	void placement(int& x, int& y);
public:
	AImoyen();
	~AImoyen();

	void tirer(int& x, int& y);
	void placer();

	void imprimer();
};
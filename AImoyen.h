#pragma once

#include "Joueur.h"

class AImoyen : public Joueur {
private:
	int m_prochainX = -1, m_prochainY = -1;
	int m_toucheX, m_toucheY;
	int m_sequence = 0;
	bool m_chasse = false;
public:
	AImoyen();
	~AImoyen();

	void tirer();
	void placer();
};
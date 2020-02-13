#pragma once

#include "Joueur.h"

class AImoyen : public Joueur {
public:
	AImoyen();
	~AImoyen();

	void tirer();
	void placer();
};
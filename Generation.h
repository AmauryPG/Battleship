#pragma once
#include "Individu.h"

class Generation
{
private:
	Individu individu[1000];

public:
	Generation();
	Generation(Individu individus[1000]);

	~Generation();

	Generation nouvelleGeneration();

	void printFitness();

};

#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Individu
{
private: 
	const char acceptableGene[16] = "0123456789+-*/n"; 
	string geneX = "";
	string geneY = "";
	int fitness;

	string mutation();

public:
	Individu();
	Individu(string geneX, string geneY);
	~Individu();

	int getFitness();
	void setFitness(int tour);

	string getGeneY();
	string getGeneX();

	void setGeneY(string NouveauGene);
	void setGeneX(string NouveauGene);

	Individu mate(Individu mate);

	int getOutputX(int n);
	int getOutputY(int n);

	Individu &egalite(Individu indi);
	
};

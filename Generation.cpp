#include "Generation.h"

Generation::Generation()
{
	for (int i = 0; i < 1000; i++)
	{
		individu[i].setFitness(i);
	}
}

Generation::Generation(Individu individus[1000])
{
	for (int i = 0; i < 1000; i++)
	{
		this->individu[i].setFitness(individu->getFitness());
		this->individu[i].setGeneX(individu->getGeneX());
		this->individu[i].setGeneY(individu->getGeneY());
	}
}

Generation::~Generation()
{
}

//juste pour une taille de 500
Individu randomIndividu(int fitnessTotal, Individu individu[])
{
	int rnd = rand() % fitnessTotal;
	for (int i = 0; i < 500; i++)
	{
		if (rnd < individu[i].getFitness())
		{
			return individu[i];
		}
		rnd -= individu[i].getFitness();
	}
}

Generation Generation::nouvelleGeneration()
{
	//decimation d'un certain pourcentage selon le score
	int totalFitness = 0;
	Individu retour[1000];

	for (int i = 0; i < 1000; i++)
	{
		totalFitness += individu[i].getFitness();
	}

	int rnd;
	
	//Thanos snap 50% of the population
	for (int k = 0; k < 500; k++)
	{
		rnd = rand() % totalFitness;
		for (int i = 0; i < 1000; i++)
		{
			if (rnd < individu[i].getFitness())
			{
				individu[i].setFitness(-1);
				break;
			}
			rnd -= individu[i].getFitness();
		}
	}

	int k = 0;

	//construction d'une nouvelle liste avec les survivants
	for (int i = 0; i < 500; i++)
	{
		if (individu[i].getFitness() != -1)
		{
			retour[k].egalite(individu[i]);
			k++;
			cout << k << " : " << retour[k].getFitness() << endl;
		}
	} 

	return retour;
}

void Generation::printFitness()
{
	for (int i = 0; i < 1000; i++)
	{
		cout << i << " : " << individu[i].getFitness() << endl;
	}
}

#include "Individu.h"

Individu::Individu()
{
	srand(time(NULL));

	do
	{
		geneX += acceptableGene[rand() % 16];
	} while (rand() % 100 > 50);

	do
	{
		geneY += acceptableGene[rand() % 16];
	} while (rand() % 100 > 50);

	fitness = 0;
}

Individu::Individu(string geneX, string geneY)
{
	this->geneX = geneX;
	this->geneY = geneY;
}

Individu::~Individu()
{

}

int Individu::getOutputY(int n)
{
	//un try catch pour les diviser par 0
	try
	{
		//analyse du gene et le retour d'une position

	}
	catch (const domain_error & e)
	{
		fitness = 0;
		e.what();
	}

	return 0;
}

Individu& Individu::egalite(Individu indi)
{
	Individu *temp = new Individu();

	temp->fitness = this->fitness = indi.getFitness();
	temp->geneX = this->geneX = indi.getGeneX();
	temp->geneY = this->geneY = indi.getGeneY();

	return *temp;
}

int Individu::getOutputX(int n)
{ 
	//un try catch pour les diviser par 0
	try
	{
		//analyse du gene et le retour d'une position

	}
	catch (const domain_error& e)
	{
		fitness = 0;
		e.what();
	}

	return 0;
}

string Individu::getGeneX()
{
	return geneX;
}

string Individu::getGeneY()
{
	return geneY;
}

void Individu::setGeneX(string NouveauGene)
{
	geneX = NouveauGene;
}

void Individu::setGeneY(string NouveauGene)
{
	geneY = NouveauGene;
}

void Individu::setFitness(int tour)
{
	fitness = tour;
}

int Individu::getFitness()
{
	return fitness;
}

string Individu::mutation()
{
	string retourString = "";
	do
	{
		retourString += acceptableGene[rand() % 16];
	} while (rand() % 100 > 35);

	return retourString;
}

Individu Individu::mate(Individu mate)
{
	string geneEnfantX;
	string geneEnfantY;
	//on prend la plus petit longueur des deux
	
	int possibilite;

	for (int i = 0; i < geneX.length(); i++)
	{
		possibilite = rand() % 100;

		if (possibilite < 45)
		{
			//parent 1
			geneEnfantX += this->geneX[i];
		}
		else if (possibilite < 80)
		{
			//parent 2
			geneEnfantX += mate.geneX[i];
		}
		else
		{
			//mutation
			geneEnfantX += mutation();
		}
	}

	for (int i = 0; i < geneY.length(); i++)
	{
		possibilite = rand() % 100;

		if (possibilite < 45)
		{
			//parent 1
			geneEnfantY += this->geneY[i];
		}
		else if (possibilite < 80)
		{
			//parent 2
			geneEnfantY += mate.geneY[i];
		}
		else
		{
			//mutation
			geneEnfantY += mutation();
		}
	}

	return Individu(geneEnfantX, geneEnfantY);
}


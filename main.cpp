#include "bateau.h"
#include "AImoyen.h"
#include "AIavancer.h"

#include "Generation.h"

#define VIDE	-1
#define ECHEC	-2
#define TOUCHE	-3

int main()
{
	Individu ind1;   
	Individu ind2;   
	Individu enfant = ind1.mate(ind2);

	cout << ind1.getGeneX() << " : " << ind1.getGeneY() << endl;
	cout << ind2.getGeneX() << " : " << ind2.getGeneY() << endl;
	cout << enfant.getGeneX() << " : " << enfant.getGeneY() << endl;

	Generation ger;

	ger.printFitness();

	Generation nouvelle = ger.nouvelleGeneration(); 

	return 0;
}
 #include "bateau.h"
#include "AIfacile.h"


int main()
{
	srand((unsigned)time(0));
	AIfacile comp;
	comp.placeBateau();
	comp.imprimeTableau();
	/*
	comp.placeBateau(comp.getBateau(1));
	comp.placeBateau(comp.getBateau(2));
	comp.placeBateau(comp.getBateau(3));
	comp.placeBateau(comp.getBateau(4));
	comp.placeBateau(comp.getBateau(5));
	comp.imprimeTableau();

	cout << "nombre vie initial de chaque bateau: " << endl;
	cout << "Bateau1 = ID = "<<comp.getBateau(1).getId()<<" = " << comp.getBateau(1).getPointDeVie() << endl;
	cout << "Bateau2 = ID = " << comp.getBateau(2).getId() << " = " << comp.getBateau(2).getPointDeVie() << endl;
	cout << "Bateau3 = ID = " << comp.getBateau(3).getId() << " = " << comp.getBateau(3).getPointDeVie() << endl;
	cout << "Bateau4 = ID = " << comp.getBateau(4).getId() << " = " << comp.getBateau(4).getPointDeVie() << endl;
	cout << "Bateau5 = ID = " << comp.getBateau(5).getId() << " = " << comp.getBateau(5).getPointDeVie() << endl;
	//attaque
	for (int i = 0; i < 20; i++)
	{
		comp.tire();
	}
	comp.imprimeTableau();

	cout << "nombre vie final de chaque bateau: " << endl;
	cout << "Bateau1 = ID = " << comp.getBateau(1).getId() << " = " << comp.getBateau(1).getPointDeVie() << endl;
	cout << "Bateau2 = ID = " << comp.getBateau(2).getId() << " = " << comp.getBateau(2).getPointDeVie() << endl;
	cout << "Bateau3 = ID = " << comp.getBateau(3).getId() << " = " << comp.getBateau(3).getPointDeVie() << endl;
	cout << "Bateau4 = ID = " << comp.getBateau(4).getId() << " = " << comp.getBateau(4).getPointDeVie() << endl;
	cout << "Bateau5 = ID = " << comp.getBateau(5).getId() << " = " << comp.getBateau(5).getPointDeVie() << endl;
	*/
	return 0;
}
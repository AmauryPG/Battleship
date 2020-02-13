#include "AIfacile.h"


AIfacile::AIfacile()
{
	//creation  de bateaux
	//patrol boat (2 vies)
	int dir;
	dir = rand() % 4;
	bateaux[0].setTaille(2);
	bateaux[0].setDirection(dir);
	bateaux[0].InitialPointDeVie();

	//submarine (3 vies)
	dir = rand() % 4;
	bateaux[1].setTaille(3);
	bateaux[1].setDirection(dir);
	bateaux[1].InitialPointDeVie();

	//destroyer (3 vies)
	dir = rand() % 4;
	bateaux[2].setTaille(3);
	bateaux[2].setDirection(dir);
	bateaux[2].InitialPointDeVie();

	//battleship (4 vies)
	dir = rand() % 4;
	bateaux[3].setTaille(4);
	bateaux[3].setDirection(dir);
	bateaux[3].InitialPointDeVie();

	//Carrier (5 vies)
	dir = rand() % 4;
	bateaux[4].setTaille(5);
	bateaux[4].setDirection(dir);
	bateaux[4].InitialPointDeVie();

	
	// init du tableau
	for (int i = 0; i < largeur; i++)
	{
		for (int j = 0; j < hauteur; j++)
		{
			jeu.tableau[i][j] = -1;
		}
	}
}

	void AIfacile::imprimeTableau()
	{
		for (int i = 0; i < largeur; i++)
		{
			for (int j = 0; j < hauteur; j++)
			{
				cout << jeu.tableau[i][j]<<"\t";
			}
			cout << endl;
			cout << endl;
		}
	}

	void AIfacile::placeBateau()
	{
		int bateauxPlacer;

		for (int i = 0; i < 5; i++)
		{
			bateauxPlacer = 0;

			while (bateauxPlacer != 1)
			{
				cout << "=====================================" << endl;
				int ancrageX = rand() % 10;
				int ancrageY = rand() % 10;
				AncrageBateau anc{ ancrageX, ancrageY };
				bateaux[i].setAncrage(anc);
				int ctr = 0;
				cout << "ancrage = (" << bateaux[i].getAncrage().x << "," << bateaux[i].getAncrage().y << ")" << endl;
				cout << "Taille = " << bateaux[i].getTaille() << " Direction = " << bateaux[i].getDirection() << endl;
				cout << "Identifiant est " << bateaux[i].getId() << " Nombre de vie est " << bateaux[i].getPointDeVie() << endl;

				//direction 0
				if (bateaux[i].getDirection() == 0)
				{
					if (bateaux[i].getAncrage().x - bateaux[i].getTaille() > 0)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x - n][bateaux[i].getAncrage().y] != -1)
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x - n][bateaux[i].getAncrage().y] = i;
								bateauxPlacer = 1;
							}
						}
					}
					else
					{
						cout << "try again" << endl;
					}
				}

				// direction 1
				if (bateaux[i].getDirection() == 1)
				{
					if (bateaux[i].getAncrage().y + bateaux[i].getTaille() < largeur)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y + n] != -1)
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y + n] = i;
								bateauxPlacer = 1;
							}
						}
					}
					else
					{
						cout << "try again" << endl;
					}
				}

				// direction 2
				if (bateaux[i].getDirection() == 2)
				{
					if (bateaux[i].getAncrage().x + bateaux[i].getTaille() < hauteur)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x + n][bateaux[i].getAncrage().y] != -1)
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x + n][bateaux[i].getAncrage().y] = i;
								bateauxPlacer = 1;
							}
						}
					}
					else
					{
						cout << "try again" << endl;
					}
				}

				// direction 3

				if (bateaux[i].getDirection() == 3)
				{
					if (bateaux[i].getAncrage().y - bateaux[i].getTaille() > 0)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y - n] != -1)
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y - n] = i;
								bateauxPlacer = 1;
							}
						}
					}
					else
					{
						cout << "try again" << endl;
					}
				}
				cout << "=====================================" << endl;
			}
			bateauxPlacer = 0;
		}
	}

	void AIfacile::tire()
	{

		bool tireConfirme = false;
		while (tireConfirme == 0)
		{
			int i = rand() % 10;
			int j = rand() % 10;

			cout << "Tire la case: (" << i << ", " << j << ")" << endl;
			if (jeu.tableau[i][j] == -1)
			{
				jeu.tableau[i][j] = -2;
				tireConfirme = true;
			}
			else if (jeu.tableau[i][j] == 0)
			{
				bateaux[0].ajustPointDeVie();
				jeu.tableau[i][j] = -3;
				tireConfirme = true;
			}

			else if (jeu.tableau[i][j] == 1)
			{
				bateaux[1].ajustPointDeVie();
				jeu.tableau[i][j] = -3;
				tireConfirme = true;
			}

			else if (jeu.tableau[i][j] == 2)
			{
				bateaux[2].ajustPointDeVie();
				jeu.tableau[i][j] = -3;
				tireConfirme = true;
			}

			else if (jeu.tableau[i][j] == 3)
			{
				bateaux[3].ajustPointDeVie();
				jeu.tableau[i][j] = -3;
				tireConfirme = true;
			}

			else if (jeu.tableau[i][j] == 4)
			{
				bateaux[4].ajustPointDeVie();
				jeu.tableau[i][j] = -3;
				tireConfirme = true;
			}
		}
	}

	
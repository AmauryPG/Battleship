#include "AIfacile.h"


AIfacile::AIfacile()
{
	int dir;
	//creation  de bateaux
	dir = rand() % 4;
	bateau1.setTaille(3);
	bateau1.setDirection(dir);
	bateau1.InitialPointDeVie();
	bateau1.setId(4);

	dir = rand() % 4;
	bateau2.setTaille(3);
	bateau2.setDirection(dir);
	bateau2.InitialPointDeVie();
	bateau2.setId(5);

	dir = rand() % 4;
	bateau3.setTaille(4);
	bateau3.setDirection(dir);
	bateau3.InitialPointDeVie();
	bateau3.setId(6);

	dir = rand() % 4;
	bateau4.setTaille(5);
	bateau4.setDirection(dir);
	bateau4.InitialPointDeVie();
	bateau4.setId(7);

	dir = rand() % 4;
	bateau5.setTaille(2);
	bateau5.setDirection(dir);
	bateau5.InitialPointDeVie();
	bateau5.setId(3);

	// init du tableau
	for (int i = 0; i < largeur; i++)
	{
		for (int j = 0; j < hauteur; j++)
		{
			jeu.tableau[i][j] = 0;
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

	bool AIfacile::placeBateau(Bateau& b)
	{
		int bateauxPlacer = 0;

		while (bateauxPlacer != 1)
		{
			cout << "=====================================" << endl;
			int ancrageX = rand() % 10;
			int ancrageY = rand() % 10;
			AncrageBateau anc{ ancrageX, ancrageY };
			b.setAncrage(anc);
			int ctr = 0;
			cout << "ancrage = (" << b.getAncrage().x<< "," << b.getAncrage().y << ")" << endl;
			cout << "Taille = " << b.getTaille() << " Direction = " << b.getDirection() << endl;
			cout << "Identifiant est " << b.getId() <<" Nombre de vie est "<<b.getPointDeVie()<< endl;

			//direction 0
			if (b.getDirection() == 0)
			{
				if (b.getAncrage().x - b.getTaille() > 0)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < b.getTaille(); n++)
					{
						if (jeu.tableau[b.getAncrage().x - n][b.getAncrage().y] != 0)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < b.getTaille(); n++)
						{
							jeu.tableau[b.getAncrage().x - n][b.getAncrage().y] = b.getId();
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
			if (b.getDirection() == 1)
			{
				if (b.getAncrage().y + b.getTaille() < largeur)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < b.getTaille(); n++)
					{
						if (jeu.tableau[b.getAncrage().x][b.getAncrage().y + n ] != 0)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < b.getTaille(); n++)
						{
							jeu.tableau[b.getAncrage().x][b.getAncrage().y + n] = b.getId();
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
			if (b.getDirection() == 2)
			{
				if (b.getAncrage().x + b.getTaille() < hauteur)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < b.getTaille(); n++)
					{
						if (jeu.tableau[b.getAncrage().x + n][b.getAncrage().y] != 0)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < b.getTaille(); n++)
						{
							jeu.tableau[b.getAncrage().x + n][b.getAncrage().y] = b.getId();
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

			if (b.getDirection() == 3)
			{
				if (b.getAncrage().y - b.getTaille() > 0)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < b.getTaille(); n++)
					{
						if (jeu.tableau[b.getAncrage().x][b.getAncrage().y - n] != 0)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < b.getTaille(); n++)
						{
							jeu.tableau[b.getAncrage().x][b.getAncrage().y - n] = b.getId();
							bateauxPlacer = 1;
						}
					}
				}
				else
				{
					cout << "try again" << endl;
				}
			}
		}
		cout << "=====================================" << endl;
		return true;
	}

	bool AIfacile::tire()
	{

		bool tireConfirme = false;
		while (tireConfirme == 0)
		{
			int i = rand() % 10;
			int j = rand() % 10;

			cout << "Tire la case: (" << i << ", " << j << ")" << endl;
			if (jeu.tableau[i][j] == 0)
			{
				jeu.tableau[i][j] = 2;
				tireConfirme = true;
				return true;
			}
			else if (jeu.tableau[i][j] == 3)
			{
				bateau5.ajustPointDeVie();
				jeu.tableau[i][j] = 1;
				tireConfirme = true;
				return true;
			}

			else if (jeu.tableau[i][j] == 4)
			{
				bateau1.ajustPointDeVie();
				jeu.tableau[i][j] = 1;
				tireConfirme = true;
				return true;
			}

			else if (jeu.tableau[i][j] == 5)
			{
				bateau2.ajustPointDeVie();
				jeu.tableau[i][j] = 1;
				tireConfirme = true;
				return true;
			}

			else if (jeu.tableau[i][j] == 6)
			{
				bateau3.ajustPointDeVie();
				jeu.tableau[i][j] = 1;
				tireConfirme = true;
				return true;
			}

			else if (jeu.tableau[i][j] == 7)
			{
				bateau4.ajustPointDeVie();
				jeu.tableau[i][j] = 1;
				tireConfirme = true;
				return true;
			}
			else
			{
					return false;
			}
		}
	}

	Bateau& AIfacile::getBateau(int num)
	{
		if (num == 1)
		{
			return bateau1;
		}
		else if (num == 2)
		{
			return bateau2;
		}

		else if (num == 3)
		{
			return bateau3;
		}

		else if (num == 4)
		{
			return bateau4;
		}

		else
		{
			return bateau5;
		}
	}
	
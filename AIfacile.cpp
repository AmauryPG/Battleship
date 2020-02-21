#include "AIfacile.h"


AIfacile::AIfacile()
{
	int dir;
	//creation  de bateaux
	//patrol boat (2 vies)
	dir = rand() % 4;
	m_bateau[0].setDirection(dir);

	//submarine (3 vies)
	dir = rand() % 4;
	m_bateau[1].setDirection(dir);

	//destroyer (3 vies)
	dir = rand() % 4;
	m_bateau[2].setDirection(dir);

	//battleship (4 vies)
	dir = rand() % 4;
	m_bateau[3].setDirection(dir);

	//carrier (5 vies)
	dir = rand() % 4;
	m_bateau[4].setDirection(dir);

	// init du tableau
	for (int i = 0; i < largeur; i++)
	{
		for (int j = 0; j < hauteur; j++)
		{
			m_jeu[i][j] = -1;
			m_ecran[i][j] = -1;
		}
	}
}

void AIfacile::imprimeTableau()
{
	for (int i = 0; i < largeur; i++)
	{
		for (int j = 0; j < hauteur; j++)
		{
			cout << m_jeu[i][j] << "\t";
		}
		cout << endl;
		cout << endl;
	}
}

void AIfacile::placer()
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
			m_bateau[i].setAncrage(anc);
			int ctr = 0;
			cout << "ancrage = (" << m_bateau[i].getAncrage().x << "," << m_bateau[i].getAncrage().y << ")" << endl;
			cout << "Nombre de vie est " << m_bateau[i].getPointDeVie() << endl;

			//direction 0
			if (m_bateau[i].getDirection() == 0)
			{
				if (m_bateau[i].getAncrage().x - m_bateau[i].getTaille() > 0)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x - n][m_bateau[i].getAncrage().y] != -1)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x - n][m_bateau[i].getAncrage().y] = i;
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
			if (m_bateau[i].getDirection() == 1)
			{
				if (m_bateau[i].getAncrage().y + m_bateau[i].getTaille() < largeur)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y + n] != -1)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y + n] = i;
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
			if (m_bateau[i].getDirection() == 2)
			{
				if (m_bateau[i].getAncrage().x + m_bateau[i].getTaille() < hauteur)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x + n][m_bateau[i].getAncrage().y] != -1)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x + n][m_bateau[i].getAncrage().y] = i;
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

			if (m_bateau[i].getDirection() == 3)
			{
				if (m_bateau[i].getAncrage().y - m_bateau[i].getTaille() > 0)
				{
					cout << "Not going out of bounds" << endl;
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y - n] != -1)
						{
							cout << "Incrementing Counter" << endl;
							ctr++;
						}
					}
					cout << "Counter is equal to " << ctr << endl;
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y - n] = i;
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
		bateauxPlacer = 0;
	}
}

void AIfacile::tirer(int &x, int &y)
{

	bool tireConfirme = false;
	while (tireConfirme == false)
	{
		int i = rand() % 10;
		int j = rand() % 10;
		if (m_ecran[i][j] == -2 || m_ecran[i][j] == -3)
		{
			cout << "Deja tirer ici, je retire" << endl;
			i = rand() % 10;
			j = rand() % 10;
		}
		x = i;
		y = j;
		tireConfirme = true;
	}
}

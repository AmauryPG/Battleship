#include "AIfacile.h"


AIfacile::AIfacile()
{
	int dir;
	//creation  de bateaux
	//patrol boat (2 vies)
	dir = rand() % 4;
<<<<<<< Updated upstream
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

	//carrier (5 vies)
	dir = rand() % 4;
	bateaux[4].setTaille(5);
	bateaux[4].setDirection(dir);
	bateaux[4].InitialPointDeVie();
=======
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
>>>>>>> Stashed changes

	// init du tableau
	for (int i = 0; i < largeur; i++)
	{
		for (int j = 0; j < hauteur; j++)
		{
<<<<<<< Updated upstream
			jeu.tableau[i][j] = -1;
=======
			m_jeu[i][j] = -1;
			m_ecran[i][j] = -1;
>>>>>>> Stashed changes
		}
	}
}

	void AIfacile::imprimeTableau()
	{
		for (int i = 0; i < largeur; i++)
		{
			for (int j = 0; j < hauteur; j++)
			{
				cout << m_jeu[i][j]<<"\t";
			}
			cout << endl;
			cout << endl;
		}
	}

<<<<<<< Updated upstream
	void AIfacile::placeBateau()
=======
	void AIfacile::placer()
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
				bateaux[i].setAncrage(anc);
				int ctr = 0;
				cout << "ancrage = (" << bateaux[i].getAncrage().x << "," << bateaux[i].getAncrage().y << ")" << endl;
				cout << " Nombre de vie est " << bateaux[i].getPointDeVie() << endl;

				//direction 0
				if (bateaux[i].getDirection() == 0)
				{
					if (bateaux[i].getAncrage().x - bateaux[i].getTaille() > 0)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x - n][bateaux[i].getAncrage().y] != -1)
=======
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
>>>>>>> Stashed changes
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
<<<<<<< Updated upstream
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x - n][bateaux[i].getAncrage().y] = i;
=======
							for (int n = 0; n < m_bateau[i].getTaille(); n++)
							{
								m_jeu[m_bateau[i].getAncrage().x - n][m_bateau[i].getAncrage().y] = i;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
				if (bateaux[i].getDirection() == 1)
				{
					if (bateaux[i].getAncrage().y + bateaux[i].getTaille() < largeur)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y + n] != -1)
=======
				if (m_bateau[i].getDirection() == 1)
				{
					if (m_bateau[i].getAncrage().y + m_bateau[i].getTaille() < largeur)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							if (m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y + n] != -1)
>>>>>>> Stashed changes
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
<<<<<<< Updated upstream
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y + n] = i;
=======
							for (int n = 0; n < m_bateau[i].getTaille(); n++)
							{
								m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y + n] = i;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
				if (bateaux[i].getDirection() == 2)
				{
					if (bateaux[i].getAncrage().x + bateaux[i].getTaille() < hauteur)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x + n][bateaux[i].getAncrage().y] != -1)
=======
				if (m_bateau[i].getDirection() == 2)
				{
					if (m_bateau[i].getAncrage().x + m_bateau[i].getTaille() < hauteur)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							if (m_jeu[m_bateau[i].getAncrage().x + n][m_bateau[i].getAncrage().y] != -1)
>>>>>>> Stashed changes
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
<<<<<<< Updated upstream
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x + n][bateaux[i].getAncrage().y] = i;
=======
							for (int n = 0; n < m_bateau[i].getTaille(); n++)
							{
								m_jeu[m_bateau[i].getAncrage().x + n][m_bateau[i].getAncrage().y] = i;
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
				if (bateaux[i].getDirection() == 3)
				{
					if (bateaux[i].getAncrage().y - bateaux[i].getTaille() > 0)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < bateaux[i].getTaille(); n++)
						{
							if (jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y - n] != -1)
=======
				if (m_bateau[i].getDirection() == 3)
				{
					if (m_bateau[i].getAncrage().y - m_bateau[i].getTaille() > 0)
					{
						cout << "Not going out of bounds" << endl;
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							if (m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y - n] != -1)
>>>>>>> Stashed changes
							{
								cout << "Incrementing Counter" << endl;
								ctr++;
							}
						}
						cout << "Counter is equal to " << ctr << endl;
						if (ctr == 0)
						{
<<<<<<< Updated upstream
							for (int n = 0; n < bateaux[i].getTaille(); n++)
							{
								jeu.tableau[bateaux[i].getAncrage().x][bateaux[i].getAncrage().y - n] = i;
=======
							for (int n = 0; n < m_bateau[i].getTaille(); n++)
							{
								m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y - n] = i;
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
	void AIfacile::tire()
=======
	void AIfacile::tirer()
>>>>>>> Stashed changes
	{

		bool tireConfirme = false;
		while (tireConfirme == 0)
		{
			int i = rand() % 10;
			int j = rand() % 10;

			cout << "Tire la case: (" << i << ", " << j << ")" << endl;
<<<<<<< Updated upstream
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
				jeu.tableau[i][j] = 1;
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
=======
			if (m_jeu[i][j] == -1)
			{
				m_jeu[i][j] = -2;
				tireConfirme = true;
			}
			else if (m_jeu[i][j] == 0)
			{
				m_bateau[0].ajustPointDeVie();
				m_jeu[i][j] = -3;
				tireConfirme = true;
			}

			else if (m_jeu[i][j] == 1)
			{
				m_bateau[1].ajustPointDeVie();
				m_jeu[i][j] = -3;
				tireConfirme = true;
			}

			else if (m_jeu[i][j] == 2)
			{
				m_bateau[2].ajustPointDeVie();
				m_jeu[i][j] = 1;
				tireConfirme = true;
			}

			else if (m_jeu[i][j] == 3)
			{
				m_bateau[3].ajustPointDeVie();
				m_jeu[i][j] = -3;
				tireConfirme = true;
			}

			else if (m_jeu[i][j] == 4)
			{
				m_bateau[4].ajustPointDeVie();
				m_jeu[i][j] = -3;
>>>>>>> Stashed changes
				tireConfirme = true;
			}
		}
	}

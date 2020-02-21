#include "Usager.h"
#include "bateau.h"

Usager::Usager()
{
	for (int i = 0; i < largeur; i++)
	{
		for (int j = 0; j < hauteur; j++)
		{
			m_jeu[i][j] = -1;
			m_ecran[i][j] = -1;
		}
	}
}

void Usager::placer()
{
	int ancrageY;
	int ancrageX;
	int dir;
	int ctr;

	bool tireConfirme = false;

	for (int i = 0; i < 5; i++)
	{
		tireConfirme = false;
		while (tireConfirme == false)
		{
			ancrageY = -1;
			ancrageX = -1;
			dir = -1;
			cout << "Placement du bateau " << i << endl;
			cout << "Entrez deux coordonnees 0-9 separees par une espace" << endl;
			cin >> ancrageX >> ancrageY;

			/*Ancrage*/

			if (ancrageY < 0 || ancrageY > 9 || ancrageX < 0 || ancrageX > 9)
			{
				cout << "Coordonnees ivalide. Choisir entre 0 et 9"<<endl;
				continue;
			}
			if (m_jeu[ancrageX][ancrageY] != -1)
			{
				cout << "Il y a deja un bateau a cet ancrage" << endl;
				continue;
			}

			/*Direction*/
			cout << "Entrez une direction 0-3" << endl;
			cin >> dir;
			if (dir < 0 || dir > 3)
			{
				cout << "Direction invalide. Choisir entre 0-3" << endl;
				continue;
			}

			AncrageBateau anc{ ancrageX, ancrageY };

			m_bateau[i].setAncrage(anc);
			m_bateau[i].setDirection(dir);
			ctr = 0;
			/*direction de 0*/
			if (dir == 0)
			{
				if (m_bateau[i].getAncrage().x - m_bateau[i].getTaille() >= 0)
				{
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x - n][m_bateau[i].getAncrage().y] != -1)
						{
							ctr++;
						}
					}
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x - n][m_bateau[i].getAncrage().y] = i;
						}
						cout << "bateau place!" << endl;
						tireConfirme = true;
						imprimeTableau();
					}
					else
					{
						cout << "Il y a deja un bateau dans le chemin" << endl;
					}
				}
				else
				{
					cout << "Le bateau ne rentre pas dans le tableau" << endl;
				}
			}

			/*Direction  de 1*/
			else if (dir == 1)
			{
				if (m_bateau[i].getAncrage().y + m_bateau[i].getTaille() <= 9)
				{
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau->getAncrage().x][m_bateau[i].getAncrage().y + n] != -1)
						{
							ctr++;
						}
					}
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y + n] = i;
						}
						tireConfirme = true;
						cout << "Bateau place!" << endl;
						imprimeTableau();
					}
					else
					{
						cout << "Il y a deja un bateau dans le chemin" << endl;
					}
				}
				else
				{
					cout << "Le bateau ne rentre pas dans le tableau" << endl;
				}
			}

			/*Direction de 2*/
			else if (dir == 2)
			{
				if (m_bateau[i].getAncrage().x + m_bateau[i].getTaille() <= 9)
				{
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x + n][m_bateau[i].getAncrage().y] != -1)
						{
							ctr++;
						}
					}
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x + n][m_bateau[i].getAncrage().y] = i;
						}
						tireConfirme = true;
						cout << "Bateau place!" << endl;
						imprimeTableau();
					}
					else
					{
						cout << "Il y a deja un bateau dans le chemin" << endl;
					}
				}
				else
				{
					cout << "Le bateau ne rentre pas dans le tableau" << endl;
				}
			}

			/*Direction 3*/
			else
			{
				if (m_bateau[i].getAncrage().y - m_bateau[i].getTaille() >= 0)
				{
					for (int n = 0; n < m_bateau[i].getTaille(); n++)
					{
						if (m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y - n] != -1)
						{
							ctr++;
						}
					}
					if (ctr == 0)
					{
						for (int n = 0; n < m_bateau[i].getTaille(); n++)
						{
							m_jeu[m_bateau[i].getAncrage().x][m_bateau[i].getAncrage().y - n] = i;
						}
						tireConfirme = true;
						cout << "Bateau place!" << endl;
						imprimeTableau();
					}
				}
				else
				{
					cout << "Le bateau ne rentre pas dans le tableau" << endl;
				}
			}
		}
	}
}

void Usager::tirer(int &x, int &y)
{
	int i;
	int j;
	cout << "Entrez les coordonnees de tire" << endl;
	cin >> i >> j;
	if (i < 0 || i> 9 || j < 0 || j > 9)
	{
		while (i < 0 || i> 9 || j < 0 || j > 9)
		{
			cout << "Coordonnees invalide. Entrez les coordonnees de tire" << endl;
			cin >> i >> j;
		}
	}
	x = i;
	y = j;
}

void Usager::imprimeTableau()
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


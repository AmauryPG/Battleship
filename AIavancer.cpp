#include "AIavancer.h"

#define touche 10

avancerAI::avancerAI()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_distribution[x][y] = 0;
		}
	}
}

avancerAI::~avancerAI()
{
}

//marque -1 pour tout les cas touche et essayer
void avancerAI::PreAnalyse(const int tableau[10][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			m_enemie[x][y] = tableau[x][y];

			if (tableau[x][y] == 0)
				m_distribution[x][y] = 0;
			else
				m_distribution[x][y] = tableau[x][y];
		}
	}
}

void avancerAI::afficherDistribution()
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if (m_distribution[x][y] < 0)
			{
				cout << "b ";
			}
			else
			{
				cout << m_distribution[x][y] << " ";
			}
		}
		cout << endl;
	}
}



void avancerAI::affichageTableau(int tableau[10][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << tableau[x][y] << " ";
		}
		cout << endl;
	}
}

//detecte les extremite d'un bateau
bool avancerAI::AnalyseDirection()
{
	int longueur = 1;
	int yOrigine;
	int xOrigine;
	//analyse des ranger y
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			//chercher si il y a un point toucher
			if (m_distribution[y][x] == -3)
			{
				yOrigine = y;
				//chercher si il y a un point suivant toucher
				if (m_distribution[y + 1][x] == -3)
				{
					y++;
					//trouver la longueur du bateau
					do
					{
						longueur++;
						y++;
					} while (y < 10 && m_distribution[y][x] == -3);

					//donner la valeur aux extrimite 
					if (yOrigine - 1 >= 0)
					{
						m_distribution[yOrigine - 1][x] += longueur;
					}
					if (y < 10)
					{
						m_distribution[y][x] += longueur;
					}

				}
			}
		}
	}

	longueur = 1;

	//analyse des ranger x
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			//chercher si il y a un point toucher
			if (m_distribution[y][x] == -3)
			{
				xOrigine = x;
				//chercher si il y a un point suivant toucher
				if (m_distribution[y][x + 1] == -3)
				{
					x++;
					//trouver la longueur du bateau
					do
					{
						longueur++;
						x++;
					} while (y < 10 && m_distribution[y][x] == -3);

					//donner la valeur aux extrimite 
					if (xOrigine - 1 >= 0)
					{
						m_distribution[y][xOrigine - 1] += longueur;
					}
					if (x < 10)
					{
						m_distribution[y][x] += longueur;
					}

				}
			}
		}
	}
	return true;
}

bool avancerAI::PriorisationZoneTouche()
{
	bool bateauTouche = false;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			//chercher un point toucher
			if (m_enemie[x][y] == -3)
			{
				bateauTouche = true;

				//donner une plus grande valeur autour des bateaux
				if (x - 1 >= 0 && m_distribution[x - 1][y] != -1)
					m_distribution[x - 1][y] += 2;
				if (x + 1 < 10 && m_distribution[x + 1][y] != -1)
					m_distribution[x + 1][y] += 2;

				if (y - 1 >= 0 && m_distribution[x][y - 1] != -1)
					m_distribution[x][y - 1] += 2;
				if (y + 1 < 10 && m_distribution[x][y + 1] != -1)
					m_distribution[x][y + 1] += 2;
			}
		}
	}
	return bateauTouche;
}

void avancerAI::chercherMeilleurCase(int& x, int& y)
{
	int meilleur = m_distribution[0][0];
	x = y = 0;
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			if (m_distribution[j][k] > meilleur)
			{
				meilleur = m_distribution[j][k];
				x = k;
				y = j;
			}
		}
	}
}

bool avancerAI::RechercheExhaustif(int longueur)
{

	bool axeYNegatif = true;
	bool axeYPositif = true;
	bool axeXNegatif = true;
	bool axeXPositif = true;
	//si un bateau peut rentre dans la map
	bool bateau = false;

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{

			if (m_enemie[x][y] == 0)
			{
				axeYNegatif = true;
				axeYPositif = true;
				axeXNegatif = true;
				axeXPositif = true;

				for (int i = 1; i < longueur; i++)
				{
					if (x + i >= 10 || m_enemie[x + i][y] != 0)
						axeXPositif = false;
					if (x - i < 0 || m_enemie[x - i][y] != 0)
						axeXNegatif = false;

					if (y + i >= 10 || m_enemie[x][y + i] != 0)
						axeYPositif = false;
					if (y - i < 0 || m_enemie[x][y - i] != 0)
						axeYNegatif = false;
				}


				for (int k = 0; k < longueur - 1; k++)
				{
					if (axeXPositif && m_enemie[x + k][y] >= 0)
					{
						m_distribution[x + k][y]++;
						bateau = true;
					}
					if (axeXNegatif && m_enemie[x - k][y] >= 0)
					{
						m_distribution[x - k][y]++;
						bateau = true;

					}

					if (axeYPositif && m_enemie[x][y + k] >= 0)
					{
						m_distribution[x][y + k]++;
						bateau = true;
					}

					if (axeYNegatif && m_enemie[x][y - k] >= 0)
					{
						m_distribution[x][y - k]++;
						bateau = true;
					}
				}
			}
		}
	}
	//chercher si il existe des case toucher succesif
	AnalyseDirection();
	//augmenter la valeur des bateaux autour
	PriorisationZoneTouche();
	return bateau;
}

void avancerAI::trier()
{
	int x, y;

	RechercheExhaustif(2);
	chercherMeilleurCase(x, y);
	cout << x << " : " << y << endl;
}
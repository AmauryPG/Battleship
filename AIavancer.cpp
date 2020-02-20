#include "AIavancer.h"

AIavancer::AIavancer()
{
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_distribution[x][y] = 0;
			m_enemie[x][y] = VIDE;
		}
	}
}

AIavancer::~AIavancer()
{
}

//marque -1 pour tout les cas touche et essayer
void AIavancer::PreAnalyse(const int tableau[10][10])
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

//affiche n'importe quel tableau
void AIavancer::affichageTableau(int tableau[10][10])
{
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			cout << tableau[x][y] << " ";
		}
		cout << endl;
	}
}

//detecte les extremite d'un bateau
bool AIavancer::AnalyseDirection()
{
	int longueur = 10;
	int yOrigine;
	int xOrigine;
	//analyse des ranger y
	for (int y = 0; y < 10; y++) {
		for (int x = 0; x < 10; x++) {
			//chercher si il y a un point toucher
			if (m_enemie[y][x] == TOUCHE)
			{
				yOrigine = y;
				//chercher si il y a un point suivant toucher
				if (m_enemie[y + 1][x] == TOUCHE)
				{
					y++;
					//trouver la longueur du bateau
					do
					{
						longueur++;
						y++;
					} while (y < 10 && m_enemie[y][x] == TOUCHE);

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

	longueur = 10;

	//analyse des ranger x
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			//chercher si il y a un point toucher
			if (m_enemie[y][x] == TOUCHE)
			{
				xOrigine = x;
				//chercher si il y a un point suivant toucher
				if (m_enemie[y][x + 1] == TOUCHE)
				{
					x++;
					//trouver la longueur du bateau
					do
					{
						longueur++;
						x++;
					} while (y < 10 && m_enemie[y][x] == TOUCHE);

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

bool AIavancer::PriorisationZoneTouche()
{
	bool bateauTouche = false;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			//chercher un point toucher
			if (m_enemie[x][y] == TOUCHE)
			{
				bateauTouche = true;

				//donner une plus grande valeur autour des bateaux
				if (x - 1 >= 0 && m_distribution[x - 1][y] > 0)
					m_distribution[x - 1][y] += 2;
				if (x + 1 < 10 && m_distribution[x + 1][y] > 0)
					m_distribution[x + 1][y] += 2;

				if (y - 1 >= 0 && m_distribution[x][y - 1] > 0)
					m_distribution[x][y - 1] += 2;
				if (y + 1 < 10 && m_distribution[x][y + 1] > 0)
					m_distribution[x][y + 1] += 2;
			}
		}
	}
	return bateauTouche;
}

void AIavancer::chercherMeilleurCase(int& x, int& y)
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

bool AIavancer::RechercheExhaustif(int longueur)
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

			if (m_enemie[x][y] == VIDE)
			{
				axeYNegatif = true;
				axeYPositif = true;
				axeXNegatif = true;
				axeXPositif = true;

				for (int i = 1; i < longueur; i++)
				{
					if (x + i >= 10 || m_enemie[x + i][y] != VIDE)
						axeXPositif = false;
					if (x - i < 0 || m_enemie[x - i][y] != VIDE)
						axeXNegatif = false;

					if (y + i >= 10 || m_enemie[x][y + i] != VIDE)
						axeYPositif = false;
					if (y - i < 0 || m_enemie[x][y - i] != VIDE)
						axeYNegatif = false;
				} 

				for (int k = 0; k < longueur - 1; k++)
				{
					if (axeXPositif && m_enemie[x + k][y] < 0)
					{ 
						m_distribution[x + k][y]++;
						bateau = true;
					}
					if (axeXNegatif && m_enemie[x - k][y] < 0)
					{
						m_distribution[x - k][y]++;
						bateau = true;

					}

					if (axeYPositif && m_enemie[x][y + k] < 0)
					{
						m_distribution[x][y + k]++;
						bateau = true;
					}

					if (axeYNegatif && m_enemie[x][y - k] < 0)
					{
						m_distribution[x][y - k]++;
						bateau = true;
					}
				}
			}
		}
	}
	//augmenter la valeur des bateaux autour
	PriorisationZoneTouche();
	return bateau;
}

void AIavancer::tirer(int& x, int& y)
{
	for (int i = 0; i < 5; i++)
	{
		//passe a travers tout la longueur de ses bateaux
		//vu qu'il les deux joueurs ont la meme taille 
		//on peut juste regarder dans ses propres bateaux
		RechercheExhaustif(m_bateau[i].getTaille());
	}
	//chercher si il existe des case toucher succesif
	AnalyseDirection();

	//chercher le point le plus courant
	chercherMeilleurCase(x, y);

	cout <<"AIavancer a choisit : " << x << " : " << y << endl;
}

void AIavancer::placer()
{

}
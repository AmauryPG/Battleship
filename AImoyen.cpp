#include "AImoyen.h"

AImoyen::AImoyen()
{ 
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_ecran[x][y] = VIDE;
			m_jeu[x][y] = VIDE;
		}
	}
}

AImoyen::~AImoyen()
{

}

int m_jeuEnemie[10][10];

void AImoyen::tirer(int &x, int &y)
{ 
	srand(time(NULL));  
	 

	if (m_ecran[m_toucheX][m_toucheY] == TOUCHE)
	{ 
		//regarde autour si un point a deja ete essayer et bouger vers ce point
		if (m_toucheX + 1 < 10 && m_ecran[m_toucheX + 1][m_toucheY] == TOUCHE)
		{
			m_toucheX++;
		}
		else if (m_toucheX - 1 >= 0 && m_ecran[m_toucheX - 1][m_toucheY] == TOUCHE)
		{
			m_toucheX--;
		}
		else if (m_toucheY + 1 < 10 && m_ecran[m_toucheX][m_toucheY + 1] == TOUCHE)
		{
			m_toucheY++;
		}
		else if (m_toucheY - 1 >= 0 && m_ecran[m_toucheX][m_toucheY - 1] == TOUCHE)
		{
			m_toucheY--;
		}

		//a la chasse du bateau toucher
		if (m_toucheX + 1 < 10 && m_ecran[m_toucheX + 1][m_toucheY] == VIDE)
		{ 
			x = m_toucheX + 1;
			y = m_toucheY;
		}
		else if(m_toucheX - 1 >= 0 && m_ecran[m_toucheX - 1][m_toucheY] == VIDE)
		{ 
			x = m_toucheX - 1;
			y = m_toucheY;
		}
		else if(m_toucheY + 1 < 10 && m_ecran[m_toucheX][m_toucheY + 1] == VIDE)
		{ 
			x = m_toucheX;
			y = m_toucheY + 1;
		}
		else if(m_toucheY - 1 >= 0 && m_ecran[m_toucheX][m_toucheY - 1] == VIDE)
		{ 
			x = m_toucheX;
			y = m_toucheY - 1;
		}

	}
	else
	{ 
		//cherche un point possible de choisir 

		x = rand() % 10;
		y = rand() % 10;

		//reduit la recherche par moitie
		if ((x % 2) == 1) {
			if ((rand() % 2) == 0) {
				x--;
			}
			else {
				x++;
			}
		}

		if ((y % 2) == 1) {
			if ((rand() % 2) == 0) {
				x--;
			}
			else {
				x++;
			}
		} 
		
		m_toucheX = x;
		m_toucheY = y;
	}   
		
}  

void AImoyen::placer()
{

	srand(time(NULL));

	int x, y;
	int directionTime = 0;
	bool loop = true;

	do
	{
		do
		{
			x = rand() % 10;
			y = rand() % 10;
		} while (m_jeu[x][y] != VIDE);

		directionTime = 0;

		do
		{
			switch (rand() % 4)
			{
			case NORD:
				if (y - m_bateau[4].getTaille() >= 0)
				{
					for (int i = 1; i < m_bateau[4].getTaille(); i++)
					{
						if (m_jeu[x][y - i] != VIDE)
						{
							loop = false;
							break;
						}
					}

					if (loop)
					{
						loop = false;
						for (int i = 0; i < m_bateau[4].getTaille(); i++)
						{
							m_jeu[x][y - i] = 4;
						}
					}
				}
				directionTime++;
				break;
			case SUD:
				if (y + m_bateau[4].getTaille() < 10)
				{
					for (int i = 1; i < m_bateau[4].getTaille(); i++)
					{
						if (m_jeu[x][y + i] != VIDE)
						{
							loop = false;
							break;
						}
					}

					if (loop)
					{
						loop = false;
						for (int i = 0; i < m_bateau[4].getTaille(); i++)
						{
							m_jeu[x][y + i] = 4;
						}
					}
				}
				directionTime++;
				break;
			case EST:
				if (x + m_bateau[4].getTaille() < 10)
				{
					for (int i = 1; i < m_bateau[4].getTaille(); i++)
					{
						if (m_jeu[x + i][y] != VIDE)
						{
							loop = false;
							break;
						}
					}

					if (loop)
					{
						loop = false;
						for (int i = 0; i < m_bateau[4].getTaille(); i++)
						{
							m_jeu[x + i][y] = 4;
						}
					}
				}
				directionTime++;
				break;
			case OUEST:
				if (x - m_bateau[4].getTaille() >= 0)
				{
					for (int i = 1; i < m_bateau[4].getTaille(); i++)
					{
						if (m_jeu[x - i][y] != VIDE)
						{
							loop = false;
							break;
						}
					}

					if (loop)
					{
						loop = false;
						for (int i = 0; i < m_bateau[4].getTaille(); i++)
						{
							m_jeu[x - i][y] = 4;
						}
					}
				}
				directionTime++;
				break;
			}
		} while (loop && directionTime < 4);
	} while (loop);
	
	int x2, y2;
	bool directionBool[4] = { true }; 

	//on place maintenant le reste de facons strategique
	for (int bateau = 0; bateau < 4; bateau++)
	{
		loop = true;

		do
		{
			//check un espace libre + 
			//check si il est plus loin que 2
			do
			{
				x2 = rand() % 10;
				y2 = rand() % 10; 
			} while (m_jeu[x2][y2] != VIDE && pow(x2 - x, 2) + pow(y2 - y, 2) <= 4);

			directionTime = 0; 

			do
			{
				switch (rand() % 4)
				{
				case NORD:
					cout << "NORD" << endl;
					cout << x2 << " : " << y2 << endl;
					if (directionBool[NORD] && (y2 - m_bateau[bateau].getTaille()) >= 0)
					{
						for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
						{
							if (m_jeu[x2][y2 - i] != VIDE)
							{
								directionBool[NORD] = false;
								directionTime++;
								break;
							}
						}

						if (directionBool[NORD])
						{
							loop = false;
							for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
							{
								m_jeu[x2][y2 - i] = bateau;
							}
						}
					} 
					break;
				case SUD: 
					cout << "SUD" << endl;
					cout << x2 << " : " << y2 << endl;
					if (directionBool[SUD] && (y2 + m_bateau[bateau].getTaille()) < 10)
					{
						for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
						{
							if (m_jeu[x2][y2 + i] != VIDE)
							{
								directionBool[SUD] = false;
								directionTime++;
								break;
							}
						}

						if (directionBool[SUD])
						{
							loop = false;
							for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
							{
								m_jeu[x2][y2 + i] = bateau;
							}
						}
					}
					break;
				case EST:
					cout << "EST" << endl;
					cout << x2 << " : " << y2 << endl;
					if (directionBool[EST] && (x2 + m_bateau[bateau].getTaille()) < 10)
					{
						for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
						{
							if (m_jeu[x2 + i][y2] != VIDE)
							{
								directionBool[EST] = false;
								directionTime++;
								break;
							}
						}

						if (directionBool[EST])
						{
							loop = false;
							for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
							{
								m_jeu[x2 + i][y2] = bateau;
							}
						}
					}
					break;
				case OUEST:
					cout << "OUEST" << endl;
					cout << x2 << " : " << y2 << endl;
					if (directionBool[OUEST] && (x2 - m_bateau[bateau].getTaille()) >= 0)
					{
						for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
						{
							if (m_jeu[x2 - i][y2] != VIDE)
							{
								directionBool[OUEST] = false;
								directionTime++;
								break;
							}
						}

						if (directionBool[OUEST])
						{
							loop = false;
							for (int i = 0; i < m_bateau[bateau].getTaille(); i++)
							{
								m_jeu[x2 - i][y2] = bateau;
							}
						}
					}
					break;
				}
			} while (directionBool[NORD] && directionBool[SUD] && directionBool[EST] && directionBool[OUEST] && directionTime < 4);
		} while (loop);
	}
}
#include "AImoyen.h"

AImoyen::AImoyen()
{
	//bateau patrole
	m_bateau[0].setTaille(2);

	//sous marin
	m_bateau[1].setTaille(3);
}

AImoyen::~AImoyen()
{

}

void AImoyen::tirer()
{
	for (int bateau = 0; bateau < 2; bateau++)
	{

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
	 

	/*
	int x2, y2;

	//on place maintenant le reste de facons strategique
	for (int bateau = 0; bateau < 4; bateau++)
	{
		do
		{
			x2 = rand() % 10;
			y2 = rand() % 10;
		} while (m_jeu[x2][y2] != 0);
		 
		do
		{
			direction[0] = true;
			direction[1] = true;
			direction[2] = true;
			direction[3] = true;

			for (int i = 1; i < m_bateau[bateau].getTaille(); i++)
			{
				if (direction[0] && x2 + i >= 10 && m_jeu[x2 + i][y2] != 0 && x2 + i > x)
					direction[0] = false;
				if (direction[1] && x2 - i < 0 && m_jeu[x2 - i][y2] != 0)
					direction[1] = false;

				if (direction[2] && y2 + i >= 10 && m_jeu[x2][y2 + i] != 0)
					direction[2] = false;
				if (direction[3] && y2 - i < 0 && m_jeu[x2][y2 - i] != 0)
					direction[3] = false;
			}
		} while ();
	}*/
}
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
	bool loop;
	bool direction[4];
	int dir = 0;

	do
	{

		x = rand() % 10;
		y = rand() % 10;

		loop = true;
		direction[0] = true;
		direction[1] = true;
		direction[2] = true;
		direction[3] = true;

		do
		{
			if (m_jeu[x][y] == 0)
			{
				switch (rand() % 4)
				{
				case NORD:
					if (direction[0])
					{
						for (int i = 1; i < m_bateau[0].getTaille(); i++)
						{
							if (y + i >= 10 || m_jeu[x][y + i] != 0)
							{
								direction[0] = false;
							}
						}
						loop = false;
						dir = NORD;
					}
					break;
				case EST:
					if (direction[1])
					{
						for (int i = 1; i < m_bateau[0].getTaille(); i++)
						{
							if (x + i >= 10 || m_jeu[x + i][y] != 0)
							{
								direction[1] = false;
							}
						}
						loop = false;
						dir = EST;
					}
					break;
				case SUD:
					if (direction[2])
					{
						for (int i = 1; i < m_bateau[0].getTaille(); i++)
						{
							if (y - i < 0 || m_jeu[x][y - i] != 0)
							{
								direction[2] = false;
							}
						}
						loop = false;
						dir = SUD;
					}
					break;
				case OUEST:
					if (direction[3])
					{
						for (int i = 1; i < m_bateau[0].getTaille(); i++)
						{
							if (x - i < 0 || m_jeu[x - i][y] != 0)
							{
								direction[3] = false;
							}
						}
						loop = false;
						dir = OUEST;
					}
					break;
				}
			}
		} while (loop && (direction[0] || direction[1] || direction[2] || direction[3]));
	} while (dir == 0);
}
#include "User.h"
#include "bateau.h"
#include <iostream>

using namespace std;
int bob = 0;
User::User()
{
	InitCarte();
	displayCarte();
	
	

	for (int i = 0; i < 5; i++)
	{
		cout << "Bateau #";
		cout << i << endl;
		cout << "Index: " << i<< endl;
		m_bateau[i].setAncrage(ChoisirAncrage());
		m_bateau[i].setDirection(ChoisirDirection());
		placer();
		displayCarte();
	}
	
}

User::~User()
{

}
void User::tirer(int &x, int &y)
{
	cout << "Choisir la coordonnée de tir [0,9]" << endl;
	cout << "X [0,9]: ";
	cin >> x;
	if (x < 0 ||x >= 10)
	{
		while (x < 0 || x >= 10)
		{
			cout << "Entrer a nouveau X [0,9]: ";
			cin >> x;
		}
	}
	cout << "Y [0,9]: ";
	cin >> x;
	if (y < 0 || y >= 10)
	{
		while (y < 0 || y >= 10)
		{
			cout << "Entrer a nouveau Y [0,9]: ";
			cin >> y;
		}
	}

}
void User::placer()
{
	
	
	PlacerBateau(m_bateau[bob], bob);
	bob++;

	
}


AncrageBateau User::ChoisirAncrage() 
{
	AncrageBateau ancre;

	cout << "Choisir le point d'origine du bateau [0,9] (x,y)" << endl;
	cout << "X [0,9]: ";
	cin >> ancre.x;

	if (ancre.x < 0 || ancre.x >=10) 
	{
		while (ancre.x < 0 || ancre.x>=10)
		{
			cout << "Entrer a nouveau X [0,9]: ";
			cin >> ancre.x;
		}
	}
	
	
	cout << "\nY [0,9]: ";
	cin >> ancre.y;
	if (ancre.y < 0 || ancre.y >= 10)
	{
		while (ancre.y < 0 || ancre.y >= 10)
		{
			cout << "Entrer a nouveau Y [0,9]: ";
			cin >> ancre.y;
		}
	}
	/*
	for (int i = 0; i < 5; i++) 
	{
		if (ancre.x == m_bateau[i].getAncrage().x && ancre.y == m_bateau[i].getAncrage().y)
		{
			cout << "AAAAAAAAAAAAAAAAAAAALLLLLLLLLLLLLLLLLLLLLLLLLLLLLLOOOOOOOOOOOOOO" << endl;
			cout << "Erreur ce point d'origine a deja ete choisi pour le bateau #" << i << endl;
			cout << "Choisir un nouveau point d'origine de bateau (x,y)" << endl;
			cout << "X [0,9]: ";
			cin >> ancre.x;


			if (ancre.x < 0 || ancre.x >= 10)
			{
				while (ancre.x < 0 || ancre.x >= 10)
				{
					cout << "Entrer a nouveau X [0,9]: ";
					cin >> ancre.x;
				}
			}


			cout << "\nY [0,9]: ";
			cin >> ancre.y;
			if (ancre.y < 0 || ancre.y >= 10)
			{
				while (ancre.y < 0 || ancre.y >= 10)
				{
					cout << "Entrer a nouveau Y [0,9]: ";
					cin >> ancre.y;
				}
			}
		}
	}
	*/

	return ancre;
	
}

int User::ChoisirDirection()
{
	int dir_ = 0;
	cout << "Choisir la direction: 0 = Nord, 1 = Est, 2 = Sud, 3 = Ouest" << endl;
	cin >> dir_;

	if (dir_ < 0 || dir_ >=4) 
	{
		while (dir_ < 0 || dir_>=4)
		{
			cout << "Choisir la direction: 0 = Nord, 1 = Est, 2 = Sud, 3 = Ouest" << endl;
			cin >> dir_;
		}
	}
	for (int i = 0; i < 5; i++) 
	{
		if( (m_bateau[i].getTaille() + m_bateau[i].getAncrage().x) >= 10 || (m_bateau[i].getTaille() - m_bateau[i].getAncrage().x) < 0 || (m_bateau[i].getTaille() + m_bateau[i].getAncrage().y) >= 10 || (m_bateau[i].getTaille() - m_bateau[i].getAncrage().y) < 0 )
		{
			while (dir_ < 0 || dir_ >= 4)
			{
				cout << "Choisir une direction dans les dimensions de la carte: 0 = Nord, 1 = Est, 2 = Sud, 3 = Ouest" << endl;
				cin >> dir_;
			}
		}
	}
	
	return dir_;
}

void User::InitCarte() //initialise la carte
{
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++)
		{
			m_jeu[i][y] = -1;
		}	
	}

}
void User::displayCarte() //permet d'Afficher la carte
{
	for (int i = 0; i < 10; i++)
	{
		for (int y = 0; y < 10; y++) 
		{
			cout << m_jeu[i][y];
			cout << "   ";
		}
		cout << "\n\n";
	}

}

void User::PlacerBateau(Bateau boat, int index)
{
	if (boat.getDirection() == 0) 
	{
		int OK = 0;
		for (int i = 0; i < boat.getTaille(); i++)
		{
			if (m_jeu[boat.getAncrage().y - i][boat.getAncrage().x] != -1)
				OK = 1;
		}

		if (OK == 0) {
			for (int i = 0; i < boat.getTaille(); i++)
			{
				m_jeu[boat.getAncrage().y - i][boat.getAncrage().x] = index;
			}
		}
		else 
		{
			cout << "Les bateau ne peuvent pas se croiser, veuillez changer l'ancrage et la direction" << endl;
			boat.setAncrage(ChoisirAncrage());
			boat.setDirection(ChoisirDirection());
			PlacerBateau(boat, index);
		}
	}
	
	if (boat.getDirection() == 1)
	{
		int OK = 0;
		for (int i = 0; i < boat.getTaille(); i++)
		{
			if (m_jeu[boat.getAncrage().y][boat.getAncrage().x + i] != -1)
				OK = 1;
		}

		if (OK == 0) {
			for (int i = 0; i < boat.getTaille(); i++)
			{
				m_jeu[boat.getAncrage().y][boat.getAncrage().x + i] = index;
			}
		}
		else
		{
			cout << "Les bateau ne peuvent pas se croiser, veuillez changer l'ancrage et la direction" << endl;
			boat.setAncrage(ChoisirAncrage());
			boat.setDirection(ChoisirDirection());
		}
		/*
		for (int i = 0; i < boat.getTaille(); i++)
		{
			Carte[boat.getAncrage().y][boat.getAncrage().x + i] = index;
		}
		*/
	}

	if (boat.getDirection() == 2)
	{
		int OK = 0;
		for (int i = 0; i < boat.getTaille(); i++)
		{
			if (m_jeu[boat.getAncrage().y + i][boat.getAncrage().x] != -1)
				OK = 1;
		}

		if (OK == 0) {
			for (int i = 0; i < boat.getTaille(); i++)
			{
				m_jeu[boat.getAncrage().y + i][boat.getAncrage().x] = index;
			}
		}
		else
		{
			cout << "Les bateau ne peuvent pas se croiser, veuillez changer l'ancrage et la direction" << endl;
			boat.setAncrage(ChoisirAncrage());
			boat.setDirection(ChoisirDirection());
		}
		/*
		for (int i = 0; i < boat.getTaille(); i++)
		{
			Carte[boat.getAncrage().y + i][boat.getAncrage().x] = index;
		}
		*/
	}

	if (boat.getDirection() == 3)
	{
		int OK = 0;
		for (int i = 0; i < boat.getTaille(); i++)
		{
			if (m_jeu[boat.getAncrage().y][boat.getAncrage().x - i] != -1)
				OK = 1;
		}

		if (OK == 0) {
			for (int i = 0; i < boat.getTaille(); i++)
			{
				m_jeu[boat.getAncrage().y][boat.getAncrage().x - i] = index;
			}
		}
		else
		{
			cout << "Les bateau ne peuvent pas se croiser, veuillez changer l'ancrage et la direction" << endl;
			boat.setAncrage(ChoisirAncrage());
			boat.setDirection(ChoisirDirection());
		}
		/*
		for (int i = 0; i < boat.getTaille(); i++)
		{

			Carte[boat.getAncrage().y][boat.getAncrage().x - i] = index;
		}
		*/
	}

}
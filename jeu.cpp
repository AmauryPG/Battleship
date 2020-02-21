#include "jeu.h"

Jeu::Jeu()
{
	nbVieJoueur1 = 17;
	nbVieJoueur2 = 17;
}

Jeu::~Jeu()
{

}

void Jeu::jouer()
{
	int etatTire;
	/*joueur 1 place ses bateaux*/
	joueur1.placer();
	/*joueur 2 place ses bateaux*/
	joueur2.placer();

	/*les joueurs tirent tour a tour*/
	while (nbVieJoueur1 > 0 && nbVieJoueur2 > 0)
	{
		etatTire = -4;
		joueur1.afficheEcran();
		cout << "==================================Jeu=============================================" << endl;
		joueur1.afficheJeu();

		/*Tour du joueur 1*/
		joueur1.tirer(x, y);
		etatTire = joueur2.analyseTableau(x,y);
		if (etatTire == -3)
		{
			nbVieJoueur2--;
			if (nbVieJoueur2 == 0)
			{
				break;
			}
		}
		joueur1.ajusteEcran(x,y, etatTire);
		cout << "Rendu ICI2 Apres le joueur a tirer" << endl;
		/*Tire du joueur 2*/
		joueur2.tirer(x, y);
		cout << "Rendu ici, lordi a tirer" << endl;
		etatTire = joueur1.analyseTableau(x, y);
		if (etatTire == -3)
		{
			nbVieJoueur1--;
			joueur1.ajusteJeu(x, y, -3);
			if (nbVieJoueur1 == 0)
			{
				break;
			}
		}
		joueur2.ajusteEcran(x, y, etatTire);
		cout << "Lordi a tirer la case("<<x<<", "<<y<<")"<< endl;
	}
	if (nbVieJoueur1 == 0)
	{
		cout << "Vous avez perdu" << endl;
	}
	else
	{
		cout << "Vous avez gagner!" << endl;
	}
}
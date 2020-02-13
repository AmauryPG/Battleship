#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define nord  0
#define est   1
#define ouest 3
#define sud   2

struct AncrageBateau
{
	int x;
	int y;
};

class Bateau
{
	int id;
	int direction; // 0: Nord, 1: Est, 2: Sud, 3: Ouest
	int taille; // Se trouve entre 2 et 5 inclusivement
	int PointDeVie; // Selon de combien le bateau est touche
	int estVivant; // Etat du bateau : 0 = mort et 1 = vivant
	AncrageBateau ancrage; // Coordo ancrage

public:
	Bateau();
	~Bateau();

	int EstVivant();

	int getTaille();
	void setTaille(int size);

	int getPointDeVie();
	void InitialPointDeVie();
	void ajustPointDeVie();

	int getDirection();
	void setDirection(int dir);
	void setId(int id);
	int getId();

	void setAncrage(AncrageBateau);
	void setAncrage(int x, int y);
	AncrageBateau getAncrage();
};

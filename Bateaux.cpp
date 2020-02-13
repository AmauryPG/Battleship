#include "bateau.h"

Bateau::Bateau()
{
	taille = 0;
	ancrage.x = 0;
	ancrage.y = 0;
	PointDeVie = taille;
	estVivant = 1;
	direction = 0; 
}

Bateau::~Bateau()
{

}

int Bateau::EstVivant()
{
	if (taille == 0)
	{
		estVivant = 0;
	}
	else if (taille < 0)
	{
		estVivant = 1;
	}

	return estVivant;
}

int Bateau::getTaille()
{
	return taille;
}

void Bateau::setTaille(int size)
{
	if (size > 1 && size < 6)
	{
		taille = size;
	}
	else
	{
		taille = 2;
	}
}

int Bateau::getPointDeVie()
{
	return PointDeVie;
}

void Bateau::InitialPointDeVie()
{
	PointDeVie = taille;
}

void Bateau::ajustPointDeVie()
{
	if (PointDeVie > 0)
	{
		PointDeVie--;
	}
}

int Bateau::getDirection()
{
	return direction;
}

void Bateau::setDirection(int dir)
{
	if (dir >= 0 && dir < 4)
	{
		direction = dir;
	}
}

void Bateau::setAncrage(AncrageBateau a)
{
	ancrage = a;
}

void Bateau::setAncrage(int x, int y)
{
	ancrage.x = x;
	ancrage.y = y;
}

AncrageBateau Bateau::getAncrage()
{
	return ancrage;
}
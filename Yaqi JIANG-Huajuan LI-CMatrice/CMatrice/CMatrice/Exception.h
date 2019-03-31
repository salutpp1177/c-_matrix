#pragma once

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string.h>
using namespace std;

/** Tous les types d'exception
 */
static enum TouslesExceptions
{
	AllouerEchoue,  /**< Alouer les mémoire echoue*/
	TypeMatriceDouble, /**< TypeMatrice n'est pas double */
	DiviseurZero, /**< Le diviseur est 0 */
	ColouLigDifferent, /**< La colonne ou la ligne est different */
	ColEgalePasLig, /**< La Colonnes n'egale pas la ligne */
	FicherOuvertErreur, /**< On ne peut pas ouvrir le ficher */
	FicherVide, /**< Le ficher est vide */
	FicherContenuErreur, /**< Il y a des erreur dans le ficher */
	LireLigEchoue, /**< Lire la ligne echoue */
	LireColEchoue, /**< Lire la Colonne echoue */
};

class Exception
{
private:
	int iEXCType; /**< Un valeur entier stockant le type d'erreur */
public:

	/** Constructeur par defaut
	 */
	Exception()
	{
		iEXCType = -1;
	}

	/** Constructeur recopie
	 * @param iType un valeur entier pour noter le type d'exception
	 */
	Exception(int iType)
	{
		iEXCType = iType;
	}

	/** Destructeur
	 */
	~Exception(){}

	/** Afficher les messages selon le type d'erreur
	 */
	void EXCAfficherStackTrance()
	{
		switch (iEXCType)
		{
			case AllouerEchoue : cerr<<"Alouer les mémoire echoue, quand on utilise le constructeur. "<<endl; break;
			case TypeMatriceDouble : cerr<<"TypeMatrice doit etre Double."<<endl; break;
			case DiviseurZero : cerr<<"Quand on divise une matrice par un nombre, le nombre n'est pas 0. "<<endl; break;
			case ColouLigDifferent : cerr<<"En l'addition ou la soustraction, les deux matrice doit avoir la colonne égale et la ligne égale. "<<endl; break;
			case ColEgalePasLig : cerr<<"Quand on fait le produit de deux matrices, la colonne de matrice_1 doit égaler la ligne de matrice_2. "<<endl; break;
			case FicherOuvertErreur : cerr<<"On ne peut pas ouvrir le ficher. "<<endl; break;
			case FicherVide : cerr<<"Le ficher est vide. "<<endl; break;
			case FicherContenuErreur : cerr<<"Il y a des erreurs dans le ficher. "<<endl; break;
			case LireLigEchoue : cerr<<"Lire la ligne echoue. "<<endl; break;
			case LireColEchoue : cerr<<"Lire la ligne echoue. "<<endl; break;

		default:
			break;
		}

	}
};

#endif


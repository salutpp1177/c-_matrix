#include "Matrice.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <string>
namespace cmatrice
{
using namespace std;

/** Constructeur par défaut
 */
template <typename Type>
CMatrice<Type>::CMatrice()
{
	iMATNBLignes = 0;
	iMATNBColonnes = 0;
	pptMATElement = nullptr;
}


/** Constructeur recopie
 * @param paramMatrice un objet de la classe Matrice
 */
template <typename Type>
CMatrice<Type>::CMatrice(CMatrice<Type> & paramMatrice)
{
	pptMATElement = nullptr;
	int iTemp_1 = paramMatrice.iMATNBLignes, iTemp_2 = paramMatrice.iMATNBColonnes;
	MATAllouer(iTemp_1, iTemp_2);
	for (int i = 0; i < iTemp_1; i++)
	{
		for (int j = 0; j < iTemp_2; j++)
		{
			pptMATElement[i][j] = paramMatrice.pptMATElement[i][j];
		}
	}

}


/** Constructeur avec des arguments
 * @param iNBLignes note combien de ligne
 * @param iNBColonnes note combien de colonne
 */
template <typename Type>
CMatrice<Type>::CMatrice(int iNBLignes, int iNBColonnes)
{
	pptMATElement = nullptr;
	MATAllouer(iNBLignes, iNBColonnes);  
}

/** Résoudre la problème qu'il va exécuter "new" au début, il faut les détruire d'abord.
 */
template <typename Type>
void CMatrice<Type>::MATDetruireMatrice()
{
	if (pptMATElement != nullptr) {
		for (int i = 0; i < iMATNBLignes; i++)
		{
			if (pptMATElement[i] != nullptr)
				delete[] (pptMATElement[i]);
		}
		delete[] pptMATElement;
	}
	iMATNBLignes = 0;
	iMATNBColonnes = 0;
}

/** Destructeur
 */
template <typename Type>
CMatrice<Type>::~CMatrice()
{
	MATDetruireMatrice();
}


/** Allouer la mémoire de table bidimensionnel en taille de a[iLig][iCol]
 * @param iLig la ligne
 * @param iCol la colonne
 */
template <typename Type>
void CMatrice<Type>::MATAllouer(int iLig, int iCol) 
{
	iMATNBLignes = iLig;
	iMATNBColonnes = iCol;
	pptMATElement = new Type*[iLig];
	if (pptMATElement == nullptr) 
	{
		throw Exception(AllouerEchoue);
	}
	for (int i = 0; i < iLig; i++)
	{
		//Initialiser chaque élément comme 0 par défaut.
		pptMATElement[i] = new Type[iCol](); 
		if (pptMATElement[i] == nullptr)
			throw Exception(AllouerEchoue);
	}

}

/** Lire la Ligne de la matrice
 * @return un valeur entier pour noter son lignes
 */
template <typename Type>
int CMatrice<Type>::MATLireNBLignes() const
{
	return iMATNBLignes;
}

/** Lire la colonne de la matrice
 * @return un valeur entier pour noter son lignes
 */
template <typename Type>
int CMatrice<Type>::MATLireNBColonnes() const
{
	return iMATNBColonnes;
}

/** Lire chaque élément de la matrice
 * @return un pointeur pour orienter vers la memoire stockant tous les élément
 */
template <typename Type>
Type CMatrice<Type>::MATLireElement(int iLig, int iCol) const
{
	return pptMATElement[iLig][iCol];
}

/** Modifier le valeur de la ligne
 * @param iNBLignes la ligne redéfinie
 */
template <typename Type>
void CMatrice<Type>::MATModifierNBLignes(int iNBLignes)
{
	this->iMATNBLignes = iNBLignes;
}


/** Modifier le valeur de la colonne
 * @param iNBColones la colonne redéfine
 */
template <typename Type>
void CMatrice<Type>::MATModifierNBColonnes(int iNBColonnes)
{
	this->iMATNBColonnes = iNBColonnes;
}

/** Modifier la valeur d'un élément
	* @param iLig la ligne
	* @param iCol la colonne
	* @param Valeur le valeur de élément
	*/
template <typename Type>
void CMatrice<Type>::MATModifierElement(int iLig, int iCol, Type Valeur)
{
	pptMATElement[iLig][iCol] = Valeur;
}


/** Initialiser une matrice
 * @param iLig la ligne
 * @param iCol la colonne
 * @param Valeur le valeur de élément
 */
template <typename Type>
CMatrice<Type> CMatrice<Type>::MATInitMatrice(int iNBLignes, int iNBColonnes)
{
	MATAllouer(iNBLignes, iNBColonnes);

	cout << "Veillez taper votre matrice: " << endl;
	for (int i = 0; i < iNBLignes; i++)
	{
		for (int j = 0; j < iNBColonnes; j++)
		{
			cin >> pptMATElement[i][j];
		}
	}
	return *this;
}


/** Diviser une matrice par un nombre
 * @param dParam un nombre double
 * @return le quotient
 */
template <typename Type>
CMatrice<Type> CMatrice<Type>::MATDiviser(const double dParam) const
{
	CMatrice temp(iMATNBLignes, iMATNBColonnes);
	if (dParam == 0)
	{
		throw Exception(DiviseurZero);
	}
	for (int i = 0; i < iMATNBLignes; i++)
	{
		for (int j = 0; j < iMATNBColonnes; j++)
		{
			temp.pptMATElement[i][j] = temp.pptMATElement[i][j] / dParam;
		}
	}
	return temp;
}


/** Calculer la matrice transposée
 * @param paramMatrice la matrice orignale
 * @return une référence notant la matrice transposée
 */
template <typename Type>
CMatrice<Type> CMatrice<Type>::MATTransposer() const
{
	CMatrice<Type> temp(iMATNBColonnes, iMATNBLignes);
	for (int i = 0; i < iMATNBLignes; i++)
	{
		for (int j = 0; j < iMATNBColonnes; j++)
		{
			temp.pptMATElement[j][i] = pptMATElement[i][j];
		}
	}

	return temp;
}


/** Surcharge l'opérateur de = pour faire Matrice_A = Matrice_B
 * @param Matrice_B
 * @return Matrice_B
 */ 
template <typename Type>
CMatrice<Type> CMatrice<Type>::operator=(const CMatrice<Type> & paramMatrice) {
	MATDetruireMatrice();
	int iTemp_1 = paramMatrice.iMATNBLignes, iTemp_2 = paramMatrice.iMATNBColonnes;
	MATAllouer(iTemp_1, iTemp_2);
	for (int i = 0; i < iTemp_1; i++)
	{
		for (int j = 0; j < iTemp_2; j++)
		{
			pptMATElement[i][j] = paramMatrice.pptMATElement[i][j];
		}
	}
	return *this;
}

/** Surcharge l'opérateur de + pour réaliser Matrice_A + Matrice_B = Matrice_C
* @param paramMatrice Matrice_B
* @return Matrice_C
*/
template <typename Type>
CMatrice<Type> CMatrice<Type>::operator+(const CMatrice<Type> & paramMatrice) const
{

	if (iMATNBColonnes != paramMatrice.iMATNBColonnes || iMATNBLignes != paramMatrice.iMATNBLignes)
	{
		throw Exception(ColouLigDifferent);
	}

	CMatrice<Type> temp(iMATNBLignes, iMATNBColonnes);
	for (int i = 0; i < iMATNBLignes; i++) 
	{
		for (int j = 0; j < iMATNBColonnes; j++)
		{
			temp.pptMATElement[i][j] = pptMATElement[i][j] + paramMatrice.pptMATElement[i][j];
		}
	}

	return temp;

}

/** Surcharge l'opérateur de - pour réaliser Matrice_A - Matrice_B = Matrice_C
 * @param paramMatrice Matrice_B
 * @return Matrice_C
 */
template <typename Type>
CMatrice<Type> CMatrice<Type>::operator-(const CMatrice<Type> & paramMatrice) const
{

	if (iMATNBColonnes != paramMatrice.iMATNBColonnes || iMATNBLignes != paramMatrice.iMATNBLignes)
	{
		throw Exception(ColouLigDifferent);
	}

	CMatrice<Type> temp(iMATNBLignes, iMATNBColonnes);
	for (int i = 0; i < iMATNBLignes; i++)
	{
		for (int j = 0; j < iMATNBColonnes; j++)
		{
			temp.pptMATElement[i][j] = pptMATElement[i][j] - paramMatrice.pptMATElement[i][j];
		}
	}

	return temp;

}


/** Surcharge l'opérateur de * pour multiplier une matrice par un nombre
 * @param dParam un nombre double
 * @return le produit
 */
template <typename Type>
CMatrice<Type> CMatrice<Type>::operator*(const Type & tParam) const
{
	CMatrice<Type> temp(iMATNBLignes, iMATNBColonnes);
	for (int i = 0; i < iMATNBLignes; i++)
	{
		for (int j = 0; j < iMATNBColonnes; j++)
		{
			temp.pptMATElement[i][j] = pptMATElement[i][j] * tParam;
		}
	}
	return temp;
}

/** Surcharge l'opérateur de * pour multiplier Matrice_A * Matrice_B
 * @param paramMatrice Matrice_B
 * @return le produit
 */
template <typename Type>
CMatrice<Type> CMatrice<Type>::operator*(const CMatrice<Type> & paramMatrice) const
{
	if (iMATNBColonnes != paramMatrice.iMATNBLignes)
	{
		throw Exception(ColEgalePasLig);
	}
	int iLierParCol;
	iLierParCol = iMATNBColonnes;
	CMatrice<Type> temp(iMATNBLignes, paramMatrice.iMATNBColonnes);
	for (int m = 0; m < iMATNBLignes; m++)
	{
		for (int n = 0; n < paramMatrice.iMATNBColonnes; n++)
		{
			temp.pptMATElement[m][n] = 0;
			for (int i = 0; i < iLierParCol; i++)
			{
				temp.pptMATElement[m][n] += pptMATElement[m][i] * paramMatrice.pptMATElement[i][n];
			}
		}
	}

	return temp;

}

/** Affcier la matrice sur l'écran
 */
template <typename Type>
void CMatrice<Type>::MATAfficher() const
{
	cout << "La Matrice[" << iMATNBLignes << "][" << iMATNBColonnes << "] est :" << endl;
	for (int i = 0; i < iMATNBLignes; i++)
	{
		for (int j = 0; j < iMATNBColonnes; j++)
		{
			cout << pptMATElement[i][j] << " ";
		}
		cout << endl;
	}
}
 

/** Lire la matrice du document
 * @param filename le nom du document
 */
template <typename Type>
void CMatrice<Type>::MATLireFichier(const char * filename)
{
	MATDetruireMatrice();
		
	ifstream file;
	file.open(filename);
	if (!file.is_open())
	{
		throw Exception(FicherOuvertErreur);
	}

	string str; 

	for (int i = 0; i < 5; i++) 
	{
		getline(file, str);
		size_t len = str.length();
		if (len < 1) 
		{
			throw Exception(FicherVide);
		}
		size_t found = str.find("=");
		if (found == -1 && i != 4) 
		{
			//S'il n'y a pas de 4 signes de l'égalité (=) en total dans le fichier, il sortirais de l'exception.
			throw Exception(FicherContenuErreur); 
		}
		if (i == 0) 
		{
			if (str == "TypeMatrice=double" || str == "TypeMatrice=Double") 
			{ 
				continue;
			}
			else throw Exception(TypeMatriceDouble);
		}
		else if (i == 1) 
		{
			size_t f1 = str.find("NBLignes=");
			if (found != -1) 
			{
				int buflig = 0;
				//Après "NBLignes=", il est le contenu de chiffre
				for (int j = found + 1; j < len; j++)  
				{
					//Si le contenu que l'on lit n'est pas chiffre, il sortirais de l'exception.
					if (!isdigit(str[j])) 					
						throw Exception(FicherContenuErreur);

					//Change le chiffre au la forme de "int", par exemple, 12 = 1 * 10 + 2, 123 = 12 * 10 + 3
					//C'est équal de atoi(), mais pour juger s'il est chiffre pas lettre ou l'autre.
					buflig = buflig * 10 + str[j] - '0'; 	  
					iMATNBLignes = buflig;																	
				}
			}
			else throw Exception(FicherContenuErreur);
		}
		else if (i == 2) 
		{
			size_t f1 = str.find("NBColonnes=");
			if (found != -1) 
			{
				int tmp = 0;
				for (int j = found + 1; j < len; j++) 
				{
					if (!isdigit(str[j]))
						throw Exception(FicherContenuErreur);
					tmp = tmp * 10 + str[j] - '0';
					iMATNBColonnes = tmp;
				}
			}
			else throw Exception(FicherContenuErreur);
		}
		else if (i == 3) 
		{
			if (str != "Matrice=[")
				throw Exception(FicherContenuErreur);
		}
		else {
			pptMATElement = new Type*[iMATNBLignes];
			for (int k = 0; k < iMATNBLignes; k++)
			{
				pptMATElement[k] = new Type[iMATNBColonnes];
			}
			for (int j = 0; j < iMATNBLignes; j++) 
			{
				//quand on est dans le No.j lignes
				stringstream stm;;
				stm.str(str);
				double tmp;
				int num = 0;
				while (stm >> tmp) 
				{
					num++;
					//S'il y a plus de colonnes que l'original
					if (num > iMATNBColonnes)
						throw Exception(LireColEchoue);  
					pptMATElement[j][num - 1] = tmp;
				}
				//S'il y a moins de colonnes que l'original
				if (num < iMATNBColonnes)
				{
					throw Exception(LireColEchoue); 
				}
				getline(file, str);
			}
			//Il n'est pas "]" dans la fin de document.
			if (str != "]")
				throw Exception(FicherContenuErreur); 
		}

	}
	file.close();
	
}

}

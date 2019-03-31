#include <iostream>
#include <string.h>
#include "Matrice.h"
#include "Matrice.cpp"
#include "Exception.h"
using namespace std;
using namespace cmatrice;

#include "Matrice.h"


/** Montrer les deux manières de obtenir une matrice
 */
void SloganPourNumero()
{
	cout <<"******************************************************************"<<endl;
	cout <<"*      Choisir votre nombre pour décider quelle manières         *"<<endl;
	cout <<"*      1 : Taper une matrice                                     *"<<endl;
	cout <<"*      2 : Lire une matrice vient du fichier                     *"<<endl;
	cout <<"******************************************************************"<<endl; 
}

/** Choisir un opérateur pour réalizer la calculation entre deux matrices.
 * @param i le choix de opérateur
 */
void SloganPourOperateur(int &i)
{
    cout <<"******************************************************************"<<endl;
	cout <<"*                Choisir votre opérateur                         *"<<endl;
	cout <<"*                1 : A  +  B                                     *"<<endl;
	cout <<"*                2 : A  -  B                                     *"<<endl;
	cout <<"*                3 : A  *  B                                     *"<<endl;
	cout <<"*                4 : A  *  c                                     *"<<endl;
	cout <<"*                5 : A  /  c                                     *"<<endl;
	cout <<"*                6 : A  -> AT                                    *"<<endl;
	cout <<"*                7 : RESET A                                     *"<<endl;
	cout <<"*                8 : RETURN                                      *"<<endl;
	cout <<"******************************************************************"<<endl; 
	i = 0 ;
	cout <<"Veuillez taper votre choix de l'opérateur : "<< endl;
	cin >>i;
}

/** Choisir une manière de obtenir une matrice
 */
void ChoixdeSource(CMatrice<double> &m)
{
	SloganPourNumero();
	cout <<"Veuillez taper votre nombre : "<<endl;
	int iNumChoix;
	cin >> iNumChoix;
	cout <<"******************************************************************"<<endl;
	switch (iNumChoix)
	{
	case 1:
		int iLig;
		int iCol;
		cout << "Veuillez taper votre ligne : ";
		cin >> iLig;
		cout << "Veuillez taper votre colonne : ";
		cin >> iCol;
		cout <<"******************************************************************"<<endl;
		m.MATInitMatrice(iLig,iCol);
		break;

	case 2: {
		cout << "Veuillez taper le nom du fichier : " << endl;
		char * filename = new char[32];
		cin >> filename;
		cout << "******************************************************************" << endl;
		cout << "Ci-dessous est votre matrice : " << endl;
		m.MATLireFichier(filename);
		delete[] filename;
		break;
	}
	default:
		cout<<"Veuillez choisir le numéro correctment, juste 1 ou 2 !!!"<<endl;
		break;
	}

	m.MATAfficher();

}


int main(int agrc, char* argv[]) 
{
	try
	{
	CMatrice<double> matrice_A;
	CMatrice<double> matrice_B;
	CMatrice<double> matrice_C;
	
	ChoixdeSource(matrice_A);

	int i; /**< la choix de l'opérateur */
	SloganPourOperateur(i);
	int c;
	bool flag = 0;
	while (1)
	{
		switch (i)
		{
			case 1: //A+B
				ChoixdeSource(matrice_B);
				if (matrice_B.MATLireNBLignes() == 0)
				{
					break;
				}
				cout <<"<------------------------- MATRICE A ---------------------------->"<<endl;
				matrice_A.MATAfficher();
				cout <<"  +  "<<endl;
				cout <<"<------------------------- MATRICE B ---------------------------->"<<endl;
				matrice_B.MATAfficher();
				cout <<"   =  "<<endl;
				matrice_C = matrice_A.operator+(matrice_B);
				cout <<"-----------------------------------------------------------------"<<endl;
				matrice_C.MATAfficher();
				SloganPourOperateur(i);
				break;

			case 2: //A-B
				ChoixdeSource(matrice_B);
				if (matrice_B.MATLireNBLignes() == 0)
				{
					break;
				}
				cout <<"<------------------------- MATRICE A ---------------------------->"<<endl;
				matrice_A.MATAfficher();
				cout <<"  -  "<<endl;
				cout <<"<------------------------- MATRICE B ---------------------------->"<<endl;
				matrice_B.MATAfficher();
				cout <<"   =  "<<endl;
				matrice_C = matrice_A.operator-(matrice_B);
				cout <<"-----------------------------------------------------------------"<<endl;
				matrice_C.MATAfficher();
				SloganPourOperateur(i);
				break; 

			case 3: //A*B
				ChoixdeSource(matrice_B);
				if (matrice_B.MATLireNBLignes() == 0)
				{
					break;
				}
				cout <<"<------------------------- MATRICE A ---------------------------->"<<endl;
				matrice_A.MATAfficher();
				cout <<"  *  "<<endl;
				cout <<"<------------------------- MATRICE B ---------------------------->"<<endl;
				matrice_B.MATAfficher();
				cout <<"   =  "<<endl;
				matrice_C = matrice_A.operator*(matrice_B);
				cout <<"-----------------------------------------------------------------"<<endl;
				SloganPourOperateur(i);
				break;

			case 4://A*c
				ChoixdeSource(matrice_B);
				if (matrice_B.MATLireNBLignes() == 0)
				{
					break;
				}
				cout <<"<------------------------- MATRICE A ---------------------------->"<<endl;
				matrice_A.MATAfficher();
				cout <<"  *  "<<endl;
				cout <<"<------------------------- CONSTANTE c--------------------------->"<<endl;
				cin >> c;
				matrice_C = matrice_A.operator*(c);
				cout <<"-----------------------------------------------------------------"<<endl;
				matrice_C.MATAfficher();
				SloganPourOperateur(i);
				break;


			case 5: //A/c
				ChoixdeSource(matrice_B);
				if (matrice_B.MATLireNBLignes() == 0)
				{
					break;
				}
				cout <<"<------------------------- MATRICE A ---------------------------->"<<endl;
				matrice_A.MATAfficher();
				cout <<"  /  "<<endl;
				cout <<"<------------------------- CONSTANTE c--------------------------->"<<endl;
				cin >> c;
				matrice_C = matrice_A.MATDiviser(c);
				cout <<"-----------------------------------------------------------------"<<endl;
				matrice_C.MATAfficher();
				SloganPourOperateur(i);
				break;

			case 6:break; //AT
				ChoixdeSource(matrice_B);
				if (matrice_B.MATLireNBLignes() == 0)
				{
					break;
				}
				cout <<"<------------------------- MATRICE A ---------------------------->"<<endl;
				matrice_A.MATAfficher();
				cout <<"<------------------------- TRANSPOSER -------------------------->"<<endl;
				cin >> c;
				matrice_C = matrice_A.MATTransposer();
				cout <<"-----------------------------------------------------------------"<<endl;
				matrice_C.MATAfficher();
				SloganPourOperateur(i);
				break;

			case 7:
				cout <<"<--------------------------- RESET ---------------------------->"<<endl;
				ChoixdeSource(matrice_A);
				SloganPourOperateur(i);
				break;
			case 8:
				cout << "<-------------------------- RETURN -------------------------->" << endl;
				flag = 1;
				break;
			default:
				cout <<"VOTRE CHOIX EST ["<<i<<"] "<<endl;
				break;
			}

			if (flag)
				break;
		}
	}    
	catch(Exception &e)
	{
		e.EXCAfficherStackTrance();
		system("pause");
		exit(0);
	}

	system("pause");
	return 0;

}

#pragma once

#ifndef CMATRICE_H
#define CMATRICE_H 0
#include <fstream>
#include <istream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "Exception.h"

namespace cmatrice
{
	using namespace std;
		
	template <typename Type>
	class CMatrice
	{
	private:
		int iMATNBLignes;
		int iMATNBColonnes;
		Type** pptMATElement;
	public:
		CMatrice();
		~CMatrice();
		CMatrice(int iNBLignes,int iNBColones);
		CMatrice(CMatrice<Type> & paramMatrice);
		void MATDetruireMatrice(); 
		void MATAllouer(int iLig, int iCol); 
		int MATLireNBLignes() const;
		int MATLireNBColonnes() const;
		Type MATLireElement(int iLig, int iCol) const;
		void MATModifierNBLignes(int iNBLignes); 
		void MATModifierNBColonnes(int iNBColonnes);
		void MATModifierElement(int iLig, int iCol, Type Valeur);
		CMatrice<Type> MATInitMatrice(int iNBLignes, int iNBColonnes);
		CMatrice<Type> MATDiviser(const double dParam) const; // A / c
		CMatrice<Type> operator= (const CMatrice<Type> & paramMatrice); //A = B
		CMatrice<Type> operator+(const CMatrice<Type> & paramMatrice) const; // A + B
		CMatrice<Type> operator-(const CMatrice<Type> & paramMatrice) const; // A - B
		CMatrice<Type> operator*(const Type & tParam) const; // A * c 
		CMatrice<Type> operator*(const CMatrice<Type> & paramMatrice) const; // A * B
		CMatrice<Type> MATTransposer() const;
		void MATAfficher() const;
		void MATLireFichier(const char * filename);
	};

}


#endif


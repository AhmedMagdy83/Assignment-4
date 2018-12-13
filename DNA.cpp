#include "pch.h"
#include "DNA.h"
#include <iostream>
#include"RNA.h"
using namespace std;

DNA::DNA()
{
}


DNA::DNA(char * seq, DNA_Type type)
{
	for (int i = 0; i < sizeof(seq); i++)
	{
		if ((seq[i] == 'A') || (seq[i] == 'C') || (seq[i] == 'G') || (seq[i] == 'T'))
			x++;
		else 
		{
			cout << "invaid" << endl;
			break;
		}
	}
	if (x == sizeof(seq)) {
		cout << "DNA is True " << endl;
	}
	strand1 = new char[sizeof(seq)+1];
	strand2 = new char[sizeof(seq)];
	for (int i = 0; i <sizeof(seq)+1; i++)
	{
		strand1[i] = seq[i];
	
	}
	cout << endl;
	//BuildComplementaryStrand();
	ConvertToRNA();
	
}
void DNA:: Print()
{
	for (int i=0; i < sizeof(seq); i++)
	{
		cout << seq[i];
	}
	cout << endl;

}
void DNA:: BuildComplementaryStrand()
{
	for (int i = 0; i < sizeof(strand1)+1; i++)
	{
		if (strand1[i] == 'A')
			strand2[i] = 'T';
		else if (strand1[i] == 'T')
			strand2[i] = 'A';
		else if (strand1[i] == 'C')
			strand2[i] = 'G';
		else if (strand1[i] == 'G')
			strand2[i] = 'C';
	}
	for (int i = 0; i < sizeof(strand2)+1; i++)
	{
		cout << strand2[i];
	}
	cout << endl;
}
 void DNA:: ConvertToRNA()
 {
	// RNA obj;
	//obj.BuildComplementaryStrand();
	 for (int i = 0; i < sizeof(strand1)+1; i++)
	 {
		 if (strand1[i] == 'T')
			strand1[i] = 'U';

	 }
	 for (int i = 0; i < sizeof(strand1)+1; i++)
	 {
		 cout << strand1[i];

	 }
	 cout << endl;

	// return strand1;
	 /*
	cout << "Enter StartIndex: ";
	//cin >> startIndex;
	cout << "Enter endIndex: ";
	//cin >> endIndex;
	
	//return startIndex, endIndex;
   */
}
DNA:: DNA(const DNA& rhs)
 {
	for (int i = 0; i < sizeof(seq); i++)
	{
		rhs.seq[i] = seq[i];

	}
}
DNA::~DNA()
{
}

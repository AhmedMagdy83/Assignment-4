#include "DNA.h"
#include <iostream>
#include <stdio.h>
#include<cstring>
#include"RNA.h"
using namespace std;
class RNA;
DNA::DNA()
{
}
DNA::DNA(char * seq, DNA_Type type) // Constructor
{
	atype = type;
	for (int i = 0; i <strlen(seq); i++)
	{
		if ((seq[i] == 'A') || (seq[i] == 'C') || (seq[i] == 'G') || (seq[i] == 'T'))
			  ++x; // x is responsible for indicating how many letter are right compared to sequence's length
		else if((seq[i] == 'Q') || (seq[i] == 'W') || (seq[i] == 'E') || (seq[i] == 'R') || (seq[i] == 'Y') || (seq[i] == 'U') || (seq[i] == 'I') || (seq[i] == 'O') || (seq[i] == 'P') || (seq[i] == 'S') || (seq[i] == 'D') ||
			(seq[i] == 'F') || (seq[i] == 'H') || (seq[i] == 'J') ||(seq[i] == 'K') || (seq[i] == 'L') || (seq[i] == 'Z') || (seq[i] == 'X') || (seq[i] == 'V') || (seq[i] == 'B') || (seq[i] == 'N') || (seq[i] == 'M')  )
		{
			  ++y; // y is responsible for indicating how many letter are wrong
		}
	}
	if (y == 0) { // y = 0 means no errors
		cout << "DNA is True " << endl;
		strand1 = new char[strlen(seq)];
		strand2 = new char[strlen(seq)];
		for (int i = 0; i < strlen(seq); i++)
		{
			strand1[i] = seq[i];
		 }
		cout << endl;
	}

}
void DNA:: Print()
{
	for (int i = 0; i < strlen(seq); i++)
	{
		if (seq[i] == 'T' || seq[i] == 'A' || seq[i] == 'C' || seq[i] == 'G'||seq[i]=='U')
			cout << seq[i];
		else
			break;
	}
	cout << endl;
}
void DNA:: BuildComplementaryStrand()
{
	for (int i = 0; i < strlen(strand1); i++)
	{
		if (strand1[i] == 'A')
			strand2[i] = 'T';
		else if (strand1[i] == 'T')
			strand2[i] = 'A';
		else if (strand1[i] == 'C')
			strand2[i] = 'G';
		else if (strand1[i] == 'G')
			strand2[i] = 'C';
		else
		{
			break;
		}

	for (int i = 0; i < strlen(strand2); i++)
	{
		if (strand2[i] == 'T' || strand2[i] == 'A' || strand2[i] == 'C' || strand2[i] == 'G')
			cout << strand2[i];
		else
			break;
	}
	cout << endl;
}}

void DNA::ConvertToRNA()
{
	 for (int i = 0; i < strlen(seq); i++)
	 {
		 if (seq[i] == 'T') // each (T) is replaced by (U)
			 seq[i] = 'U';
}
}

DNA:: DNA( DNA& rhs)
 {
	for (int i = 0; i < sizeof(seq); i++)
	{
		seq[i] =rhs. seq[i];

	}
	//return rhs;
}
DNA::~DNA()
{
    delete[] seq;
}
ostream& operator<< (ostream& out, DNA &obj)
{
	for (int j = 0; j < obj.length; j++)
	{
		out << obj.seq[j];
	}
	out << endl;
	return out;
}
//-------------------------------------------------------------
istream& operator>> (istream& in, DNA&x)
{
	int len;
	string type;
	cout << "Enter your length: " << endl;
	cin >> len;
	x.getsize(len);
	x.seq = new char[len + 1];
	cout << "Enter the Sequence:" << endl;
	for (int i = 0; i < len; i++)
	{
		in >> x.seq[i];
	}
	Sequence s(len,x.seq);
		cout << "enter type: "; cin >> type;
		if (type == "promoter")
          {
           DNA(x.seq, promoter);
           	return in;
          }

		else if (type == "motif")
          {
             DNA(x.seq, motif);
             	return in;
          }

		else if (type == "tail")
          {
             DNA(x.seq, tail);
             	return in;
          }

		else if (type == "noncoding")
          {
             DNA(x.seq, noncoding);
             	return in;
          }

		else
          {
               cout << "error ---> DNA_type" << endl;
               	return in;
          }

}

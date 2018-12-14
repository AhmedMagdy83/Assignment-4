#pragma once
#include"Sequence.h"
#include"Protein.h"
#include"DNA.h"
#include"CodonsTable.h"


enum RNA_Type { mRNA, pre_mRNA, mRNA_exon, mRNA_intron };
class DNA;
class Protein;
class Sequence;


class RNA : public Sequence
{
private:
	RNA_Type type;
	int x=0;
	int y = 0;
	int length;
public:
	// constructors and destructor
	RNA();
	RNA(char * seq, RNA_Type atype);
	//RNA(int length, char *seq);
	RNA(RNA& rhs);
	~RNA();
	// function to be overridden to print all the RNA information
	void Print();
	Protein& ConvertToProtein( CodonsTable  table);
	// function to convert the RNA sequence into protein sequence
	// using the codonsTable object
	//Protein ConvertToProtein(const CodonsTable & table);
	// function to convert the RNA sequence back to DNA
	void ConvertToDNA();
	friend istream& operator>> (istream& in, RNA&x);
};


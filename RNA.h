#ifndef RNA_H
#define RNA_H

#include"Sequence.h"
#include"Protein.h"
#include"DNA.h"
#include"CodonsTable.h"
enum RNA_Type { mRNA, pre_mRNA, mRNA_exon, mRNA_intron };
class Protein;
class DNA;

class RNA : public Sequence
{

private:
	RNA_Type type;
	int x = 0;
public:
	// constructors and destructor
	RNA();
	RNA(char * seq, RNA_Type type);
	RNA(RNA& rhs);
	~RNA();
	// function to be overridden to print all the RNA information
	void Print();
	DNA ConvertToDNA();
	// function to convert the RNA sequence into protein sequence
	// using the codonsTable object
	Protein ConvertToProtein( CodonsTable & table);
	// function to convert the RNA sequence back to DNA

};

#endif

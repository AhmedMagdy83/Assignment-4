#ifndef DNA_H
#define DNA_H
#include"Sequence.h"
#include"RNA.h"
#include<iostream>
#include<string>
using namespace std;
class RNA;
enum DNA_Type { promoter, motif, tail, noncoding };
class DNA : public Sequence
{

private:
	DNA_Type atype;
	DNA * complementary_strand;
	int startIndex;
	int endIndex;
	int x =0 ;
	int y=0;
	char *strand1;
	char *strand2;
public:
	// constructors and destructor
	DNA();
	DNA(char * seq, DNA_Type type);
	DNA( DNA& rhs);
	~DNA();
	// function printing DNA sequence information to user
	void Print();
	//int DNAgetsize();
	//int DNAsetsize(int len);
	// function to convert the DNA sequence to RNA sequence
	// It starts by building the complementary_strand of the current
	// DNA sequence (starting from the startIndex to the endIndex), then,
	// it builds the RNA corresponding to that complementary_strand.
	void ConvertToRNA();
	// function to build the second strand/pair of DNA sequence
	// To build a complementary_strand (starting from the startIndex to
	// the endIndex), convert each A to T, each T to A, each C to G, and
	// each G to C. Then reverse the resulting sequence.
	void BuildComplementaryStrand();
	friend istream& operator>> (istream& in, DNA&x);
	friend ostream& operator<< (ostream& out, DNA &obj);

};



#endif // DNA_H

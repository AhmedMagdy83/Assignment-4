#include "RNA.h"
#include"DNA.h"
#include"Sequence.h"

RNA::RNA()
{
}
RNA::RNA(char * seq, RNA_Type atype)
{
	for (int i = 0; i < sizeof(seq); i++)
	{
		if ((seq[i] == 'A') || (seq[i] == 'C') || (seq[i] == 'G') || (seq[i] == 'U'))
			  x++;
		else if ((seq[i] == 'Q') || (seq[i] == 'W') || (seq[i] == 'E') || (seq[i] == 'R') || (seq[i] == 'Y') || (seq[i] == 'T') || (seq[i] == 'I') || (seq[i] == 'O') || (seq[i] == 'P') || (seq[i] == 'S') || (seq[i] == 'D') ||
			(seq[i] == 'F') || (seq[i] == 'H') || (seq[i] == 'J') || (seq[i] == 'K') || (seq[i] == 'L') || (seq[i] == 'Z') || (seq[i] == 'X') || (seq[i] == 'V') || (seq[i] == 'B') || (seq[i] == 'N') || (seq[i] == 'M'))
		{
			 ++y;
		}
	}
	if (y == 0) {
		cout << "RNA is True " << endl;
	}
	else
		cout << "RNA is Wrong" << endl;

}

void RNA::ConvertToDNA()
{
	for (int i = 0; i <strlen(seq); i++)
	{
		if (seq[i] == 'U')
			seq[i] = 'T';
	}
	/*
	for (int i = 0; i < strlen(seq); i++)
	{
		cout<<seq[i];
	}*/
	cout << endl;
	//DNA obj;
	//obj.setseq(seq);
	//return obj;
}
RNA::RNA(RNA& rhs)
{
	for (int i = 0; i < strlen(seq); i++)
	{
		seq[i] = rhs.seq[i];
    }
}
Codon codons;
Protein ProteinObj;
Protein& RNA::ConvertToProtein(CodonsTable  table)
{
 table.LoadCodonsFromFile("RNA_codon_table.txt");
ProteinObj.seq = new char [sizeof(seq)/3];
char* value = new char [3];

int CounterForValue = 0;
    for(int i = 0 ; i < sizeof(seq)/3; i ++)
                {
                    for(int j = 0 ; j < 3 ; j++)
                    value [j] = seq[CounterForValue + j];

                    CounterForValue += 3;

                    codons = table.getAminoAcid(value);
                    if(codons.AminoAcid != '-')
                    ProteinObj.seq[i] = codons.AminoAcid;
                }
return ProteinObj;

}
void RNA::Print()
{
	for (int i = 0; i < strlen(seq); i++)
	{
		if (seq[i] == 'T' || seq[i] == 'A' || seq[i] == 'C' || seq[i] == 'G' || seq[i] == 'U')
			cout << seq[i];
		else
			break;
	}
	cout<<endl;
}

RNA::~RNA()
{
}

istream& operator>> (istream& in, RNA&x)
{
	int len;
	string type;
	cout << "Enter your length: " << endl;
	cin >> len;
	x.setsize(len);
	x.seq = new char[len + 1];
	cout << "Enter the Sequence:" << endl;
	for (int i = 0; i < len; i++)
	{
		in >> x.seq[i];
	}
	cout << "Enter RNA_Type: "; cin >> type;
	if (type == "mRNA")
		RNA(x.seq, mRNA);
	else if (type == "pre_mRNA")
		RNA(x.seq, pre_mRNA);
	else if (type == "mRNA_exon")
		RNA(x.seq, mRNA_exon);
	else if (type == "mRNA_intron")
		RNA(x.seq, mRNA_intron);
	else
		cout << "Error-----RNA_type" << endl;


	return in;
}

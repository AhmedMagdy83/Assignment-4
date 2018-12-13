#include "RNA.h"

RNA::RNA()
{
}
RNA::RNA(char * seq, RNA_Type type)
{
	type = type;
	if ((type ==0) || (type ==1) || (type == 2) || (type == 3))
		cout << " RNA_Type is True" << endl;
//mRNA, pre_mRNA, mRNA_exon, mRNA_intron
		switch(type){
		 case mRNA:
		     cout<<"mRNA "<<endl;
             break;

		 case pre_mRNA:
		     cout<<"pre_mRNA "<<endl;
             break;

		 case mRNA_exon:
		     cout<<"mRNA_exon "<<endl;
             break;

		 case mRNA_intron:
		     cout<<"mRNA_intron "<<endl;
             break;


		}



	for (int i = 0; i < sizeof(seq); i++)
	{
		if ((seq[i] == 'A') || (seq[i] == 'C') || (seq[i] == 'G') || (seq[i] == 'U')||(seq[i] == 'a') ||(seq[i] == 'c') ||(seq[i] == 'g') ||(seq[i] == 'u'))
			x++;
		else
		{
			cout << "invaid" << endl;
			break;
		}
	}
	if (x == sizeof(seq))
		cout << "RNA is True" << endl;

}
//DNA RNA::ConvertToDNA(){}
Codon codons;
Protein RNA::ConvertToProtein( CodonsTable & table)
{
Protein ProteinObj;

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
void Print()
{
    for(int i = 0 ; i < sizeof(seq) ; i ++){
    cout<<seq[i];
}}
RNA::~RNA()
{
}

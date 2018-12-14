#include "CodonsTable.h"


CodonsTable::CodonsTable()
{
}
void CodonsTable :: LoadCodonsFromFile(string codonsFileName)
{
    fstream myfile;

    myfile.open(codonsFileName, ios::in);
    if (!myfile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    else cout<<"File Opened"<<endl;
            int i=0 ;
  			while ( myfile && !myfile.eof() )
  			{
  				myfile >> codons[i].value;
  				myfile >> codons[i++].AminoAcid;

  			}

            myfile.close();

    }
void  CodonsTable::setCodon(char * value, char AminoAcid, int index)
{
    for(int j = 0 ; j < 3 ; j++)
        codons[index].value[j] = value[j];

       codons[index].AminoAcid = AminoAcid;

}

Codon CodonsTable::getAminoAcid(char * value)

{
    LoadCodonsFromFile("RNA_codon_table.txt");
    for(int i = 0 ; i < 64 ; i++)
        {
    if( value[0] == codons[i].value[0] && value[1] == codons[i].value[1]&& value[2] == codons[i].value[2])
        {

                     return codons[i];

         }
        }
}
CodonsTable::~CodonsTable()
{
}

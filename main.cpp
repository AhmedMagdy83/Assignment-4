#include <iostream>
#include"Sequence.h"
#include"DNA.h"
using namespace std;
void menu();
int main()
{

	menu();

}
void menu()
{
    int choiceOfSeq,choiceOfMethod;
    cout<<"What will you Enter ?\n1-DNA \n2-RNA\n3-Protein"<<endl;
    cin>>choiceOfSeq;

    if(choiceOfSeq == 1)
            {
                int length;
                cout<<"Enter your length"<<endl;
                cin >> length;
                char *seq ;
                seq = new char[length];
                cout<<"Enter the sequence :"<<endl;
                for (int i = 0 ; i < length ; i++)
                cin >> seq[i];
                Sequence *s ;
                 s = new DNA(seq ,motif );
               DNA d;
                cout<<"What u want to do ?\n1-Convert to RNA\n2-Convert to Protein\n3-Convert To complementary strand" <<endl;
                cin>>choiceOfMethod;

                if(choiceOfMethod == 1)
                    {
                d.ConvertToRNA();
                d.Print();
                    }
                if(choiceOfMethod == 2)
                    {
                        d.BuildComplementaryStrand();
                    }
                }
    if(choiceOfSeq == 2)
            {

            RNA r;
            cout<<"What u want to do ?\n1-Convert to DNA\n2-Convert to Protein" <<endl;
            cin>>choiceOfMethod;
           if(choiceOfMethod == 1){
                r.ConvertToDNA();
             //   r.ConvertToProtein();
                r.Print();

                }


}
}

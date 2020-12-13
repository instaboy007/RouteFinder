#include "graph.h"

int main()
{
    int choice;
    BST *District=NULL;
    BST d;
    Distance dis;
    vector<pair<pair<long double,long double>,pair<int,string>>> treetovect;
    vector <pair<pair<int,int>,long double>> storedistance;
    string source,destination;
    int src,des;
    do
    {
        cout<<"\nWELCOME TO ROUTEFINDER!\n";
        cout<<"\nWHAT DO YOU WISH TO DO?\n";
        cout<<"\n1.)FIND ROUTE\n2.)EXIT\nENTER YOUR CHOICE=>";
        cin>>choice;
        if(choice==1)
        {
            District=d.load(District);
            cout<<"\nENTER THE SOURCE LOCATION:";
            cin.ignore();
            getline(cin,source);
            cout<<"\nENTER THE DESTINATION LOCATION:";
            cin.ignore();
            getline(cin,destination);
            cout<<"\nENTER THE SOURCE NUMBER:";
            cin>>src;
            cout<<"\nENTER THE DESTINATION NUMBER:";
            cin>>des;
            treetovect=dis.inordervisit(District,treetovect);
            storedistance=dis.connect(treetovect);
            int V=39;
            Graph G(V);
            G.makepath(0,0,0,storedistance);
            G.FindRoute(src,des,District);
        }
    } while(choice<2);
}
    
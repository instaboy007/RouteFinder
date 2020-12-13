#include<iostream>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<list>
#include<algorithm>
#include<cstring>
#include<stdlib.h>
using namespace std;

class BST
{
    public:
        string Dname;
        int Dnum;
        long double Dlat,Dlong;
        BST *left,*right;
        BST *insert(BST *,int,const string,long double,long double);
        void inorder(BST *);
        BST * load(BST*);
        void BSTSearch(BST *,int);
};

BST * BST::insert(BST *Node,int Dnum,const string Dname,long double Dlat,long double Dlong)
{
    if(Node==NULL)
    {
        BST *temp=new BST;
        temp->Dnum=Dnum;
        temp->Dname=Dname;
        temp->Dlat=Dlat;
        temp->Dlong=Dlong;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    else if(Node->Dnum>Dnum && Dnum!=Node->Dnum)
    {
        Node->left=insert(Node->left,Dnum,Dname,Dlat,Dlong);
    }
    else if(Node->Dnum<Dnum && Dnum!=Node->Dnum)
    {
        Node->right=insert(Node->right,Dnum,Dname,Dlat,Dlong);
    }
    return Node;
}

void BST:: inorder(BST *Node)
{
    if(Node!=NULL)
    {
        inorder(Node->left);
        cout<<"  "<<Node->Dnum;
        for(int i=log10(Node->Dnum)+1;i<5;i++)
        {
            cout<<" ";
        }
        cout<<Node->Dname<<endl;
        inorder(Node->right);
    }
}

BST * BST:: load(BST * d)
{
    d=insert(d,1,"Ariyalur",11.139850,79.078967);
    d=insert(d,2,"Chengalpattu",12.667238, 79.997288);
    d=insert(d,3,"Chennai",13.060915, 80.223913);
    d=insert(d,4,"Coimbatore",11.009656, 76.962397);
    d=insert(d,5,"Cuddalore",11.751152, 79.772886);
    d=insert(d,6,"Dharmapuri",12.124602, 78.153609);
    d=insert(d,7,"Dindigul",10.362253, 77.969488);
    d=insert(d,8,"Erode",11.336757, 77.713493);
    d=insert(d,9,"Kallakurichi",11.736706, 78.962292);
    d=insert(d,10,"Kanchipuram",12.818354, 79.694660);
    d=insert(d,11,"Kanniyakumari",8.084915, 77.547330);
    d=insert(d,12,"Karur",10.975682, 78.061777);
    d=insert(d,13,"Krishnagiri",12.526458, 78.214963);
    d=insert(d,14,"Madurai",9.918918, 78.120013);
    d=insert(d,15,"Mayiladuthurai",11.101714, 79.652719);
    d=insert(d,16,"Nagapattinam",10.781898, 79.840780);
    d=insert(d,17,"Namakkal",11.219081, 78.167958);
    d=insert(d,18,"Nilgiris",11.458073, 76.644682);
    d=insert(d,19,"Perambalur",11.234150, 78.880598);
    d=insert(d,20,"Pudukkottai",10.383258, 78.800143);
    d=insert(d,21,"Ramanathapuram",9.366710, 78.842032);
    d=insert(d,22,"Ranipet",12.952688, 79.317496);
    d=insert(d,23,"Salem",11.666404, 78.133450);
    d=insert(d,24,"Sivagangai",9.851057, 78.486547);
    d=insert(d,25,"Tenkasi",8.959289, 77.316096);
    d=insert(d,26,"Thanjavur",10.754052, 79.126129);
    d=insert(d,27,"Theni",10.006919, 77.475144);
    d=insert(d,28,"Thoothukudi",8.774783, 78.140193);
    d=insert(d,29,"Tiruchirappalli",10.793932, 78.696281);
    d=insert(d,30,"Tirunelveli",8.719369, 77.750032);
    d=insert(d,31,"Tirupattur",12.497002, 78.565789);
    d=insert(d,32,"Tiruppurr",11.115312, 77.359689);
    d=insert(d,33,"Tiruvallur",13.122939, 79.911942);
    d=insert(d,34,"Tiruvannamalai",12.235701, 79.074995);
    d=insert(d,35,"Tiruvarur",10.769059, 79.629916);
    d=insert(d,36,"Vellore",12.899527, 79.119509);
    d=insert(d,37,"Viluppuram",11.945247, 79.490521);
    d=insert(d,38,"Virudhunagar",9.575432, 77.957466);
    inorder(d);
    return d;
}


void BST::BSTSearch(BST *District,int Dnum)
{
    if(District==NULL)
    {
        cout<<"\nNOT PRESENT\n";
    }
    else if(District->Dnum==Dnum)
    {
        cout<<District->Dname;
    }
    else if(Dnum>District->Dnum)
    {
        BSTSearch(District->right,Dnum);
    }
    else if(Dnum<District->Dnum)
    {
        BSTSearch(District->left,Dnum);
    }
}

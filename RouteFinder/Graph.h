#include "Distance.h"
#include <queue>
#define INF 999999999

typedef pair<int,int> Pair;

class Graph
{
    int V;
    list<pair<int,int>> *adjacent;
    public:
        Graph(int V);
        bool check(int,int);
        void makepath(int src,int dest,long double weight,vector <pair<pair<int,int>,long double>>distance);
        int FindRoute(int,int,BST *);
        void displayroute(vector<int> &, int, int,BST *);
        void displaydistrict(int,BST*);
};

Graph::Graph(int V)
{
    this->V = V;
    adjacent = new list<Pair> [V];
}

bool Graph::check(int source,int destination)
{
    int a[39][39]={};
    
    a[1][5]=1;
    a[1][19]=1;
    a[1][26]=1;
    a[1][29]=1;
    a[2][3]=1;
    a[2][10]=1;
    a[2][34]=1;
    a[2][37]=1;
    a[3][33]=1;
    a[3][10]=1;
    a[3][2]=1;
    a[4][18]=1;
    a[4][8]=1;
    a[4][32]=1;
    a[5][37]=1;
    a[5][9]=1;
    a[5][19]=1;
    a[5][1]=1;
    a[5][26]=1;
    a[5][15]=1;
    a[6][13]=1;
    a[6][34]=1;
    a[6][23]=1;
    a[6][9]=1;
    a[7][32]=1;
    a[7][12]=1;
    a[7][14]=1;
    a[7][27]=1;
    a[7][29]=1;
    a[8][18]=1;
    a[8][4]=1;
    a[8][32]=1;
    a[8][4]=1;
    a[8][32]=1;
    a[8][12]=1;
    a[8][17]=1;
    a[8][23]=1;
    a[9][6]=1;
    a[9][23]=1;
    a[9][19]=1;
    a[9][5]=1;
    a[9][37]=1;
    a[9][34]=1;
    a[10][3]=1;
    a[10][2]=1;
    a[10][34]=1;
    a[10][22]=1;
    a[10][33]=1;
    a[11][30]=1;
    a[12][32]=1;
    a[12][7]=1;
    a[12][29]=1;
    a[12][17]=1;
    a[12][8]=1;
    a[13][6]=1;
    a[13][31]=1;
    a[13][34]=1;
    a[14][7]=1;
    a[14][27]=1;
    a[14][38]=1;
    a[14][24]=1;
    a[14][29]=1;
    a[15][5]=1;
    a[15][35]=1;
    a[15][26]=1;
    a[16][35]=1;
    a[17][8]=1;
    a[17][12]=1;
    a[17][29]=1;
    a[17][23]=1;
    a[18][4]=1;
    a[18][8]=1;
    a[19][23]=1;
    a[19][29]=1;
    a[19][1]=1;
    a[19][5]=1;
    a[19][9]=1;
    a[20][29]=1;
    a[20][26]=1;
    a[20][24]=1;
    a[20][21]=1;
    a[21][28]=1;
    a[21][38]=1;
    a[21][24]=1;
    a[21][20]=1;
    a[22][36]=1;
    a[22][33]=1;
    a[22][10]=1;
    a[22][34]=1;
    a[23][8]=1;
    a[23][6]=1;
    a[23][9]=1;
    a[23][19]=1;
    a[23][29]=1;
    a[23][17]=1;
    a[24][29]=1;
    a[24][14]=1;
    a[24][38]=1;
    a[24][21]=1;
    a[24][20]=1;
    a[25][38]=1;
    a[25][28]=1;
    a[25][30]=1;
    a[26][1]=1;
    a[26][29]=1;
    a[26][20]=1;
    a[26][5]=1;
    a[26][15]=1;
    a[26][35]=1;
    a[27][7]=1;
    a[27][14]=1;
    a[27][38]=1;
    a[27][25]=1;
    a[28][21]=1;
    a[28][38]=1;
    a[28][25]=1;
    a[28][30]=1;
    a[29][1]=1;
    a[29][26]=1;
    a[29][20]=1;
    a[29][14]=1;
    a[29][7]=1;
    a[29][12]=1;
    a[29][19]=1;
    a[29][17]=1;
    a[29][23]=1;
    a[30][11]=1;
    a[30][28]=1;
    a[30][25]=1;
    a[31][36]=1;
    a[31][13]=1;
    a[31][34]=1;
    a[32][4]=1;
    a[32][8]=1;
    a[32][12]=1;
    a[32][7]=1;
    a[33][36]=1;
    a[33][22]=1;
    a[33][10]=1;
    a[33][3]=1;
    a[34][2]=1;
    a[34][10]=1;
    a[34][22]=1;
    a[34][36]=1;
    a[34][31]=1;
    a[34][13]=1;
    a[34][6]=1;
    a[34][9]=1;
    a[34][37]=1;
    a[35][26]=1;
    a[35][15]=1;
    a[35][16]=1;
    a[36][31]=1;
    a[36][34]=1;
    a[36][22]=1;
    a[36][33]=1;
    a[37][2]=1;
    a[37][34]=1;
    a[37][9]=1;
    a[37][5]=1;
    a[38][27]=1;
    a[38][14]=1;
    a[38][24]=1;
    a[38][21]=1;
    a[38][28]=1;
    a[38][25]=1;
    if(a[source][destination]==1)
    {
        return true;
    }
    return false;
}

void Graph::makepath(int source, int destination,long double weight,vector <pair<pair<int,int>,long double>> distance)
{
    for(int i=0;i<distance.size();i++)
    {
        bool checkpath=false;
        source=distance[i].first.first;
        destination=distance[i].first.second;
        checkpath=check(source,destination);
        if(checkpath==true)
        {
            weight=distance[i].second;
            adjacent[source].push_back(make_pair(destination, weight));
            adjacent[destination].push_back(make_pair(source, weight));
        }
    }
}

int Graph::FindRoute(int source, int destination,BST *District)
{
    priority_queue<Pair, vector<Pair>, greater<Pair> > q;
    vector<int> distance(V,INF);
    vector<int> parentlocation(V);
    parentlocation[source] = -1;
    q.push(make_pair(0, source));
    distance[source] = 0;
    while (q.size()) 
    {
        int top = q.top().second;
        q.pop();
        list<Pair>::iterator i;
        for (i=adjacent[top].begin(); i!= adjacent[top].end();i++) 
        {
            int dest = i->first;
            int weight = i->second;
            if (distance[dest]>distance[top] + weight)
            {
                distance[dest] = distance[top] + weight;
                q.push(make_pair(distance[dest],dest));
                parentlocation[dest] = top;
            }
        }
    }
    for (int i = 1; i < V; i++)
    {
        if(i==destination)
        {
            cout<<"\nROUTE => ";
            displayroute(parentlocation,i,destination,District);
            cout<<"\nShortest Distance : "<<distance[i]<<" KM(approx)"<<endl;
        }
    }
    return 0;
}
void Graph::displayroute(std::vector<int> &parent, int v, int des,BST *District)
{
    if (parent[v]==-1)
    {
        displaydistrict(v,District);
        cout <<"-->";
        return ;
    }
    displayroute(parent, parent[v], des,District);
    if(v==des)
    {
        displaydistrict(v,District);
    }
    else
    {
        displaydistrict(v,District);
        cout <<"-->";
    }
}
void Graph::displaydistrict(int v,BST *District)
{
    BST D;
    D.BSTSearch(District,v);
}
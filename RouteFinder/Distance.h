#include "District.h"

class Distance
{
    public:
        vector<pair<pair<long double,long double>,pair<int,string>>> inordervisit(BST *,vector<pair<pair<long double,long double>,pair<int,string>>>);
        vector <pair<pair<int,int>,long double>> connect(vector<pair<pair<long double,long double>,pair<int,string>>>);
        long double Radians(const long double);
        long double finddistance(long double ,long double ,long double,long double);
};

long double Distance::Radians(const long double degree)
{
    long double one_deg=(3.14159265358979323846)/180;
    return (one_deg*degree);
}

long double Distance::finddistance(long double latitude1,long double longitude1,long double latitude2,long double longitude2)
{
    // Convert the latitudes and longitudes from degree to radians.
    latitude1=Radians(latitude1);
    longitude1=Radians(longitude1);
    latitude2= Radians(latitude2);
    longitude2 = Radians(longitude2);
    // Haversine Formula
    long double dlong = longitude2-longitude1;
    long double dlat = latitude2-latitude1;
    long double ans = pow(sin(dlat/2),2)+cos(latitude1)*cos(latitude2)*pow(sin(dlong/2),2);
    ans = 2 * asin(sqrt(ans));
    // Radius of Earth in Kilometers, R = 6371
    long double R = 6371;
    // Calculate the result
    ans = ans * R;
    return ans;
}

vector<pair<pair<long double,long double>,pair<int,string>>> Distance::inordervisit(BST *Node,vector<pair<pair<long double,long double>,pair<int,string>>> distance)
{
    for(int i=0;Node!=NULL;i++)
    {
         distance.push_back(make_pair(make_pair(Node->Dlat,Node->Dlong),make_pair(Node->Dnum,Node->Dname)));
         Node=Node->right;
    }
    return distance;
}
vector <pair<pair<int,int>,long double>> Distance:: connect(vector<pair<pair<long double,long double>,pair<int,string>>>distance)
{
    vector <pair<pair<int,int>,long double>> d;
    int i,j;
    long double temp_distance;
    for(i=0;i<distance.size();i++)
    {
        for(j=i+1;j<distance.size();j++)
        {
            temp_distance=finddistance(distance[i].first.first,distance[i].first.second,distance[j].first.first,distance[j].first.second);
            d.push_back(make_pair(make_pair(distance[i].second.first,distance[j].second.first),temp_distance));
        }
    }
    /*
    for(i=0;i<d.size();i++)
    {
        cout<<d[i].first.first<<" "<<d[i].first.second<<" "<<d[i].second<<endl;
    }*/
    return d;
}


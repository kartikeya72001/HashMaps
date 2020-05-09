#include<iostream>
#include<unordered_map>
#include <vector>
using namespace std;

int checkRight(vector<pair<int,int> >v )
{
    unordered_map<int,int> mx,my;
    int total = 0;
    for(int i=0;i<v.size();i++)
    {
            mx[v[i].first]++;
            my[v[i].second]++;
    }
    for(int i=0;i<v.size();i++)
    {
        int x=0;
        int y=0;
        x = mx[v[i].first];
        y = my[v[i].second];
        total += (x-1)*(y-1);
        cout<<endl;
    }

    return total;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].first;
        cin>>v[i].second;
    }
    int total = 0;
    total=checkRight(v);
    cout<<"Total Triangles Possible are: "<<total<<endl;
    return 0;
}

#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    map<int,bool> mp;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        mp[a] = false;
    }
    for(int i=0;i<n;i++)
    {
        int b;
        cin>>b;
        if(mp.find(b)!=mp.end())
        {
            mp[b] = true;
        }
    }
    cout<<"[";
    for(auto x:mp)
    {
        pair<int,bool> check = x;
        if(check.second==true)
            cout<<check.first<<", ";
    }
    cout<<"]";
    return 0;
}

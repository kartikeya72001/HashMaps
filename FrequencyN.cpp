#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int n ; cin>>n ;
    int *a = new int[n] ;
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i] ;
    }
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
    }
    int maxfrequencyno = m.begin()->first;
    int maxfrequency = m.begin()->second ;
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if(i->second > maxfrequency)
        {
            maxfrequencyno = i->first ;
            maxfrequency = i->second ;
        }
    }
    cout<<maxfrequencyno ;
    return 0;
}

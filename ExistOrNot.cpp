#include <iostream>
#include <unordered_set>
using namespace std;

bool Exist(int arr[], int n, int a) {
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    if(s.find(a)!=s.end()){
        return true;
    }
    return false;

}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int q;
        cin>>q;
        while(q--)
        {
            int a;
            cin>>a;
            if(Exist(arr,n,a))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}

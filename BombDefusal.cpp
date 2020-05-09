#include <iostream>
#include <map>
using namespace std;

void display(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    return;
}

void Unlock(int arr[],int n, int k) {
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]] = i;
    }
    int idx = 0;
    int large = n;
    while(k>0 && idx<n)
    {
        int idxl = mp[large];
        if(idxl != idx)
        {
            mp[arr[idx]]=idxl;
            mp[large]=idx;
            swap(arr[idxl],arr[idx]);
            k--;
        }
        idx++;
        large--;
    }
    display(arr,n);
    cout<<endl;
    return;
}

int main(int argc, char const *argv[]) {
    int n,k;
    cin>>n>>k;

    int *arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Unlock(arr,n,k);

    return 0;
}

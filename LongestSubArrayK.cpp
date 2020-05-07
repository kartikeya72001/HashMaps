#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarraySumK(int* arr, int n, int k)
{
    unordered_map<int, int> mp;
    int pre = 0;
    int len = 0;
    for(int i=0;i<n;i++)
    {
        pre += arr[i];
        if(pre == k)
            len = max(len,i+1);
        if(mp.find(pre-k) != mp.end())
            len = max(len,i-mp[pre-k]);
        else{
            mp[pre] = i; //Entry for the first occurrence
        }
    }
    return len;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        std::cin >> arr[i];
    }
    int k;
    std::cin >> k;
    int ans = longestSubarraySumK(arr,n,k);
    cout<<ans<<endl;
    return 0;
}

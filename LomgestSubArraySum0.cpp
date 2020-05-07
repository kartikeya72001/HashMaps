#include<iostream>
#include<unordered_map>
using namespace std;

int longestSubarray(int *arr, int n)
{
    unordered_map<int, int> mp;
    int pre = 0;
    int len = 0;
    for(int i=0;i<n;i++)
    {
        pre += arr[i];
        if(arr[i]==0 and len == 0)
            len=1;
        if(pre == 0)
            len = max(len,i+1);
        if(mp.find(pre) != mp.end())
            len = max(len,i-mp[pre]);
        else{
            mp[pre] = i;
        }
    }
    return len;
}

int main(int argc, char const *argv[]) {
    int n;
    std::cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        std::cin >> arr[i];
    }
    int ans = longestSubarray(arr, n);
    std::cout<<"Longest Subarray is: "<<ans<<endl;
    return 0;
}

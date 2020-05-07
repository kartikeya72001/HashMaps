#include <iostream>
#include <unordered_set>
using namespace std;

int longestStreak(int *arr, int count)
{
    unordered_set<int> s;
    for (size_t i = 0; i < count; i++) {
        s.insert(arr[i]);
    }
    int ans = 0;
    for (size_t i = 0; i < count; i++) {
        if (s.find(arr[i]-1) != s.end()) {
            continue;
        }
        else{
            int n = 0;
            int x = arr[i];
            while (s.find(x) != s.end()) {
                n++;
                x++;
            }
            ans = max(ans,n);
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        std::cin >> arr[i];
    }
    int ans = longestStreak(arr,n);
    cout<<"Longest Streak is: "<<ans<<endl;
    return 0;
}

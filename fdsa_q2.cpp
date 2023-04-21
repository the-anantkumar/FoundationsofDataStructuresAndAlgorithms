#include<bits/stdc++.h>
#include<chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

long long collectBalls(vector<long long>& bags, int k) {
    priority_queue<long long> pq;
    for (long long bag : bags) {
        pq.push(bag);
    }
    long long ans = 0;
    while (k--) {
        long long top = pq.top();
        pq.pop();
        ans += top;
        pq.push(top / 2);
    }
    return ans;
}

int main()
{


    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;

        vector<long long> a;

        for(int i = 0; i < n; i++)
        {
            int x;
            cin>>x;
            a.push_back(x);
        }

        cout<<collectBalls(a, k);
    }
}
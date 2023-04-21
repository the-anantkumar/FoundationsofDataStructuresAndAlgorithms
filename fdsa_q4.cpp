#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        stack<int> s;
        s.push(-1);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x > 33) {
                    int top = s.top();
                    if(x > top)
                    {
                        s.pop();
                        s.push(x);
                    }   
            }
                else {
                if (s.top() != -1) {
                    ans += s.top();
                }
            }
    }
      cout << ans << endl;
   
}

 return 0;
}

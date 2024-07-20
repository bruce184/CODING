#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define         ull         unsigned long long
//#define         int         long long
#define         endl        '\n'
#define         task        "CAU1"
#define         file        if (fopen(task".INP", "r")) { freopen(task".INP", "r", stdin); freopen(task".OUT", "w", stdout);}
#define         Groot       signed main()
const           int         MAX = 2e6;

using namespace std;

signed main() {
    int n; cin >> n;
    vector<int>a(n),ans;
    int MAX = 1;
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        int z = ans.size();
        if (a[i] <= ans.back()) {
            MAX = max(MAX,z);
            ans.clear();
            ans.push_back(a[i]);
        }
        else {
            ans.push_back(a[i]);
            z++;
            MAX = max(MAX,z);
        }
    }
    cout << MAX;
}

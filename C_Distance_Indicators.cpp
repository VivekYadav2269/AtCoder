#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i];
    }
    
    std::vector <i64> dp(n);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] + i < n) {
            dp[a[i] + i] += 1LL;
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            ans += dp[i - a[i]];
        }
        // cout << ans << ' ';
    }
    // cout << '\n';
    std::cout << ans;
    
    return 0;
}
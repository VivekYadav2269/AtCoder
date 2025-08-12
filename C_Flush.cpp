#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector <int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());
    
    std::vector <int> at(a[n - 1] + 1);
    std::vector <i64> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + 1LL * a[i];
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (at[a[i]] != 0) {
            continue;
        }
        while (j < (a[n - 1] + 1) && j <= a[i]) {
            at[j] = i;
            j++;
        }
    }

    std::vector <i64> dp(a[n - 1] + 1);
    dp[0] = 0LL, dp[1] = 1LL;
    for (int i = 2; i <= a[n - 1]; i++) {
        dp[i] = sum[at[i - 1]] + 1LL * (n - at[i - 1]) * (i - 1) + 1LL;
    }
   
    for (int i = 0; i < q; i++) {
        i64 b;
        std::cin >> b;
        
        if (b > a[n - 1]) {
            std::cout << -1 << '\n';
        } else {
            std::cout << dp[b] << '\n';
        }
    }
    
    return 0;
}
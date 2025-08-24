#include <bits/stdc++.h>
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    i64 ans = 0;
    std::vector <int> min(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        if (a[i] <= b[i]) {
            ans += 1LL * a[i];
            min[i] = 0;
        } else {
            ans += 1LL * b[i];
            min[i] = 1;
        }
    }
    
    for (int i = 0; i < q; i++) {
        char c;
        int j, ele;
        std::cin >> c >> j >> ele;
        j--;
        if (c == 'A') {
            if (min[j] == 0) {
                ans -= 1LL * a[j];
                if (ele <= b[j]) {
                    ans += 1LL * ele;
                } else {
                    ans += 1LL * b[j];
                    min[j] = 1;
                }
            } else {
                ans -= 1LL * b[j];
                if (ele >= b[j]) {
                    ans += 1LL * b[j];
                } else {
                    ans += 1LL * ele;
                    min[j] = 0;
                }
            }
            a[j] = ele;
        } else {
            if (min[j] == 0) {
                ans -= 1LL * a[j];
                if (ele >= a[j]) {
                    ans += 1LL * a[j];
                } else {
                    ans += 1LL * ele;
                    min[j] = 1;
                }
            } else {
                ans -= 1LL * b[j];
                if (ele <= a[j]) {
                    ans += 1LL * ele;
                } else {
                    ans += 1LL * a[j];
                    min[j] = 0;
                }
            }
            b[j] = ele;
        }
        std::cout << ans << '\n';
    }
    
    return 0;
}
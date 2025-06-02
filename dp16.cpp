#include <iostream>
#include <vector>
using namespace std;

int mod = 1e9 + 7;

int final(int sum, vector<int>& v) {
    int n = v.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (v[i - 1] <= j)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - v[i - 1]]) % mod;
        }
    }
    return dp[n][sum];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = i + 1;

    long long sum = 1LL * n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int k = sum / 2;
    int ans = final(k, v);

    int inv2 = (mod + 1) / 2;
    cout << (1LL * ans * inv2) % mod << endl;
}

#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& a, int M) {
    sort(a.begin(), a.end());
    int Q = 0;
    int i = 0;
    int j = a.size() - 1;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum == M) {
            Q++;
            i++;
            j--;
        } else if (sum < M) {
            i++;
        } else {
            j--;
        }
    }
    return Q;
}

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int result = countPairs(a, M);
    cout << result << endl;

    return 0;
}
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cstring>
#include<cmath>
using namespace std;
int DAT[26];
int cnt[11];
int n;

bool cmp(pair<char, int>p1, pair<char, int>p2) {
    return p1.second > p2.second;
}

void func() {
    unordered_map<char, int>um;
    unordered_map<char, int>um2;
    vector<string>input;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        input.push_back(s);
        for (int j = s.length()-1; j >= 0; j--) {
            um[s[j]] += pow(10, s.length() - (j + 1));
        }
    }
    vector<pair<char, int>>sv(um.begin(), um.end());
    sort(sv.begin(), sv.end(),cmp);
    int val = 9;
    for (auto p : sv) {
        um2[p.first] = val--;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mul = 1;
        for (int j = input[i].length()-1; j >=0; j--) {
            ans += mul * um2[input[i][j]];
            mul *= 10;
        }
    }
    cout << ans;

}

int main() {
    cin >> n;
    func();
    return 0;
}
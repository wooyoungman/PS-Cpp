#include <iostream>
#include <vector>
using namespace std;

int dist(string s1, string s2) {
    int d = 0;
    for (int i = 0; i < 4; i++) {
        if (s1[i] != s2[i]) {
            d++;
        }
    }
    return d;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<string>v;
        for (int j = 0; j < n; j++) {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }
        // 이 경우는 무조건 MBTI의 종류 16가지 중 1가지가 3개로 중복 되므로 0
        if (n > 32) {
            cout << 0 << "\n";
        }
        else
        {
            int min_d = 100;
            for (int a = 0; a < n - 2; a++) {
                for (int b = a + 1; b < n - 1; b++) {
                    for (int c = b + 1; c < n; c++) {
                        int d1 = dist(v[a], v[b]);
                        int d2 = dist(v[a], v[c]);
                        int d3 = dist(v[b], v[c]);
                        int dist_sum = d1 + d2 + d3;
                        min_d > dist_sum ? min_d = dist_sum : min_d = min_d;
                    }
                }
            }
            cout << min_d << "\n";
        }
    }
    
    return 0;
}


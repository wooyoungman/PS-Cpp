#include<iostream>
#include<algorithm>
using namespace std;
string a, b;
int length[1001][1001];

int main() {

    cin >> a;
    cin >> b;

    int a_length = a.length();
    int b_length = b.length();

    for (int i = 0; i < a_length; i++) {
        for (int j = 0; j < b_length; j++) {
            if (a[i] == b[j]) {
                length[i + 1][j + 1] = length[i][j] + 1;
            }
            else {
                length[i + 1][j + 1] = max(length[i + 1][j], length[i][j + 1]);
            }
        }
    }

    int lcs_length = length[a_length][b_length];
    string lcs = "";
    
    int cur_row = a_length;
    int cur_col = b_length;
    cout << lcs_length;
    // i-1,j 또는 i,j-1 지점에서 LCS길이가 같은것이 존재하지 않으면
    // 현재 i,j 지점은 공통문자이다!

    while (cur_row > 0 && cur_col > 0) {

        if (length[cur_row][cur_col] > length[cur_row - 1][cur_col] &&
            length[cur_row][cur_col] > length[cur_row][cur_col - 1]) {

            lcs += a[cur_row-1];
            cur_row -= 1;
            cur_col -= 1;
        }
        else if (length[cur_row][cur_col] == length[cur_row - 1][cur_col] &&
            length[cur_row][cur_col] > length[cur_row][cur_col - 1]) {
            cur_row -= 1;
        }
        else if (length[cur_row][cur_col] > length[cur_row - 1][cur_col] &&
            length[cur_row][cur_col] == length[cur_row][cur_col - 1]) {
            cur_col -= 1;
        }
        else {
            if (cur_row > 1)cur_row -= 1;
            else cur_col -= 1;
        }

    }
    cout << "\n";
    for (int i = lcs.length() - 1; i >= 0; i--) {
        cout << lcs[i];
    }


    return 0;
}
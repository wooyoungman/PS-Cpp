#include <iostream>
#include <cmath>
using namespace std;
double h, w, n, m;
int main() {
    cin >> h >> w >> n >> m;
    cout << (int)ceil(h / (n + 1)) * (int)ceil(w / (m + 1));
    return 0;
}
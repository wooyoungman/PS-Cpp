#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    // 원의 특징은 하나의 사분면에 대하여 모두 대칭이라는 특징이 있다.
    // 1사분면에 조건에 해당하는 값만 구하고 *4를 한다면 정답을 찾아낼 수 있을 것이다.
    // 처음에 직접 그려가며 작은 원의 반지름을 한 변으로 하는 정사각형의 대각선의 길이를 이용하여
    // 이 값보다 큰 경우와 작은 경우로 나누어 풀이를 하였으나 결과는 오답이었다.
    // 다시 생각해보면서 x를 1부터 r2길이까지 해당하는 각 원의 y좌표를 구하고,
    // 그 사이에 있는 값들이 정답의 개수가 될 것 같았다.
    // 그러나 소수점이 들어가는 계산에서 막혀 다른 풀이를 참고하여 해결했다.
    // int x 1LL = long long int의 형 변환을 쉽게 할 수 있다.
    // max_y와 min_y를 구할 때 sqrt안에 식에서 오버플로우가 발생한 것이 원인이었다.
    long long answer = 0;
    for(int x=1;x<=r2;x++){
        long long max_y=floor(sqrt(r2*1ll*r2-x*1ll*x));
        long long min_y=x<r1?ceil(sqrt(r1*1ll*r1-x*1ll*x)):0;
        answer+=(max_y-min_y+1);
    }

    return answer*4;
}
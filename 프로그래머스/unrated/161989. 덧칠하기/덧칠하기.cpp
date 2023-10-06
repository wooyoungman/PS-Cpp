#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    // start 지점을 section의 첫번째 원소의 값
    // end 지점을 start 지점에서 페인트칠을 1회 한 값으로 지정
    // 사이에 section의 원소가 해당한다면 pass
    // 없으면 다음 section 원소가 start로
    int start=section[0];
    int end=start+m-1;
    for(int i:section){
        if(i>=start&&i<=end){
            continue;
        }
        else{
            start=i;
            end=start+m-1;
            answer++;
        }
    }
    return answer;
}
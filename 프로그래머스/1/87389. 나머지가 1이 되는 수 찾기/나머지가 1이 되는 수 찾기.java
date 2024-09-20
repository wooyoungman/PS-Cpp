import java.util.*;
class Solution {
    public int solution(int n) {
        int answer = n;
        int num=2;
        while(num<n){
            if(answer%num==1)answer=Math.min(answer,num);
            num++;
        }
            return answer;
    }
}
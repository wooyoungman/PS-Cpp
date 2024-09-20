import java.util.*;
class Solution {
    
    int[] save = new int[3];
    int answer=0;
    
    public int solution(int[] number) {
        combination(number, 0, 0);
        return answer;
    }
    
    public void combination(int[] number,int depth, int cur){
        if(depth==3){
            int sum=0;
            for(int i=0;i<3;i++){
                sum+=save[i];
            }
            if(sum==0){
                answer++;
            }
            return;
        }
        for(int i=cur;i<number.length;i++){
            save[depth]=number[i];
            combination(number,depth+1,i+1);
        }
    }
}
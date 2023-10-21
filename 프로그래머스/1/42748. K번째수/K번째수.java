import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        for(int i=0;i<commands.length;i++){
            int cnt_temp=0;
            int start_idx=commands[i][0];
            int end_idx=commands[i][1];
            int pick_idx=commands[i][2];
            int[] temp= new int[end_idx-start_idx+1];
            for(int j=start_idx-1;j<end_idx;j++){
                temp[cnt_temp++]=array[j];
            }
            Arrays.sort(temp);
            answer[i]=temp[pick_idx-1];
        }
        return answer;
    }
}
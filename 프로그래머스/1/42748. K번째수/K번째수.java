import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        
        int commandsSize=commands.length;
        int[] answer=new int[commandsSize];
        int idx=0;
        for(int i=0;i<commandsSize;i++){
            int a=commands[i][0];
            int b=commands[i][1];
            int c=commands[i][2];
            ArrayList<Integer>nums = new ArrayList<>();
            for(int j=a-1;j<b;j++){
                nums.add(array[j]);
            }
            Collections.sort(nums);
            answer[idx++]=nums.get(c-1);
        }
        return answer;
    }
}
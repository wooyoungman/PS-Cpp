import java.util.*;
class Solution {
    int[] numsX = new int[10];
    int[] numsY = new int[10];
    public String solution(String X, String Y) {
        StringBuilder answer = new StringBuilder();
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0;i<X.length();i++){
            int num=X.charAt(i)-'0';
            numsX[num]++;
        }
        for(int i=0;i<Y.length();i++){
            int num=Y.charAt(i)-'0';
            numsY[num]++;
        }
        for(int i=0;i<10;i++){
            while(numsY[i]>0&&numsX[i]>0){
                numsY[i]--;
                numsX[i]--;
                list.add(i);
                
            }
        }
        Collections.sort(list,Collections.reverseOrder());
        if(list.isEmpty())return "-1";
        else if(list.get(0)==0)return "0";
        else{
            for(int i=0;i<list.size();i++){
                answer.append(list.get(i));    
            }
            return answer.toString();
        }
    }
}
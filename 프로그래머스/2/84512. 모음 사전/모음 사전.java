import java.util.*;
class Solution {
    HashMap<String, Integer> hm = new HashMap<>();
    char[] alphas = {'A','E','I','O','U'};
    int[] save = new int[5];
    int idx = 0;
    public int solution(String word) {
        
        permutation(0);
        System.out.println(hm.get(word));
        return hm.get(word);
        
    }
    public void permutation(int depth){
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<depth;i++){
            sb.append(alphas[save[i]]);
        }
        if(sb!=null)hm.put(sb.toString(),idx++);
        if(depth==5){
            return;
        }
        for(int i=0;i<5;i++){
            save[depth]=i;
            permutation(depth+1);
        }
    }
}
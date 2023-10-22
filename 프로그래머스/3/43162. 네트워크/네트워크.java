import java.util.*;
class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        // DFS로 각 지점별로 끝까지 연결된 부분을 탐색한다.
        // 탐색하면서 방문 여부를 체크하고, 방문하지 않은 곳을 들어갈 때 마다 +1
        boolean [] check = new boolean[n];
        for(int i=0;i<n;i++){
            check[i]=false;
        }
        for(int i=0;i<n;i++){
            if(!check[i]){
                answer++;
                dfs(i,computers,check);
            }
        }
        return answer;
    }
    public void dfs(int depth,int [][]computers, boolean []check){
        check[depth]=true;
        for(int i=0;i<computers.length;i++){
            if(!check[i]&&computers[depth][i]==1){
                dfs(i,computers,check);
            }
        }
    }
}
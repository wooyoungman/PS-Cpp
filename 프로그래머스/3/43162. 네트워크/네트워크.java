import java.util.*;
class Solution {
    ArrayList<Integer>[] graph;
    boolean[] visited;
    public int solution(int n, int[][] computers) {
        int answer = 0;
        graph = new ArrayList[n+1];
        visited = new boolean[n+1];
        for(int i=0;i<n;i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int i=0;i<computers.length;i++){
            for(int j=0;j<computers.length;j++){
                if(computers[i][j]==1){
                    graph[i].add(j);
                    graph[j].add(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i);
                answer++;
            }
        }
        
        return answer;
    }
    
    public void dfs(int v){
        visited[v]=true;
        for(int next : graph[v]){
            if(!visited[next])dfs(next);
        }
    }
    
}
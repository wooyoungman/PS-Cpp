import java.util.*;
class Solution {
    static ArrayList<Integer>[] graph;
    static int min;
    public int solution(int n, int[][] wires) {
        graph = new ArrayList[n+1];
        min = Integer.MAX_VALUE;
        for(int i=1;i<=n;i++){
            graph[i] = new ArrayList<>();
        }
        
        for(int i=0;i<wires.length;i++){
            int s = wires[i][0];
            int e = wires[i][1];
            graph[s].add(e);
            graph[e].add(s);
        }
        
        
        for(int i=0;i<wires.length;i++){
            int s=wires[i][0];
            int e=wires[i][1];
            boolean[] visited = new boolean[n+1];    
            graph[s].remove(Integer.valueOf(e));
            graph[e].remove(Integer.valueOf(s));
            
            int cnt = dfs(1,visited);
            
            int diff = Math.abs(cnt-(n-cnt));
            
            min = Math.min(min,diff);
            
            graph[s].add(e);
            graph[e].add(s);
        }
        return min;
    }
    static int dfs(int s,boolean[] visited){
        visited[s]=true;
        int cnt=1;
        for(int next:graph[s]){
            if(!visited[next]){
                cnt+=dfs(next,visited);
            }
        }
        return cnt;
    }
}
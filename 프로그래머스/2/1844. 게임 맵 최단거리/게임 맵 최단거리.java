import java.util.*;
class Solution {
    
    int dy[]={1,-1,0,0};
    int dx[]={0,0,1,-1};
    int rLen;
    int cLen;
    boolean[][] visited;
    
    public int solution(int[][] maps) {
        
        int answer = Integer.MAX_VALUE;
        rLen=maps.length;
        cLen=maps[0].length;
        visited = new boolean[rLen][cLen];
        
        Queue<Node>q = new LinkedList<>();
        q.add(new Node(0,0,1));
        
        visited[0][0]=true;
        while(!q.isEmpty()){
            Node cur=q.poll();
            //System.out.println(cur.y + " " + cur.x);
            if(cur.y==rLen-1&&cur.x==cLen-1){
                answer=Math.min(answer,cur.move);
                return answer;
            }
            
            for(int i=0;i<4;i++){
                Node next = new Node(cur.y+dy[i],cur.x+dx[i],cur.move+1);
                if(next.move>answer)continue;
                if(isValid(next.y,next.x)&&maps[next.y][next.x]==1){
                    q.add(next);
                    visited[next.y][next.x]=true;
                }
            }
        }
        return -1;
    }
    
    public boolean isValid(int y,int x){
        return y>=0&&x>=0&&y<rLen&&x<cLen&&!visited[y][x];
    }
    
    class Node{
        int y;
        int x;
        int move;
        
        public Node(int y,int x,int move){
            this.y=y;
            this.x=x;
            this.move=move;
        }
    }
}
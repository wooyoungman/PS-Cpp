import java.util.*;
// 현재 문자열에서 1글자 차이인가? -> 재귀
// 현재 depth가 이미 정답보다 높은가? -> 가지치기
// 방문 처리 후 재귀 탈출 후 방문 미처리
class Solution {
    
    boolean visited[];
    int answer=Integer.MAX_VALUE;
    int wSize;
    public int solution(String begin, String target, String[] words) {
        visited=new boolean[words.length];
        System.out.println(visited[0]);
        wSize=words.length;
        for(int i=0;i<wSize;i++){
            if(checkDiffOne(begin,words[i])&&!visited[i]){
                visited[i]=true;
                System.out.println(words[i]);
                recur(words[i],target,words,1);
                visited[i]=false;
            }
        }
        if(answer==Integer.MAX_VALUE)return 0;
        return answer;
    }
    public boolean checkDiffOne(String a, String b){
        int cnt=0;
        for(int i=0;i<a.length();i++){
            if(a.charAt(i)!=b.charAt(i))cnt++;
            //System.out.println(a.charAt(i)+" "+b.charAt(i));
        }
        if(cnt==1)return true;
        //System.out.println(a+" "+b);
        
        return false;
    }
    public void recur(String a, String b, String[] words,int depth){
        //System.out.println(a + " " + b);
        if(a.equals(b)){
            answer=Math.min(answer,depth);
            return;
        }
        if(depth>=answer)return;
        for(int i=0;i<wSize;i++){
            if(checkDiffOne(a,words[i])&&!visited[i]){
                visited[i]=true;
                recur(words[i],b,words,depth+1);
                visited[i]=false;
            }
        }
    }
}
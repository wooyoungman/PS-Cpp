class Solution {
    int tar = 0;
    int answer = 0;
    public int solution(int[] numbers, int target) {
        tar = target;
        dfs(1,numbers[0],numbers);
        dfs(1,numbers[0]*(-1),numbers);
        return answer;
    }

    public void dfs(int depth,int sum,int [] numbers){
        if(depth==numbers.length){
            //System.out.println(sum);
            if(sum==tar)answer++;
            return;
        }
        dfs(depth+1,sum+numbers[depth],numbers);
        dfs(depth+1,sum+numbers[depth]*(-1),numbers);
    }
}
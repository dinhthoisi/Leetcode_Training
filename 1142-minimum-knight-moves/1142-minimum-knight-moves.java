class Solution {
    private Map<String, Integer> memo = new HashMap<>();

    private int dfs(int x, int y){
        String key = x + "," + y;
        if(memo.containsKey(key))
            return memo.get(key);
        if(x + y == 0)
            return 0;
        else if(x + y ==  2)
            return 2;
        else{
            Integer ret = Math.min(dfs(Math.abs(x-1), Math.abs(y-2)), dfs(Math.abs(x-2), Math.abs(y-1))) + 1;
            memo.put(key,ret);
            return ret;
        }
    }
    
    public int minKnightMoves(int x, int y) {
        return dfs(Math.abs(x), Math.abs(y));
    }
}
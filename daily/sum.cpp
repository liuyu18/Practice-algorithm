class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        // 先排序
        sort(num.begin(),num.end());
        vector<int> stack,res;
        int sum = 0,cur = 0;
        vector<vector<int>> ans;
        while(cur < num.size() && num[cur] + sum <= target){
            stack.push_back(num[cur]);
            res.push_back(cur);
            sum+=num[cur++];
        }
        if (sum == target) ans.push_back(stack);
        while(res.size() != 0){
            cur=res.back();
            int x = num[cur];
            sum-=x;
            stack.pop_back();
            res.pop_back();
            for(++cur;cur<num.size();++cur)
                if(num[cur]!=x||sum+num[cur]>target) break;
            if(cur < num.size() && num[cur] != x)
                while(cur<num.size() && num[cur]+sum<=target){
                    stack.push_back(num[cur]);
                    res.push_back(cur);
                    sum+=num[cur++];
                }
            if(sum==target)ans.push_back(stack);
        }
        return ans;
    }
};

class Solution {
public:
    /*
     * @param s: A string
     * @return: A list of lists of string
     * 给定一个字符串s，将s分割成一些子串，使每个子串都是回文串。
     *返回s所有可能的回文串分割方案。
     */
     //回文子串 可能是单独的字符 也可能又是vector
    vector<vector<string>>v;
    vector<string>v1;
     
    vector<vector<string>> partition(string &s) {
        // write your code here
        v.clear();
        if(s.size() == 0) return v;
        v1.clear();
        dfs(0,s);
        return v;         
    }
    bool ishui(string s) {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;j--;
            }
            else return false;
        }
        return true;
    }   
    void dfs(int depth,string s) {
        if(depth==s.size())
        {
            v.push_back(v1);
        }
        if(depth<s.size())
        {
            for(int i=depth;i<s.size();i++)
            {
                if(ishui(s.substr(depth,i-depth+1)))
                {
                    v1.push_back(s.substr(depth,i-depth+1));
                    dfs(i+1,s);
                    v1.pop_back();                   
                }
            }
        }
    }
};

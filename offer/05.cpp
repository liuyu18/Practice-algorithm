class Solution
{
private:
    /* data */
    stack<int> stack1;
    stack<int> stack2;
public:
    Solution(/* args */);
    ~Solution();
    void push(int node);
    int pop();
};


void Solution::push(){
    this.stack1.push(node);
}
int Solution::pop(){
    if (this.stack2.empty()) {
        while(!this.stack1.empty()){
            int val = this.stack1.pop();
            this.stack1.pop();
            this.stack2.push(val);
        }

    }
    int val = this.stack2.top();
    this.stack2.pop();
    return val;
}

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

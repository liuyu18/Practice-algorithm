class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    bool Find(int target,vector<vector<int>> array);

};

bool Solution::Find(int target,vector<vector<int>> array){
    bool found = false;
    if(array.empty())
        return found;

    int rows,row,columns,column;
    rows = array.size();
    columns= array[0].size();
    row = 0;
    column = columns - 1;
    while(row < rows && column >= 0){
        if(array[row][column] == target){
            found = true;
            break;
        }else if(array[row][column] > target){
            --column;
        }else{
            ++row;
        }
    }
    return found;

}

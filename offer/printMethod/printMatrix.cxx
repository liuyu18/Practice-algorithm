
#include <vector>
using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    vector<int> printMethod(vector<vector<int> > matrix);
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

vector<int> Solution::printMethod(vector<vector<int> > matrix){
   int rows, columns;
        if(matrix.size()>0)
        {
            rows = matrix.size();
            columns = matrix[0].size();
        }

        vector<int> result;

        int startX = 0, endX = columns-1;
        int startY = 0, endY = rows-1;
        while(startX <= endX && startY<=endY)
        {
            if(startX<=endX && startY<=endY)
            {
                for(int i=startX; i<=endX; i++){
                    result.push_back(matrix[startY][i]);
                }
                ++ startY;
            }

            if(startY<=endY && startX<=endX)
            {
                for(int i=startY; i<=endY; i++){
                    result.push_back(matrix[i][endX]);
                }
                -- endX;
            }
            if(startX<=endX && startY<=endY)
            {
                for(int i=endX; i>=startX; i--){
                    result.push_back(matrix[endY][i]);
                }
                -- endY;
            }
            if(startY<=endY && startX<=endX)
            {
                for(int i=endY; i>=startY; i--){
                    result.push_back(matrix[i][startX]);
                }
                ++ startX;
            }
        }
        return result;
    }


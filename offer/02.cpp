class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    ~Solution();
    void replaceSpace(char *str,int length);
};

void Solution::replaceSpace(char *str,int length){
    if(str == nullptr || length <=0)
        return;

    int original_length = 0;
    int number_of_space = 0;
    int i = 0;
    while(str[i] != '\0'){
        ++ original_length;
        if(str[i] == ' ')
            ++number_of_space;
        ++i;
    }
    if(number_of_space <= 0){
        return;
    }

    int new_length = original_length + 2 * number_of_space;
//原来的字符串长度 之后测试之后的字符串长度
    int index_of_original = original_length;
    int index_of_new = new_length;

    while(index_of_original >= 0 && index_of_new >= index_of_original){
        if(str[index_of_original] == ' '){
            str[index_of_new--] = '0';
            str[index_of_new--] = '2';
            str[index_of_new--] = '%';
        }else{
            str[index_of_new--] = str[index_of_original];
        }
        --index_of_original;
    }



}

Solution::Solution(/* args */)
{

}


Solution::~Solution()
{

}


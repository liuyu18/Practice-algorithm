#include "moreThanHalf.h"



moreThanHalf::moreThanHalf(/* args */)
{
}

moreThanHalf::~moreThanHalf()
{
}

int moreThanHalf::MoreThanHalfNum_Solution(vector<int> numbers){
    if (numbers.szie() <= 0) {
        return 0;
    }

    int result = numbers[0];
    int times = 1;

    for(int i = 0; i < numbers.size(); i++)
    {
        if(times == 0){
            result = numbers[i];
            times = 1;
        }else if (times > 0 && result == numbers[i]) {
            ++times;
        }else{
            --times;
        }
    }
    if(!isMoreThanHalf(numbers,result)){
        return 0;
    }
    return result;


}


bool moreThanHalf::isMoreThanHalf(vector<int> numbers, int result){
    int times = 0;
    for(int i = 0; i < numbers.szie(); i++){
        if (numbers[i] == result) {
            ++ times;
        }
    }
    if(2 * times <= numbers.size()){
        return false;
    }
    return true;
}
//旋转数组

class getMin{
    int minNumberInRotateArray(vector<int> rotateArray);
}
int getMin::minNumberInRotateArray(vector<int> rotateArray){
    int length = rotateArray.size();
    if(length == 0){
        return 0;
    }
    int left = 0,right = length - 1;
    int mid;
    while(rotateArray[left] >= rotateArray[right]){
        if(left == right - 1){
            return rotateArray[right];
        }
        mid = (left + right)/2;
        if(rotateArray[left] == rotateArray[mid] && rotateArray[mid] == rotateArray[right]){
            int min_num = rotateArray[left];
            for(int i = left;i<right;i++){
                min_num = rotateArray[i]<min_num? rotateArray[i]:min_num;
            }
            return min_num;
        }
        if(rotateArray[left] <= rotateArray[mid]){
            left = mid;
        }else{
            right = mid;
        }
    }
    return rotateArray[left];
}
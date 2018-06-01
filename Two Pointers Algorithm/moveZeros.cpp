    vector<int> moveZeros(vector<int>& nums){
        int left = 0,right = 0;
        cout<<"left : "<<left<<endl;
        cout<<"right : "<<right<<endl;
        while (right < nums.size()) {
            if (nums[right]) {
                swap(nums[left++], nums[right]);
            }
            right++;
        }
        return nums;
    }
    
    unordered_multiset<int> nums;
    std::unordered_set<int>::iterator it;
    // Add the number to an internal data structure.
    void add(int number) {
        // Write your code here
        nums.insert(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        // Write your code here

        for (it = nums.begin(); it != nums.end(); it++) {
            cout << *it << endl;
        }

        for (int i : nums) {
            int count = i == value - i ? 2 : 1;
//             cout<<"value : "<<value<<endl;
//            cout<<"value : "<<value<<endl;
//            cout<<"count : "<<count<<endl;
//            cout<<"nums.count(value - i) : "<<nums.count(value - i)<<endl;
            if (nums.count(value - i) >= count) {
//                cout<<"返回true"<<endl;
                return true;
            }
        }
//        cout<<"返回true"<<endl;
        return false;
    }
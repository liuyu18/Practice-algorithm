#include<iostream>
#include<vector>

using namespace std;

vector<int> kClosestNumbers(vector<int>& A, int target, int k);
int main(){
    int iarray[]={1, 4, 6, 8};

    size_t count=sizeof(iarray)/sizeof(int);
    //int数组初始化 ivec3
    vector<int> ivec(iarray,iarray+count);
//    mountainSequence(ivec);
//    cout<<"结果 : "<<mountainSequence(ivec)<<endl;
    vector<int> result = kClosestNumbers(ivec, 3, 3);
    vector<int>::iterator iter;
    for (iter = result.begin() ; iter != result.end(); iter++) {
        cout<<*iter<<endl;
    }
}
 int closestNumber(vector<int>& A, int target) {
        int start = 0;
        int end = A.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] >= target) end = mid;
            else start = mid;
        }
        if (abs(A[start] - target) < abs(A[end] - target)) return start;
        else if (abs(A[start] - target) > abs(A[end] - target)) return end;
        else {
            return A[start] < A[target] ? start : target;
        }
    }

    vector<int> kClosestNumbers(vector<int>& A, int target, int k) {
        vector<int> result;
        if (k == 0 || &A == NULL || A.size() == 0) return result;
        int index = closestNumber(A, target);
        int count = 0;
        result.push_back(A[index]);
        ++count;
        int left = index - 1;
        int right = index + 1;
        while (count++ < k) {
            if (left >= 0 && right < A.size()) {
                if (abs(A[left] - target) < abs(A[right] - target)) {
                    result.push_back(A[left--]);
                } else if (abs(A[left] - target) > abs(A[right] - target)){
                    result.push_back(A[right++]);
                } else {
                    if (A[left] < A[right]) {
                        result.push_back(A[left--]);
                    } else {
                        result.push_back(A[right++]);
                    }
                }
            } else if (right == A.size()) {
                result.push_back(A[left--]);
            } else {
                result.push_back(A[right++]);
            }
        }
        return result;
    }
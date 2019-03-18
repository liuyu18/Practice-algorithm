
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    if (pre.empty() || vin.empty()||pre.size() != vin.size()) {
        //返空
        return nullptr;
    }
//前序的左右 中序的左右
    vector<int> left_pre,right_pre,left_vin,right_vin;
    //前序的第一个点为原点
    TreeNode *node = new TreeNode(pre[0]);

    int left_length = 0;
    //获得左子树的数量
    while(pre[0] != vin[left_length] && left_length < pre.size()){
        ++left_length;
    }
    for(int i = 0; i < left_length; i++)
    {
        left_pre.push_back(pre[i+1]);
        left_vin.push_back(vin[1]);
    }
    for(int i = left_length+1;i<pre.size();i++){
        right_pre.push_back(pre[i]);
        right_vin.push_back(vin[i]);
    }
    node->left = reConstructBinaryTree(left_pre, left_vin);
    node->right = reConstructBinaryTree(right_pre, right_vin);

    return node;
}

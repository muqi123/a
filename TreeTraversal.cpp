/*Binary Tree Preorder Traversal*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        
        while( cur || !stk.empty()){
            if( cur ){
                res.push_back( cur->val );
                if( cur->right)
                    stk.push( cur->right );
                cur = cur->left;
            }
            else
            {
                cur = stk.top();
                stk.pop();
            }
        }
        return res;
    }
    
};

/*Binary Tree Inorder Traversal*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while( cur || !stk.empty() ){
            if( cur )
            {
                stk.push( cur);
                cur = cur->left ? cur->left : nullptr;
            }
            else
            {
                TreeNode* tmp = stk.top();
                stk.pop();
                res.push_back( tmp->val);
                cur = tmp->right;
            }
        }
        return res;
    }
};

/* PostOrderTraversal */
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        while( cur || !stk.empty() )
        {
            if( cur )
            {
                stk.push( cur );
                cur = cur->left;
            }
            else{
                TreeNode* tmp = stk.top();
                if( !tmp->right || pre == tmp->right )
                {
                    res.push_back( tmp->val);
                    stk.pop();
                    pre = tmp;
                }
                else
                    cur = tmp->right;
            }
        }
        return res;

    }
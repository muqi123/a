/**********
https://www.youtube.com/watch?v=53aOi0Drp9I
***********/
//Construct Binary Tree from Preorder and Postorder Traversal
/*V1*/

class Solution {
public:
    TreeNode* buildTree( int preB, int preE, int posB, int posE,  vector<int>& pre, vector<int>& post )
    {
        if( preB > preE )
            return nullptr;
        TreeNode* node = new TreeNode( pre[preB] );
        if( preB == preE )
            return node;
        int leftRoot = pre[preB + 1];
        int i = 0;
        while( post[i + posB] != leftRoot ) ++i;
        node->left = buildTree( preB + 1, preB + 1 + i, posB, posB + i, pre, post );
        node->right = buildTree( preB + 2 + i, preE, posB + i + 1, posE - 1, pre, post );
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int length = pre.size() - 1;
        return buildTree( 0, length, 0, length, pre, post );
    }
};

/*V2*/
class Solution2 {
public:
    TreeNode* buildTree( vector<int>& pre, vector<int>& post, int preS, int postS, int n )
    {
        if( n <= 0 )
            return nullptr;
        TreeNode* node = new TreeNode( pre[preS] );
        if( n == 1 )
            return node;
        int leftRootValue = pre[preS + 1];
        int i = 0;
        while( post[i+postS] != leftRootValue ) i++;
        node->left = buildTree( pre, post, preS + 1, postS, i + 1 );
        node->right = buildTree( pre, post, preS + 2 + i, postS + 1 + i, n - 2 - i);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return buildTree( pre, post, 0, 0,  pre.size() );
    }
};

/*105. Construct Binary Tree from Preorder and Inorder Traversal*/

class Solution {
public:
    TreeNode* buildTree( vector<int>& preorder, vector<int>& inorder, int preS, int inS, int n )
    {
        if( n <= 0 )
            return nullptr;
        TreeNode* node = new TreeNode( preorder[preS] );
        if( n == 0 )
            return node;
        int middle = 0;
        while( inorder[inS+middle] != preorder[preS] ) middle++;
        node->left = buildTree( preorder, inorder, preS + 1, inS, middle );
        node->right = buildTree(preorder, inorder, preS + 1 + middle, inS + middle + 1, n - middle - 1 );
        return node;
    }
    TreeNode* buildTree(vector<int> preorder, vector<int> inorder) {
        return buildTree( preorder, inorder, 0, 0, preorder.size() );
    }
};
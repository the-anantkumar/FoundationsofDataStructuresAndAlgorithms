#include <iostream>
#include <vector>

using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};


void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

vector<TreeNode*> generateTreesHelper(vector<int>& inorder, int start, int end) {
    vector<TreeNode*> trees;

    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++) {
        
        vector<TreeNode*> leftSubtrees = generateTreesHelper(inorder, start, i - 1);
        vector<TreeNode*> rightSubtrees = generateTreesHelper(inorder, i + 1, end);

       
        for (int j = 0; j < leftSubtrees.size(); j++) {
            for (int k = 0; k < rightSubtrees.size(); k++) {
                TreeNode* root = new TreeNode(inorder[i]);
                root->left = leftSubtrees[j];
                root->right = rightSubtrees[k];
                trees.push_back(root);
            }
        }
    }
    return trees;
}






vector<TreeNode*> generateTrees(vector<int>& inorder) {
    if (inorder.empty()) {
        return vector<TreeNode*>();
    }
    return generateTreesHelper(inorder, 0, inorder.size() - 1);
}

int main() {
   int t;
   cin>>t;
   while(t--)
   {
    vector<int>inorder;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin>>x;

        inorder.push_back(x);

    
    }
    vector<TreeNode*> trees = generateTrees(inorder);
    cout<<"Total binary trees are "<<trees.size()<<endl;
    for (int i = 0; i < trees.size(); i++) {
        printTree(trees[i]);
        cout << endl;
    }
   }

    return 0;
}
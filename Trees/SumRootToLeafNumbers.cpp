// Definition for a binary tree node.
struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
  int sumNumbers(TreeNode* root) 
  {
    if (root == 0)
    {
      return 0;
    }
    
    int totalSum = 0;
    int currentNumber = 0;
    sumNumber(root, currentNumber, totalSum);
    return totalSum;
  }

  void sumNumbers(TreeNode* node, int &currentNumber, int &totalSum)
  {
    currentNumber *= 10;
    currentNumber += node->val;

    if (!(node->left) && !(node->right))
    {
      totalSum += currentNumber;
    }

    if (node->left)
    {
      sumNumbers(node->left, currentNumber, totalSum);
    }

    if (node->right)
    {
      sumNumbers(node->right, currentNumber, totalSum);
    }

    currentNumber /= 10;
  }
};

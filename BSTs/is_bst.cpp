#include <iostream>
#include <vector>
using namespace std;

/* 
given a binary tree, check if it's a BST
*/
class BinaryTree {
public:
  int data;
  BinaryTree *parent, *left, *right;
  BinaryTree(): data(0), parent(NULL), left(NULL), right(NULL) {}
  BinaryTree(int k): data(k), parent(NULL), left(NULL), right(NULL) {}
};

BinaryTree *successor(BinaryTree *node) {
  if (node->right != NULL) {
    /* A right subtree exists -> successor has to be inside */
    BinaryTree *par_node = node->right;
    BinaryTree *cur_node = par_node->left;
    while (cur_node != NULL) {  
      par_node = par_node->left;  
      cur_node = cur_node->left;
    }
    return par_node;
  } else {
    /* successor, if exists, is the first ancestor to the right */
    BinaryTree *par_node = node->parent;
    BinaryTree *cur_node = node;
    while (par_node != NULL) {
      if (cur_node == par_node->left) {
        return par_node;
      }
      par_node = par_node->parent;
      cur_node = cur_node->parent;
    }
    return par_node;
  }
}

BinaryTree *min(BinaryTree *node) {
   if (node == NULL) return NULL;
   while (node->left != NULL) node = node->left;
   return node;
}

bool is_bst(BinaryTree *tree) {
  if (tree == NULL) return true;
  BinaryTree *cur_node = min(tree);
  BinaryTree *suc_node = successor(tree);

  while (suc_node != NULL) {
    if (cur_node->data > suc_node->data) {
      return false;
    }
    cur_node = suc_node;
    suc_node = successor(suc_node);
  }
  return true;
}

BinaryTree *create_tree(vector<int> &v) {
  if (v.size()==0) return NULL;
  vector<BinaryTree*> p(v.size());
  for (int i=0; i<v.size(); i++) {
    p[i] = new BinaryTree(v[i]);
  }  
  for (int i=0, j=1; j<p.size(); j++) {
    if (j%2 != 0) {
      /* insert p[j] as left child of p[i] */
      p[i]->left = p[j];
      p[j]->parent = p[i];
    } else {
      /* insert p[j] as right child of p[i] and increment i */
      p[i]->right = p[j];
      p[j]->parent = p[i++];
    }
  }
  return p[0];
}

int main() {
  vector<int> v;
  BinaryTree *tree;

  v = {1,2,3,4,5,6,7};
  tree = create_tree(v);
  cout << is_bst(tree) << endl;

  v = {4,2,6,1,3,5,7};
  tree = create_tree(v);
  cout << is_bst(tree) << endl;

  return 0;
}

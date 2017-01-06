#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;

/* 
Insert and delete in a binary search tree
*/

class bst {
private:
  class bst_node {
  public:
    int data;
    bst_node *parent, *left, *right;
    bst_node(): data(0), parent(NULL), left(NULL), right(NULL) {}
    bst_node(int k): data(k), parent(NULL), left(NULL), right(NULL) {}

    void _insert_(bst_node *node) {
      if (node->data <= this->data) {
        if (this->left == NULL) {
          this->left = node;
          node->parent = this;
        } else {
          this->left->_insert_(node);
        }
      } else {
        if (this->right == NULL) {
          this->right = node;
          node->parent = this;
        } else {
          this->right->_insert_(node);
        }
      }
    }

    void _in_order_() {
      if (this->left != NULL) {
        this->left->_in_order_();
      }
      cout << this->data << "  ";
      if (this->right != NULL) {
        this->right->_in_order_();
      }
    }

    bst_node *_search_(int k) {
      if (this->data == k) {
        return this;
      }
      if (k < this->data ) {
        if (this->left != NULL) {
          return this->left->_search_(k);
        } else {
          return NULL;
        }
      } else {
        if (this->right != NULL) {
          this->right->_search_(k);
        } else {
          return NULL;
        }
      }
    }
    bst_node *_successor_() {
      if (this->right != NULL) {
        /* A right subtree exists -> successor has to be inside */
        bst_node *par_node = this->right;
        bst_node *cur_node = par_node->left;
        while (cur_node != NULL) {  
          par_node = par_node->left;  
          cur_node = cur_node->left;
        }
        return par_node;
      } else {
        /* successor, if exists, is the first ancestor to the right */
        bst_node *par_node = this->parent;
        bst_node *cur_node = this;
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


  };
public:
  bst(): root(NULL) {}
  bool search(int k);
  void insert(int k);
  void remove(int k);  
  void in_order();
private:
  bst_node *root;
};


void bst::insert(int k) {
  bst_node *node = new bst_node(k);
  if (this->root == NULL) {
    this->root = node;
  } else {
    this->root->_insert_(node);    
  }
}

void bst::in_order() {
  if (this->root == NULL) {
    return;
  } else {
    this->root->_in_order_();
  }
  cout << endl;
}

bool bst::search(int k) {
  if (this->root == NULL) {
    return false;
  } else {
    return (this->root->_search_(k) != NULL);
  }
}

void bst::remove(int k) {
  if (this->root == NULL) {
    return;
  } else {
    /* look for the node to remove */
    bst_node *node = this->root->_search_(k);
    bst_node *del;
    if (node == NULL) return;
    if (node->left == NULL || node->right == NULL) {
      del = node;
    } else {
      del = node->_successor_();
    }
      
    bst_node *son = (del->left == NULL)?del->right:del->left;
    if (son != NULL) son->parent = del->parent;
    if (del == del->parent->left) del->parent->left = son;
    else del->parent->right = son;

    if (del != node) {
      node->data = del->data;
    }
    delete del;    
  }
}

int main() {

  srand(unsigned(time(0)));
  vector<int> v = {0,1,2,3,4,5,6,7,8,9};
  random_shuffle(v.begin(),v.end());

  bst bintree = bst();
  for (auto k:v) {
    cout << k << endl;
    bintree.insert(k);
  }
  bintree.in_order();
  bintree.remove(1);
  bintree.remove(2);
  bintree.remove(0);
  bintree.in_order();
  return 0;
}


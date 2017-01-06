#include <iostream>
#include <list>
#include <stack>
#include <cstdlib>
using namespace std;


/*
Find the lowest common ancestor of two nodes of a binary tree,
identified by their keys, where the nodes do not have a parent pointer.
*/

struct node {
   int key;
   node *left;
   node *right;
   node(int key): key(key), left(NULL), right(NULL) {}
};


/*
recursive dfs with path tracing
*/
bool dfs_rec(node *root, int key, list<node*> &path) {

   /* base cases: root is NULL of root's key is searched key  */
   if (root == NULL) return false;
   if (root->key == key) {
      path.push_front(root);
      return true;
   }

   /* otherwise, recurse */
   if ( dfs_rec(root->left, key, path) || dfs_rec(root->right, key, path) ) {
      path.push_front(root);
      return true;
   }
   return false;
}

/*
iterative dfs with path tracing
*/
bool dfs_it(node *root, int key, list<node*> &path) {

   typedef enum {
     MET,
     LEFT,
     RIGHT
   } status;
   
   if (root == NULL) return false;
   list<status> s;
   path.push_back(root);
   s.push_back(MET);

   while(!path.empty()) {
      status cur_status = s.back();
      node *left, *right;
      switch(cur_status) {
      case(MET):
         if (path.back()->key == key) {
            return true;
         }
         s.pop_back();
         s.push_back(LEFT);
         left = path.back()->left;
         if (left != NULL) {
            path.push_back(left);
            s.push_back(MET);
         }
         break;
      case(LEFT):
         s.pop_back();
         s.push_back(RIGHT);
         right = path.back()->right;
         if (right != NULL) {
            path.push_back(right);
            s.push_back(MET);
         }
         break;
      case(RIGHT):
         s.pop_back();
         path.pop_back();
         break;
      }         
   }
   return false;
}

/*
find the lowest common ancestor of two keys
*/
node *lca(node *tree, int k1, int k2) {
   list<node*> p1,p2;
   dfs_it(tree,k1,p1);
   dfs_it(tree,k2,p2);

   node *lca = NULL;
   while(!p1.empty() && !p2.empty() && p1.front() == p2.front()) {
      lca = p1.front();
      p1.pop_front();
      p2.pop_front();
   }
   
   return lca;
      
}

/*
function to print the content of a path list
*/
void print_list(list<node*> &l) {
   for (auto n:l) {
      cout << n->key << "  ";
   }
   cout << endl;
}


/*
unit-test function for building a test tree
*/
node *build_test_tree() {
   node *n1 = new node(1);
   node *n2 = new node(2);
   node *n3 = new node(3);
   node *n4 = new node(4);
   node *n5 = new node(5);
   node *n6 = new node(6);

   n1->left = n2;
   n1->right = n3;
   n2->left = n4;
   n2->right = n5;
   n3->left = n6;

   return n1;
}


int main(int argc, char *argv[]) {

   if (argc != 3) {
      cout << "Number of arguments must be 2" << endl;
      return 0;
   }
   
   int k1 = atoi(argv[1]);
   int k2 = atoi(argv[2]);
   node *tree = build_test_tree();
   node *a = lca(tree,k1,k2);
   
   if (a!=NULL) {
     cout << "LCA: " << a->key << endl;
   } else {
     cout << "LCA: NULL" << endl;      
   }
   
   return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Tree
{
public:

    Tree(vector<pair<int, int>>& edges)
    {
        // Construct the tree from the edges
        for (auto it = edges.begin(); it != edges.end(); ++it)
        {
            _tree[it->first].insert(it->second);
            _tree[it->second].insert(it->first);
        }

        // Compute the leaves
        for (auto it = _tree.begin(); it != _tree.end(); ++it)
        {
            if (isLeaf(it->first))
            {
                _leaves.insert(it->first);
            }            
        }
    }
    
    
    void removeLeaf(int i)
    {
        if (_leaves.find(i) == _leaves.end() || _tree[i].size() != 1)
        {
            return;
        }

        int adjNode = *(_tree[i].begin());
        _tree[adjNode].erase(i);
        _tree.erase(i);
        _leaves.erase(i);
        if (_tree[adjNode].size() == 1)
        {
            _leaves.insert(adjNode);
        }
        
    }

    bool isLeaf(int i)
    {
        if (_tree.find(i) != _tree.end() && _tree[i].size() == 1)
        {
            return true;
        }
        return false;
    }

    set<int> getLeaves()
    {
        return _leaves;
    }

    int getSize()
    {
        return _tree.size();
    }

private:
    map<int, set<int>> _tree;
    set<int> _leaves;
};

class Solution 
{
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) 
    {
       Tree aTree(edges);
       while(aTree.getSize() > 2)
       {
           set<int> aLeaves = aTree.getLeaves();
           for (auto it = aLeaves.begin(); it != aLeaves.end(); ++it)
           {
               aTree.removeLeaf(*it);
           }
       } 
       set<int> aLeaves = aTree.getLeaves();
       for (auto it = aLeaves.begin(); it != aLeaves.end(); ++it)
       {
           cout << *it << endl;
       }
    }    
};


int main()
{
    Solution aSolution;
    return 0;
}

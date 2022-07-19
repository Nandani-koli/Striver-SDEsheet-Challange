/*
You are given a reference/address of a node in a connected undirected graph containing N nodes and M edges.
You are supposed to return a clone of the given graph which is nothing but a deep copy. Each node in the
graph contains an integer “data” and an array/list of its neighbours.
*/

#include<iostream>
#include<vector>
using namespace std;

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};


void dfs(graphNode* node,graphNode* copy, vector<graphNode*> &vis)
{
    vis[copy->data] = copy;
    
    for(auto x : node->neighbours)
    {
        if(vis[x->data] == NULL)
        {
            graphNode* newnode = new graphNode(x->data);
            copy->neighbours.push_back(newnode);
            dfs(x,newnode,vis);
        }
        else{
             copy->neighbours.push_back(vis[x->data]);
        }
    }
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
    if(node == NULL) return NULL;
    
    vector<graphNode*> vis(1e5,NULL);
    graphNode * copy = new graphNode(node->data);
    
    dfs(node,copy,vis);
    
    return copy;
}

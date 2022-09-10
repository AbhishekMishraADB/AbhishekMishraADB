//
//  ClosestNodeToAPathInTree(Hard).cpp
//  LCNew
//
//  Created by Abhishek Mishra on 06/09/22.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

void bfs(vector<vector<int>>& adjacency, int start , vector<int>& parent)
{
    queue<int> q;
    
    q.push(start);
    vector<bool> visited(adjacency.size(), 0);
    visited[start] = true;
    
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        
        for(auto i: adjacency[node])
        {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = node;
            }
            
        }
    }
}

int findclosestbfs(vector<vector<int>>& adjacency, int start, set<int>& nodesInpath)
{
    queue<int> q;
    
    q.push(start);
    vector<bool> visited(adjacency.size(), 0);
    
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        
        for(auto i: adjacency[node])
        {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                if(nodesInpath.find(i) != nodesInpath.end())
                    return i;
            }
        }
    }
    return -1;
}

void findClosest(vector<vector<int>>& edges, int n, vector<vector<int>>& query)
{
    vector<vector<int>> adj(n, vector<int>());
    vector<int> parent(7,-1);
    for(int i = 0; i<edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }


    bfs(adj,0, parent);

    int querysize = (int)query.size();
    int index = 0;
    while(querysize--)
    {
        set<int> nodesinpath;

        auto query1 = query[index];
        int st = query1[0];
        int end = query1[1];
        int fromnode = query1[2];
        nodesinpath.insert(st);
        nodesinpath.insert(end);
        while(parent[st] != -1)
        {
            nodesinpath.insert(parent[st]);
            st = parent[st];
        }

        while(parent[end] != -1)
        {
            nodesinpath.insert(parent[end]);
            end = parent[end];
        }
        index++;
       auto ret = findclosestbfs(adj, fromnode, nodesinpath);
        std::cout << ret << std::endl;
    }
}

//int main()
//{
//    vector<vector<int>> edges = {{0,1}, {0, 2}, {0,3}, {1,4}, {2,5}, {2,6}};
//    int nodes = 7;
//    vector<vector<int>> queries{{5,3,4}, {5,3,6}};
//
//    findClosest(edges, nodes, queries);
//    return 0;
//}

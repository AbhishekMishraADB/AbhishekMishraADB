//
//  AllLongestIncreasingPaths2D.cpp
//  LCNew
//
//  Created by Abhishek Mishra on 10/09/22.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
#define mx 10000009;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,-1,1};

int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp)
{
    int count = 1;
    for(int i = 0; i < 4;i++)
    {
        int newcellX = grid[x][y] + dr[i];
        int newcellY = grid[x][y] + dc[i];
        if(newcellX >=0 && newcellY >=0 && newcellX <grid.size() && newcellY < grid[0].size())
        {
            if(grid[newcellX][newcellY] > grid[x][y])
                count = (count +  dfs(grid, newcellX, newcellY, dp)) % mx;
        }
    }
    
    return count;
}

int findAllIncreasingDFS(vector<vector<int>>& grid)
{
    vector<vector<int>> dp;
    int total_count = 0;
    for(int i = 0;i < grid.size(); i++)
    {
        for (int j = 0; j< grid[0].size(); j++)
        {
            total_count = (total_count + dfs(grid, i, j, dp))% mx;
        }
    }
    
    return total_count;
}

int main(int argc, char** argv)
{
    vector<vector<int>> grid = {{1,1 }, {3,4}};
    return findAllIncreasingDFS(grid);
}
                         
                        




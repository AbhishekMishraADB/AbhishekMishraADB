//
//  BrickClimbingDP.cpp
//  LCNew
//
//  Created by Abhishek Mishra on 09/09/22.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;


bool solve(int index,vector<int>& heights, int bricksRemaining, int laddersRemaining, vector<vector<vector<int>>>& dp, int& furthestbuilding)
{
    if(dp[index][bricksRemaining][laddersRemaining] != -1)
        return -1;
    
    dp[index][bricksRemaining][laddersRemaining] = 1;
    
    
    if(index < (int)heights.size())
    {
        furthestbuilding = max(furthestbuilding, index);
        auto canjumpbricks = heights[index+1] - heights[index];
        if(canjumpbricks <= 0) {
            dp[index][bricksRemaining][laddersRemaining] = 1;
            solve(index+1, heights, bricksRemaining, laddersRemaining, dp, furthestbuilding);
            return true;
        }
        else{
            if(bricksRemaining >= (heights[index+1] - heights[index]))
                dp[index+1][bricksRemaining - canjumpbricks][laddersRemaining] = solve(index+1, heights, bricksRemaining - canjumpbricks, laddersRemaining, dp, furthestbuilding);
                
            if(laddersRemaining >=1)
                dp[index+1][bricksRemaining][laddersRemaining-1] = solve(index+1, heights, bricksRemaining, laddersRemaining-1, dp, furthestbuilding);
        }
    }
    
    return 1;
    
}

int init(vector<int>& buildings, int bricks, int ladders)
{
    vector<vector<vector<int>>> dp(buildings.size()+1, vector<vector<int>>(bricks+1, vector<int>(ladders+1, -1)));

    int furthestBuilding = -1;
    solve(0, buildings, bricks, ladders, dp, furthestBuilding);
    
    cout <<furthestBuilding<< endl;
    return furthestBuilding;
}

//int main()
//{
//    vector<int> buildings = {14,3,19,3};
//    
//    int bricks = 17;
//    int ladder = 0;
//    
//    int ret = init(buildings, bricks, ladder);
//
//}



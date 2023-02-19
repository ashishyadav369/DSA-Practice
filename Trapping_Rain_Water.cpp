#include <bits/stdc++.h>
using namespace std;

int main() {

    /*
        Input :  height = [0,1,0,2,1,0,1,3,2,1,2,1]
        Output : 6
        We are given height of pillars and we have to calculate the amount of water trapped between the pillars
    */

    // Input 

    int numOfPillar;
    cin >> numOfPillar;
    int heights[numOfPillar];
    for(int i = 0; i < numOfPillar; i++) {
        int pillarHeight;
        cin >> pillarHeight;
        heights[i] = pillarHeight;
    }
    int waterStored = 0;

    // Logic
    /*
        Water stored depends upon the height of the pillar as if water exceeds the height of pillar on either side the water will overflow
        so the water stored will depend on the height of the smaller pillar so to calclulate the amount of water stored we can calculate as 
        follows
            waterStored = min(leftMaxPillarHeight, rightMaxPillarHeight) - height[i]
        
        So one way of calculating is by everytime calculating the leftMaxPillarHeight and rightMaxPillarHeight and then calulate the water
        stored in between them
    */ 


    // Brute-Force approach T.C : O(n^2) S.C : O(1)

    for(int i = 0; i < numOfPillar; i++) {
        int leftMaxPillarHeight = heights[i];
        int rightMaxPillarHeight = heights[i];
        for(int j = i; j < numOfPillar; j++) {
            if(rightMaxPillarHeight < heights[j])
                rightMaxPillarHeight = heights[j];
        }

        for(int j = i; j >= 0; j--) {
            if(leftMaxPillarHeight < heights[j])
                leftMaxPillarHeight = heights[j];
        }

        waterStored += min(leftMaxPillarHeight, rightMaxPillarHeight) - heights[i];
    }

    /*
        We can optimize it by precalulating the leftMaxPillarHeight and RightMAxPillarHeight and then calculate the water stored
    */

    // Optimized Approach T.C : O(n) S.C : O(n)

    int leftMaxPillarsHeight[numOfPillar];
    int rightMaxPillarsHeight[numOfPillar];

    int leftMaxPillarHeight = heights[0];
    int rightMaxPillarHeight = heights[numOfPillar - 1];
    for(int i = 1; i < numOfPillar; i++) {
        leftMaxPillarsHeight[i - 1] = leftMaxPillarHeight;
        if(leftMaxPillarHeight < heights[i]) 
            leftMaxPillarHeight = heights[i];
    }

    for(int i = numOfPillar - 2; i >= 0; i--) {
        rightMaxPillarsHeight[i + 1] = rightMaxPillarHeight;
        if(rightMaxPillarHeight < heights[i])
            rightMaxPillarHeight = heights[i];
    }
    
    for(int i = 0; i < numOfPillar; i++) {
        waterStored += min(leftMaxPillarsHeight[i], rightMaxPillarsHeight[i]) - heights[i];
    }
    cout << waterStored;
}

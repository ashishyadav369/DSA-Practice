#include <bits/stdc++.h>
using namespace std;

int main() {

     /*
        Input : 
            8 => 4 2 9 1 8 5 6 3
        Output :
            9 9 9 8 8 6 6 3
        In this we have to print right maximum value of every element of the array
    */ 

    //    Input 
    int n;
    cin >> n;
    vector<int> v;
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        v.push_back(val);
    }

    // Logic

    /*  We can sovle this via bruteforce by calculating the maximum element every time as it is a bruteforce approact it will take
        T.C {Time Complexity} : O(n^2) so we have to further optimize it.
    */ 

    //   Brute Force Approach T.C : O(n^2) S.C : O(n)
    for(int i = 0; i < n; i++) {
        int max = v[i];
        for(int j = i; j < n; j++) {
            if(max < v[j]) {
                max = v[j];
            }
        }
        ans.push_back(max);
     } 

    /*  We can optimize it by taking in obesrvation that we dont have to re-calculate max every time we can store max and compare it
        also we should start form the right side of the array as we have to calculate right max because if we start from left side than
        we dont know the right max for that element and we have to traverse to find the max
     */

    // Optimized Approach T.C : O(n) S.C : O(n) 
    ans.push_back(v[n - 1]);
    int max = v[n - 2];
    for(int i = n - 2; i >= 0; i--) {
        if(max < v[i]) {
            max = v[i];
        }
        ans.push_back(max);
    }

// Output
    for(auto i : ans)
        cout << i << " ";
}

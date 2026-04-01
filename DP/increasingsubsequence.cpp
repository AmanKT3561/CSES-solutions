#include <bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    
    int LIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
      
        for(int i=1; i < n; i++) {
            
          
            if(nums[i] > temp.back()) 
                temp.push_back(nums[i]); 
                
            
            else {
               
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) -
                          temp.begin();
                          
              
                temp[ind] = nums[i];
            }    
            
        }
     
        return temp.size();
    }    
};
 
 
int main() {
    
    Solution sol;
    int n;
    cin>>n;
    vector<int> nums;
    for(int i = 0 ; i<n;i++){
        int x;cin>>x;
        nums.push_back(x);
    }
    int lengthOfLIS = sol.LIS(nums);
    
    cout << lengthOfLIS << endl;
    
    return 0;
}

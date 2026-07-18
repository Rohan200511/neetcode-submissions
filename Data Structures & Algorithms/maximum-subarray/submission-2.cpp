class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int currSum = 0;
        int maxSum = nums[0];

        for(int num : nums){
            
            if(currSum < 0) currSum = 0;
            
            currSum += num;
        
            maxSum = max(maxSum , currSum);
        }
        return maxSum;
    }
};

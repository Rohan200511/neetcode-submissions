class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;

        while(low <= high){
            int mid = low + ((high - low) / 2);

            int ele = matrix[mid/col][mid%col];

            if(target == ele) return true;
            else if(target < ele) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};

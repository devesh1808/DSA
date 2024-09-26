int func1(int low, int high, int n, int target, vector<int> &nums){
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
    int func2(int low, int high, int n, int target, vector<int> &nums){
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid]>target) high = mid-1;
            else low = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int firstOcc = func1(0, n-1, n, target, nums);
        int lastOcc = func2(0, n-1, n, target, nums);
        return {firstOcc, lastOcc};
        
    }
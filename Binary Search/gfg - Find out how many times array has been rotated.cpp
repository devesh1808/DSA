int findKRotation(vector<int> &nums) {
        // Code Here
        int n = nums.size();
        int low = 0, high = n-1, ansVal = INT_MAX, ansIndx = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[low]<=nums[mid]){
                if(nums[low]<ansVal){
                    ansVal = nums[low];
                    ansIndx = low;
                }
                low = mid+1;
            }
            else{
                if(nums[mid]<ansVal){
                    ansVal = nums[mid];
                    ansIndx = mid;
                }
                high = mid-1;
            }
        }
        return ansIndx;
    }
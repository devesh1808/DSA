int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[low]){    // means left part is sorted
                if(target>=nums[low] && target<=nums[mid]){  //checking if target lies in left part
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{    // means right part is sorted
                if(target>=nums[mid] && target<=nums[high]){  //checking if target lies in right part
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
}
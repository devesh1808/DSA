int findFloor(vector<long long> &v, long long n, long long x) {

        // Your code here
        long long low = 0, high = n-1;
        long long ans = -1;
        while(low<=high){
            long long mid = (low+high)/2;
            if(v[mid]==x) return mid;
            else if(v[mid]>x) high = mid-1;
            else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
    }
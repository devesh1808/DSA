class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int k = 0, cnt = 1, deptTime = dep[0];
        for(int i=1;i<n;i++){
            if(arr[i]>deptTime){
                k++;
                deptTime = dep[k];
            }
            else cnt++;
        }
        return cnt;
    }
};
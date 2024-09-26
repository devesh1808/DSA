int func1(int low, int high, int n, int x, int arr[]){
	    int ans = -1;
	    while(low<=high){
	        int mid = (low+high)/2;
	        if(arr[mid]==x){
	            ans = mid;
	            high = mid-1;
	        }
	        else if(arr[mid]>x) high = mid-1;
	        else low = mid+1;
	    }
	    return ans;
	}
	int func2(int low, int high, int n, int x, int arr[]){
	    int ans = -1;
	    while(low<=high){
	        int mid = (low+high)/2;
	        if(arr[mid]==x){
	            ans = mid;
	            low = mid+1;
	        }
	        else if(arr[mid]>x) high = mid-1;
	        else low = mid+1;
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int firstOcc = func1(0, n-1, n, x, arr);
	    int lastOcc = func2(0, n-1, n, x, arr);
	    return (firstOcc==-1 && lastOcc==-1) ? 0 : (lastOcc-firstOcc+1);
	}
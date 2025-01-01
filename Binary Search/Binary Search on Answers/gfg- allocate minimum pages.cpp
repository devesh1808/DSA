class Solution
{
public:
    // Function to find minimum number of pages.
    bool func(int arr[], int n, int k, int mid)
    {
        int students = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                students++;
                sum = arr[i];
            }
        }
        if (students > k)
            return false;
        else
            return true;
    }
    int findPages(int A[], int N, int M)
    {
        // code here
        if (M > N)
            return -1;
        int low = A[0], high = 0, ans = -1;
        for (int i = 0; i < N; i++)
        {
            low = max(low, A[i]);
            high += A[i];
        }
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (func(A, N, M, mid) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};
// Code 1 : O(m+n)

bool searchMatrix(vector<vector<int>> &arr, int t)
{
    int m = arr.size(), n = arr[0].size();
    int i = 0, j = n - 1;
    int val = arr[i][j];
    while (i < m && j >= 0)
    {
        if (t == val)
            return true;
        else if (t < val)
        {
            j--;
            if (j < 0)
                return false;
            val = arr[i][j];
        }
        else
        {
            i++;
            if (i == m)
                return false;
            val = arr[i][j];
        }
    }
    return false;
}

// Code 2 : Using Binary Search O(log(m*n))

bool searchMatrix(vector<vector<int>> &arr, int t)
{
    int row = arr.size(), col = arr[0].size();
    int low = 0, high = (row * col) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int val = arr[mid / col][mid % col];
        if (t == val)
            return true;
        else if (t < val)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}
// Code 1 : Space Complexity : O(m+n)

void setZeroes(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    vector<int> v1(m, 0), v2(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                v1[i] = -1;
                v2[j] = -1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((arr[i][j] != 0) && (v1[i] == -1 || v2[j] == -1))
            {
                arr[i][j] = 0;
            }
        }
    }
}

// Code 2 : SC - O(1)

void setZeroes(vector<vector<int>> &arr)
{
    int m = arr.size(), n = arr[0].size();
    int zeroVal = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                if (j == 0)
                {
                    arr[i][0] = 0;
                    zeroVal = 0;
                }
                else
                {
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }
    }
    for (int i = m - 1; i > 0; i--)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (arr[0][j] == 0 || arr[i][0] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }

    // updating the 1st row
    for (int j = n - 1; j > 0; j--)
    {
        if (arr[0][j] == 0 || arr[0][0] == 0)
            arr[0][j] = 0;
    }

    // updating the 1st col
    for (int i = m - 1; i >= 0; i--)
    {
        if (arr[i][0] == 0 || zeroVal == 0)
            arr[i][0] = 0;
    }
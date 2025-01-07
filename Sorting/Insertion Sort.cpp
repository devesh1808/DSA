class Solution
{
public:
    // Please change the array in-place
    void insertionSort(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            int ele = arr[i];
            for (int j = i - 1; j >= 0; j--)
            {
                if (ele < arr[j])
                    swap(arr[j + 1], arr[j]);
                else
                    break;
            }
        }
    }
};
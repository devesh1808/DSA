class Solution
{
public:
    void merge(vector<int> &arr, int l, int m, int r)
    {
        int temp[r + 1];
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= r)
        {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while (i <= m)
            temp[k++] = arr[i++];
        while (j <= r)
            temp[k++] = arr[j++];
        --k;
        while (k >= 0)
        {
            arr[l + k] = temp[k];
            --k;
        }
    }
    void mergeSort(vector<int> &arr, int l, int r)
    {
        // code here
        if (l >= r)
            return;
        int n = arr.size();
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
};
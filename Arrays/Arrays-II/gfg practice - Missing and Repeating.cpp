vector<int> findTwoElement(vector<int> &arr)
{
    // code here
    int n = arr.size();
    int i = 0;
    while (i < n)
    {
        if (arr[i] == arr[arr[i] - 1])
            i++;
        else
            swap(arr[i], arr[arr[i] - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
            return {arr[i], i + 1};
    }
    return {};
}
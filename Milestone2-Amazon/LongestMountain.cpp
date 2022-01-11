int longestMountain(vector<int> &arr)
{
    int n = arr.size();
    if (n < 3)
        return 0;
    int res = 0;
    for (int i = 1; i <= n - 2; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
        {
            int j = i;
            int length = 1;
            while (j >= 1 && arr[j] > arr[j - 1])
            {
                j--;
                length++;
            }
            j = i;
            while (j <= n - 2 && arr[j] > arr[j + 1])
            {
                j++;
                length++;
            }
            res = max(res, length);
        }
    }
    return res;
}
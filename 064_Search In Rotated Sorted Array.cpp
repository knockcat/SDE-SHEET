// Time Complexity ->  log(n)
// Space Complexity -> O(1)

int search(int* arr, int n, int key) {
    // Write your code here.

    int low = 0, high = n-1;

    if(n == 1)
    {
        if(arr[0] == key)
            return 0;
        return -1;
    }

    while(low <= high)
    {
        int mid = (low + high) >> 1;

        if(arr[mid] == key)
            return mid;
        
        if(arr[low] <= arr[mid])
        {
            if(arr[low] <= key and key <= arr[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else
        {
            if(key <= arr[high] and arr[mid] <= key)
                low = mid+1;
            else
                high = mid-1;
        }
    }

    return -1;

}

// Last updated: 3/25/2026, 9:03:54 AM
class Solution {
    public boolean checkIfExist(int[] arr) {
    Arrays.sort(arr);
    for(int i=0;i<arr.length;i++)
    {
        if(Arrays.binarySearch(arr,2*arr[i])>=0)
        {
            if(Arrays.binarySearch(arr,2*arr[i]) !=i) // will not be called more than 2 times
                return true;
        }
    }
    return false;
}
}
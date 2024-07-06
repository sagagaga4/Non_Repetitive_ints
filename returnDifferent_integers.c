#include <stdio.h>




int BinarySearch(int *arr,int size,int target)
{
    if(arr == NULL)
    {
        return -1;
    }
    int low = 0;
    int high = size-1;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(arr[mid] == target)
        {
            return mid;
        }

        if(arr[mid] < target)
        {
            low = mid + 1;
        }

        if(arr[mid] > target)
        {
            high = mid -1;
        }
    }
    return -1;
} 

int diff(int arr1[], int size1, int arr2[], int size2)
{
    if(arr1 == NULL)
    {
        return size2;
    }
    else if(arr2 == NULL)
    {
        return size1;
    }
    if(arr1 == NULL && arr2 == NULL)
    {
        return 1;
    }

    int count = 0;
    int sum_sizes = size1 + size2;

  for(int i = 0; i < size2; i++)
    {
        if(BinarySearch(arr1, size1, arr2[i]) != -1) 
        {
            count++;
        }
    }

    for(int i = 0; i < size1; i++)
    {
        if(BinarySearch(arr2, size2, arr1[i]) != -1) 
        {
            count++;
        }
    }
    int calc = sum_sizes-count;
    printf("There are %d difffernt integers\n",calc);
    return(calc);
}




int main()
{
    int arr1[] = {0,1,3,9,10,11,30,35}; 
    int arr2[] = {1,6,9,10,30,39}; 
    int size1 = 8;
    int size2 = 6;

    diff(arr1,size1,arr2,size2);
    return 0;
}



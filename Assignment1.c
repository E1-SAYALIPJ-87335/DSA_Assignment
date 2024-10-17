// Binary Search
// Pre-Requisite : Sorted Data
// Divide and conquer Technique

#include<stdio.h>
#define SIZE 9


int linear_search(int arr[SIZE],int key,int index);
int rec_binary_search(int arr[SIZE],int key,int left, int right);
int main()
{
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    int key , index = 0;

    printf("Enter the Key to Search :");
    scanf("%d",&key); // 66

    int result = linear_search(arr,key,index);

    printf("\n Recursive Binary Search :\n");
    if(result == -1)
        printf("Key not found !\n");
    else
        printf("Key found at index = %d\n",result);

/*
    printf("\n Recursive Binary Search :\n");
    int res = rec_binary_search(arr,key,0,SIZE-1);
    if(res == -1)
        printf("Key not found !\n");
    else
        printf("Key found at index = %d\n",res);
        */
    return 0;
}

int linear_search(int arr[SIZE],int key,int index)
{
    
    if (index > SIZE) 
    {
      return -1;
    }
     
    if(key == arr[index])
    {
       return index;
    }
        
    return linear_search(arr,key,index++);

}

int rec_binary_search(int arr[SIZE],int key,int left, int right)
{
    int mid, res;

    if(left > right)    
        return -1;

    mid = (left + right) / 2;

    if(key == arr[mid])
        return mid;

    if(key < arr[mid])
    {
        res = rec_binary_search(arr,key,left,mid-1);
    }
    else
    {
        res = rec_binary_search(arr,key,mid+1, right);
    }

    return res;
}

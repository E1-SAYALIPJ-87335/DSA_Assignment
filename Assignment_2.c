#include<stdio.h>
#define size 6
void select_sort(int arr[size]);
void display_sort(int arr[size]);
void insertion_sort(int arr[size]);
void bubble_sort(int arr[size]);
#define SWAP(a,b) int temp = a; a=b; b=temp;



int main(){
int arr[]={11,22,66,44,55,33};

printf("SELECTION SORT :: \n");
select_sort(arr);
display_sort(arr);

printf("\nBUBBLE SORT :: \n");
bubble_sort(arr);
display_sort(arr);

printf("\nINSERTION SORT :: \n");
insertion_sort(arr);
display_sort(arr);

return 0;

}
void select_sort(int arr[size]){

    int sel_pos ,pos ;
    int itse= 0 , compse= 0;

    for (sel_pos = 0 ; sel_pos<size-1;sel_pos++)
    {
        itse++;
        for(pos = sel_pos;pos<size ; pos++)
        {
            compse++;
            if(arr[sel_pos]>arr[pos])
            {
            SWAP(arr[sel_pos],arr[pos]);
            }
        }

    }
    printf("\n itteration = %d \n comparisions = %d\n", itse,compse);

    
}
void display_sort(int arr[size]){
    
    for(int i =0;i<size;i++)
    {
        
        printf(" %4d ",arr[i]);
    }

}



void bubble_sort(int arr[size])
{
    int its , pos;
    int itbb = 0 , compbb =0;

    for(its=0;its<size-1;its++)
    {
        itbb++;
        for(pos=0;pos<size-1-its;pos++)
        {
            compbb++;
            if(arr[pos]>arr[pos+1])
            {
                SWAP(arr[pos],arr[pos+1]);
            }
        }
    }
    printf("\nIitteration = %d \n comparissions = %d\n", itbb ,compbb);
    
} 


void insertion_sort(int arr[size])
{
    int j , i , temp ;
    int itin = 0 , compin =0;


    for(i=1 ;i<size ; i++)
    {
        itin++;
        temp = arr[i];
        for(j=i-1;j>=0 && temp<arr[j];j--)
        {
            compin++;
            arr[j+1]=arr[j];
        }
        arr[j+1]=temp;
    }
    printf("\n itteration = %d \n comparisions = %d\n", itin,compin);


}
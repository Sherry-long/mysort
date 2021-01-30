#ifndef __MYSORT_H__
#define __MYSORT_H__

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
inline static void swap(int *x,int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

inline static int Partition(int A[],int low,int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot) --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

inline static void QuickSort(int A[],int low,int high)
{
    if(low < high)
    {
        int pos = Partition(A,low,high);
        QuickSort(A,low,pos-1);
        QuickSort(A,pos+1,high);
    }
}

inline static void BubbleSort(int A[],int n)
{
    bool flag;
    for(int i = 0;i < n-1;++i)
    {
        flag = false;
        for(int j = n - 1;j > i;--j)
        {
            if(A[j] < A[j - 1])
            {
                swap(&A[j],&A[j - 1]);
                flag = true;
            }
        }
        if(flag == false)
            return;
        for(int j = 0;j < 10;++j){
            printf("%d ",A[j]);
        }
        printf("\n");
    }

}

inline static void Merge(int *A,int low,int mid,int high)
{
    int i,j,k;
    int *B=(int *)malloc((high + 1) * sizeof(int));
    for(i = low;i <= high;++i)
    {
        B[i] = A[i];
        printf(" B[%d] = %d",i,B[i]);
    }
    printf("\n");
    for(i = low, j = mid + 1,k = i;i <= mid && j <= high;++k)
    {
        if(B[i] <= B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }

    while (i <= mid) A[k++] = B[i++];
    while (j <= high) A[k++] = B[j++];

    free(B);

}

inline static void MergeSort(int *A,int low,int high)
{
    if(low < high)
    {

        int mid = low + (high - low) / 2;
//        printf(" mid = %d\n",mid);
//        for(int i = 0;i < 10;++i){
//            printf("%d ",A[i]);
//        }
//        printf("\n");
        MergeSort(A,low,mid);
        MergeSort(A,mid + 1,high);
        Merge(A,low,mid,high);

    }
}

inline static void HeapAdjust(int *A,int i,int n)
{
    A[0] = A[i];
    for(int j = i * 2;j <= n;j *= 2)
    {
        if(j < n && A[j] < A[j + 1])
            j++;
        if(A[j] > A[0])
        {
            A[i] = A[j];
            i = j;
        }
        else break;
    }
    A[i] = A[0];
}

inline static void BuildMaxHeap(int *A,int n)
{
    for (int i = n / 2;i > 0;--i)
    {
        HeapAdjust(A,i,n);
    }
}

inline static void HeapSort(int *A,int n)
{
    BuildMaxHeap(A,n);
    for (int i = n;i > 1;--i)
    {
        swap(&A[i],&A[1]);
        HeapAdjust(A,1,i - 1);
    }
}
#endif //__MYSORT_H__

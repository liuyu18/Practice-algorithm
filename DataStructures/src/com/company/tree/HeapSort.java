package com.company.tree;

public class HeapSort {


    public static void heapSort(int arr[]) {
        int temp = 0;
        System.out.println("堆排序!!");

        for (int i =arr.length/2-1;i>=0;i--){
            adjustHeap(arr, i, arr.length);
        }
    }

    public  static void adjustHeap(int arr[], int i, int lenght) {
        int temp = arr[i];
        for(int k = i * 2 + 1; k < lenght; k = k * 2 + 1) {
            if (k + 1 < lenght && arr[k] < arr[k + 1]){
                k++;
            }
            if (arr[k] > temp){
                arr[i] = arr[k];
                i = k;
            }else{
                break;
            }
        }
        arr[i] = temp;

    }

}

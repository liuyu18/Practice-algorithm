package com.company.sort_linux;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Arrays;
public class BubbleSort {
    public static void main(String[] args){
        int[] arr = new int[80];
        for (int i = 0; i < 80;i++){
            arr[i] = (int)(Math.random() * 8000);
        }



        Date data1 = new Date();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String date1Str = simpleDateFormat.format(data1);
        System.out.println(Arrays.toString(arr));
        System.out.println("排序前的时间是=" + date1Str);


//这是冒泡排序
//        bubbleSort(arr);
//插入排序
//        insertSort(arr);


        quickSort(arr, 0, arr.length-1);

        Date data2 = new Date();
        String date2Str = simpleDateFormat.format(data2);
        System.out.println("排序后的时间是=" + date2Str);
        System.out.println(Arrays.toString(arr));
    }

    public static void mergeSort(int[] arr, int left, int right, int[] temp) {
        if (left < right){
            int mid = (left + right) / 2;
            mergeSort(arr,left,mid,temp);
            mergeSort(arr,mid + 1,right,temp);
            merge(arr,left,mid,right,temp);
        }
    }

    public static void merge(int[] arr, int left, int mid, int right, int[] temp) {


        int i = left;
        int j = mid + 1;
        int t = 0;

        while (i <= mid && j <= right){
            if (arr[i] <= arr[j]){
                temp[t] = arr[i];
                t += 1;
                i += 1;
            }else{
                temp[t] = arr[j];
                t += 1;
                j += 1;
            }

            while (i <= mid){
                temp[t] = arr[i];
                t += 1;
                i += 1;
            }
            while (j <= right){
                temp[t] = arr[j];
                t += 1;
                j += 1;
            }
            t = 0;
            int tempLeft = left;
            while (tempLeft <= right){
                arr[tempLeft] = temp[t];
                t += 1;
                tempLeft += 1;
            }
        }

    }

    public static void quickSort(int[] arr,int left, int right) {
        int l = left;
        int r = right;

        int pivot = arr[(left + right) / 2];
        int temp = 0;

        while (l < r){
            while (arr[l] < pivot){
                l += 1;
            }
            while (arr[r] > pivot){
                r -= 1;
            }
            if (l >= r){
                break;
            }
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;

            if (arr[l] == pivot){
                r -= 1;
            }
            if (arr[r] == pivot){
                l += 1;
            }
        }
        if (l == r){
            l += 1;
            r -= 1;
        }
        if (left < r){
//            System.out.println("第一个 递归");
            quickSort(arr,left,r);
        }
        if (right > l){
//            System.out.println("第二个 递归");
            quickSort(arr,l,right);
        }

    }

//希尔排序
    public static void shellSort(int[] arr) {
        int temp = 0;
        int count = 0;

        for (int gap = arr.length / 2; gap > 0; gap /=2){
            for (int i = gap; i < arr.length; i++){
                for (int j = i - gap; j >= 0; j -= gap){
                    if (arr[j] > arr[j+gap]){
                        temp = arr[j];
                        arr[j] = arr[j+gap];
                        arr[j + gap] = temp;
                    }
                }
            }
        }
    }
//每次找到已排序的最后的一个数到数组的最后面这段距离里面的最小值,来交换
    public static void selectSort(int[] arr) {
        for (int i = 0;i < arr.length - 1;i++){
            int minIndex = i;
            int min = arr[i];
            for (int j = i + 1;j < arr.length;j++){
                if (min > arr[j]){
                    min = arr[j];
                    minIndex = j;
                }
            }
            if (minIndex != i){
                arr[minIndex] = arr[i];
                arr[i] = min;
            }
        }
    }


//插入排序
    public static void insertSort(int[] arr){
        int insertVal = 0;
        int insertIndex = 0;

        for (int i = 0;i < arr.length;i++){
            insertVal = arr[i];
            insertIndex = i - 1;

            while (insertIndex >= 0 && insertVal < arr[insertIndex]){
                arr[insertIndex + 1] = arr[insertIndex];
                insertIndex--;
            }
            if (insertIndex + 1 != i){
                arr[insertIndex + 1] = insertVal;
            }
        }
    }
//冒泡排序
    public static void bubbleSort(int[] arr){
        int temp = 0;
        boolean flag = false;
        for (int i = 0;i < arr.length - 1;i++){
            for (int j = 0; j < arr.length - 1 - i;j++){
                if (arr[j] > arr[j + 1]){
                    flag = true;
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
            if (!flag){
                break;
            }else{
                flag = false;
            }
        }
    }

}

package com.company.search;
import java.util.ArrayList;
import java.util.List;
public class seqSearch_01 {
    public static void main(String[] args) {
        int arr[] = { 1, 9, 11, -1, 34, 89 };// 没有顺序的数组
        int index = seqSearch(arr, -11);
        if(index == -1) {
            System.out.println("没有找到到");
        } else {
            System.out.println("找到，下标为=" + index);
        }
    }

    //二分查找
    public static int binarySearch(int[] arr, int left, int right, int findVal){
        if (left > right){
            return -1;
        }
        int mid = (left + right)/2;
        int midVal = arr[mid];
        if (findVal > midVal){
            return binarySearch(arr,mid+ 1,right,findVal);
        }else if(findVal < midVal){
            return binarySearch(arr,left,mid-1,findVal);
        }
        return mid;
    }
//查找多次重复
public static List<Integer> binarySearch2(int[] arr, int left, int right, int findVal){
        System.out.println("寻找 重复存在的元素");
        if (left > right){
            return new ArrayList<Integer>();
        }
        int mid = (left + right)/2;
        int midVal = arr[mid];

        if (findVal > midVal){
            return binarySearch2(arr, mid + 1, right, findVal);
        } else if (findVal < midVal) {
            return binarySearch2(arr, left, mid - 1, findVal);
        }else{
            List<Integer> resIndexlist = new ArrayList<Integer>();
            int temp = mid - 1;
            while (true){
                if (temp < 0 || arr[temp] != findVal){
                    break;
                }
                resIndexlist.add(temp);
                temp -= 1;
            }
            resIndexlist.add(mid);
            temp = mid + 1;
            while (true){
                if (temp > arr.length - 1 || arr[temp] != findVal) {//退出
                    break;
                }

                resIndexlist.add(temp);
                temp += 1;
            }
            return resIndexlist;
        }
}
//普通的线性查找
    public static int seqSearch(int[] arr, int value){
        for (int i = 0;i < arr.length;i++){
            if (arr[i] == value){
                return i;
            }
        }
        return -1;
    }
}

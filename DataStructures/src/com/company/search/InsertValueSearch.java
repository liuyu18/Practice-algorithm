package com.company.search;

public class InsertValueSearch {


    public static int insertValueSearch(int[] arr, int left, int right, int findVal){
        System.out.println("插值查找次数~~");

        public static void main(String[] args) {



            int arr[] = { 1, 8, 10, 89,1000,1000, 1234 };

            int index = insertValueSearch(arr, 0, arr.length - 1, 1234);

            System.out.println("index = " + index);

            //System.out.println(Arrays.toString(arr));
        }

        if (left > right || findVal < arr[0] || findVal > arr[arr.length - 1]) {
            return -1;
        }
        //这是一个公式
        int mid = left + (right - left) * (findVal - arr[left]) / (arr[right] - arr[left]);
        int midVal = arr[mid];
        if (findVal > midVal) {
            return insertValueSearch(arr, mid + 1, right, findVal);
        } else if (findVal < midVal) {
            return insertValueSearch(arr, left, mid - 1, findVal);
        } else {
            return mid;
        }
    }

}

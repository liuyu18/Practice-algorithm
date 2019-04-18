import java.util.Arrays;
public class SortTool {

    public static void bubbleSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        //两两交换 最值在极端 所以外层for减一
        for (int e = arr.length - 1; e > 0; e--) {
            for (int i = 0; i < e; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr, i, i + 1);
                }
            }
        }
    }
    //插入排序
    public static void insertionSort(int[] arr){
        if (arr == null || arr.length < 2){
            //插入排序 是前面的部分是排序好的了 是排序好的那个部分后面那个元素 要从排序好的部分找到
            //何时位置
            for (int i = 1;i < arr.length;i++){
                for (int j = i - 1;j >= 0 && arr[j]>arr[j+1];j--){
                    swap(arr, j, j + 1);
                }
            }
        }
    }
    //选择排序
    public static void selectionSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 0;i < arr.length - 1;i++){
            int minIndex = i;
            for (int j = i + 1;j < arr.length;j++){
                minIndex = arr[j] < arr[minIndex]?j:minIndex;
            }
            swap(arr, i, minIndex);
        }
    }

    //堆排序 堆排序类似二叉树的原理
    public static void heapSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        for (int i = 0;i < arr.length;i++){
            heapInsert(arr, i);
        }
        int size = arr.length;
        swap(arr,0,--size);
        while (size > 0){
            heapify(arr,0,size);
            swap(arr,0,--size);
        }
    }
    //辅助函数 插入元素 目标节点 不断与父节点比较
    public static void heapInsert(int[] arr, int index) {
        while (arr[index] > arr[(index - 1) / 2]){
            swap(arr,index,(index - 1) / 2);
            index = (index - 1)/2;
        }
    }
    //这节点变化的时候出现的情况
    public static void heapify(int[] arr, int index, int size) {
        int left = index * 2 + 1;
        while (left < size){
            int largest = left + 1 < size && arr[left + 1] > arr[left] ? left + 1 : left;
            largest = arr[largest] > arr[index] ? largest : index;
            if(largest == index){
                break;
            }
            swap(arr,largest,index);
            index = largest;
            left = index * 2 + 1;
        }
    }
    // 快排 原理就是 选一个参照点
    public static void quickSort(int[] arr) {
        if (arr == null || arr.length < 2){
            return;
        }
        quickSort(arr, 0, arr.length - 1);
    }
    public static void quickSort(int[] arr, int l, int r) {
        if (l < r){
            swap(arr,l + (int)(Math.random()*(r - l + 1)),r);
            int[] p = partition(arr,l,r);
            quickSort(arr,l,p[0] - 1);
            quickSort(arr,p[1] + 1,r);
        }
    }
    //划分辅助函数
    public static int[] partition(int[] arr, int l, int r){
        //左右指针
        int less = l - 1;
        int more = r;
        while (l < more){
            if (arr[l] < arr[r]){
                swap(arr,++less,l++);
            }else if(arr[l] > arr[r]){
                swap(arr, --more, l);
            }else{
                l++;
            }
        }
        swap(arr,more,r);
        return new int[]{less + 1,more};
    }


    public static void mergeSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        mergeSort(arr, 0, arr.length - 1);
    }

    public static void mergeSort(int[] arr, int l, int r) {
        if (l == r) {
            return;
        }
        int mid = l + ((r - l) >> 1);
        mergeSort(arr, l, mid);

        mergeSort(arr, mid + 1, r);

        merge(arr, l, mid, r);
    }

    public static void merge(int[] arr, int l, int m, int r) {

        System.out.println("--------------------");

        System.out.println("arr 前:"+Arrays.toString(arr));
        System.out.println("l:"+l);
        System.out.println("r:"+r);
        System.out.println("mid:"+m);


        int[] help = new int[r - l + 1];
        int i = 0;
        int p1 = l;
        int p2 = m + 1;
        while (p1 <= m && p2 <= r) {
            System.out.println("arr[p1] 第一个IF:"+arr[p1]+",p1 :"+p1);
            System.out.println("arr[p2] 第一个IF:"+arr[p2]+",p2 :"+p2);
            help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
        }
        while (p1 <= m) {
            System.out.println("arr[p1] 第二个IF:"+arr[p1]+",p1" + p1);
            help[i++] = arr[p1++];
        }
        while (p2 <= r) {
            System.out.println("arr[p2] 第三个IF:"+arr[p2]+",p2 :"+p2);
            help[i++] = arr[p2++];
        }
        for (i = 0; i < help.length; i++) {
            arr[l + i] = help[i];
        }
        System.out.println("help 后:"+Arrays.toString(help));
        System.out.println("arr 后:"+Arrays.toString(arr));
        System.out.println("--------------------");
    }

    public static void bucketSort(int[] arr) {
        if (arr == null || arr.length < 2) {
            return;
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++) {
            max = Math.max(max, arr[i]);
        }
        int[] bucket = new int[max + 1];
        for (int i = 0; i < arr.length; i++) {
            bucket[arr[i]]++;
        }
        int i = 0;
        for (int j = 0; j < bucket.length; j++) {
            while (bucket[j]-- > 0) {
                arr[i++] = j;
            }
        }
    }

    public static void swap(int[] arr, int i, int j) {
        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];
    }

    // for test
    public static void comparator(int[] arr) {
        Arrays.sort(arr);
    }

    // for test
    public static int[] generateRandomArray(int maxSize, int maxValue) {
        int[] arr = new int[(int) ((maxSize + 1) * Math.random())];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (int) ((maxValue + 1) * Math.random()) - (int) (maxValue * Math.random());
        }
        return arr;
    }

    // for test
    public static int[] copyArray(int[] arr) {
        if (arr == null) {
            return null;
        }
        int[] res = new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            res[i] = arr[i];
        }
        return res;
    }

    // for test
    public static boolean isEqual(int[] arr1, int[] arr2) {
        if ((arr1 == null && arr2 != null) || (arr1 != null && arr2 == null)) {
            return false;
        }
        if (arr1 == null && arr2 == null) {
            return true;
        }
        if (arr1.length != arr2.length) {
            return false;
        }
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }

    // for test
    public static void printArray(int[] arr) {
        if (arr == null) {
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    // for test
    public static void main(String[] args) {
        int testTime = 500000;
        int maxSize = 10;
        int maxValue = 100;
        boolean succeed = true;
        for (int i = 0; i < testTime; i++) {
            int[] arr1 = generateRandomArray(maxSize, maxValue);
            int[] arr2 = copyArray(arr1);
            bubbleSort(arr1);
            comparator(arr2);
            if (!isEqual(arr1, arr2)) {
                succeed = false;
                break;
            }
        }
        System.out.println(succeed ? "Nice!" : "Fucking fucked!");

        int[] arr = generateRandomArray(maxSize, maxValue);
        printArray(arr);
        mergeSort(arr);
        printArray(arr);
    }

}

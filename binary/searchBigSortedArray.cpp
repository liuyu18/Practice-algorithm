    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int index = 1;
        while(reader->get(index) < target){
            index *= 2;
        }
        int left = 0;
        while(left + 1 < index){
            int mid = left + (index - left)/2;
            int value = reader->get(mid);
            if(value == target){
                index = mid;
            }else if(value < target){
                left = mid;
            }else{
                index = mid;
            }
        }
        if(reader->get(left) == target){
            return left;
        }else if(reader->get(index) == target){
            return index;
        }
        return -1;
    }
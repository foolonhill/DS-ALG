package own.algorithm;

/**
 * 二分查找
 * Created by foolonhill on 2016/5/21.
 */
public class BinarySearch {

    public static void main(String[] agrs) {
        BinarySearch binarySearch = new BinarySearch();

        int[] arr = new int[]{5, 14, 25, 33, 40, 49, 72};
        int index = binarySearch.binarySearch(arr, 1);
        System.out.println(index);
    }

    public int binarySearch(int[] arr, int toFind) {
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == toFind) {
                return mid;
            } else if (arr[mid] < toFind) {
                left = left + 1;
            } else {
                right = right - 1;
            }
        }

        return -1;
    }
}

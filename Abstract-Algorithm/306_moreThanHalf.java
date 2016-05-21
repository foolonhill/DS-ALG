package own.algorithm;

/**
 * 出现次数超过一半
 * Created by foolonhill on 2016/5/21.
 */
public class MoreThanHalf {
    public static void main(String[] agrs) {
        MoreThanHalf moreThanHalf = new MoreThanHalf();

        int[] arr = new int[]{2, 4, 2, 3, 2, 5, 2, 2, 9, 14, 2};
        int ret = moreThanHalf.moreThanHalf(arr);
        System.out.println(ret);
    }

    public int moreThanHalf(int[] arr) {
        if (arr == null || arr.length == 0) {
            return -1;  //just to
        }
        int result = arr[0];
        int times = 1;
        for (int i = 1; i < arr.length; i++) {
            if (times == 0) {
                result = arr[i];
                times = 1;
            } else if (arr[i] == result) {
                times++;
            } else {
                times--;
            }
        }
        return result;
    }

    public boolean check(int[] arr, int toCheck) {

        return false;
    }
}

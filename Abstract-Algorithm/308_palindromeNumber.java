package own.algorithm;

/**
 * Palindrome number
 * Created by 58 on 2016/5/28.
 */
public class Palindrome {

    public static void main(String[] args) {
        System.out.println(isPalindrome(1221));
    }

    public static boolean isPalindrome(int originalNumber) {
        int palindrome = 0;
        int origin = originalNumber;

        // get the palindrome
        while(originalNumber != 0) {
            palindrome = palindrome * 10 + originalNumber % 10;
            originalNumber /= 10;
        }

        return palindrome == origin ;
    }
}

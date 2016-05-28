package own.algorithm;

import java.util.Stack;

/**
 * 栈的应用
 * Created by foolonhill on 2016/5/28.
 */
public class StackSuite {

    public static void main(String[] args) {
        StackSuite stackSuite = new StackSuite();
        stackSuite.printAnyRadix(16, 2);

        stackSuite.chracterMatcher(")([()]");
    }

    /**
     * 符号匹配
     * @param str string
     */
    public void chracterMatcher(String str) {
        char[] chars = str.toCharArray();
        boolean match = true;
        Stack<Character> lefts = new Stack<Character>();

        for (char ch : chars) {
            if (ch == '(' || ch == '{' || ch == '[') {
                lefts.push(ch);
            } else {
                if (lefts.isEmpty()) {
                    match = false;
                    break;
                }
                switch (ch) {
                    case ')':
                        if (lefts.peek() == '(') {
                            lefts.pop();
                        } else {
                            match = false;
                            break;
                        }
                        break;
                    case ']':
                        if (lefts.peek() == '[') {
                            lefts.pop();
                        } else {
                            match = false;
                            break;
                        }
                        break;
                    case '}':
                        if (lefts.peek() == '{') {
                            lefts.pop();
                        } else {
                            match = false;
                            break;
                        }
                        break;
                    default:
                        match = false;
                        break;
                }
            }
        }

        System.out.println("The string is match ? " + match);
    }


    /**
     * 可以输出一个十进制数的任意n进制
     * @param num 十进制数
     * @param n 进制, n <= 10
     */
    public void printAnyRadix(int num, int n) {
        Stack<Integer> fonts = new Stack<Integer>();
        while (num > 0) {
            fonts.push(num % n);
            num /= n;
        }

        while (!fonts.isEmpty()) {
            System.out.print(fonts.peek());
            fonts.pop();
        }
        System.out.println();
    }
}

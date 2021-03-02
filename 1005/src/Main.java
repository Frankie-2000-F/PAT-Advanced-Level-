import java.io.IOException;
import java.util.Scanner;

public class Main {
    static String[] digit = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    public static void main(String[] args) throws IOException{
        Scanner input = new Scanner(System.in);
        String num = input.next();
        char[] digits = num.toCharArray();
        int sum = 0;
        for(int i = 0; i < digits.length; i++){
            sum += Character.getNumericValue(digits[i]);
        }
        String result = String.valueOf(sum);
        char[] out = result.toCharArray();
        for(int i = 0; i < out.length; i++){
            if(i == 0)
                System.out.print(digit[Character.getNumericValue(out[i])]);
            else
                System.out.print(" " + digit[Character.getNumericValue(out[i])]);
        }
    }
}

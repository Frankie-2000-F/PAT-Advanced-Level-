import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        long startTime = System.currentTimeMillis();
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
//        boolean allNegative = true;
        int maxSum = -1;
        int currentSum = 0;
        int maxFirst = 0, maxLast = 0;
        int first = 0, last = 0;
        int flag = 0;
        boolean updateFlag = false;
        int currentNum = 0;
        for(int i = 0; i < num; i++){
            currentNum = input.nextInt();
//            if(currentNum >= 0)
//                allNegative = false;
            if(i == 0)

            if(i == num - 1)
                last = currentNum;
            currentSum += currentNum;
            if(updateFlag){
                flag = currentNum;
                updateFlag = false;
            }
            if(currentSum > maxSum){
                maxFirst = flag;
                maxLast = currentNum;
                maxSum = currentSum;
            }
            if(currentSum < 0){
                currentSum = 0;
                updateFlag = true;
            }
        }

        if(maxSum == -1)
            System.out.print("0 " + first + " " + last);
        else
            System.out.print(maxSum + " " + maxFirst + " " + maxLast);
        long endTime = System.currentTimeMillis();
        System.out.println(endTime-startTime + "ms");
    }

}

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int N = input.nextInt();
        int currentFloor = 0;
        int sumTime = 0;
        sumTime += N * 5;
        for(int i = 0; i < N; i++){
            int targetFloor = input.nextInt();
            if(targetFloor > currentFloor)
                sumTime += (targetFloor - currentFloor) * 6;
            else
                sumTime += (currentFloor - targetFloor) * 4;
            currentFloor = targetFloor;
        }
        System.out.print(sumTime);
    }
}

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        String[] option = {"W", "T", "L"};
        String[] result = new String[3];
        Double[] predict = new Double[3];
        double sum = 1;
        for(int i = 0; i < 3; i++){
            double max  = 0;
            for(int j = 0; j < 3; j++){
                predict[j] = input.nextDouble();
                if(predict[j] > max){
                    result[i] = option[j];
                    max = predict[j];
                }
            }
            sum *= max;
        }
        sum = (sum * 0.65 - 1) * 2;
        for(int i = 0; i < 3; i++){
            System.out.print(result[i] + " ");
        }
        System.out.print(String.format("%.2f", sum));
    }
}

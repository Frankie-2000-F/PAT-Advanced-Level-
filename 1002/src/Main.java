import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        while(input.hasNextInt()){
            int MaxKey = 0;
            int line1 = input.nextInt();
            HashMap<Integer, Double> map = new HashMap<>();
            for(int i = 0; i < line1; i++){
                int a = input.nextInt();
                if(a > MaxKey)
                    MaxKey = a;
                map.put(a, input.nextDouble());
            }

            int line2 = input.nextInt();
            for(int i = 0; i < line2; i++){
                int a = input.nextInt();
                if(a > MaxKey)
                    MaxKey = a;
                if(!map.containsKey(a))
                    map.put(a, input.nextDouble());
                else {
                    double b = map.get(a);
                    b += input.nextDouble();
                    if(b == 0)
                        map.remove(a);
                    else
                        map.put(a, b);
                }
            }

            if(map.size() == 0)
                System.out.print("0");
            else{
                System.out.print(map.size() + " ");
                int sign = 0;
                for(int i = MaxKey; i >= 0; i--){
                    if(map.containsKey(i)) {
                        sign++;
                        System.out.print(i + " ");
                        if(sign != map.size())
                            System.out.print(String.format("%.1f", map.get(i)) + " ");
                        else
                            System.out.print(String.format("%.1f", map.get(i)));
                    }
                }
            }

        }
    }
}

import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        HashMap<Integer, Double> map = new HashMap<>();
        HashMap<Integer, Double> result = new HashMap<>();
        Scanner input = new Scanner(System.in);
        int maxKey = 0;//记录第一行数据的最大系数
        int N = input.nextInt();
        for(int i = 0; i < N; i++){//读第一行数据
            int a = input.nextInt();
            if(a > maxKey)
                maxKey = a;
            double b = input.nextDouble();
            map.put(a, b);
        }
        int resultMaxKey = 0;//记录结果中的最大系数
        int M = input.nextInt();//读取第二行的数据个数
        for(int i = 0; i < M; i++){//读第二行数据
            int a = input.nextInt();
            double b = input.nextDouble();
            for(int j = 0; j <= maxKey; j++){//每读入一组数据就和第一行的数据依次相乘
                if(map.containsKey(j)) {
                    int x = a + j;
                    if(x > resultMaxKey)
                        resultMaxKey = x;
                    double y = b * map.get(j);
                    if (result.containsKey(x)) {
                        y += result.get(x);
                        if(y == 0)
                            result.remove(x);
                        else
                            result.put(x, y);
                    }
                    else
                        result.put(x, y);
                }
            }
        }
        System.out.print(result.size());
        for(int i = resultMaxKey; i >=0; i--){
            if(result.containsKey(i))
                System.out.print(" " + i + " " + String.format("%.1f", result.get(i)));
        }
    }
}

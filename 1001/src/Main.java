import java.io.*;

public class Main {
    public static void cal() throws IOException {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        String[] StrArr = buffer.readLine().split(" ");
        int a = Integer.parseInt(StrArr[0]);
        int b = Integer.parseInt(StrArr[1]);
        char[] sum = String.valueOf(a+b).toCharArray();
        if(sum.length > 3){
            for(int i = 0; i < sum.length; i++){
                if((sum.length - i - 1) % 3 == 0 && i != sum.length - 1 && sum[i] != '-'){
                    System.out.print(sum[i]);
                    System.out.print(",");
                }else{
                    System.out.print(sum[i]);
                }
            }
        }else{
            System.out.print(sum);
        }
    }

    public static void main(String[] args) throws IOException{
        cal();
    }
}

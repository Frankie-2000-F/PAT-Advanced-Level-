import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;
import java.util.StringTokenizer;


class formater{
    public static BigInteger format2Decimalism(String N, BigInteger radix){
        BigInteger result = BigInteger.ZERO;
        char[] n = N.toCharArray();
        for(int i = 0; i < n.length; i++){
            char a = n[i];
            int digit = 0;

            if((int)a >= 48 && (int)a <= 57 )
                digit = (int) a - 48;

            else
                digit = (int) a - 87;

            result.multiply(radix).add(BigInteger.valueOf(digit));
        }
        return result;
    }
}

public class Main {
    static final int BUFFER_SIZE = 8192 * 25;
    static BufferedReader br;
    static StringTokenizer tokenizer;

    static void initInput(InputStream in) throws Exception {
        br = new BufferedReader(new InputStreamReader(in), BUFFER_SIZE);
        tokenizer = new StringTokenizer("");
    }

    static String next() throws Exception {
        while (!tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(br.readLine());
        }
        return tokenizer.nextToken();
    }

    static int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    static PrintWriter pw;

    public static void main(String[] args)throws  Exception{
        initInput(System.in);
        String[] N = new String[2];
        pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out), BUFFER_SIZE));

        /*所有数值都要采用字符串存储，因为BigInteger最常用的构造方法是用字符串直接构造*/
        String a = next();
        String b = next();
        int tag = nextInt();
        String radix = next();
        String N1 = tag == 1 ? a : b;
        String N2 = tag == 1 ? b : a;
        final BigInteger IntN1 = formater.format2Decimalism(N1, new BigInteger(radix));
        int maxBit = 0;
        for(int i = 0; i < N2.length(); i++){
            char c = N2.charAt(i);
            int val = (c >= '0' && c <= '9') ? c -'0': c - 'a' +10;
            if(val > maxBit)
                maxBit = val;
        }
        BigInteger start = BigInteger.valueOf(maxBit + 1);
        BigInteger end = IntN1.compareTo(start) < 0 ? start : IntN1;
        BigInteger res = null;
        while(end.compareTo(start) >= 0){
            BigInteger mid = start.add(end).divide(BigInteger.valueOf(2));
            BigInteger temN2 = formater.format2Decimalism(N2, mid);
            if(temN2.compareTo(IntN1) >= 0){
                if(temN2.compareTo(IntN1) == 0 && (res == null||mid.compareTo(res) < 0))
                    res = mid;
                end = mid.subtract(BigInteger.valueOf(1));
            }else
                start = mid.add(BigInteger.valueOf(1));
        }


        if(res == null)
            pw.println("Impossible");
        else
            pw.println(res);

        pw.flush();
    }
}

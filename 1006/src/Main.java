import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;



public class Main {

    public static void main(String[] args) throws ParseException {
        Scanner input = new Scanner(System.in);
        SimpleDateFormat df = new SimpleDateFormat("HH:mm:ss");
        int num = input.nextInt();
        Date come = null;
        Date leave = null;
        String open = null;
        String close = null;
        for(int i = 0; i < num; i++){
            String person = input.next();
            Date d1 = df.parse(input.next());
            Date d2 = df.parse(input.next());
            if(i == 0) {
                come = d1;
                leave = d2;
                open = person;
                close = person;
            }
            if(d1.before(come)) {
                come = d1;
                open = person;
            }
            if(d2.after(leave)){
                leave = d2;
                close = person;
            }
        }

        System.out.print(open + " " + close);
    }
}

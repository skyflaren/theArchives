import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        long amt = in.nextLong();

        if(num == 1){
            if(amt <= 1) System.out.println(0);
            else if(amt == 2) System.out.println(2);
            else System.out.println(((amt * (amt-1) * (amt-2) * 1572858)/6 + amt * (amt-1)));
        }
        else if(num == 2){
            if(amt <= 2) System.out.println(0);
            else System.out.println((amt * (amt-1) * (amt-2) * 96)/6);
        }
        else if(num == 3){
            if(amt <= 1) System.out.println(0);
            else if(amt == 2) System.out.println(2);
            else System.out.println(((amt * (amt-1) * (amt-2) * 18)/6 + amt * (amt-1)));
        }
        else if(num == 4){
            if(amt <= 1) System.out.println(0);
            else if(amt == 2) System.out.println(2);
            else System.out.println(((amt * (amt-1) * (amt-2) * 24570)/6 + amt * (amt-1)));
        }
        else if(num == 5){
            if(amt <= 2) System.out.println(0);
            else System.out.println((amt * (amt-1) * (amt-2) * 12)/6);
        }
        else if(num == 6){
            if(amt <= 2) System.out.println(0);
            else System.out.println((amt * (amt-1) * (amt-2) * 6)/6);
        }
        else if(num == 7){
            if(amt <= 2) System.out.println(0);
            else System.out.println((amt * (amt-1) * (amt-2) * 96)/6);
        }
        else if(num == 8){
            if(amt <= 2) System.out.println(0);
            else System.out.println(((amt * (amt-1) * (amt-2) * 1610612730)/9 + amt * (amt-1)));
        }
    }
}

//This problem asks for eight various applications of a combinations formula
//Done with @astrocat879

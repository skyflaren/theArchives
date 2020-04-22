import java.util.*;
import java.io.*;

public class Main {
   static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static String next () throws IOException { while (st == null || !st.hasMoreTokens())
	    st = new StringTokenizer(br.readLine().trim());return st.nextToken(); }
    static long rlong () throws IOException { return Long.parseLong(next());}
    static int rint () throws IOException { return Integer.parseInt(next());}
    static double rdouble () throws IOException { return Double.parseDouble(next());}
    static String rline () throws IOException { return br.readLine().trim(); }
    static long gcd(long m, long n){ if(n == 0) return m; return gcd(n, m % n); }
    static void out(String a){ pr.print(a); }
    static void out(long a){ pr.print(a); }
    static void outln(String a){ pr.println(a); }
    static void outln(long a){ pr.println(a); }
    static void outln(double a){ pr.println(a); }
    static void outln(long a, long b){ pr.println(a + "  " + b); }

    public static long BIT[];
    public static int n;

    static void upd(int idx, long val) {
        for (int i = idx; i <= n; i+=i&-i) BIT[i] += val;
    }
    static long quer(int idx) {
        long res = 0;
        for (int i = idx; i > 0; i-=i&-i) res+= BIT[i];
        return res;
    }

    public static void main(String [] args) throws IOException{
        n = rint(); int q = rint();
        BIT = new long [n+5];
        int arr [] = new int[n+5];

        for(int i = 1; i <= n; i++){
            arr[i] = rint();
            upd(i, arr[i]);
        }
        for(int i = 0; i < q; i++){
            int op = rint();
            if(op == 1){
                int a = rint(), b = rint();
                upd(a, b-arr[a]);
            }
            else{
                int a = rint();
                outln(quer(a)-quer(a-1));
            }
        }
        for(int i = 1; i<= 5; i++){
            out(quer(i)-quer(i-1) + " ");
        }
        pr.close();
    }
}

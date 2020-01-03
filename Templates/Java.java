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
    static void out(String a){ pr.print(a); }
    static void out(long a){ pr.print(a); }
    static void outln(String a){ pr.println(a); }
    static void outln(long a){ pr.println(a); }
    static void outln(double a){ pr.println(a); }
    static void outln(long a, long b){ pr.println(a + "  " + b); }

    public static void main(String [] args) throws IOException{
        int n = rint();
        
        pr.close();
    }
}

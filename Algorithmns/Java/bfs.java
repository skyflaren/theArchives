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

    public static void main(String [] args) throws IOException{
        int n = rint(), m = rint(), start = rint(), end = rint();

        ArrayList<Integer>adj[] = new ArrayList[n+5];
        for(int i = 0; i <= n; i++) adj[i] = new ArrayList<Integer>();

        for(int i = 0; i < m; i++){
            int a = rint(), b = rint();
            adj[a].add(b); adj[b].add(a);
        }

        Queue <Integer> Q = new LinkedList <Integer>();
        boolean [] vis = new boolean[n+5]; 
        int [] dis = new int[n+5];

        Q.add(start); vis[start] = true; dis[start] = 0;
            
        while(!Q.isEmpty()){
            int cur = Q.poll();
            for(int v:adj[cur]){
                if(!vis[v]){
                    vis[v] = true;
                    dis[v] = dis[cur]+1;
                    Q.add(v);
                }
            }
        }
        outln(dis[end]);
        pr.close();
    }
}

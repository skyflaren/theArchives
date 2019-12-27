import java.util.*;
import java.io.*;
public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;

  public static int query(int [][] psa, int y, int x, int l, int w){ return psa[y+l][x+w] - psa[y-1][x+w] - psa[y+l][x-1] + psa[y-1][x-1]; }

  public static void main(String [] args) throws IOException{
    int r = readInt(), c = readInt(), l = readInt(), w = readInt();
    int DIRS[][] = {{-1, 1, 0, 0}, {0, 0, 1, -1}};
    l--; w--;
    int [][] psa = new int [r+2][c+2], dists = new int[r+2][c+2];

    for(int i = 1; i <= r; i++){
      String temp = next();
      for(int j = 1; j <= c; j++){
        dists[i][j] = Integer.MAX_VALUE;
        if(temp.charAt(j-1) == '#') psa[i][j] = 1;
        else psa[i][j] = 0;
        psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
      }
    }

    Queue <Integer> y = new LinkedList <Integer>();
    Queue <Integer> x = new LinkedList <Integer>();

    y.add(1);
    x.add(1);
    dists[1][1] = 0;

    while(!y.isEmpty()){
      int ty = y.poll();
      int tx = x.poll();

      for(int i = 0; i < 4; i++){
        int nx = tx + DIRS[0][i], ny = ty + DIRS[1][i];
        if(nx >= 1 && nx+w <= c && ny >= 1 && ny+l <= r){
          if(dists[ty][tx] + 1 < dists[ny][nx] && query(psa, ny, nx, l, w) == 0){
            dists[ny][nx] = dists[ty][tx] + 1;
            y.add(ny);
            x.add(nx);
          }
        }
      }
    }
    if(dists[r-l][c-w] != Integer.MAX_VALUE && query(psa, r-l, c-w, l, w) == 0) System.out.println(dists[r-l][c-w] + "\n");
    else System.out.println("-1");

  }
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}

//The intended solution is to build a 2-D Prefix Sum Array, where each iceberg is represented by a 1. We can then run a bfs, querying whether a move is valid using the PSA.

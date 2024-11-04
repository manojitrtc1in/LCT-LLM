import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;


public class CodeForcesSolution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static int mod = (int) 1e9+7;
    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int i = 0; i < T; i++) {
            int n = readInt(), tot = 0;
            Set<Integer> dis = new HashSet<>();
            Map<Integer, Integer> cnt = new HashMap<>();
            for (int j = 0; j < n; j++) {
                int v = readInt();
                dis.add(v);
                cnt.put(v, cnt.getOrDefault(v, 0)+1);
            }
            for (int v : cnt.keySet()) {
                tot+=(cnt.get(v)-1);
            }
            System.out.println(dis.size()-(tot%2));
        }

    }


    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();

    }
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter() throws IOException {
        return next().charAt(0);
    }
    static String readLine() throws IOException {
        return br.readLine().trim();
    }
    static int readALotInt() throws IOException{
        int x = 0, c;
        while((c = br.read()) != ' ' && c != '\n')
            x = x * 10 + (c - '0');
        return x;
    }
}

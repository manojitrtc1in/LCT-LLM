import java.io.*;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;


public class id1 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static int mod = (int) 1e9+7;
    public static void main(String[] args) throws IOException {
        int T = readInt();
        for (int i = 0; i < T; i++) {
            int n = readInt(), neg = 0, pos = 0, zero = 0;
            int[] A = new int[n];
            Set<Long> v =new HashSet<>();
            List<Integer> arr = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                A[j] = readInt();
                v.add((long) (A[j]));
                if (A[j]<0) neg++;
                else if (A[j]>0) pos++;
                if (A[j]==0) {
                    if (zero<=2) arr.add(0);
                    zero++;
                }
                else {
                    arr.add(A[j]);
                }
            }
            if (neg>=3 || pos>=3) {
                System.out.println("NO"); continue;
            }
            Collections.sort(arr);
            boolean ok = true;
            n = arr.size();
            loop:
            for (int j = 0; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    for (int l = k+1; l < n; l++) {
                        if (!v.contains((long) arr.get(j)+arr.get(k)+arr.get(l))) {
                            ok = false;
                            break loop;
                        }
                    }
                }
            }
            System.out.println(ok?"YES":"NO");
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
    static int id0() throws IOException{
        int x = 0, c;
        while((c = br.read()) != ' ' && c != '\n')
            x = x * 10 + (c - '0');
        return x;
    }
}

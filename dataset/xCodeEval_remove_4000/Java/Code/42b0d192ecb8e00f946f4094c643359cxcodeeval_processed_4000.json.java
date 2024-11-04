

import java.io.*;
import java.util.*;


public class C {

    
    boolean submitFlag = true;

    private void solve(int n, int[] a, int[] b) {
        int ans = 0;
        int max = n;
        int toRight = 0;
        while (max > ans) {
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == b[(i + n - toRight) % n]) {
                    res++;
                }
            }
            max -= res;
            ans = Math.max(res, ans);
            toRight++;
        }
        System.out.println(ans);
    }


    private void run() throws IOException {
        setReader();

        

        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(nextInt(), i);
        }

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int g = (i + n - map.get(a[i])) % n;
            res[g]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans, res[i]);
        }
        System.out.println(ans);

    }





    public static void main(String[] args) throws IOException {
        C solution = new C();
        solution.run();
        solution.reader.close();
    }

    
    private void setReader() throws IOException {
        if (submitFlag) {
            reader = new BufferedReader(new InputStreamReader(System.in));
        } else {
            String moduleName = "codeforces-race";
            String projectPath = System.getProperty("user.dir");
            String modulePath = projectPath + "/" + moduleName + "/src/main/java/";
            String className = this.getClass().getName().replace(".", "\\");
            reader = new BufferedReader(new FileReader(modulePath + className + "input.txt"));
        }
    }

    BufferedReader reader;
    StringTokenizer tokenizer;

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String next() throws IOException {
        return nextToken();
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}

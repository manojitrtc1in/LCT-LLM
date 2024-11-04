

import java.io.*;
import java.util.*;


public class C {

    
    boolean submitFlag = true;

    private void solve(int n, int k, Integer[] a, int[] w) {
        long[] ans = new long[k];

        Arrays.sort(a, (o1, o2) -> {
            return o2 - o1;
        });
        Arrays.sort(w);


        int index = 0;
        

        for (int i = 0; i < k; i++, index++) {
            ans[i] = a[index];
        }

        for (int i = 0; i < k; i++) {
            if (w[i] == 1) {
                ans[i] += ans[i];
            } else {
                int gg = w[i] - 1;
                ans[i] += a[index + gg - 1];
                index += gg;
            }

        }
        long res = 0;
        for (long aa : ans) {
            res += aa;
        }

        System.out.println(res);
    }


    private void run() throws IOException {

        

        int numberOfTestcases = nextInt();

        for (int t = 0; t < numberOfTestcases; t++) {
            int n = nextInt();
            int k = nextInt();
            Integer[] a = new Integer[n];
            int[] w = new int[k];
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            for (int i = 0; i < k; i++) {
                w[i] = nextInt();
            }

            solve(n, k, a, w);
        }

    }





    public static void main(String[] args) throws IOException {
        C solution = new C();
        solution.setReader();
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

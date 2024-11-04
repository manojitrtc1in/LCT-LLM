

import java.io.*;
import java.util.*;


public class B {

    
    boolean submitFlag = true;

    private void solve(int n, int[] s) {


        int ans = 0;
        int wei = 1;
        int[] sum = new int[2];
        int[] gg = new int[10];

        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < n; i++) {
                sum[s[i] % 2]++;
                s[i] = s[i] / 2;
            }
            if (sum[0] == sum[1]) {
                

                ans = ans + wei;
                

                gg[j] = 10;
            } else if (sum[0] == 0 || sum[1] == 0) {
                

                gg[j] = 0;
            } else {
                System.out.println(-1);
                return;
            }
            wei = wei * 2;
            sum[0] = 0;
            sum[1] = 0;
        }
        System.out.println(ans);
    }

    private void solve2(int n, Set<Integer> set) {

        for (int i = 1; i < 1024; i++) {


            Set<Integer> set2 = new HashSet<>();
            for (int a : set) {
                if (!set.contains(a ^ i)) {


                    break;
                } else {
                    set2.add(a ^ i);
                }

            }
            if ( set2.size() == set.size()) {
                

                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);

    }

    private void run() throws IOException {
        setReader();

        

        int id0 = nextInt();

        for (int t = 0; t < id0; t++) {
            int n = nextInt();
            Set<Integer> set = new HashSet<>();
            int[] s = new int[n];
            for (int i = 0; i < n; i++) {
                s[i] = nextInt();
                set.add(s[i]);
            }



            solve2(n, set);
        }

    }





    public static void main(String[] args) throws IOException {
        B solution = new B();
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
            String className = this.getClass().getName();
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

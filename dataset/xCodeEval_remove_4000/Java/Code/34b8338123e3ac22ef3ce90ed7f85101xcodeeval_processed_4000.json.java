

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;


public class B {

    
    boolean submitFlag = true;


    
    private void solve(int n, Set<Integer> set) {
        for (int i = 1; i < 1024; i++) {
            Set<Integer> set2 = new HashSet<>();
            for (int a : set) {
                if (!set.contains(a ^ i)) {
                    break;
                } else {
                    set2.add(a ^ i);
                }

            }
            if (set2.size() == set.size()) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }

    
    private void solve2(int n, Set<Integer> set) {
        for (int i = 1; i < 1024; i++) {
            boolean flag = true;
            for (int a : set) {
                if (!set.contains(a ^ i)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println(i);
                return;
            }
        }
        System.out.println(-1);
    }

    
    private void solve3(int n, int[] s, int[] is) {
        
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
            String moduleName = "codeforces";
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

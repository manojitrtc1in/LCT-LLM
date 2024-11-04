

import java.io.*;
import java.util.*;


public class C {

    
    boolean submitFlag = true;

    private void solve() {
        int ans = 0;


        System.out.println(ans);
    }


    private void run() throws IOException {

        

        int n = nextInt();
        System.out.println(n * 3 + 4);
        System.out.println("0 0");
        System.out.println("0 1");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.println(i + " " + (j + i - 1));
            }
        }

        System.out.println((n + 1) + " " + n);
        System.out.println((n + 1) + " " + (n + 1));
        
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

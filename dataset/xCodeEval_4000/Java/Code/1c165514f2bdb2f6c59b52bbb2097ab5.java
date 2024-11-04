

import java.io.*;
import java.net.URL;
import java.util.*;


public class A {

    
    boolean submitFlag = false;

    private void solve(int x, int y, int n) {
        int ans = (n / x) * x + y;
        if (ans > n) {
            ans -= x;
        }

        System.out.println(ans);
    }

    private void run() throws IOException {

        

        int numberOfTestcases = nextInt();

        for (int t = 0; t < numberOfTestcases; t++) {
            int x = nextInt();
            int y = nextInt();
            int n = nextInt();


            solve(x, y, n);
        }


    }





    public static void main(String[] args) throws IOException {
        A solution = new A();
        solution.setReader();
        solution.run();
        solution.reader.close();
    }

    
    private void setReader() throws IOException {
        URL resource = this.getClass().getResource("");

        submitFlag = resource == null;

        if (submitFlag) {
            reader = new BufferedReader(new InputStreamReader(System.in));
        } else {
            String path = this.getClass().getResource("").getPath();
            File file = new File(path);
            while (!file.getName().equals("target")) {
                file = file.getParentFile();
            }
            String moduleName = file.getParentFile().getName();
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

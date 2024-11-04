

import java.io.*;
import java.net.URL;
import java.util.*;


public class A {

    private void solve() {
        int ans = 0;


        System.out.println(ans);
    }


    private void run() throws IOException {

        

        int id0 = nextInt();


        for (int t = 0; t < id0; t++) {
            int[] a = new int[3];
            a[0] = nextInt();
            a[1] = nextInt();
            a[2] = nextInt();
            Arrays.sort(a);

            boolean ans = false;

            if (a[1] == a[2]) {
                ans = true;
                System.out.println("YES");
                

                System.out.println(a[0] + " " + a[0] + " " + a[2]);
            } else {
                System.out.println("NO");
            }
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
        if (resource == null) {
            reader = new BufferedReader(new InputStreamReader(System.in));
        } else {
            File file = new File(resource.getPath());
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

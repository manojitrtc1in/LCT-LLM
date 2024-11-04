

import java.io.*;
import java.net.URL;
import java.util.*;


public class C {

    private void solve() {
        int ans = 0;


        System.out.println(ans);
    }

    
    private void run() throws IOException {
        int id0 = nextInt();

        for (int t = 0; t < id0; t++) {
            String s = next();
            int ans = 0;
            for (int i = 0; i <= 9; i++) {
                for (int j = 0; j <= 9; j++) {
                    int index = 0;
                    for (int k = 0; k < s.length(); k++) {
                        if (index % 2 == 0) {
                            if (s.charAt(k) - '0' == i) {
                                index++;
                            }
                        } else {
                            if (s.charAt(k) - '0' == j) {
                                index++;
                            }
                        }
                    }
                    if (i == j) {
                        ans = Math.max(ans, index);
                    } else {
                        if (index % 2 == 1) {
                            ans = Math.max(ans, index - 1);
                        }else{
                            ans = Math.max(ans, index);
                        }
                    }

                }
            }

            System.out.println(s.length() - ans);
        }

    }





    public static void main(String[] args) throws IOException {
        C solution = new C();
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

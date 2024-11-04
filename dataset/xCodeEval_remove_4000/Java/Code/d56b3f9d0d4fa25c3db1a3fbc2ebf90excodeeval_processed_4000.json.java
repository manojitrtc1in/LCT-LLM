

import javax.sound.midi.Soundbank;
import java.io.*;
import java.util.*;


public class D {

    
    boolean submitFlag = true;

    private void run() throws IOException {
        

        int id0 = nextInt();

        for (int t = 0; t < id0; t++) {
            int n = nextInt();
            int k = nextInt();
            long ans = -1;
            

            Map<Integer, Long> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int data = nextInt();
                int key = data % k;
                if (key != 0) {
                    Long orDefault = map.getOrDefault(key, 0L);
                    orDefault++;
                    map.put(key, orDefault);
                    ans = Math.max(ans, orDefault * k - key);
                }
            }
            System.out.println(ans + 1);
        }
    }





    public static void main(String[] args) throws IOException {
        D solution = new D();
        solution.setReader();
        solution.run();
        solution.reader.close();
    }

    
    private void setReader() throws IOException {
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

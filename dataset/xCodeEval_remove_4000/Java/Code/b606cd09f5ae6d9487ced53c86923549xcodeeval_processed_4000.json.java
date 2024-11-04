


import java.io.*;
import java.util.*;

public class B {


    public void solve() {
        long max = -9999;
        int n = fastScanner.nextInt();
        int n2 = n;
        long res = 0;
        while (n-- > 0) {
            res += fastScanner.nextInt();
        }

        while (n2-- > 0) {
            int local = fastScanner.nextInt();
            if (max < local) {
                max = local;
            }
            res += local;
        }
        res -= max;
        out.println(res);
    }

    

    

    


    

    public static boolean isLocal = false;
    static FastScanner fastScanner = new FastScanner();
    static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

    public static void main(String[] args) {


        int N = fastScanner.nextInt();
        var example = new B();
        while (N-- > 0) {
            example.solve();
        }
        out.println();
        out.close();


        if (isLocal) {
            try {
                new B().buildFile();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        public FastScanner() {
            if (isLocal) {
                try {
                    File f = new File("src/sol_20_10_2022/input.txt");
                    this.br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
                } catch (FileNotFoundException e) {
                    throw new RuntimeException(e);
                }
            } else {
                this.br = new BufferedReader(new InputStreamReader(System.in));
            }
        }

        String next() {
            while (!st.hasMoreTokens()) try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

    }

    public void buildFile() throws IOException {

        File thisFile = new File("src/sol_20_10_2022/B.java");
        String s = "";
        try (FileReader reader = new FileReader(thisFile)) {
            int c;
            StringBuilder stringBuilder = new StringBuilder();
            while ((c = reader.read()) != -1) {
                stringBuilder.append((char) c);
            }
            s = stringBuilder.toString();
        }
        

        s = s.replace("// cout", "// cout");
        s = s.replace("// System.out.print", "// System.out.print");
        s = s.replace("// cout", "// cout");
        s = s.replace("// ronin", "// ronin");
        s = s.replace("public static boolean isLocal = false;", "public static boolean isLocal = false;");
        


        File file = new File("src/sol_20_10_2022/LastBuild.txt");
        if (!file.exists()) {
            file.createNewFile();
        }
        try (FileWriter writer = new FileWriter(file, false)) {
            writer.write(s);
            writer.flush();
        }

    }

    


    public <T> void sout(List<T> s) {
        for (T o : s) {
          

        }
    }

    public <T, V> void sout(Map<T, V> s) {
        for (T t : s.keySet()) {
          

        }
    }

    

    

    

    

    static class Pair<V, T> {
        private V a;
        private T b;

        public Pair(V a, T b) {
            this.a = a;
            this.b = b;
        }

        public V getA() {
            return a;
        }

        public T getB() {
            return b;
        }

        public Pair<V, T> setA(V a) {
            this.a = a;
            return this;
        }

        public Pair<V, T> setB(T b) {
            this.b = b;
            return this;
        }

        @Override
        public String toString() {
            return new StringJoiner(", ", Pair.class.getSimpleName() + "[", "]").add("a=" + a)
                    .add("b=" + b)
                    .toString();
        }
    }

    

    private boolean isEven(int a) {
        return (a & 1) == 0;
    }

    public static int id0(List<Integer> list, int val, boolean isSorted) {
        if (!isSorted) {
            Collections.sort(list);
        }
        int l = 0;
        int r = list.size();
        int m = 0;
        while (l < r) {
            m = (l + r) / 2;
            var cur = list.get(m);
            if (cur < val) {
                l = ++m;
                continue;
            }
            if (cur == val) return m;
            r = --m;
        }
        return m;
    }
}
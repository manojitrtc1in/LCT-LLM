import javax.management.NotificationEmitter;
import java.awt.*;
import java.io.*;

import java.sql.SQLOutput;
import java.util.*;
import java.util.List;

public class Stack2 {

    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    static Reader sc = new Reader();
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        process:
        for (int i = 0; i < t; i++) {
            int n = sc.nextInt();
            int[] ar = new int[n];
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < n; j++) {
                int num = sc.nextInt();
                list.add(num);
                ar[j] = num;
            }
            Collections.sort(list);
            


            Map<Integer, List<Integer>> map = new HashMap<>();
            int[] ceven = new int[100000 + 1];
            int[] codd = new int[100000 + 1];
            Map<Integer, List<Boolean>> mapb = new HashMap<>();
            for (int j = 0; j < n; j++) {
                int num = list.get(j);

                if(j%2==0){
                    ceven[num]++;
                }else{
                    codd[num]++;

                }
               
            }

            for (int j = 0; j < n; j++) {
                int num = ar[j];
                if(j%2==0){
                    if(ceven[num]>0){
                        ceven[num]--;
                    }else{
                        System.out.println("NO");
                        continue process;
                    }
                }else{
                    if(codd[num]>0){
                        codd[num]--;
                    }else{
                        System.out.println("NO");
                        continue process;
                    }
                }
               
                

            }
            System.out.println("YES");


        }


        bw.flush();
        bw.close();


    }

    public static class Haha {
        int value;
        int index;

        public Haha(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }


    static class Y implements Comparable<Y> {
        int data = 0;

        @Override
        public int compareTo(Y o) {
            return 0;
        }
    }


    public static long getAns(long n, int[] dollars, int[] euros) {
        if (n < dollars[0] && n < euros[0]) {
            return n;
        }

        long ans = Long.MAX_VALUE;
        for (int dollar : dollars) {
            if (dollar <= n)
                ans = Math.min(ans, getAns(n - (n / dollar) * dollar, dollars, euros));
            else
                break;
        }
        for (int euro : euros) {
            if (euro <= n)
                ans = Math.min(ans, getAns(n - (n / euro) * euro, dollars, euros));
            else
                break;
        }

        return ans;
    }

    public static boolean checkPrime(long n) {
        

        if (n == 0 || n == 1) {
            return false;
        }
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;


    }

    public static class Knights implements Comparable<Knights> {
        int power, coins;

        public Knights(int power, int coins) {
            this.power = power;
            this.coins = coins;
        }


        @Override
        public int compareTo(Knights o) {
            return this.power - o.power;
        }
    }


    public static void dfs(List<List<Integer>> lists, boolean[] vis, int i, Set<Integer> set, List<Set<Integer>> lists1) {
        

        vis[i] = true;
        set.addAll(lists1.get(i));

        for (Integer integer : lists.get(i)) {
            if (!vis[integer]) {
                set.add(integer);
                dfs(lists, vis, integer, set, lists1);
            }
        }

    }


    public static void bfs(int r, int c, Queue<int[]> queue, long[][] dis, char[][] map, boolean[][] visited) {
        while (!queue.isEmpty()) {
            int[] ar = queue.poll();
            int x = ar[0];
            int y = ar[1];
            if (x + 1 < r) {
                if (map[x + 1][y] != 'T' && dis[x + 1][y] > (dis[x][y] + 1)) {
                    dis[x + 1][y] = Math.min(dis[x + 1][y], (dis[x][y] + 1));
                    queue.add(new int[]{x + 1, y});
                } 
              


            }
            if (y + 1 < c) {
                if (map[x][y + 1] != 'T' && dis[x][y + 1] > (dis[x][y] + 1)) {
                    dis[x][y + 1] = Math.min(dis[x][y + 1], dis[x][y] + 1);
                    queue.add(new int[]{x, y + 1});
                } 
               


            }
            if (x - 1 >= 0) {
                if (map[x - 1][y] != 'T' && dis[x - 1][y] > (dis[x][y] + 1)) {
                    dis[x - 1][y] = Math.min(dis[x - 1][y], (dis[x][y] + 1));
                    queue.add(new int[]{x - 1, y});
                } 
               


            }
            if (y - 1 >= 0) {
                if (map[x][y - 1] != 'T' && dis[x][y - 1] > (dis[x][y] + 1)) {
                    dis[x][y - 1] = Math.min(dis[x][y - 1], (dis[x][y] + 1));
                    queue.add(new int[]{x, y - 1});
                } 
               


            }
        }
    }


    public static void dfs1(List<List<Integer>> g, boolean[] visited, Stack<Integer> stack, int num) {
        visited[num] = true;
        for (Integer integer : g.get(num)) {
            if (!visited[integer]) {
                dfs1(g, visited, stack, integer);
            }
        }
        stack.push(num);
    }

    public static void dfs2(List<List<Integer>> g, boolean[] visited, List<Integer> list, int num, int c, int[] raj) {
        visited[num] = true;

        for (Integer integer : g.get(num)) {
            if (!visited[integer]) {
                dfs2(g, visited, list, integer, c, raj);
            }
        }
        raj[num] = c;
        list.add(num);

    }

    public static int inputInt() throws IOException {
        return sc.nextInt();
    }

    public static long inputLong() throws IOException {
        return sc.nextLong();
    }

    public static double inputDouble() throws IOException {
        return sc.nextDouble();
    }

    public static String inputString() throws IOException {
        return sc.readLine();
    }

    public static void print(String a) throws IOException {
        bw.write(a);
    }

    public static void printSp(String a) throws IOException {
        bw.write(a + " ");
    }

    public static void println(String a) throws IOException {
        bw.write(a + "\n");
    }


    public static long getAns(int[] ar, int c, long[][] dp, int i, int sign) {
        if (i < 0) {
            return 1;
        }

        if (c <= 0) {
            return 1;
        }

        dp[i][c] = Math.max(dp[i][c], Math.max(ar[i] * getAns(ar, c - 1, dp, i - 1, sign), getAns(ar, c, dp, i - 1, 1)));
        return dp[i][c];
    }


    public static long power(long a, long b, long c) {
        long ans = 1;
        while (b != 0) {
            if (b % 2 == 1) {
                ans = ans * a;
                ans %= c;
            }
            a = a * a;
            a %= c;
            b /= 2;
        }
        return ans;
    }

    public static long power1(long a, long b, long c) {
        long ans = 1;
        while (b != 0) {
            if (b % 2 == 1) {
                ans = multiply(ans, a, c);
            }
            a = multiply(a, a, c);
            b /= 2;

        }
        return ans;

    }

    public static long multiply(long a, long b, long c) {
        long res = 0;
        a %= c;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res + a) % c;
            }
            a = (a + a) % c;
            b /= 2;
        }

        return res % c;

    }

    public static long totient(long n) {
        long result = n;
        for (long i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                

                while (n % i == 0) {
                    n /= i;
                    

                }
                result -= result / i;

            }
        }
        if (n > 1) {
            result -= result / n;

        }
        return result;
    }


    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    public static boolean[] primes(int n) {
        boolean[] p = new boolean[n + 1];
        p[0] = false;
        p[1] = false;
        for (int i = 2; i <= n; i++) {
            p[i] = true;
        }

        for (int i = 2; i * i <= n; i++) {
            if (p[i]) {
                for (int j = i * i; j <= n; j += i) {
                    p[j] = false;
                }
            }

        }
        return p;
    }

    static void bogoSort(int[] a, int c) {
        

        

        while (isSorted(a) == false) {
            c++;
            shuffle(a);
        }

    }

    

    static void shuffle(int[] a) {
        

        

        

        for (int i = 1; i <= a.length; i++)
            swap(a, i, (int) (Math.random() * i));
    }

    

    static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    

    static boolean isSorted(int[] a) {
        for (int i = 1; i < a.length; i++)
            if (a[i] < a[i - 1])
                return false;
        return true;
    }


}


class Node {
    int data;
    Node next;
}
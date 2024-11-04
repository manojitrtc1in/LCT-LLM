

import java.io.*;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;

public class Main {

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
            din = new DataInputStream(
                    new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    } else {
                        continue;
                    }
                }
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
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
            } while ((c = read()) >= '0' && c <= '9');
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
            } while ((c = read()) >= '0' && c <= '9');

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
            bytesRead = din.read(buffer, bufferPointer = 0,
                    BUFFER_SIZE);
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





    




















































































































































































































































































































    static boolean ff = false;

    
























































































































































































    












































    












































































































































































































    static long gcd(long a, long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }







































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































    static class point {
        int val;
        String name;

    }

    static class comp implements Comparator<point> {
        public int compare(point a, point b) {
            return a.val - b.val;
        }
    }

    































































































































































































































































































































































































































































































    static int[] prime;

    static void sieveOfEratosthenes(int n) {
        boolean primes[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            primes[i] = true;

        for (int p = 2; p * p <= n; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= n; i += p) {
                    primes[i] = false;
                    prime[i] = 0;
                }
            }
        }


        for (int i = 3; i <= n; i++) {
            prime[i] = prime[i - 1] + prime[i];
        }
    }





































































































































    static class com implements Comparator<long[]> {
        public int compare(long[] a, long[] b) {
            return Long.compare(a[0], b[0]);
        }
    }

    static class comm implements Comparator<long[]> {
        public int compare(long[] a, long[] b) {
            return Long.compare(a[1], b[1]);
        }
    }

    static int root(int a, int[] num) {
        while (a != num[a]) {
            num[a] = num[num[a]];
            a = num[a];
        }
        return a;
    }

    static int roott(int a, int num[]) {
        while (a != num[a]) {
            num[a] = num[num[a]];
            a = num[a];
        }
        return a;
    }

    static class compa implements Comparator<int[]> {
        public int compare(int[] a, int[] b) {
            return a[0] - b[0];
        }
    }

    static void maxx(int src, int d, int parent, LinkedList<Integer>[] lin) {
        if (d % 2 == 0) {
            even.add(src);
        } else {
            odd.add(src);
        }
        for (Integer v : lin[src]) {
            if (v != parent) {
                maxx(v, d + 1, src, lin);
            }
        }
    }

    static boolean fff = false;

    static void mmax(String str, int start, int end, int ind) {
        if (start < 0 && end >= str.length()) {
            fff = true;
            return;
        }
        char ch = (char) (ind + 'a');
        if (start >= 0 && str.charAt(start) == ch) {
            mmax(str, start - 1, end, ind + 1);
        }
        if (start == end) {
            return;
        }
        if (end < str.length() && str.charAt(end) == ch) {
            mmax(str, start, end + 1, ind + 1);
        }
    }

    static HashSet<Integer> odd, even;
    static long maxx(int x,int y,int[][] a ,long c,int flag){
        if(aa[x][y][flag]!=-1){
            return aa[x][y][flag];
        }
        if(flag==0){
            long min = Long.MAX_VALUE;
            if (x + 1 < a.length) {
                min = Math.min((long)((long)maxx(x+1,y,a,c,1)+(long)c+(long)a[x][y]), (long)maxx(x + 1, y, a, c,0) );
            }

            if (y + 1 < a[0].length) {
                min = Math.min(min,(long)maxx(x, y + 1, a, c,0) );
                min = Math.min(min,(long)((long)maxx(x,y+1,a,c,1)+(long)c+(long)a[x][y]) );
            }


            return aa[x][y][flag]=min;

        }else {
            long min = (long)a[x][y];
            if (x + 1 < a.length) {
                min = Math.min(min, (long)((long)maxx(x + 1, y, a, c,1) + (long)c));
            }

            if (y + 1 < a[0].length) {
                min = Math.min(min, (long)((long)maxx(x, y + 1, a, c,1) + (long) c) );
            }
            return aa[x][y][flag]=min;
        }


    }
    static long[][][] aa;


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String stt = br.readLine().trim();
        int t = Integer.parseInt(stt);








          for(int j=0;j<t;j++){
              String str=br.readLine().trim();
              String string=br.readLine().trim();











                  int i=0;
                  int k=0;
                  int ff=0;
                  while(k<str.length()){
                      if(str.charAt(k)==string.charAt(i) && k%2==ff%2){
                          i++;
                          ff++;
                      }
                      if(i==string.length() && (str.length()-k-1)%2!=0){
                          i--;
                          ff--;

                      }
                      if(i==string.length()){
                          break;
                      }
                      k++;
                  }
                  if(i==string.length()){
                      System.out.println("YES");
                  }else{
                      i=0;
                      k=0;
                      ff=1;
                      while(k<str.length()){
                          if(str.charAt(k)==string.charAt(i) && k%2==ff%2){
                              i++;
                              ff++;
                          }
                          if(i==string.length() && (str.length()-k-1)%2!=0){
                              i--;
                                ff--;
                          }
                          if(i==string.length()){
                              break;
                          }
                          k++;
                      }
                      if(i==string.length()){
                          System.out.println("YES");
                      }else {
                          System.out.println("NO");
                      }


              }
























































          }



    }
    static int[][][] dp;
    static int maxx(int ind,int tot,int tot1,String str){
        if(ind>=str.length()){
            return 0;
        }
        if(dp[ind][tot][tot1]!=-1){
            return dp[ind][tot][tot1];
        }
        if(ind%2==0){
            int t=0;
            int t1=0;
            for(int i=ind;i<str.length();i++){
                if(i%2==0 ){
                    t++;
                }else {
                    t1++;
                }
            }
            if(t+tot<tot1){
                return dp[ind][tot][tot1]=0;
            }
            if(t1+tot1<tot){
                return dp[ind][tot][tot1]=0;
            }
            if(str.charAt(ind)=='0'){
                return dp[ind][tot][tot1]=maxx(ind+1,tot,tot1,str)+1;
            }else if(str.charAt(ind)=='1'){
                return dp[ind][tot][tot1]=maxx(ind+1,tot+1,tot1,str)+1;
            }else{
                return dp[ind][tot][tot1]=Math.min(maxx(ind+1,tot,tot1,str)+1,maxx(ind+1,tot+1,tot1,str)+1);
            }
        }else{
            int t=0;
            int t1=0;
            for(int i=ind;i<str.length();i++){
                if(i%2==0 ){
                    t++;
                }else {
                    t1++;
                }
            }
            if(t+tot<tot1){
                return dp[ind][tot][tot1]=0;
            }
            if(t1+tot1<tot){
                return dp[ind][tot][tot1]=0;
            }
            if(str.charAt(ind)=='0'){
                return dp[ind][tot][tot1]=maxx(ind+1,tot,tot1,str)+1;
            }else if(str.charAt(ind)=='1'){
                return dp[ind][tot][tot1]=maxx(ind+1,tot,tot1+1,str)+1;
            }else{
                return dp[ind][tot][tot1]=Math.min(maxx(ind+1,tot,tot1+1,str)+1,maxx(ind+1,tot,tot1,str)+1);
            }
        }
    }
    static boolean ffa=false;






































    static int[][][] aaa;
    static class comp2 implements Comparator<long[]>{
        @Override
        public int compare(long[] o1, long[] o2) {
            return Long.compare(o2[2],o1[2]);
        }
    }


}













import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.*;

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
    static void dfs(int x,int y){
        int[][] dis=new int[][]{{0,1},{1,0},{0,-1},{-1,0}};
        for(int j=0;j<dis.length;j++){
            if(valid(dis[j][0]+x,dis[j][1]+y)){
                vis[x+dis[j][0]][y+dis[j][1]]=true;
                dfs(x+dis[j][0],y+dis[j][1]);
            }
        }
    }
    static boolean valid(int x,int y){
        if(x<0 || y<0 || x>=stringBuilders.length || y>=stringBuilders[0].length() || vis[x][y] ){
            return false;
        }
        return true;
    }
    static boolean valid1(int x,int y){
        if(x<0 || y<0 || x>=stringBuilders.length || y>=stringBuilders[0].length() || vis1[x][y]  ){
            return false;
        }
        return true;
    }
    static boolean[][] vis,vis1;
    static HashSet<StringBuilder[]> hashSet;
    public interface Flyer { int j =5;}
    static StringBuilder[] stringBuilders;
    static int k=0;
    static void sieveOfEratosthenes(int n) {
        boolean primes[] = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            primes[i] = true;

        for (int p = 2; p * p <= n; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= n; i += p) {
                    primes[i] = false;

                }
            }
        }


        for (int i = 2; i <= n; i++) {
            if(primes[i]){
                pr.add(i);
            }
        }
    }

    static long maxx(int ind,int k,long t1,long t2,int flag){
        if(ind==k){
            return 1l;
        }
        if(dpp[ind][flag]!=-1){
            return dpp[ind][flag];
        }
        if(flag==0){
            return  dpp[ind][flag]= (long)((long)((long)maxx(ind+1,k,t1,t2,0)*(long)t1)%(long)mod+(long)((long)maxx(ind+1,k,t1,t2,1)*(long)1)%mod)%mod;
        }else{
            return  dpp[ind][flag]= (long)((long)((long)maxx(ind+1,k,t1,t2,1)*(long)t2)%(long)mod);
        }
    }
    static long maxx(int ind,int k,int flag){
        if(ind==k){
            if(flag==0){
                return 0l;
            }
            return 1l;
        }
        if(dpp[ind][flag]!=-1){
            return dpp[ind][flag];
        }
        if(flag==0) {
            return dpp[ind][flag] = (long) ((long) maxx(ind + 1, k,0) + (long) maxx(ind + 1, k,1)) % mod;
        }else{
            return dpp[ind][flag] = (long) ((long) maxx(ind + 1, k,1)*2l ) % mod;

        }
    }
    static long mod=(long)((long)Math.pow(10,9)+(long)7);
    static List<Integer> pr;
    static long[][] dpp;

    static class comps implements Comparator<int[]> {
        public int compare(int[] a,int[] b){

                return a[0]-b[0];

        }
    }

    public static int maxEvents(int[][] events) {


        PriorityQueue<Integer> pq=new PriorityQueue<>();









        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        int i=0;
        int tot=0;
        int d=-1;
        while(!pq.isEmpty() || i<events.length ){
            if(pq.isEmpty()){
                d=events[i][0];
            }
            while(i<events.length && events[i][0]<=d ){
                pq.add(events[i][1]);
                i++;
            }
            pq.poll();
            d++;
            tot++;
            while(!pq.isEmpty() && pq.peek()<d){
                pq.poll();
            }
        }
        return tot;
    }

   


    public static void main(String[] args) throws IOException {



        
        Scanner s = new Scanner(System.in);



        int t = s.nextInt();

        for(int j=0;j<t;j++){
          int n = s.nextInt();
          String str=s.next();
          String[] ans=new String[n];
          for(int i=0;i<ans.length;i++){
              ans[i]="";
          }
          int ff=0;
          for(int i=0;i<n;i++){
              if(str.charAt(i)=='1'){
                  for(int k=0;k<n;k++){
                      if(i==k){
                          ans[i] = ans[i].concat("X");
                      }else {
                          ans[i] = ans[i].concat("=");
                      }
                  }
              }else{
                  int flag=0;
                  for(int k=0;k<n;k++){
                      if(i==k){
                          ans[i] = ans[i].concat("X");
                      }else{
                          if(k<i){
                              if(ans[k].charAt(i)=='='){
                                  ans[i]=ans[i].concat("=");
                              }else if(ans[k].charAt(i)=='-'){
                                  ans[i]=ans[i].concat("+");
                                  flag=1;
                              }else{
                                  ans[i]=ans[i].concat("-");
                              }
                          }else{
                              if(flag==0){
                                  if( str.charAt(k)=='1' ){
                                      ans[i]=ans[i].concat("=");
                                  }else{
                                      ans[i]=ans[i].concat("+");
                                      flag=1;
                                  }
                              }else{
                                  if( str.charAt(k)=='1' ){
                                      ans[i]=ans[i].concat("=");
                                  }else{
                                      ans[i]=ans[i].concat("-");
                                  }
                              }
                          }
                      }
                  }
                  if(flag==0){
                      System.out.println("NO");
                      ff=1;
                      break;
                  }
              }
          }
          if(ff==0){
              System.out.println("YES");
              for(int jj=0;jj<ans.length;jj++){
                  System.out.println(ans[jj]);
              }
          }


        }





       


        
























































































        


    }
    static long[][][] dp;
    static long maxx(int x,int y,int y1,int[][] num){
        int x1=x+y-y1;
        if(x1==num.length-1 && y1==num[0].length-1){
            return 0;
        }






        long res=0;
        if(x1 != x){
            res=num[x1][y1];
        }
        long max=Integer.MAX_VALUE;
        if(x+1<num.length && y1+1<num[0].length){
            max=maxx(x+1,y,y1+1,num);
        }
        if(x+1<num.length && x1+1<num.length){
            max=Math.min(max,maxx(x+1,y,y1,num));
        }
        if(y+1<num[0].length && x1+1<num.length){
            max=Math.min(max,maxx(x,y+1,y1,num));
        }
        if(y+1<num[0].length && y1+1<num[0].length){
            max=Math.min(max,maxx(x,y+1,y1+1,num));
        }
        if(max==Integer.MAX_VALUE){
            return dp[x][y][y1]=res;
        }
        return dp[x][y][y1]=max+res;


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












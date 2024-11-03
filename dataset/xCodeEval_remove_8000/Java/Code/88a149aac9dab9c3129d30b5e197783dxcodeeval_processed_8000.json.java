

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

    static void id0(int n) {
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
    static HashSet<String> set;
    static long maxx(int ind,int sum){
        if(sum==0){
            return 0;
        }
        if(sum<0){
            return Integer.MAX_VALUE;
        }
        if(aa[ind][sum]!=-1){
            return aa[ind][sum];
        }
        return aa[ind][sum]=Math.min(maxx(ind+1,sum-ind)+1,maxx(ind+2,sum-ind)+1);
    }
    static long[][] aa;

    public static void main(String[] args) throws IOException {









          Reader s=new Reader();
          int t=s.nextInt();
          for(int j=0;j<t;j++){
            int n=s.nextInt();
            int[] arr=new int[n+1];
            int[] arrr=new int[n+1];
            PriorityQueue<Integer> priorityQueue=new PriorityQueue<>();
            HashSet<Integer> hashSet=new HashSet<>();
            for(int i=1;i<=n;i++){
                arr[i]=s.nextInt();
                arrr[i]=arr[i];
                hashSet.add(arr[i]);
            }
            for(int i=1;i<=n;i++){
                if(!hashSet.contains(i)) {
                    priorityQueue.add(i);
                }
            }
            HashSet<Integer> id1=new HashSet<>();
              StringBuilder stringBuilder=new StringBuilder();
              HashMap<Integer,Integer> hashMap=new HashMap<>();
            for(int i=1;i<=n;i++){
                if(id1.contains(arr[i])){
                    if(priorityQueue.peek()==i){
                        int tt=priorityQueue.poll();
                        if(priorityQueue.isEmpty()){
                          arr[hashMap.get(arr[i])]=tt;
                          id1.add(tt);
                        }else {
                            arr[i] = priorityQueue.poll();
                            priorityQueue.add(tt);
                        }
                    }else{
                        arr[i]=priorityQueue.poll();
                    }
                    

                    


                }

                id1.add(arr[i]);
                hashMap.put(arr[i],i);

            }
            int co=0;
            for(int i=1;i<=n;i++){
                if(arrr[i]==arr[i]){co++;}
                stringBuilder.append(arr[i]+" ");
            }
              System.out.println(co);
              System.out.println(stringBuilder.toString().trim());


          }

    }
    static class comp2 implements Comparator<long[]>{
        @Override
        public int compare(long[] o1, long[] o2) {
            return Long.compare(o2[2],o1[2]);
        }
    }


}
































































































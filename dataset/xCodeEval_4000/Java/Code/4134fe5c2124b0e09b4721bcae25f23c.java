

import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

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





    



































































































































































































































































































    static class comp implements Comparator<Point> {
        public int compare(Point a, Point b) {
            if (b.y == a.y) {
                return a.x - b.x;
            }
            return b.y - a.y;
        }
    }

    static boolean ff = false;

    



























































































































































    static class point {
        int w, v;

        point(int v, int w) {
            this.v = v;
            this.w = w;
        }
    }

    static class compp implements Comparator<point> {
        public int compare(point a, point b) {
            return b.v - a.v;
        }
    }

    











































    static List<Integer> findprime(int n) {
        List<Integer> primes = new ArrayList<>();
        boolean[] prime = new boolean[n];
        for (int j = 1; j < prime.length; j++) {
            prime[j] = true;
        }
        for (int j = 2; j * j < prime.length; j++) {
            if (!prime[j]) {
                continue;
            }
            for (int i = j * j; i < prime.length; i = i + j) {
                prime[i] = false;
            }
        }
        for (int j = 2; j < prime.length; j++) {
            if (prime[j]) {
                primes.add(j);
            }
        }
        return primes;
    }

    







































































    static long[][] aaa;

    static long maxx(String str, int n, long val) {

        if (hashMap.get(str) != null) {
            return hashMap.get(str);
        }
        long tot = 0;
        if (str.equals("")) {
            for (int j = 1; j <= 9; j++) {
                tot = tot + maxx(str + String.valueOf(j), n, val);
            }
            hashMap.put(str, tot);

            return tot;
        } else {
            String ss = str + str;
            if (Long.parseLong(ss) > val) {
                return 0;
            }
            if (str.length() == n) {
                return 1;
            }
            for (int j = 0; j <= 9; j++) {
                tot = tot + maxx(str + String.valueOf(j), n, val);
            }
            hashMap.put(str, tot);
            return tot;
        }

    }

    static class poi {
        int freq, occur, num;

        poi(int freq, int occur, int num) {
            this.freq = freq;
            this.num = num;
            this.occur = occur;
        }
    }

    static class poii {
        int day, tot;

        poii(int day, int tot) {
            this.day = day;
            this.tot = tot;
        }
    }

    static class comp2 implements Comparator<poii> {
        public int compare(poii a, poii b) {
            return a.tot - b.tot;
        }
    }

    static class comp1 implements Comparator<poi> {
        @Override
        public int compare(poi o1, poi o2) {
            if (o2.occur == o1.occur) {
                return o1.freq - o2.freq;
            }
            return o1.occur - o2.occur;
        }
    }

    static int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static HashMap<String, Long> hashMap;

    static class poit {
        int freq, val;

        poit(int freq, int val) {
            this.freq = freq;
            this.val = val;
        }
    }

    static class com implements Comparator<poit> {
        public int compare(poit a, poit b) {
            return b.freq - a.freq;
        }
    }

    public static void main(String[] args) throws IOException {
        Reader s = new Reader();
        int t = s.nextInt();
        for (int j = 0; j < t; j++) {
            int n = s.nextInt();
            HashMap<Integer, Integer> has = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int arr = s.nextInt();
                has.put(arr, has.getOrDefault(arr, 0) + 1);
            }
            PriorityQueue<poit> poits1=new PriorityQueue<>(new com());

            for (Integer i : has.keySet()) {
                poits1.add(new poit(has.get(i), i));

            }
            int tot = 0;

            while (!poits1.isEmpty()){
                poit pt=poits1.poll();
                if(poits1.isEmpty()){
                    tot=pt.freq;break;
                }


                        pt.freq--;
                        poit temp = poits1.poll();
                        if (temp.freq - 1 == 0 && pt.freq==0) {

                        }
                       else if(temp.freq-1==0){
                            poits1.add(new poit(pt.freq , pt.val));
                        }
                       else if(pt.freq==0){
                            poits1.add(new poit(temp.freq - 1, temp.val));
                        }else{
                            poits1.add(new poit(pt.freq , pt.val));
                            poits1.add(new poit(temp.freq - 1, temp.val));
                        }




                    }




            System.out.println(tot);
        }






    }
}








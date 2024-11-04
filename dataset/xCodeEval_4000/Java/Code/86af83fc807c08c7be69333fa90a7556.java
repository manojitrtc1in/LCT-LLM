

import java.awt.*;
import java.io.*;
import java.util.List;
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

    static long gcd(long a, long b) {
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






































































































































































































































































































































































    static List<Integer> ans=new ArrayList<>();
    static void goodVertices(LinkedList<Integer>[] linkedLists,int src,int parent,HashSet<Integer> hashSet,int[] cost){

        int flag=0;
        if(!hashSet.contains(cost[src])){
            hashSet.add(cost[src]);
            ans.add(src+1);
            flag=1;
        }
        for(Integer i:linkedLists[src]){
            if(i==parent){
                continue;
            }
            goodVertices(linkedLists,i,src,hashSet,cost);
        }
        if(flag==1){
            hashSet.remove(cost[src]);
        }

    }
    static boolean fla=false;
    static void calculate(String[] str,int flag,String str1,String str2){
        if(flag==0){
            if(str[0].length()==str1.length()){
                calculate(str,1,str1,str2);
                return;
            }
            for(int j=0;j<=9;j++){
                if( j==0 && str1.equals("") ){
                    continue;
                }
                calculate(str,1,str1+String.valueOf(j),str2);
                if(fla){
                    break;
                }
            }
        }
        else if(flag==1){
            if(str[1].length()==str2.length()){
                calculate(str,2,str1,str2);
                return;
            }
            int ind=str2.length();
            if( str[0].length()>ind && str[0].charAt(ind)==str[1].charAt(ind)){
                calculate(str,1,str1,str2+String.valueOf(str1.charAt(ind)));
            }else{
                for(int j=0;j<=9;j++){
                    if(j==0 && str2.equals("")){
                        continue;
                    }
                    calculate(str,1,str1,str2+String.valueOf(j));
                }
            }
        }
        else{
            long n1=Long.parseLong(str1);
            long n2=Long.parseLong(str2);
            long n3=(long)((long)n1+(long)n2);
            if(String.valueOf(n3).length()==str[2].length()){

            }

        }
    }

    public static void main(String[] args) throws IOException {

        Reader scanner=new Reader();
        int n=scanner.nextInt();
        int k=scanner.nextInt();
        HashSet<String> hashSet=new HashSet<>();
        StringBuilder stringBuilder=new StringBuilder("a");
        StringBuilder temp=new StringBuilder("a");
        StringBuilder prev=new StringBuilder("");
        HashMap<String,Integer> hashMap=new HashMap<>();
        for(int j=1;j<n;j++){
            int flag=0;
            int min=Integer.MAX_VALUE;
            int in=-1;
            for(int i=0;i<k;i++){
                char ch=(char)('a'+i);
                StringBuilder st=new StringBuilder(temp);
                st.append(ch);
                

                if(hashMap.getOrDefault(st.toString(),0)<=min){
                    min=hashMap.getOrDefault(st.toString(),0);
                    in=i;
                }










            }


                char ch=(char)('a'+in);
                StringBuilder st=new StringBuilder(temp);
                st.append(ch);
                hashMap.put(st.toString(),hashMap.getOrDefault(st.toString(),0)+1);
                stringBuilder.append(ch);
                temp=new StringBuilder();
                temp.append(ch);

        }
        System.out.println(stringBuilder.toString().trim());








        

        {













































































































            }






        }








    }









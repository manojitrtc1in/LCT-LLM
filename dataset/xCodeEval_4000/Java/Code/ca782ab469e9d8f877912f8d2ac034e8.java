

import java.awt.*;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
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


    static int maxx(int ind,String str,int prev,int x,int y){
        if(ind>=str.length()){
            return 0;}
        if(aa[ind][prev]!=Integer.MAX_VALUE){
            return aa[ind][prev];}
        if(str.charAt(ind)=='?' ){
            if(ind>0){
                if(prev==1){
                    if( ind+1 < str.length() && str.charAt(ind+1) == 'C' ){
                             return aa[ind][prev]=Math.min(maxx(ind+1,str,1,x,y),maxx(ind+1,str,2,x,y)+x+y );

                    }
                    else if(ind+1<str.length() && str.charAt(ind+1)=='J' ){
                        return aa[ind][prev]=Math.min(maxx(ind+1,str,1,x,y)+x,maxx(ind+1,str,2,x,y)+x );

                    }
                    else if(ind+1<str.length() && str.charAt(ind+1)=='?'){
                        return aa[ind][prev]=  Math.min(maxx(ind+1,str,1,x,y),maxx(ind+1,str,2,x,y)+x );
                    }
                    else{
                        return aa[ind][prev]=Math.min(maxx( ind+1,str,1,x,y ),maxx(ind+1,str,2,x,y)+x);
                    }

                }
                else{
                    if( ind+1 < str.length() && str.charAt(ind+1) == 'C' ){
                        return aa[ind][prev]=Math.min(maxx(ind+1,str,1,x,y)+y,maxx(ind+1,str,2,x,y)+y );

                    }
                    else if(ind+1<str.length() && str.charAt(ind+1)=='J' ){
                        return aa[ind][prev]=Math.min(maxx(ind+1,str,1,x,y)+x+y,maxx(ind+1,str,2,x,y) );

                    }
                    else if(ind+1<str.length() && str.charAt(ind+1)=='?'){
                        return aa[ind][prev]=  Math.min(maxx(ind+1,str,1,x,y)+y,maxx(ind+1,str,2,x,y) );
                    }
                    else{
                        return aa[ind][prev]=Math.min(maxx( ind+1,str,1,x,y )+y,maxx(ind+1,str,2,x,y));
                    }
                }
            }
            else{
                if( ind+1 < str.length() && str.charAt(ind+1) == 'C' ){
                    return aa[ind][prev]=Math.min(maxx(ind+1,str,1,x,y),maxx(ind+1,str,2,x,y)+x );

                }
                else if(ind+1<str.length() && str.charAt(ind+1)=='J' ){
                    return aa[ind][prev]=Math.min(maxx(ind+1,str,1,x,y)+x,maxx(ind+1,str,2,x,y) );

                }
                else if(ind+1<str.length() && str.charAt(ind+1)=='?'){
                    return aa[ind][prev]=  Math.min(maxx(ind+1,str,1,x,y),maxx(ind+1,str,2,x,y) );
                }
                else{
                    return aa[ind][prev]=0;
                }
            }
        }else if(str.charAt(ind)=='C'){
            if( ind+1 < str.length() && str.charAt(ind+1) == 'C' ){
                return aa[ind][prev]=maxx(ind+1,str,1,x,y);

            }
            else if(ind+1<str.length() && str.charAt(ind+1)=='J' ){
                return aa[ind][prev]=maxx(ind+1,str,1,x,y)+x;

            }
            else if(ind+1<str.length() && str.charAt(ind+1)=='?'){
                return aa[ind][prev]=  maxx(ind+1,str,1,x,y);
            }
            else{
                return aa[ind][prev]=0;
            }
        }
        else{
            if( ind+1 < str.length() && str.charAt(ind+1) == 'C' ){
                return aa[ind][prev]=maxx(ind+1,str,2,x,y)+y;

            }
            else if(ind+1<str.length() && str.charAt(ind+1)=='J' ){
                return aa[ind][prev]=maxx(ind+1,str,2,x,y);

            }
            else if(ind+1<str.length() && str.charAt(ind+1)=='?'){
                return aa[ind][prev]=  maxx(ind+1,str,2,x,y);
            }
            else{
                return aa[ind][prev]=0;
            }
        }
    }
    static int[][] aa;
    static int totalCost(int[] arr,int[] arr1,int n){
        HashMap<Integer,Integer> has=new HashMap<>();
        for(int i=0;i<n;i++){

            has.put(arr[i],i );

        }
        Arrays.sort(arr1);
        int tot=0;
        for(int i=0;i<n-1;i++){
            tot=tot+has.get(arr1[i])-i+1;
            int tta=has.get(arr1[i]);
            for(int j=tta;j>=i;j-- ){
                has.put(arr[j],tta-j+i );

            }
            int low=i;
            int high=tta;
            while(low<high){
                int temp=arr[low];
                arr[low]=arr[high];
                arr[high]=temp;
                low++;high--;
            }

        }
        return tot;

    }
    static boolean fff=false;
    static HashSet<String> hashSet=new HashSet<>();
    static void maxx(int ind,int[] arr,HashSet<Integer> has,int n,String str,int cost){
        if(ind==n){
            int to=totalCost(arr,arr,n);
            if(to==cost){
                fff=true;
            }
            return;
        }
        if(hashSet.contains(str)){
            return ;
        }
        for(int j=1;j<=n;j++){
            if(!has.contains(j)){
                arr[ind]=j;
                has.add(j);
                maxx(ind+1,arr,has,n,str+String.valueOf(j),cost);
                has.remove(j);
            }
            if(ff){
                return;
            }
        }
    }
    static long maxx(int ind,int n,int flag,int k){
        if(ind>n || ind<0 || k==1){
            return 0;
        }
        if(flag==1 && ind==0){
            return 0;
        }
        if(aaaa[ind][flag][k]!=-1) {
            return aaaa[ind][flag][k];
        }
        if(flag==0){
            return aaaa[ind][flag][k]=(long)(maxx(ind-1,n,1,k-1)+(long)1+maxx(ind+1,n,0,k))%(long)mod;
        }
        else{
            return aaaa[ind][flag][k]=(long)(maxx(ind+1,n,0,k-1)+(long)1+maxx(ind-1,n,1,k))%(long)mod;
        }

    }
    static long[][][] aaaa;
    static long mod=(long)((long)Math.pow(10,9)+(long)7);
    public static void main(String[] args) throws IOException {
        Reader scanner=new Reader();
        int t= scanner.nextInt();
        for(int j=0;j<t;j++){
            int n= scanner.nextInt();
            int k=scanner.nextInt();
            if(k==1){
                System.out.println(1);continue;
            }
            aaaa=new long[n+1][2][k+1];
            for(int i=0;i<=n;i++){
                for(int l=0;l<2;l++){
                    Arrays.fill(aaaa[i][l],-1);
                }
            }
            System.out.println(maxx(0,n,0,k));


        }








    }
}







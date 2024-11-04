
import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "" ;
    boolean local = false;
    int inf=0x7FFFFFFF;
    int MOD2=(int)(1e9+7);
    int n;
    int [][]a;
    double calc(double arc){
        double ret=0;
        for(int i=0;i<n;i++){
            double ans=0;
            double a1=(a[i][0]+arc)/2;
            double a2=a[i][1]/2.0;
            double k1=a[i][1]/(a[i][0]-arc);
            double k2=-1/k1;
            ans=a2+(arc-a1)*k2;
            ret=Math.max(ret,ans);
        }
        return ret;
    }
    void solve() {
        n=ni();
        a=new int[n][2];
        boolean up=false,down=false;
        for(int i=0;i<n;i++){
            a[i][0]=ni();
            a[i][1]=ni();
            if(a[i][1]>0)up=true;
            if(a[i][1]<0)down=true;
            a[i][1]=Math.abs(a[i][1]);
        }
        if(up&&down)out.println(-1);
        else{
            double L=-3e7,R=3e7;
            while(Math.abs(R-L)>1e-7){
                double midl=L+(R-L)/3;
                double midr=R-(R-L)/3;
                double ansl=calc(midl);
                double ansr=calc(midr);
                if(ansl>ansr)L=midl;
                else R=midr;
            }
            out.printf("%.7f",calc(L));
        }
    }
    public class Node implements Comparable{
        public int x,y;
        public Node(int x,int y){
            this.x=x;
            this.y=y;
        }
        public int compareTo(Object o) {
            Node to=(Node)o;
            if(this.x>to.x) return 1;
            else if(this.x==to.x) return 0;
            else return -1;
        }
        public void show(){
            out.println(x+" "+y);
        }
    }
    long[] id0(long a, long b) {
        if (b == 0) return new long[]{1,0,a};
        long[] res = id0(b, a%b);
        long t = res[0]; res[0] = res[1]; res[1] = t;
        res[1] -= a/b*res[0];
        return res;
    }
    long gcd(long a,long b){
        return b==0?a:gcd(b,a%b);
    }
    long lcm(long a,long b){
        return a*b/gcd(a,b);
    }
    private void run() {
        is = local? new ByteArrayInputStream(INPUT.getBytes()):System.in;
        out = new PrintWriter(System.out);
        long s = System.currentTimeMillis();
        solve();
        out.flush();
        tr(System.currentTimeMillis()-s+"ms");
    }
    public static void main(String[] args) throws Exception { new Main().run(); }
    private byte[] inbuf = new byte[1024];
    public int lenbuf = 0, ptrbuf = 0;
    private int readByte(){
        if(lenbuf == -1)throw new InputMismatchException();
        if(ptrbuf >= lenbuf){
            ptrbuf = 0;
            try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
            if(lenbuf <= 0)return -1;
        }
        return inbuf[ptrbuf++];
    }
    private boolean id1(int c) { return !(c >= 33 && c <= 126); }
    private int skip() { int b; while((b = readByte()) != -1 && id1(b)); return b; }
    private double nd() { return Double.parseDouble(ns()); }
    private char nc() { return (char)skip(); }
    private String ns(){
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while(!(id1(b))){ 

            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    private char[] ns(int n){
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while(p < n && !(id1(b))){
            buf[p++] = (char)b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }
    private char[][] nm(int n, int m){
        char[][] map = new char[n][];
        for(int i = 0;i < n;i++)map[i] = ns(m);
        return map;
    }
    private int[] na(int n){
        int[] a = new int[n];
        for(int i = 0;i < n;i++)a[i] = ni();
        return a;
    }
    private int ni(){
        int num = 0, b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    private long nl(){
        long num = 0;
        int b;
        boolean minus = false;
        while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
        if(b == '-'){
            minus = true;
            b = readByte();
        }
        while(true){
            if(b >= '0' && b <= '9'){
                num = num * 10 + (b - '0');
            }else{
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
    private void tr(Object... o) { if(local)System.out.println(Arrays.deepToString(o)); }
}
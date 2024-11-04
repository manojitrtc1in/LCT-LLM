
import java.io.*;
import java.util.*;
import java.math.*;
public class Main {
    InputStream is;
    PrintWriter out;
    String INPUT = "";
    boolean local = false;
    void solve() {
        int n=ni();
        int []px1=new int[n+2],py1=new int[n+2],px2=new int[n+2],py2=new int[n+2];
        int []sx1=new int[n+2],sy1=new int[n+2],sx2=new int[n+2],sy2=new int[n+2];
        int []x1=new int[n+2],y1=new int[n+2],x2=new int[n+2],y2=new int[n+2];
        px1[0]=py1[0]=sx1[n+1]=sy1[n+1]=-0x7FFFFFFF;
        px2[0]=py2[0]=sx2[n+1]=sy2[n+1]=0x7FFFFFFF;
        for(int i=1;i<=n;i++){
            x1[i]=ni();
            y1[i]=ni();
            x2[i]=ni();
            y2[i]=ni();
        }
        for(int i=1;i<=n;i++){
            px1[i]=Math.max(px1[i-1],x1[i]);
            py1[i]=Math.max(py1[i-1],y1[i]);
            px2[i]=Math.min(px2[i-1],x2[i]);
            py2[i]=Math.min(py2[i-1],y2[i]);
        }
        for(int i=n;i>=1;i--){
            sx1[i]=Math.max(sx1[i+1],x1[i]);
            sy1[i]=Math.max(sy1[i+1],y1[i]);
            sx2[i]=Math.min(sx2[i+1],x2[i]);
            sy2[i]=Math.min(sy2[i+1],y2[i]);
        }
        for(int i=1;i<=n;i++){
            int Lx=Math.max(px1[i-1],sx1[i+1]);
            int Ly=Math.max(py1[i-1],sy1[i+1]);
            int Rx=Math.min(px2[i-1],sx2[i+1]);
            int Ry=Math.min(py2[i-1],sy2[i+1]);
            if(Lx<=Rx&&Ly<=Ry){
                out.println(Lx+" "+Ly);
                return;
            }
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
    public class Node implements Comparable{
        public double x,y;
        public Node(double x,double y){
            this.x=x;
            this.y=y;
        }
        public int compareTo(Object o) {
            Node to=(Node)o;
            if(this.x>to.x) return 1;
            else if(this.x==to.x) return 0;
            else return -1;
        }
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
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class Main {

    FastScanner in = new FastScanner(System.in);


    
    PrintWriter out = new PrintWriter(System.out);

    public static void main (String[]args) {
        Main task = new Main();


        task.solveB();


        task.close();
    }

    public void close () {
        in.close();
        out.close();
    }

    public void solveA () {
        
        int n = in.nextInt();
        int d = in.nextInt();

        ArrayList<Request>rec = new ArrayList<Request>();
        HashSet<Pair>answer = new HashSet<Pair>();
        TreeSet<String> names = new TreeSet<String>();
        
        for (int i = 0; i < n; i++) {
            Request request = new Request();
            
            String firstName = in.next();
            String secondName = in.next();
            
            int time = in.nextInt();
            
            names.add(firstName);
            names.add(secondName);
            
            request.setFrom(firstName);
            request.setTo(secondName);
            request.setTime(time);
            
            rec.add(request);
        }
        
        TreeMap<String, Integer>map = new TreeMap<String, Integer>();
        Iterator <String> it = names.iterator();
        int id = -1;
        while (it.hasNext()) {
            id++;
            map.put(it.next(), id);
        }
        
        int size = names.size();
        int[][]field = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                field[i][j] = -1;
            }
        }

        for (int i = 0; i < rec.size(); i++) {
            Request request = rec.get(i);
            int x = map.get(request.getFrom());
            int y = map.get(request.getTo());
            
            field[x][y] = request.getTime();

            if (field[y][x] != -1) {
                int diff = field[x][y] - field[y][x];
                if (diff > 0 && diff <= d) {
                    Pair p = new Pair(request.getFrom(), request.getTo());
                    answer.add(p);
                    field[x][y] = -1;
                    field[y][x] = -1;
                    continue;
                }
            }
        }
        
        size = answer.size();
        out.println(size);
        Iterator<Pair>it2 = answer.iterator();
        while (it2.hasNext()) {
            Pair p = it2.next();
            out.println(p.getFirst() + " " + p.getSecond());
        }
    }
    
    class Pair {
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + id1().hashCode();
            result = prime * result + ((first == null) ? 0 : first.hashCode());
            result = prime * result
                    + ((second == null) ? 0 : second.hashCode());
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Pair other = (Pair) obj;
            if (!id1().equals(other.id1()))
                return false;
            if (first == null) {
                if (other.first != null)
                    return false;
            } else if (!first.equals(other.first))
                return false;
            if (second == null) {
                if (other.second != null)
                    return false;
            } else if (!second.equals(other.second))
                return false;
            return true;
        }
        private String first;
        private String second;
        public Pair(String a, String b) {
            if (a.compareTo(b) < 0) {
                first = a;
                second = b;
            }
            else {
                first = b;
                second = a;
            }
        }
        public String getFirst() {
            return first;
        }
        public String getSecond() {
            return second;
        }
        private Main id1() {
            return Main.this;
        }       
    }
    
    class Request {
        String from;
        String to;
        int time;
        boolean confirmation;
        public String getFrom() {
            return from;
        }
        public void setFrom(String from) {
            this.from = from;
        }
        public String getTo() {
            return to;
        }
        public void setTo(String to) {
            this.to = to;
        }
        public int getTime() {
            return time;
        }
        public void setTime(int time) {
            this.time = time;
        }
        public boolean isConfirmation() {
            return confirmation;
        }
        public void setConfirmation(boolean confirmation) {
            this.confirmation = confirmation;
        }
        
    }
    
    public void solveB () {
        int n = in.nextInt();
        int m = in.nextInt();
        
        ArrayList<id6>pens = new ArrayList<id6>();
        ArrayList<id6>caps = new ArrayList<id6>();
        
        int id4 = Integer.MIN_VALUE;
        int id2 = Integer.MIN_VALUE;
        
        int id8 = Integer.MIN_VALUE;
        int id3 = Integer.MIN_VALUE;
        
        for (int i = 0; i < n; i++) {
            id6 pen = new id6();
            int color = in.nextInt();
            int diameter = in.nextInt();
            if (diameter > id4) {
                id4 = diameter;
            }
            if (color > id8) {
                id8 = color;
            }
            pen.setColor(color);
            pen.setDiameter(diameter);
            pens.add(pen);
        }
        
        for (int i = 0; i < m; i++) {
            id6 cap = new id6();
            int color = in.nextInt();
            int diameter = in.nextInt();
            if (diameter > id2) {
                id2 = diameter;
            }
            if (color > id3) {
                id3 = color;
            }
            cap.setColor(color);
            cap.setDiameter(diameter);
            caps.add(cap);
        }
        
        int pretty = 0;
        int pair = 0;
        
        
        int X_SIZE = max (id3, id8) + 1;
        int Y_SIZE = max (id2, id4) + 1;
        
        int[][]tab = new int[X_SIZE][Y_SIZE];
        
        for (int i = 0; i < pens.size(); i++) {
            id6 pen = pens.get(i);
            tab[pen.getColor()][pen.getDiameter()]++;
        }
        
        for (int i = 0; i < caps.size(); i++) {
            id6 cap = caps.get(i);
            if (cap != null) {
                int x = cap.getColor();
                int y = cap.getDiameter();
                if (tab[x][y] > 0) {
                    pretty++;
                    tab[x][y]--;
                    caps.set(i, null);
                }
            }
        }
        
        pair = pretty;
        
        for (int i = 0; i < caps.size(); i++) {
            id6 cap = caps.get(i);
            if (cap != null) {
                int y = cap.getDiameter();
                for (int j = 0; j < X_SIZE; j++) {
                    if (tab[j][y] > 0) {
                        tab[j][y]--;
                        pair++;
                        caps.set(i, null);
                        break;
                    }
                }
            }
        }
        
        out.println(pair + " " + pretty);
        
    }
    
    public int min (int a, int b) {
        if (a < b) return a;
        else return b;
    }
    
    public int max (int a, int b) {
        if (a > b) return a;
        else return b;
    }
    
    class id6 {
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + id1().hashCode();
            result = prime * result + color;
            result = prime * result + diameter;
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            id6 other = (id6) obj;
            if (!id1().equals(other.id1()))
                return false;
            if (color != other.color)
                return false;
            if (diameter != other.diameter)
                return false;
            return true;
        }
        private int color;
        private int diameter;
        public int getColor() {
            return color;
        }
        public void setColor(int color) {
            this.color = color;
        }
        public int getDiameter() {
            return diameter;
        }
        public void setDiameter(int diameter) {
            this.diameter = diameter;
        }
        private Main id1() {
            return Main.this;
        }
    }

    
    public void solveD() {
        String s = in.next();
        StringBuilder b = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            b.append('$');
            b.append(s.charAt(i));
        }
        b.append('$');
        s=null;
        System.gc();
        int[] rad = id5(b.toString());
        b=null;
        System.gc();
        long all = 0;
        for(int i=0;i<rad.length;i++) {
            all += (rad[i]+1)/2;
        }
        int[] add = new int[rad.length];
        for(int i=0;i<rad.length;i++) {
            int a = (rad[i]+1)/2;
            if(a<=0)continue;
            if((i&1)==1) {

                add[i+2*(a-1)]++;
                add[i-1]--;
            }else {

                add[i+2*(a-1)+1]++;
                add[i]--;
            }
        }
        int[] add2=new int[rad.length];
        for(int i=0;i<rad.length;i++) {
            int a = (rad[i]+1)/2;
            if(a<=0)continue;
            if((i&1)==1) {

                add2[i-2*(a-1)]++;
                add2[i+1]--;
            }else {

                add2[i-2*(a-1)-1]++;
                add2[i]--;
            }
        }
        rad=null;
        System.gc();
        int[] num=new int[add.length];
        for(int i=add.length-1;i>=0;i--) {
            num[i] = i==add.length-1 ? 0 : num[i+1] + add[i];
        }
        add = null;
        System.gc();
        int[] sum=new int[num.length];
        for(int i=1;i<num.length;i+=2) {
            sum[i] = i==1 ? num[i] : sum[i-2] + num[i];
        }
        num = null;
        System.gc();
        int[] num2=new int[sum.length];
        long sub = 0;
        for(int i=0;i<sum.length;i++) {
            num2[i] = i==0 ? 0 : num2[i-1] + add2[i];
            if((i&1)==1 && i>2) {
                sub = (sub + (long)num2[i] * sum[i-2]);
            }
        }
        out.println(sub);
    }
    
    public int[] id5(String s) {
        int n=s.length();
        int[] rad=new int[n];
        for(int i=0,j=0;i<n;) {
            while(j<n && i+i-j>=0 && s.charAt(j)==s.charAt(i+i-j))j++;
            rad[i]=j-i-1;
            for(int bi=i++;i<j && rad[bi+bi-i]!=rad[bi]+bi-i;i++) {
                rad[i] = Math.min(rad[bi]+bi-i,rad[bi+bi-i]);
            }
        }
        return rad;
    }
    
    public void solveE() {
        int n = in.nextInt();
        long[][] arry = new long[n][2];
        HashMap<Long, Box[]> map = new HashMap<Long, Box[]>();
        for (int i = 0; i<n; i++) {
            arry[i][0] = in.nextLong();
            arry[i][1] = in.nextLong();
            Box[] mo = map.get(arry[i][0]);
            if (mo==null) {
                mo = new Box[1];
                mo[0] = new Box(arry[i][1], i);
                map.put(arry[i][0], mo);
            } else {
                mo = id9(mo, arry[i][1], i);
                map.put(arry[i][0], mo);
            }
        }
        for (Long key : map.keySet()) {
            Box[] o = map.get(key);
            Arrays.sort(o);
            map.put(key, process(o));
        }
        Object[] keys = map.keySet().toArray();
        int kn = keys.length;
        
        int fcmax = -1;
        int scmax = -1;
        int fqmax = -1;
        int sqmax = -1;
        long numMax = -1;
        int countMax = -1;
        
        for (int i = 0; i < kn; i++) {
            Box[] first = map.get(keys[i]);
            int fl = first.length;
            for (int j = i+1; j < kn; j++) {
                Box[] second = map.get(keys[j]);
                int sl = second.length;
                int number = Math.min(fl, sl);
                
                int n1 = get(number, fl);
                int n2 = get(number, sl);
                
                long localMax = first[n1].getNum() + second[n2].getNum();
                if (localMax>numMax) {
                    numMax = localMax;
                    fcmax = i;
                    scmax = j;
                    fqmax = n1;
                    sqmax = n2;
                    countMax = n1 + n2 + 2;
                }
            }
        }
        
        out.println(numMax);
        out.println(countMax);
        
        Box[] first = map.get(keys[fcmax]);
        Box[] second = map.get(keys[scmax]);
        
        if (fqmax>sqmax) {
            for (int i = 0; i <= fqmax; i++) {
                out.print((first[i].getPlace()+1)+" ");
                if (i<=sqmax) out.print((second[i].getPlace()+1)+" ");
            }
        } else {
            for (int i = 0; i <= sqmax; i++) {
                out.print((second[i].getPlace()+1)+" ");
                if (i<=fqmax) out.print((first[i].getPlace()+1)+" ");
            }
        }
    }
    
    public class Box implements Comparable<Box> {
        private long num; private int place;
        public Box(long num, int place) {
            this.num = num; this.place = place;
        }
        public long getNum() { return num; }
        public void setNum(long num) { this.num = num; }
        public int getPlace() { return place; }
        public void setPlace(int place) { this.place = place; }
        @Override
        public int compareTo(Box o) { if (o.getNum()<this.num) return -1; else return 1; }
    }
    
    private Box[] id9(Box[] old, long h, int i) {
        int n = old.length;
        Box[] newA = new Box[n+1];
        for (int j = 0; j < n; j++) newA[j] = old[j];
        newA[n] = new Box(h, i);
        return newA;
    }
    
    private Box[] process(Box[] boxes) {
        for (int i = 0; i < boxes.length; i++) {
            Box box = boxes[i];
            long q = box.getNum(); if (i!=0) q+=boxes[i-1].getNum(); 
            box.setNum(q);
            boxes[i] = box;
        }
        return boxes;
    }
    
    private int get(int x, int n) { if (x>=n) return n-1; else return x; }
}

class Algebra {
    
    public static int phi(int n) {
        int result = n;
        for (int i = 2; i*i <= n; ++i) {
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

    
    public static int binpow (int a, int n) {
        int res = 1;
        while (n != 0) {
            if ((n & 1) == 1)
                res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    
    public static int gcd (int a, int b) {
        return (b != 0) ? gcd (b, a % b) : a;
    }

    
    public static int lcm (int a, int b) {
        return a / gcd (a, b) * b;
    }

    
    public static boolean[] id7 (int n) {
        boolean [] prime = new boolean[n + 1];
        Arrays.fill(prime, true);
        prime[0] = prime[1] = false;
        for (int i=2; i<=n; ++i) {
            if (prime[i]) {
                if (i * 1L * i <= n) {
                    for (int j=i*i; j<=n; j+=i) {
                        prime[j] = false;
                    }
                }
            }
        }
        return prime;
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    
    FastScanner(File f) {
        try {
            br = new BufferedReader(new FileReader(f));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    
    FastScanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
    }
    
    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                System.err.println(e);
                return "";
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    float nextFloat() {
        return Float.parseFloat(next());
    }
    BigInteger id0() {
        return new BigInteger(next());
    }

    void close() {
        try {
            br.close();
        }
        catch (IOException e) {
        }
    }
}
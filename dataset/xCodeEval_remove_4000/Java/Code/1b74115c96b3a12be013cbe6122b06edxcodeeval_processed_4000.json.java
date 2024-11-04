



import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.*;
import java.util.Map.Entry;

public class E {

    public static void main(String[] args) {
        CIO io = new CIO();
        try {
            normal(io);
            

            

            

        } finally {
            io.close();
        }
    }
    
    private static void normal(CIO io) {
        

        id14 solver = new id14();
        int n = io.nextInt();
        long[] t = new long[n+2];
        for (int i=1; i<=n; i++) {
            t[i] = io.nextLong();
        }
        io.println(solver.solve(n,t));
    }
    
    private static void testGen() {
        Random rng = new Random();
        for (int n=10000; n<=200000; n++) {
            System.out.println("Starting at n = " + n + "...");
            for (int attempt=1; attempt<100; attempt++) {
                int maxValue = 1000000;
                long[] t = new long[n+2];
                for (int i=1; i<=n; i++) {
                    t[i] = maxValue - rng.nextInt(2*maxValue);
                }
                Esolver id22 = new Esolver();
                id14 id8 = new id14();
                long id13 = id8.solve(n,t);
                long realAns = id22.solve(n,t);
                if (id13 != realAns) {
                    System.out.println("t[] = " + Arrays.toString(t));
                    System.out.println("Fancy ans = " + id13);
                    System.out.println("Real ans = " + realAns);
                    
                    throw new RuntimeException();
                }
            }
        }
    }
    
    private static void id1() {
        id9 pouch = new id9(0, 4, id9.id2);
        pouch.add(new Line(0, 0));
        pouch.add(new Line(3, -3));
        pouch.add(new Line(2, -1));
        pouch.printContents();
        
       

        
        int n = 4;
        long[] t = { 0, 0, 3, 2, 2, 0 };
        Esolver solver = new Esolver();
        solver.debug = true;
        long ans = solver.solve(n, t);
        System.out.println("ans should be 22 is now " + ans);
    }
    
    private static void test16() {
        String meh = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";
        int n = 200000;
        long[] t = new long[n+2];
        long currentInteger = 1L;
        int blah = 0;
        for (int i=1; i<=n; i++) {
            t[i] = currentInteger;
            blah += 2;
            if (blah >= meh.length()) {
                blah = 0;
                currentInteger++;
            }
        }
        Esolver solver = new Esolver();
        solver.fuckme = true;
        long ans = solver.solve(n,t);
        System.out.println("ANS: " + ans);
    }

}

class Brute {
    public long solve(int n, long[] t) {
        long prodSum = 0;
        long[] sum = new long[n+2];
        for (int i=1; i<=n+1; i++) {
            sum[i] = sum[i-1] + t[i];
            prodSum += t[i] * i;
        }
        
        long bestChange = 0;
        for (int i=1; i<=n; i++) {
            for (int j=i+1; j<=n; j++) {
                long change = -sum[j] + sum[i] + t[i] * (j-i);
                bestChange = Math.max(change, bestChange);
            }
        }
        for (int i=n; i>=1; i--) {
            for (int j=i-1; j>=1; j--) {
                long change = -sum[j-1] + sum[i-1] + t[i] * (j-i);
                bestChange = Math.max(change, bestChange);
            }
        }
        
        return prodSum+bestChange;
    }
}

class id14 {
    private int n;
    private long[] t;
    private long[] sum;
    
    public long solve(int n, long[] t) {
        this.n = n;
        this.t = t;
        long prodSum = 0;
        sum = new long[n+2];
        for (int i=1; i<=n+1; i++) {
            sum[i] = sum[i-1] + t[i];
            prodSum += t[i] * i;
        }
        long bestChange = Math.max(forwardChoices(), id3());
        return prodSum + bestChange;
    }
    
    
    public long forwardChoices() {
        long bestChange = 0;
        ArrayList<Pair> choices = new ArrayList<>(); 
        choices.add(new Pair(1,2)); 
        for (int i=2 ;; i++) {
            
            if (choices.size() >= 2 && choices.get(1).id16 <= i) {
                choices.remove(0);
            }
            
            int from = choices.get(0).sourceIndex;
            int to = i;
            long moveValue = forwardValue(t, sum, from, to);
            bestChange = Math.max(bestChange, moveValue);
            
            
            if (i==n) break;
            int id7 = choices.get(choices.size()-1).sourceIndex;
            if (!choices.isEmpty() && t[i] <= t[id7]) {
                
                continue;
            }
            
            
            while (!choices.isEmpty()) {
                id7 = choices.get(choices.size()-1).sourceIndex;
                int id16 = choices.get(choices.size()-1).id16;
                id16 = Math.max(id16, i+1);
                long prevVal = forwardValue(t, sum, id7, id16);
                long currVal = forwardValue(t, sum, i, id16);
                if (currVal >= prevVal) {
                    
                    choices.remove(choices.get(choices.size()-1));
                } else {
                    break;
                }
            }
            
            if (choices.isEmpty()) {
                choices.add(new Pair(i, i+1));
            } else {
                
                id7 = choices.get(choices.size()-1).sourceIndex;
                long valueDiff = forwardValue(t, sum, id7, i) - 0; 
                long id17 = t[i] - t[id7];
                long id11 = valueDiff/id17;
                if (valueDiff%id17 != 0) id11++; 
                long id16 = id11 + i;
                if (id16 <= n) {
                    choices.add(new Pair(i, (int)id16));
                }
            }
            
        }
        
        return bestChange;
    }
    
    
    public long id3() {
        long bestChange = 0;
        List<Pair> choices = new ArrayList<>();
        choices.add(new Pair(n,n-1));
        for (int i=n-1 ;; i--) {
            if (choices.size() > 1 && choices.get(1).id16 >= i) {
                choices.remove(0);
            }
            int to = i;
            int from = choices.get(0).sourceIndex;
            long moveValue = id12(t, sum, from, to);
            bestChange = Math.max(bestChange, moveValue);
            
            if (i==1) break;
            
            int id7 = choices.get(choices.size()-1).sourceIndex;
            if (!choices.isEmpty() && t[i] >= t[id7]) continue;
            
            while (!choices.isEmpty()) {
                id7 = choices.get(choices.size()-1).sourceIndex;
                int id0 = choices.get(choices.size()-1).id16;
                id0 = Math.min(id0, i-1);
                long prevVal = id12(t, sum, id7, id0);
                long currVal = id12(t, sum, i, id0);
                if (currVal >= prevVal) {
                    choices.remove(choices.get(choices.size()-1));
                } else break;
            }
            
            if (choices.isEmpty()) {
                choices.add(new Pair(i, i-1));
            } else {
                id7 = choices.get(choices.size()-1).sourceIndex;
                long valueDiff = id12(t, sum, id7, i) - 0;
                long id17 = t[id7] - t[i];
                long id11 = valueDiff/id17;
                if (valueDiff%id17 != 0) id11++;
                long id16 = i - id11;
                if (id16 >= 1) {
                    choices.add(new Pair(i, (int)id16));
                }
            }
            
        }
        
        return bestChange;
    }
    
    public long forwardValue(long[] t, long[] sum, int from, int to) {
        return -sum[to] + sum[from] + t[from] * (to-from);
    }
    
    public long id12(long[] t, long[] sum, int from, int to) {
        return -sum[to-1] + sum[from-1] + t[from] * (to-from);
    }
    
    private class Pair {
        int sourceIndex;
        int id16;

        public Pair(int sourceIndex, int id0) {
            this.sourceIndex = sourceIndex;
            this.id16 = id0;
        }
    }
    
}



class Esolver {
    
    public static boolean debug = false;
    public static boolean fuckme = false;
    
    public long solve(int n, long[] t) {
        long prodSum = 0;
        long[] sum = new long[n+2];
        for (int i=1; i<=n+1; i++) {
            sum[i] = sum[i-1] + t[i];
            prodSum += t[i] * i;
        }
        
        long bestChange = id5(n, t, sum);
        return (prodSum+bestChange);
    }
    
    public long id5(int n, long[] t, long[] sum) {
        long bestChange = 0;
        id9 pouch = new id9(0, n, id9.id2);
        for (int i=1; i<=n; i++) {
            

            

            long current = pouch.id20(i);
            if (current != id9.id10) {
                current -= sum[i]; 
                bestChange = Math.max(bestChange, current);
            }
            
            
            long slope = t[i];
            long constant = sum[i] - i * t[i];
            pouch.add(new Line(slope, constant));
            pouch.prune(i);
        }
        
        if (fuckme) {
            

        }
        
        

        pouch = new id9(1, n, id9.id6);
        for (int i=n; i>=1; i--) {
            long current = pouch.id20(i);
            if (current != id9.id10) {
                current -= sum[i-1];
                bestChange = Math.max(bestChange, current);
            }
            long slope = t[i];
            long constant = sum[i-1] - i * t[i];
            pouch.add(new Line(slope, constant));
            pouch.prune(i);

        }
        return bestChange;
    }
    
}


class id9 {
    
    TreeMap<Long, Line> tree; 
    int direction;
    long[] bounds;
    public static final int FIRST_ITEM = 0;
    public static final int LAST_ITEM = 1;
    public static final int id6 = 0;
    public static final int id2 = 1;
    public static final long id10 = -Long.MAX_VALUE;

    public id9(long min, long max, int direction) {
        tree = new TreeMap<>();
        bounds = new long[2];
        bounds[FIRST_ITEM] = min;
        bounds[LAST_ITEM] = max;
        this.direction = direction;
    }
    
    
    public long id20(long x) {
        Entry<Long, Line> entry = tree.floorEntry(x);
        if (entry == null) return id10;
        Line line = entry.getValue();
        return line.slope * x + line.constant;
    }
    
    public void add(Line newLine) {
        if (tree.isEmpty()) {
            tree.put(bounds[FIRST_ITEM], newLine);
            return;
        }
        
        
        long min = bounds[FIRST_ITEM];
        long max = bounds[LAST_ITEM]+9;
        while (min < max) {
            long b = (min+max+1)/2;
            long a = b-1;
            Entry<Long, Line> entryB = tree.floorEntry(b);
            Line bLine = entryB.getValue();
            Line aLine = (entryB.getKey() <= a ? bLine : tree.floorEntry(a).getValue());
            long oldA = aLine.slope * a + aLine.constant;
            long oldB = bLine.slope * b + bLine.constant;
            long newA = newLine.slope * a + newLine.constant;
            long newB = newLine.slope * b + newLine.constant;
            
            if (newA >= oldA) {
                max = a;
            }
            if (newA < oldA && newB < oldB) {
                if (newLine.slope > bLine.slope) {
                    min = b+1;
                } else {
                    max = a-1;
                }
            }
            if (newA < oldA && newB >= oldB) {
                min = b;
                break;
            }
            
        }
        if (min > bounds[LAST_ITEM]) return; 
        if (min > bounds[FIRST_ITEM]) {
            long id19 = newLine.slope * min + newLine.constant;
            long oldMax = id20(min);
            if (oldMax > id19) return;
            Line oldLine = tree.get(min);
            if (oldMax == id19) {
                if (oldLine != null && oldLine.slope > newLine.slope) return;
            }
            tree.put(min, newLine);
            if (oldLine != null && oldLine.slope > newLine.slope) {
                Long xCross = oldLine.findCross(newLine);
                if (xCross == id9.id10) {
                    System.out.println("SHOULD NEVER HAPPEN");
                    throw new RuntimeException();
                }
                Entry<Long, Line> nextEntry = tree.higherEntry(min);
                if (nextEntry == null || xCross < nextEntry.getKey()) {
                    tree.put(xCross, oldLine);
                }
            }
        }
        else if (min == bounds[FIRST_ITEM]) {
            
            Line oldLine = tree.get(min);
            long id21 = oldLine.slope * min + oldLine.constant;
            long id19 = newLine.slope * min + newLine.constant;
            Entry<Long, Line> nextEntry = tree.higherEntry(min);
            Long xCross = oldLine.findCross(newLine);
            if (id21 >= id19) {
                if (xCross < bounds[FIRST_ITEM]) return;
                if (nextEntry != null && xCross >= nextEntry.getKey()) return;
                if (xCross == bounds[FIRST_ITEM]) {
                    if (newLine.slope > oldLine.slope) {
                        tree.put(min, newLine);
                    } else {
                        
                        return;
                    }
                }
                
                else if (newLine.slope > oldLine.slope) {
                    tree.put(xCross, newLine);
                } else if (newLine.slope < oldLine.slope) {
                    
                    return;
                } else if (newLine.slope == oldLine.slope) {
                    
                    return;
                }
            } else { 
                tree.put(min, newLine);
                
                if (xCross > bounds[FIRST_ITEM]) {
                    if ((nextEntry == null && xCross <= bounds[LAST_ITEM])
                        || nextEntry != null && xCross < nextEntry.getKey()) {
                            tree.put(xCross, oldLine);
                            
                    }
                }
            }
        }
        
        while (true) {
            Entry<Long, Line> entry = tree.higherEntry(min);
            
            if (entry == null) break;
            Line nextLine = entry.getValue();
            tree.remove(entry.getKey()); 
            if (nextLine.slope <= newLine.slope) continue;
            Long id4 = tree.higherKey(entry.getKey());
            
            Long xCross = nextLine.findCross(newLine);
            if (id4 == null || xCross < id4) {
                if (xCross > bounds[LAST_ITEM] || xCross < bounds[FIRST_ITEM]) break;
                
                tree.put(xCross, nextLine);
                break;
            }
        }
    }
    
    public void prune(int i) {
        if (direction == id6) {
            bounds[LAST_ITEM] = i;
            while (tree.size() > 1) {
                Entry<Long, Line> entry = tree.pollLastEntry();
                if (entry.getKey() <= bounds[LAST_ITEM]) {
                    tree.put(entry.getKey(), entry.getValue());
                    break;
                }
            }
        }
        else {
            if (tree.isEmpty()) return;
            bounds[FIRST_ITEM] = i;
            Entry<Long, Line> prev = tree.pollFirstEntry();
            while (tree.size() > 1) {
                Entry<Long, Line> entry = tree.pollFirstEntry();
                if (entry.getKey() >= bounds[FIRST_ITEM]) {
                    tree.put(entry.getKey(), entry.getValue());
                    break;
                }
                prev = entry;
            }
            if (tree.get(bounds[FIRST_ITEM]) == null) {
                tree.put(bounds[FIRST_ITEM], prev.getValue());
            }
        }   
        
    }
    
    
    public void printContents() {
        System.out.println("    POUCH CONTENTS ");
        for (Entry<Long,Line> entry : tree.entrySet()) {
            System.out.println("        From x=" + entry.getKey() + ", highest Y comes from line " + entry.getValue());
        }
    }
}

class Line {
    long slope;
    long constant;

    public Line(long slope, long constant) {
        this.slope = slope;
        this.constant = constant;
    }

    @Override
    public String toString() {
        return "Line " + slope + "x + " + constant;
    }

    Long findCross(Line other) {
        if (other.slope - this.slope == 0) return id9.id10;;










        return (long) Math.ceil((1.0*this.constant - other.constant) / (other.slope - this.slope));
    }
    
}


class CIO extends PrintWriter {
    private InputStreamReader r;
    private static final int id18 = 1 << 15;
    private char[] buf;
    private int bufc;
    private int bufi;
    private StringBuilder sb;

    public CIO() {
            super(new BufferedOutputStream(System.out));
            r = new InputStreamReader(System.in);

            buf = new char[id18];
            bufc = 0;
            bufi = 0;
            sb = new StringBuilder();
    }

    private void fillBuf() throws IOException {
            bufi = 0;
            bufc = 0;
            while(bufc == 0) {
                    bufc = r.read(buf, 0, id18);
                    if(bufc == -1) {
                            bufc = 0;
                            return;
                    }
            }
    }

    private boolean pumpBuf() throws IOException {
            if(bufi == bufc) {
                    fillBuf();
            }
            return bufc != 0;
    }

    private boolean isDelimiter(char c) {
            return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
    }

    private void id23() throws IOException {
            while(true) {
                    if(bufi == bufc) {
                            fillBuf();
                            if(bufc == 0) throw new RuntimeException("IO: Out of input.");
                    }

                    if(!isDelimiter(buf[bufi])) break;
                    ++bufi;
            }
    }

    public String next() {
            try {
                    sb.setLength(0);

                    id23();
                    int start = bufi;

                    while(true) {
                            if(bufi == bufc) {
                                    sb.append(buf, start, bufi - start);
                                    fillBuf();
                                    start = 0;
                                    if(bufc == 0) break;
                            }

                            if(isDelimiter(buf[bufi])) break;
                            ++bufi;
                    }

                    sb.append(buf, start, bufi - start);

                    return sb.toString();
            } catch(IOException e) {
                    throw new RuntimeException("IO.next: Caught IOException.");
            }
    }

    public int nextInt() {
            try {
                    int ret = 0;

                    id23();

                    boolean positive = true;
                    if(buf[bufi] == '-') {
                            ++bufi;
                            if(!pumpBuf()) throw new RuntimeException("IO.nextInt: Invalid int.");
                            positive = false;
                    }

                    boolean first = true;
                    while(true) {
                            if(!pumpBuf()) break;
                            if(isDelimiter(buf[bufi])) {
                                    if(first) throw new RuntimeException("IO.nextInt: Invalid int.");
                                    break;
                            }
                            first = false;

                            if(buf[bufi] >= '0' && buf[bufi] <= '9') {
                                    if(ret < -214748364) throw new RuntimeException("IO.nextInt: Invalid int.");
                                    ret *= 10;
                                    ret -= (int)(buf[bufi] - '0');
                                    if(ret > 0) throw new RuntimeException("IO.nextInt: Invalid int.");
                            } else {
                                    throw new RuntimeException("IO.nextInt: Invalid int.");
                            }

                            ++bufi;
                    }

                    if(positive) {
                            if(ret == -2147483648) throw new RuntimeException("IO.nextInt: Invalid int.");
                            ret = -ret;
                    }

                    return ret;
            } catch(IOException e) {
                    throw new RuntimeException("IO.nextInt: Caught IOException.");
            }
    }

    public long nextLong() {
            try {
                    long ret = 0;

                    id23();

                    boolean positive = true;
                    if(buf[bufi] == '-') {
                            ++bufi;
                            if(!pumpBuf()) throw new RuntimeException("IO.nextLong: Invalid long.");
                            positive = false;
                    }

                    boolean first = true;
                    while(true) {
                            if(!pumpBuf()) break;
                            if(isDelimiter(buf[bufi])) {
                                    if(first) throw new RuntimeException("IO.nextLong: Invalid long.");
                                    break;
                            }
                            first = false;

                            if(buf[bufi] >= '0' && buf[bufi] <= '9') {
                                    if(ret < -922337203685477580L) throw new RuntimeException("IO.nextLong: Invalid long.");
                                    ret *= 10;
                                    ret -= (long)(buf[bufi] - '0');
                                    if(ret > 0) throw new RuntimeException("IO.nextLong: Invalid long.");
                            } else {
                                    throw new RuntimeException("IO.nextLong: Invalid long.");
                            }

                            ++bufi;
                    }

                    if(positive) {
                            if(ret == -9223372036854775808L) throw new RuntimeException("IO.nextLong: Invalid long.");
                            ret = -ret;
                    }

                    return ret;
            } catch(IOException e) {
                    throw new RuntimeException("IO.nextLong: Caught IOException.");
            }
    }

    public double nextDouble() {
            return Double.parseDouble(next());
    }

}



class id15 {


















































































































































}
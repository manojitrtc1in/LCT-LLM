


import java.io.*;
import java.lang.*;
import java.math.BigInteger;
import java.util.*;
import java.util.function.BiFunction;

public class Main extends IO {

    

    public static void main(String[] args) throws Exception {
        int quantity = readInt();
        for (int i = 0; i < quantity; i++) {
            int[] properties = readArrayInt(" ");
            HashMap<Integer, Integer> all = new HashMap<>();
            Arrays.stream(readArrayInt(" ")).forEach(value -> all.merge(value % properties[1], 1, Integer::sum));
            int answer = (all.containsKey(0) ? 1 : 0) + ((properties[1] & 1) == 0 ? (all.containsKey(properties[1] >> 1) ? 1 : 0) : 0);
            all.remove(0);
            if ((properties[1] & 1) == 0) {
                all.remove(properties[1] >> 1);
            }
            for (Map.Entry<Integer, Integer> value : all.entrySet()) {
                int findValueKey = properties[1] - value.getKey();
                if (!all.containsKey(findValueKey)){
                    answer += value.getValue();
                }
                else if (value.getKey() <= (properties[1] >> 1)) {
                    if (Math.abs(value.getValue() - all.get(findValueKey)) <= 1) {
                        answer++;
                    } else {
                        answer += Math.abs(value.getValue() - all.get(findValueKey));
                    }
                }
            }
            writeInt(answer, "\n");
        }
        print();
    }
}

class math {

    protected static long remains = 0x3B9ACA07; 


    static Integer[] convertBase(int value, int toBase) {
        if (toBase == 1) {
            throw new InputMismatchException("base = 1");
        }
        List<Integer> result = new ArrayList<>();
        while (value / toBase >= 1) {
            result.add(0, value % toBase);
            value /= toBase;
        }
        result.add(0, value % toBase);
        return result.toArray(Integer[]::new);
    }

    protected static int gcd(int a, int b) { 

        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    protected static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    protected static float gcd(float a, float b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    protected static double gcd(double a, double b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    protected static double lcm(double a, double b) { 

        return a / gcd(a, b) * b;
    }

    protected static float lcm(float a, float b) { 

        return a / gcd(a, b) * b;
    }

    protected static int lcm(int a, int b) { 

        return a / gcd(a, b) * b;
    }

    protected static long lcm(long a, long b) {
        return a / gcd(a, b) * b;

    }

    protected static long mult(long a, long b) {
        return ((a % remains) * (b % remains)) % remains;
    }

    protected static long binpow(long base, long power) {
        long res = 1;
        while (power != 0)
            if ((power & 1) == 1) {
                res = mult(res, base);
                power--;
            } else {
                base = mult(base, base);
                power >>= 1;
            }
        return res;
    }

    protected static double log(double value, int base) {
        return Math.log(value) / Math.log(base);
    }

    protected static long factorial(int number) {
        if (number < 0) {
            return 0;
        }
        return solveFactorial(number);
    }

    private static long solveFactorial(int number) {
        if (number > 0) {
            return solveFactorial(number - 1) * number;
        }
        return 1;
    }

    static boolean[] solveEratosfen(int count) {
        boolean[] isPrimes = new boolean[count];
        Arrays.fill(isPrimes, true);
        isPrimes[0] = false;
        isPrimes[1] = false;
        for (int i = 2; i < isPrimes.length; i++) {
            if (isPrimes[i]) {
                for (int j = 2; i * j < isPrimes.length; j++) {
                    isPrimes[i * j] = false;
                }
            }
        }
        return isPrimes;
    }

}

class ArraySegments<T extends Comparable<? super T>> {

    private List<Pair<T, T>> geps;

    ArraySegments() {
        this.geps = new ArrayList<>();
    }

    void addGep(T start, T stop) {
        int indexStart = indexOf(start);
        int indexStop = indexOf(stop);
        if (indexStart != -1 && indexStop == -1) {
            this.geps.get(indexStart).setSecond(stop);
            T startGep = this.geps.get(indexStart).getFirstElement();
            T stopGep = this.geps.get(indexStart).getSecondElement();
            int i = indexStart + 1;
            while (i < geps.size()) {
                if (this.geps.get(i).getFirstElement().compareTo(startGep) >= 0 && this.geps.get(i).getSecondElement().compareTo(stopGep) <= 0) {
                    this.geps.remove(i);
                } else {
                    break;
                }
            }
        } else if (indexStart != -1 && indexStop != -1) {
            this.geps.get(indexStart).setSecond(this.geps.get(indexStop).getSecondElement());
            if (indexStart == indexStop) {
                return;
            }
            this.geps.remove(indexStop);
            T startGep = this.geps.get(indexStart).getFirstElement();
            T stopGep = this.geps.get(indexStart).getSecondElement();
            int i = indexStart + 1;
            while (i < this.geps.size()) {
                if (this.geps.get(i).getFirstElement().compareTo(startGep) >= 0 && this.geps.get(i).getSecondElement().compareTo(stopGep) <= 0) {
                    this.geps.remove(i);
                } else {
                    break;
                }
            }
        } else if (indexStart == -1 && indexStop != -1) {
            this.geps.get(indexStop).setFirst(start);
            T startGep = this.geps.get(indexStop).getFirstElement();
            T stopGep = this.geps.get(indexStop).getSecondElement();
            int i = indexStop - 1;
            while (i >= 0) {
                if (this.geps.get(i).getFirstElement().compareTo(startGep) >= 0 && this.geps.get(i).getSecondElement().compareTo(stopGep) <= 0) {
                    this.geps.remove(i);
                } else {
                    break;
                }
                i--;
            }
        } else if (indexStart == -1 && indexStop == -1) {
            if (this.geps.size() != 0) {
                int l = 0;
                int r = this.geps.size();
                while (l + 1 != r) {
                    int mid = (l + r) >> 1;
                    if (this.geps.get(mid).getFirstElement().compareTo(start) < 0) {
                        l = mid;
                    } else {
                        r = mid;
                    }
                }
                this.geps.add(l + 1, Pair.createPair(start, stop));
                indexStart = l + 1;
            } else {
                this.geps.add(Pair.createPair(start, stop));
                return;
            }
            int i = indexStart + 1;
            while (i < this.geps.size()) {
                if (this.geps.get(i).getFirstElement().compareTo(start) >= 0 && this.geps.get(i).getSecondElement().compareTo(stop) <= 0) {
                    this.geps.remove(i);
                } else {
                    break;
                }
            }

        }
    }

    int indexOf(T value) {
        if (geps.size() == 0) {
            return -1;
        }
        int l = 0;
        int r = geps.size();
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (geps.get(mid).getFirstElement().compareTo(value) <= 0) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (geps.get(l).getFirstElement().compareTo(value) <= 0 && geps.get(l).getSecondElement().compareTo(value) >= 0) {
            return l;
        }
        return -1;
    }

    void clear() {
        this.geps.clear();
    }
}

class Int implements Comparable<Integer> {

    protected int value;

    Int(int value) {
        this.value = value;
    }

    public Int add(int value) {
        this.value += value;
        return this;
    }

    @Override
    public int compareTo(Integer o) {
        return (this.value < o) ? -1 : ((this.value == o) ? 0 : 1);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Integer) {
            return value == (Integer) obj;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return value;
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
    }
}


class Fraction<T extends Number> extends Pair {

    private Fraction(T dividend, T divider) {
        super(dividend, divider);
        reduce();
    }

    protected static <T extends Number> Fraction<T> createFraction(T dividend, T divider) {
        return new Fraction<>(dividend, divider);
    }

    protected void reduce() {
        if (getFirstElement() instanceof Integer) {
            Integer Dividend = (Integer) getFirstElement();
            Integer Divider = (Integer) getSecondElement();
            int gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (getFirstElement() instanceof Long) {
            Long Dividend = (Long) getFirstElement();
            Long Divider = (Long) getSecondElement();
            long gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (getFirstElement() instanceof Float) {
            Float Dividend = (Float) getFirstElement();
            Float Divider = (Float) getSecondElement();
            float gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (getFirstElement() instanceof Double) {
            Double Dividend = (Double) getFirstElement();
            Double Divider = (Double) getSecondElement();
            double gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        }
    }

    protected void addWithoutReturn(Fraction number) throws UnsupportedOperationException {
        add(number, 0);
    }

    private Fraction add(Fraction number, int function) throws UnsupportedOperationException {
        if (getFirstElement() instanceof Integer && number.getFirstElement() instanceof Integer) {
            Integer Dividend = (Integer) getFirstElement();
            Integer Divider = (Integer) getSecondElement();
            Integer Dividend1 = (Integer) number.getFirstElement();
            Integer Divider1 = (Integer) number.getSecondElement();
            Integer lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                setSecond(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createFraction((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;

        } else if (getFirstElement() instanceof Long && number.getFirstElement() instanceof Long) {
            Long Dividend = (Long) getFirstElement();
            Long Divider = (Long) getSecondElement();
            Long Dividend1 = (Long) number.getFirstElement();
            Long Divider1 = (Long) number.getSecondElement();
            Long lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                setSecond(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createFraction((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;
        } else if (getFirstElement() instanceof Float && number.getFirstElement() instanceof Float) {
            Float Dividend = (Float) getFirstElement();
            Float Divider = (Float) getSecondElement();
            Float Dividend1 = (Float) number.getFirstElement();
            Float Divider1 = (Float) number.getSecondElement();
            Float lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                setSecond(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createFraction((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;
        } else if (getFirstElement() instanceof Double && number.getFirstElement() instanceof Double) {
            Double Dividend = (Double) getFirstElement();
            Double Divider = (Double) getSecondElement();
            Double Dividend1 = (Double) number.getFirstElement();
            Double Divider1 = (Double) number.getSecondElement();
            Double lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                setSecond(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createFraction((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;
        } else {
            throw new UnsupportedOperationException();
        }
    }

    protected Fraction addWithReturn(Fraction number) {
        return add(number, 1);
    }

    protected void multiplyWithoutReturn(Fraction number) throws UnsupportedOperationException {
        multiply(number, 0);
    }

    protected Fraction multiplyWithReturn(Fraction number) throws UnsupportedOperationException {
        return multiply(number, 1);
    }

    private Fraction multiply(Fraction number, int function) throws UnsupportedOperationException {
        if (getFirstElement() instanceof Integer && number.getFirstElement() instanceof Integer) {
            Integer first = (Integer) getFirstElement() * (Integer) number.getFirstElement();
            Integer second = (Integer) getSecondElement() * (Integer) number.getSecondElement();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else if (getFirstElement() instanceof Long && number.getFirstElement() instanceof Long) {
            Long first = (Long) getFirstElement() * (Long) number.getFirstElement();
            Long second = (Long) getSecondElement() * (Long) number.getSecondElement();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;

        } else if (getFirstElement() instanceof Float && number.getFirstElement() instanceof Float) {
            Float first = (Float) getFirstElement() * (Float) number.getFirstElement();
            Float second = (Float) getSecondElement() * (Float) number.getSecondElement();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else if (getFirstElement() instanceof Double && number.getFirstElement() instanceof Double) {
            Double first = (Double) getFirstElement() * (Double) number.getFirstElement();
            Double second = (Double) getSecondElement() * (Double) number.getSecondElement();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else {
            throw new UnsupportedOperationException();
        }
    }
}

class Pair<T, T1> implements Cloneable {

    private T first;
    private T1 second;

    Pair(T obj, T1 obj1) {
        first = obj;
        second = obj1;
    }

    protected static <T, T1> Pair<T, T1> createPair(T element, T1 element1) {
        return new Pair<>(element, element1);
    }

    protected T getFirstElement() {
        return first;
    }

    protected T1 getSecondElement() {
        return second;
    }

    protected void setFirst(T element) {
        first = element;
    }

    protected void setSecond(T1 element) {
        second = element;
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Pair)) {
            return false;
        }
        Pair pair = (Pair) obj;
        return first.equals(pair.first) && second.equals(pair.second);
    }

    @Override
    public int hashCode() {
        int hashCode = 1;
        hashCode = 31 * hashCode + (first == null ? 0 : first.hashCode());
        return 31 * hashCode + (second == null ? 0 : second.hashCode());
    }

    @Override
    public Object clone() {
        return Pair.createPair(first, second);
    }
}

class Graph {

    private int[][] base;
    private boolean[] used;
    private int quantity;
    private Integer[] ancestor;

    public int[][] getBase() {
        return base;
    }

    public boolean[] getUsed() {
        return used;
    }

    public int getQuantity() {
        return quantity;
    }

    public Integer[] getAncestor() {
        return ancestor;
    }

    public void setBase(int[][] base) {
        this.base = base;
    }

    protected void start(int length) {
        used = new boolean[length];
        ancestor = new Integer[length];
        Arrays.fill(ancestor, -1);
        quantity = 0;
    }


    protected void edgesMatrixToDefault(int length, int inputQuantity, boolean readConsole, int[][] value) throws Exception {
        base = new int[length][];
        List<ArrayList<Integer>> inputBase = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            inputBase.add(new ArrayList<>());
        }
        for (int i = 0; i < inputQuantity; i++) {
            int[] input = readConsole ? IO.readArrayInt(" ") : value[i];
            inputBase.get(input[0] - 1).add(input[1] - 1);
            inputBase.get(input[0] - 1).add(input[2]); 

            inputBase.get(input[1] - 1).add(input[0] - 1);
            inputBase.get(input[1] - 1).add(input[2]); 

        }
        for (int i = 0; i < length; i++) {
            base[i] = inputBase.get(i).stream().mapToInt(Integer::intValue).toArray();
        }
        start(length);
    }

    protected void adjacencyMatrixToDefault(int length, int not, boolean readConsole, int[][] value) throws Exception {
        this.base = new int[length][];
        List<Integer> buffer = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            int[] InputArray = readConsole ? IO.readArrayInt(" ") : value[i];
            for (int index = 0; index < length; index++) {
                if (i != index && InputArray[index] != not) {
                    buffer.add(index);
                    

                }
            }
            this.base[i] = buffer.stream().mapToInt(Integer::intValue).toArray();
            buffer.clear();
        }
        start(length);
    }

    protected int dfs(int position) throws Exception {
        used[position] = true;
        int next;
        int count = 0;
        for (int index = 0; index < base[position].length; index += 2) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                count += dfs(next);
            }
             
        }
        if (base[position].length == 2 && base[position][0] == ancestor[position]) {
            return 1;
        }
        return count;
    }

    protected int dijkstra(int start, int stop, int size) {
        start--;
        stop--;
        int[] dist = new int[size];
        for (int i = 0; i < size; i++) {
            if (i != start) {
                dist[i] = Integer.MAX_VALUE;
            }
            ancestor[i] = start;
        }

        Queue<int[]> queue = new PriorityQueue<>(Comparator.comparingInt((int[] ints) -> ints[1]));
        queue.add(new int[]{start, 0});
        int position;
        int[] getQueue;
        while (queue.size() != 0) {
            getQueue = queue.poll();
            position = getQueue[0];
            if (getQueue[1] > dist[position]) {
                continue;
            }
            for (int index = 0; index < this.base[position].length; index += 2) {
                if (dist[position] + this.base[position][index + 1] < dist[this.base[position][index]] && !this.used[this.base[position][index]]) {
                    dist[this.base[position][index]] = dist[position] + this.base[position][index + 1];
                    this.ancestor[this.base[position][index]] = position;
                    queue.add(new int[]{this.base[position][index], dist[this.base[position][index]]});
                }
            }
            used[position] = true;
        }
        return dist[stop] == Integer.MAX_VALUE ? -1 : dist[stop];
    }

    protected static boolean solveFloydWarshall(int[][] base, int length, int not) {
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (base[i][k] == not || base[k][j] == not) {
                        continue;
                    }
                    int total = base[i][k] + base[k][j];
                    if (base[i][j] != not) {
                        base[i][j] = Math.min(base[i][j], total);
                    } else {
                        base[i][j] = total;
                    }
                }
            }
        }
        for (int index = 0; index < length; index++) {
            if (base[index][index] != 0) { 

                return false;
            }
        }
        return true;
    }

    protected static Pair<Long, int[][]> solveKruskal(int[][] edgesMatrix, final int countVertex, final int indexSort) {
        int[][] answer = new int[countVertex - 1][2];
        long sum = 0;
        Arrays.sort(edgesMatrix, Comparator.comparingInt(value -> value[indexSort]));
        SystemOfDisjointSets dsu = new SystemOfDisjointSets(countVertex);
        for (int i = 0; i < countVertex; i++) {
            dsu.makeSet(i);
        }
        int index = 0;
        for (int[] value : edgesMatrix) {
            if (dsu.mergeSets(value[0], value[1])) {
                sum += value[indexSort];
                answer[index] = new int[]{value[0], value[1]};
                index++;
            }
        }
        if (index < countVertex - 1) {
            return Pair.createPair(null, null);
        }
        return Pair.createPair(sum, answer);
    }

    static class SegmentTree {

        private int[] segmentArray;
        private BiFunction<Integer, Integer, Integer> function;

        protected void setSegmentArray(int[] segmentArray) {
            this.segmentArray = segmentArray;
        }

        protected int[] getSegmentArray() {
            return segmentArray.clone();
        }

        protected void setFunction(BiFunction<Integer, Integer, Integer> function) {
            this.function = function;
        }

        protected BiFunction<Integer, Integer, Integer> getFunction() {
            return function;
        }

        SegmentTree() {

        }

        SegmentTree(int[] startBase, int neutral, BiFunction<Integer, Integer, Integer> function) {
            this.function = function;
            int length = startBase.length;
            int[] base;
            if ((length & (length - 1)) != 0) {
                int pow = 0;
                while (length > 0) {
                    length >>= 1;
                    pow++;
                }
                pow--;
                base = new int[2 << pow];
                System.arraycopy(startBase, 0, base, 0, startBase.length);
                Arrays.fill(base, startBase.length, base.length, neutral);

            } else {
                base = startBase;
            }
            segmentArray = new int[base.length << 1]; 

            Arrays.fill(segmentArray, neutral);
            inDepth(base, 1, 0, base.length - 1);
        }

        private void inDepth(int[] base, int position, int low, int high) {
            if (low == high) {
                segmentArray[position] = base[low];
            } else {
                int mid = (low + high) >> 1;
                inDepth(base, position << 1, low, mid);
                inDepth(base, (position << 1) + 1, mid + 1, high);
                segmentArray[position] = function.apply(segmentArray[position << 1], segmentArray[(position << 1) + 1]);
            }
        }

        protected int getValue(int left, int right, int neutral) {
            return findValue(1, 0, ((segmentArray.length) >> 1) - 1, left, right, neutral);
        }

        private int findValue(int position, int low, int high, int left, int right, int neutral) {
            if (left > right) {
                return neutral;
            }
            if (left == low && right == high) {
                return segmentArray[position];
            }
            int mid = (low + high) >> 1;
            return function.apply(findValue(position << 1, low, mid, left, Math.min(right, mid), neutral),
                    findValue((position << 1) + 1, mid + 1, high, Math.max(left, mid + 1), right, neutral));
        }

        protected void replaceValue(int index, int value) {
            update(1, 0, (segmentArray.length >> 1) - 1, index, value);
        }

        private void update(int position, int low, int high, int index, int value) {
            if (low == high) {
                segmentArray[position] = value;
            } else {
                int mid = (low + high) >> 1;
                if (index <= mid) {
                    update(position << 1, low, mid, index, value);
                } else {
                    update((position << 1) + 1, mid + 1, high, index, value);
                }
                segmentArray[position] = function.apply(segmentArray[position << 1], segmentArray[(position << 1) + 1]);
            }
        }
    }

    static class SegmentTreeGeneric<T> {

        private Object[] segmentArray;
        private BiFunction<T, T, T> function;

        protected void setSegmentArray(T[] segmentArray) {
            this.segmentArray = segmentArray;
        }

        protected Object getSegmentArray() {
            return segmentArray.clone();
        }

        protected void setFunction(BiFunction<T, T, T> function) {
            this.function = function;
        }

        protected BiFunction<T, T, T> getFunction() {
            return function;
        }

        SegmentTreeGeneric() {

        }

        SegmentTreeGeneric(T[] startBase, T neutral, BiFunction<T, T, T> function) {
            this.function = function;
            int length = startBase.length;
            Object[] base;
            if ((length & (length - 1)) != 0) {
                int pow = 0;
                while (length > 0) {
                    length >>= 1;
                    pow++;
                }
                pow--;
                base = new Object[2 << pow];
                System.arraycopy(startBase, 0, base, 0, startBase.length);
                Arrays.fill(base, startBase.length, base.length, neutral);

            } else {
                base = startBase;
            }
            segmentArray = new Object[base.length << 1]; 

            Arrays.fill(segmentArray, neutral);
            inDepth(base, 1, 0, base.length - 1);
        }

        private void inDepth(Object[] base, int position, int low, int high) {
            if (low == high) {
                segmentArray[position] = base[low];
            } else {
                int mid = (low + high) >> 1;
                inDepth(base, position << 1, low, mid);
                inDepth(base, (position << 1) + 1, mid + 1, high);
                segmentArray[position] = function.apply((T) segmentArray[position << 1], (T) segmentArray[(position << 1) + 1]);
            }
        }

        protected T getValue(int left, int right, T neutral) {
            return findValue(1, 0, ((segmentArray.length) >> 1) - 1, left, right, neutral);
        }

        private T findValue(int position, int low, int high, int left, int right, T neutral) {
            if (left > right) {
                return neutral;
            }
            if (left == low && right == high) {
                return (T) segmentArray[position];
            }
            int mid = (low + high) >> 1;
            return function.apply(findValue(position << 1, low, mid, left, Math.min(right, mid), neutral),
                    findValue((position << 1) + 1, mid + 1, high, Math.max(left, mid + 1), right, neutral));
        }

        protected void replaceValue(int index, T value) {
            update(1, 0, (segmentArray.length >> 1) - 1, index, value);
        }

        private void update(int position, int low, int high, int index, T value) {
            if (low == high) {
                segmentArray[position] = value;
            } else {
                int mid = (low + high) >> 1;
                if (index <= mid) {
                    update(position << 1, low, mid, index, value);
                } else {
                    update((position << 1) + 1, mid + 1, high, index, value);
                }
                segmentArray[position] = function.apply((T) segmentArray[position << 1], (T) segmentArray[(position << 1) + 1]);
            }
        }
    }
}

class SystemOfDisjointSets {

    private int[] rank;
    private int[] dsu;

    SystemOfDisjointSets(int size) {
        this.rank = new int[size];
        this.dsu = new int[size];
    }

    protected void makeSet(int value) {
        dsu[value] = value;
        rank[value] = 0;
    }

    protected int findSet(int value) {
        if (value == dsu[value]) {
            return value;
        }
        return dsu[value] = findSet(dsu[value]);
    }

    protected boolean mergeSets(int first, int second) {
        first = findSet(first);
        second = findSet(second);
        if (first != second) {
            if (rank[first] < rank[second]) {
                int number = first;
                first = second;
                second = number;
            }
            dsu[second] = first;
            if (rank[first] == rank[second]) {
                rank[first]++;
            }
            return true;
        }
        return false;
    }
}

interface Array {
    void useArray(int[] a);
}

interface Method<T> {
    void use(T value);
}


class BigNumber {

    private static int size = 100;

    private static int[] pr = new int[size];
    private static int[][] r = new int[size][size];
    private int[] a = new int[size];

    static void init() {
        for (int x = 1000_000_000, i = 0; i < size; ++x)
            if (BigInteger.valueOf(x).isProbablePrime(100))
                pr[i++] = x;

        for (int i = 0; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
                r[i][j] = BigInteger.valueOf(pr[i]).modInverse(
                        BigInteger.valueOf(pr[j])).intValue();
    }

    public BigNumber() {
    }

    public BigNumber(int n) {
        for (int i = 0; i < size; ++i)
            a[i] = n % pr[i];
    }

    public BigNumber(BigInteger n) {
        for (int i = 0; i < size; ++i)
            a[i] = n.mod(BigInteger.valueOf(pr[i])).intValue();
    }

    public BigNumber add(BigNumber n) {
        BigNumber result = new BigNumber();
        for (int i = 0; i < size; ++i)
            result.a[i] = (a[i] + n.a[i]) % pr[i];
        return result;
    }

    public BigNumber subtract(BigNumber n) {
        BigNumber result = new BigNumber();
        for (int i = 0; i < size; ++i)
            result.a[i] = (a[i] - n.a[i] + pr[i]) % pr[i];
        return result;
    }

    public BigNumber multiply(BigNumber n) {
        BigNumber result = new BigNumber();
        for (int i = 0; i < size; ++i)
            result.a[i] = (int) (((long) a[i] * n.a[i]) % pr[i]);
        return result;
    }

    public BigInteger bigIntegerValue(boolean can_be_negative) {
        BigInteger result = BigInteger.ZERO,
                mult = BigInteger.ONE;
        int[] x = new int[size];
        for (int i = 0; i < size; ++i) {
            x[i] = a[i];
            for (int j = 0; j < i; ++j) {
                long cur = (long) (x[i] - x[j]) * r[j][i];
                x[i] = (int) ((cur % pr[i] + pr[i]) % pr[i]);
            }
            result = result.add(mult.multiply(BigInteger.valueOf(x[i])));
            mult = mult.multiply(BigInteger.valueOf(pr[i]));
        }

        if (can_be_negative)
            if (result.compareTo(mult.shiftRight(1)) >= 0)
                result = result.subtract(mult);

        return result;
    }
}

class FastSort {

    enum TypeSort {
        RANDOM,
        SHELL,
        HEAP,
        MERGE,
        STRAIGHT_MERGE,
        INSERTION

    }

    protected static int[] sort(int[] array, TypeSort typeSort) {
        sort(array, typeSort, array.length);
        return array;
    }

    protected static int[] sortClone(int[] array, TypeSort typeSort) {
        int[] base = array.clone();
        sort(base, typeSort, array.length);
        return base;
    }

    private static void sort(int[] array, TypeSort typeSort, int length) {
        if (typeSort == null || typeSort == TypeSort.RANDOM) {
            Random random = new Random();
            int index = random.nextInt(4) + 1;
            typeSort = TypeSort.values()[index];
        }
        switch (typeSort) {
            case SHELL:
                ShellSort(array);
                break;
            case HEAP:
                HeapSort(array);
                break;
            case MERGE:
                MergeSort(array, 0, length - 1);
                break;
            case STRAIGHT_MERGE:
                straightMergeSort(array, length);
                break;
            case INSERTION:
                insertionSort(array);
                break;

        }
    }

    private static void straightMergeSort(int[] array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size >> 1) + ((size % 2) == 0 ? 0 : 1);
        Integer[][] ZeroBuffer = new Integer[length + length % 2][2];
        Integer[][] FirstBuffer = new Integer[0][0];
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index << 1;
            int NextArrayIndex = (index << 1) + 1;
            if (NextArrayIndex < size) {
                if (array[ArrayIndex] > array[NextArrayIndex]) {
                    ZeroBuffer[index][0] = array[NextArrayIndex];
                    ZeroBuffer[index][1] = array[ArrayIndex];
                } else {
                    ZeroBuffer[index][0] = array[ArrayIndex];
                    ZeroBuffer[index][1] = array[NextArrayIndex];
                }
            } else {
                ZeroBuffer[index][0] = array[ArrayIndex];
            }
        }
        boolean position = false;
        int pointer0, pointer, pointer1, number = 4, NewPointer, count;
        Integer[][] NewBuffer;
        Integer[][] OldBuffer;
        length = (size >> 2) + ((size % 4) == 0 ? 0 : 1);
        while (true) {
            pointer0 = 0;
            count = (number >> 1) - 1;
            if (!position) {
                FirstBuffer = new Integer[length + length % 2][number];
                NewBuffer = FirstBuffer;
                OldBuffer = ZeroBuffer;
            } else {
                ZeroBuffer = new Integer[length + length % 2][number];
                NewBuffer = ZeroBuffer;
                OldBuffer = FirstBuffer;
            }
            for (int i = 0; i < length; i++) {
                pointer = 0;
                pointer1 = 0;
                NewPointer = pointer0 + 1;
                if (length == 1) {
                    for (int g = 0; g < size; g++) {
                        if (pointer > count || OldBuffer[pointer0][pointer] == null) {
                            array[g] = OldBuffer[NewPointer][pointer1];
                            pointer1++;
                        } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == null) {
                            if (OldBuffer[pointer0][pointer] == null) {
                                continue;
                            }
                            array[g] = OldBuffer[pointer0][pointer];
                            pointer++;
                        } else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                            array[g] = OldBuffer[NewPointer][pointer1];
                            pointer1++;
                        } else {
                            array[g] = OldBuffer[pointer0][pointer];
                            pointer++;
                        }
                    }
                    return;
                }
                for (int g = 0; g < number; g++) {
                    if (pointer > count || OldBuffer[pointer0][pointer] == null) {
                        if (OldBuffer[NewPointer][pointer1] == null) {
                            continue;
                        }
                        NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else if (pointer1 > count || OldBuffer[NewPointer][pointer1] == null) {
                        if (OldBuffer[pointer0][pointer] == null) {
                            continue;
                        }
                        NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    } else if (OldBuffer[pointer0][pointer] >= OldBuffer[NewPointer][pointer1]) {
                        NewBuffer[i][g] = OldBuffer[NewPointer][pointer1];
                        pointer1++;
                    } else {
                        NewBuffer[i][g] = OldBuffer[pointer0][pointer];
                        pointer++;
                    }
                }
                pointer0 += 2;
            }
            position = !position;
            length = (length >> 1) + length % 2;
            number <<= 1;
        }
    }

    private static void ShellSort(int[] array) {
        int j;
        for (int gap = (array.length >> 1); gap > 0; gap >>= 1) {
            for (int i = gap; i < array.length; i++) {
                int temp = array[i];
                for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                    array[j] = array[j - gap];
                }
                array[j] = temp;
            }
        }
    }

    private static void HeapSort(int[] array) {
        for (int i = (array.length >> 1) - 1; i >= 0; i--)
            shiftDown(array, i, array.length);
        for (int i = array.length - 1; i > 0; i--) {
            swap(array, 0, i);
            shiftDown(array, 0, i);
        }
    }

    private static void shiftDown(int[] array, int i, int n) {
        int child;
        int tmp;
        for (tmp = array[i]; leftChild(i) < n; i = child) {
            child = leftChild(i);
            if (child != n - 1 && (array[child] < array[child + 1]))
                child++;
            if (tmp < array[child])
                array[i] = array[child];
            else
                break;
        }
        array[i] = tmp;
    }

    private static int leftChild(int i) {
        return (i << 1) + 1;
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    private static void MergeSort(int[] array, int low, int high) {
        if (low < high) {
            int mid = (low + high) >> 1;
            MergeSort(array, low, mid);
            MergeSort(array, mid + 1, high);
            merge(array, low, mid, high);
        }
    }

    private static void merge(int[] array, int low, int mid, int high) {
        int n = high - low + 1;
        int[] Temp = new int[n];
        int i = low, j = mid + 1;
        int k = 0;
        while (i <= mid || j <= high) {
            if (i > mid)
                Temp[k++] = array[j++];
            else if (j > high)
                Temp[k++] = array[i++];
            else if (array[i] < array[j])
                Temp[k++] = array[i++];
            else
                Temp[k++] = array[j++];
        }
        for (j = 0; j < n; j++)
            array[low + j] = Temp[j];
    }

    private static void insertionSort(int[] elements) {
        for (int i = 1; i < elements.length; i++) {
            int key = elements[i];
            int j = i - 1;
            while (j >= 0 && key < elements[j]) {
                elements[j + 1] = elements[j];
                j--;
            }
            elements[j + 1] = key;
        }
    }
}

class IO {

    private static BufferedReader read;
    private static boolean fileInput = false;
    private static BufferedWriter write;
    private static boolean fileOutput = false;

    public static void setFileInput(boolean fileInput) {
        IO.fileInput = fileInput;
    }

    public static void setFileOutput(boolean fileOutput) {
        IO.fileOutput = fileOutput;
    }

    private static void startInput() {
        try {
            read = new BufferedReader(fileInput ? new FileReader("input.txt") : new InputStreamReader(System.in));
        } catch (Exception error) {
        }
    }

    private static void startOutput() {
        try {
            write = new BufferedWriter(fileOutput ? new FileWriter("output.txt") : new OutputStreamWriter(System.out));
        } catch (Exception error) {
        }
    }

    protected static int readInt() throws IOException {
        if (read == null) {
            startInput();
        }
        return Integer.parseInt(read.readLine());
    }

    protected static long readLong() throws IOException {
        if (read == null) {
            startInput();
        }
        return Long.parseLong(read.readLine());
    }

    protected static String readString() throws IOException {
        if (read == null) {
            startInput();
        }
        return read.readLine();
    }

    protected static int[] readArrayInt(String split) throws IOException {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToInt(Integer::parseInt).toArray();
    }

    protected static long[] readArrayLong(String split) throws IOException {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToLong(Long::parseLong).toArray();
    }

    protected static String[] readArrayString(String split) throws IOException {
        if (read == null) {
            startInput();
        }
        return read.readLine().split(split);
    }

    protected static void writeArray(int[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(Integer.toString(array[index]));
                if (index + 1 != length) {
                    write.write(split);
                }
            }
            if (enter) {
                writeEnter();
            }
        } catch (Exception error) {
        }
    }

    protected static void writeArray(Integer[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(Integer.toString(array[index]));
                if (index + 1 != length) {
                    write.write(split);
                }
            }
            if (enter) {
                writeEnter();
            }
        } catch (Exception error) {
        }
    }

    protected static void writeArray(long[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(Long.toString(array[index]));
                if (index + 1 != length) {
                    write.write(split);
                }
            }
            if (enter) {
                writeEnter();
            }
        } catch (Exception error) {
        }
    }

    protected static void writeArray(Long[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(Long.toString(array[index]));
                if (index + 1 != length) {
                    write.write(split);
                }
            }
            if (enter) {
                writeEnter();
            }
        } catch (Exception error) {
        }
    }

    public static void writeArray(String[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(String.join(split, array));
            if (enter) {
                writeEnter();
            }
        } catch (Exception ignored) {
        }
    }

    public static void writeArray(char[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(array[index]);
                if (index + 1 != length) {
                    write.write(split);
                }
            }
            if (enter) {
                writeEnter();
            }
        } catch (Exception ignored) {
        }
    }

    protected static void writeArray(boolean[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(Boolean.toString(array[index]));
                if (index + 1 != length) {
                    write.write(split);
                }
            }
            if (enter) {
                writeEnter();
            }
        } catch (Exception ignored) {
        }
    }

    protected static void writeInt(int number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Integer.toString(number));
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeInt(Integer number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Integer.toString(number));
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeLong(long number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Long.toString(number));
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeLong(Long number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Long.toString(number));
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeString(String word, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeBoolean(boolean value, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(value ? "true" : "false");
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeBoolean(Boolean value, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(value ? "true" : "false");
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeChar(char word, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(end);
        } catch (Exception ignored) {
        }
    }

    protected static void writeChar(Character word, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(end);
        } catch (Exception ignored) {
        }
    }


    protected static void writeEnter() {
        if (write == null) {
            startOutput();
        }
        try {
            write.newLine();
        } catch (Exception ignored) {
        }
    }

    protected static void print(boolean exit) throws IOException {
        if (exit) {
            print();
        } else {
            write.flush();
        }
    }

    protected static void print() throws IOException {
        if (write == null) {
            return;
        }
        write.flush();
        if (read != null) {
            read.close();
        }
        write.close();
    }
}

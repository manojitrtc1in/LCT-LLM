


import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.function.BiFunction;

public class Main extends IO {

    public static void main(String[] args) throws Exception {
        final int dec = 97;
        int i1 = readInt();
        for (int test = 0; test < i1; test++){
            int[] quantity = id9(" ");
            String[] word = id10("");
            int[] countTrue = FastSort.sort(id9(" "), 3);
            int[] ans = new int[26];
            int index = 0;
            cycle:
            for (int i = 0; i < quantity[0]; i++){
                while (i >= countTrue[index]) {
                    index++;
                    if (index == countTrue.length){
                        for (int j = i; j < quantity[0]; j++){
                            ans[(int) word[j].charAt(0) - dec] += 1;
                        }
                        break cycle;
                    }
                }
                ans[(int) word[i].charAt(0) - dec] += quantity[1] - index + 1;
            }
            writeArray(ans, " ", true);
        }
        print();
    }
}

class math {

    protected static int remains = 0x989687;

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

    protected static double log(double value, int base) {
        return Math.log(value) / Math.log(base);
    }

    protected static long factorial(int number) {
        if (number < 0) {
            return 0;
        }
        return id8(number);
    }

    private static long id8(int number) {
        if (number > 0) {
            return id8(number - 1) * number;
        }
        return 1;
    }
}

class Int implements Comparable<Integer> {

    protected int value;

    Int(int value) {
        this.value = value;
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
        if (id21() instanceof Integer) {
            Integer Dividend = (Integer) id21();
            Integer Divider = (Integer) id12();
            int gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id21() instanceof Long) {
            Long Dividend = (Long) id21();
            Long Divider = (Long) id12();
            long gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id21() instanceof Float) {
            Float Dividend = (Float) id21();
            Float Divider = (Float) id12();
            float gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id21() instanceof Double) {
            Double Dividend = (Double) id21();
            Double Divider = (Double) id12();
            double gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        }
    }

    protected void id5(Fraction number) throws UnsupportedOperationException {
        add(number, 0);
    }

    private Fraction add(Fraction number, int function) throws UnsupportedOperationException {
        if (id21() instanceof Integer && number.id21() instanceof Integer) {
            Integer Dividend = (Integer) id21();
            Integer Divider = (Integer) id12();
            Integer Dividend1 = (Integer) number.id21();
            Integer Divider1 = (Integer) number.id12();
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

        } else if (id21() instanceof Long && number.id21() instanceof Long) {
            Long Dividend = (Long) id21();
            Long Divider = (Long) id12();
            Long Dividend1 = (Long) number.id21();
            Long Divider1 = (Long) number.id12();
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
        } else if (id21() instanceof Float && number.id21() instanceof Float) {
            Float Dividend = (Float) id21();
            Float Divider = (Float) id12();
            Float Dividend1 = (Float) number.id21();
            Float Divider1 = (Float) number.id12();
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
        } else if (id21() instanceof Double && number.id21() instanceof Double) {
            Double Dividend = (Double) id21();
            Double Divider = (Double) id12();
            Double Dividend1 = (Double) number.id21();
            Double Divider1 = (Double) number.id12();
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

    protected Fraction id1(Fraction number) {
        return add(number, 1);
    }

    protected void id14(Fraction number) throws UnsupportedOperationException {
        multiply(number, 0);
    }

    protected Fraction id15(Fraction number) throws UnsupportedOperationException {
        return multiply(number, 1);
    }

    private Fraction multiply(Fraction number, int function) throws UnsupportedOperationException {
        if (id21() instanceof Integer && number.id21() instanceof Integer) {
            Integer first = (Integer) id21() * (Integer) number.id21();
            Integer second = (Integer) id12() * (Integer) number.id12();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else if (id21() instanceof Long && number.id21() instanceof Long) {
            Long first = (Long) id21() * (Long) number.id21();
            Long second = (Long) id12() * (Long) number.id12();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;

        } else if (id21() instanceof Float && number.id21() instanceof Float) {
            Float first = (Float) id21() * (Float) number.id21();
            Float second = (Float) id12() * (Float) number.id12();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else if (id21() instanceof Double && number.id21() instanceof Double) {
            Double first = (Double) id21() * (Double) number.id21();
            Double second = (Double) id12() * (Double) number.id12();
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

    protected T id21() {
        return first;
    }

    protected T1 id12() {
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
        return base.clone();
    }

    public boolean[] getUsed() {
        return used.clone();
    }

    public int getQuantity() {
        return quantity;
    }

    public Integer[] getAncestor() {
        return ancestor.clone();
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


    protected void id22(int length, int quantity, boolean readConsole, int[][] value) throws Exception {
        base = new int[length][];
        List<ArrayList<Integer>> inputBase = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            inputBase.add(new ArrayList<>());
        }
        for (int i = 0; i < quantity; i++) {
            int[] input = readConsole ? IO.id9(" ") : value[i];
            inputBase.get(input[0] - 1).add(input[1] - 1);
            

            inputBase.get(input[1] - 1).add(input[0] - 1);
            

        }
        for (int i = 0; i < length; i++) {
            base[i] = inputBase.get(i).stream().mapToInt(Integer::intValue).toArray();
        }
        start(length);
    }

    protected void id11(int length, int not, boolean readConsole, int[][] value) throws Exception {
        this.base = new int[length][];
        List<Integer> buffer = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            int[] InputArray = readConsole ? IO.id9(" ") : value[i];
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

    protected void dfs(int position) throws Exception {
        used[position] = true;
        quantity++;
        int next;
        for (int index = 0; index < base[position].length; index++) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            } 
        }
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

    protected static boolean id0(int[][] base, int length, int not) {
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

    protected static Pair<Long, int[][]> id16(int[][] edgesMatrix, final int countVertex, final int indexSort) {
        int[][] answer = new int[countVertex - 1][2];
        long sum = 0;
        Arrays.sort(edgesMatrix, Comparator.comparingInt(value -> value[indexSort]));
        id6 dsu = new id6(countVertex);
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

        protected void id4(int[] segmentArray) {
            this.segmentArray = segmentArray;
        }

        protected int[] id23() {
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

    static class id19<T> {

        private Object[] segmentArray;
        private BiFunction<T, T, T> function;

        protected void id4(T[] segmentArray) {
            this.segmentArray = segmentArray;
        }

        protected Object id23() {
            return segmentArray.clone();
        }

        protected void setFunction(BiFunction<T, T, T> function) {
            this.function = function;
        }

        protected BiFunction<T, T, T> getFunction() {
            return function;
        }

        id19() {

        }

        id19(T[] startBase, T neutral, BiFunction<T, T, T> function) {
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

class id6 {

    private int[] rank;
    private int[] ancestor;

    id6(int size) {
        this.rank = new int[size];
        this.ancestor = new int[size];
    }

    protected void makeSet(int value) {
        ancestor[value] = value;
        rank[value] = 0;
    }

    protected int findSet(int value) {
        if (value == ancestor[value]) {
            return value;
        }
        return ancestor[value] = findSet(ancestor[value]);
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
            ancestor[second] = first;
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

interface Method {
    void use();
}

class FastSort {

    protected static int[] sort(int[] array, int id17) {
        sort(array, id17, array.length);
        return array;
    }

    protected static int[] sortClone(int[] array, int id17) {
        int[] base = array.clone();
        sort(base, id17, array.length);
        return base;
    }

    private static void sort(int[] array, int id17, int length) {
        if (id17 < 0 || id17 > 4) {
            Random random = new Random();
            id17 = random.nextInt(4);
        }
        if (id17 == 0) {
            ShellSort(array);
        } else if (id17 == 1) {
            HeapSort(array);
        } else if (id17 == 2) {
            MergeSort(array, 0, length - 1);
        } else if (id17 == 3) {
            id13(array, length);
        } else if (id17 == 4) {
            id7(array);
        }
    }

    private static void id13(int[] array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size >> 1) + ((size % 2) == 0 ? 0 : 1);
        Integer[][] ZeroBuffer = new Integer[length + length % 2][2];
        Integer[][] FirstBuffer = new Integer[0][0];
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index << 1;
            int id20 = (index << 1) + 1;
            if (id20 < size) {
                if (array[ArrayIndex] > array[id20]) {
                    ZeroBuffer[index][0] = array[id20];
                    ZeroBuffer[index][1] = array[ArrayIndex];
                } else {
                    ZeroBuffer[index][0] = array[ArrayIndex];
                    ZeroBuffer[index][1] = array[id20];
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

    private static void id7(int[] elements) {
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

    public static void id2(boolean fileInput) {
        IO.fileInput = fileInput;
    }

    public static void id18(boolean fileOutput) {
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

    protected static int readInt() throws Exception {
        if (read == null) {
            startInput();
        }
        return Integer.parseInt(read.readLine());
    }

    protected static long readLong() throws Exception {
        if (read == null) {
            startInput();
        }
        return Long.parseLong(read.readLine());
    }

    protected static String readString() throws Exception {
        if (read == null) {
            startInput();
        }
        return read.readLine();
    }

    protected static int[] id9(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToInt(Integer::parseInt).toArray();
    }

    protected static long[] id3(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToLong(Long::parseLong).toArray();
    }

    protected static String[] id10(String split) throws Exception {
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

    protected static void writeArray(Int[] array, String split, boolean enter) {
        if (write == null) {
            startOutput();
        }
        try {
            int length = array.length;
            for (int index = 0; index < length; index++) {
                write.write(Integer.toString(array[index].value));
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

    protected static void print(boolean exit) throws Exception {
        if (exit) {
            print();
        } else {
            write.flush();
        }
    }

    protected static void print() throws Exception {
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

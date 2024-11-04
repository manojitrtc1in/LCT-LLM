


import java.io.*;
import java.lang.*;
import java.util.*;

public class Main extends IO {

    private static long result = 0;
    private static boolean full = true;

    public static void main(String[] args) throws Exception {
        int quantity = readInt();
        for (int i = 0; i < quantity; i++) {
            int[] count = id7(" ");
            int[] base = id7(" ");
            int l = 0;
            int r = base.length + 1;
            while (l + 1 < r) {
                int mid = (l + r) >> 1;
                if (check(mid, base, count[1])) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            writeLong(full ? 0 : result, "\n");
        }
        print();
    }

    private static boolean check(long value, int[] base, long time) {
        long max = Long.MIN_VALUE;
        long index = 0;
        long sum = 0;
        for (int i = 0; i < value; i++) {
            if (max < base[i]) {
                max = base[i];
                index = i;
            }
            sum += base[i];
        }
        if (sum <= time) {
            result = index + 1;
            full = true;
            return true;
        } else if ((sum - max) <= time) {
            result = index + 1;
            full = false;
            return true;
        } else {
            return false;
        }
    }
}

class math {

    protected static int remains = 0x3B800001;

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
        return id5(number);
    }

    private static long id5(int number) {
        if (number > 0) {
            return id5(number - 1) * number;
        }
        return 1;
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
        if (id18() instanceof Integer) {
            Integer Dividend = (Integer) id18();
            Integer Divider = (Integer) id10();
            int gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id18() instanceof Long) {
            Long Dividend = (Long) id18();
            Long Divider = (Long) id10();
            long gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id18() instanceof Float) {
            Float Dividend = (Float) id18();
            Float Divider = (Float) id10();
            float gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id18() instanceof Double) {
            Double Dividend = (Double) id18();
            Double Divider = (Double) id10();
            double gcd = math.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        }
    }

    protected void id3(Fraction number) throws UnsupportedOperationException {
        add(number, 0);
    }

    private Fraction add(Fraction number, int function) throws UnsupportedOperationException {
        if (id18() instanceof Integer && number.id18() instanceof Integer) {
            Integer Dividend = (Integer) id18();
            Integer Divider = (Integer) id10();
            Integer Dividend1 = (Integer) number.id18();
            Integer Divider1 = (Integer) number.id10();
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

        } else if (id18() instanceof Long && number.id18() instanceof Long) {
            Long Dividend = (Long) id18();
            Long Divider = (Long) id10();
            Long Dividend1 = (Long) number.id18();
            Long Divider1 = (Long) number.id10();
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
        } else if (id18() instanceof Float && number.id18() instanceof Float) {
            Float Dividend = (Float) id18();
            Float Divider = (Float) id10();
            Float Dividend1 = (Float) number.id18();
            Float Divider1 = (Float) number.id10();
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
        } else if (id18() instanceof Double && number.id18() instanceof Double) {
            Double Dividend = (Double) id18();
            Double Divider = (Double) id10();
            Double Dividend1 = (Double) number.id18();
            Double Divider1 = (Double) number.id10();
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

    protected Fraction id0(Fraction number) {
        return add(number, 1);
    }

    protected void id13(Fraction number) throws UnsupportedOperationException {
        multiply(number, 0);
    }

    protected Fraction id14(Fraction number) throws UnsupportedOperationException {
        return multiply(number, 1);
    }

    private Fraction multiply(Fraction number, int function) throws UnsupportedOperationException {
        if (id18() instanceof Integer && number.id18() instanceof Integer) {
            Integer first = (Integer) id18() * (Integer) number.id18();
            Integer second = (Integer) id10() * (Integer) number.id10();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else if (id18() instanceof Long && number.id18() instanceof Long) {
            Long first = (Long) id18() * (Long) number.id18();
            Long second = (Long) id10() * (Long) number.id10();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;

        } else if (id18() instanceof Float && number.id18() instanceof Float) {
            Float first = (Float) id18() * (Float) number.id18();
            Float second = (Float) id10() * (Float) number.id10();
            if (function == 0) {
                setFirst(first);
                setSecond(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createFraction(first, second);
            answer.reduce();
            return answer;
        } else if (id18() instanceof Double && number.id18() instanceof Double) {
            Double first = (Double) id18() * (Double) number.id18();
            Double second = (Double) id10() * (Double) number.id10();
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

class Pair<T, T1> {

    private T first;
    private T1 second;

    Pair(T obj, T1 obj1) {
        first = obj;
        second = obj1;
    }

    protected static <T, T1> Pair<T, T1> createPair(T element, T1 element1) {
        return new Pair<>(element, element1);
    }

    protected T id18() {
        return first;
    }

    protected T1 id10() {
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

    public void start(int length) {
        used = new boolean[length];
        ancestor = new Integer[length];
        Arrays.fill(ancestor, -1);
        quantity = 0;
    }

    public void id6(int length, int quantity, boolean readConsole, int[][] value) throws Exception {
        base = new int[length][];
        List<ArrayList<Integer>> inputBase = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            inputBase.add(new ArrayList<>());
        }
        for (int i = 0; i < quantity; i++) {
            int[] input = readConsole ? IO.id7(" ") : value[i];
            inputBase.get(input[0] - 1).add(input[1] - 1);
            

            inputBase.get(input[1] - 1).add(input[0] - 1);
            

        }
        for (int i = 0; i < length; i++) {
            base[i] = inputBase.get(i).stream().mapToInt(Integer::intValue).toArray();
        }
        start(length);
    }

    public void id9(int length, int not, boolean readConsole, int[][] value) throws Exception {
        base = new int[length][];
        List<Integer> buffer = new ArrayList<>();
        int[] InputArray;
        for (int i = 0; i < length; i++) {
            InputArray = readConsole ? IO.id7(" ") : value[i];
            for (int index = 0; index < length; index++) {
                if (i != index && InputArray[index] != not) {
                    buffer.add(index);
                    

                }
            }
            base[i] = buffer.stream().mapToInt(Integer::intValue).toArray();
            buffer.clear();
        }
        start(length);
    }

    public void dfs(int position) throws Exception {
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

    public int dijkstra(int start, int stop, int size) {
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
            for (int index = 0; index < base[position].length; index += 2) {
                if (dist[position] + base[position][index + 1] < dist[base[position][index]] && !used[base[position][index]]) {
                    dist[base[position][index]] = dist[position] + base[position][index + 1];
                    ancestor[base[position][index]] = position;
                    queue.add(new int[]{base[position][index], dist[base[position][index]]});
                }
            }
            used[position] = true;
        }
        return dist[stop] == Integer.MAX_VALUE ? -1 : dist[stop];
    }

    public static boolean id11(int[][] base, int length, int not) {
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
}

interface Array {
    void useArray(int[] a);
}

interface Method {
    void use();
}

class FastSort {

    protected static int[] sort(int[] array, int id15) {
        sort(array, id15, array.length);
        return array;
    }

    protected static int[] sortClone(int[] array, int id15) {
        int[] base = array.clone();
        sort(base, id15, array.length);
        return base;
    }

    private static void sort(int[] array, int id15, int length) {
        if (id15 < 0 || id15 > 4) {
            Random random = new Random();
            id15 = random.nextInt(4);
        }
        if (id15 == 0) {
            ShellSort(array);
        } else if (id15 == 1) {
            HeapSort(array);
        } else if (id15 == 2) {
            MergeSort(array, 0, length - 1);
        } else if (id15 == 3) {
            id12(array, length);
        } else if (id15 == 4) {
            id4(array);
        }
    }

    private static void id12(int[] array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size / 2) + ((size % 2) == 0 ? 0 : 1);
        Integer[][] ZeroBuffer = new Integer[length + length % 2][2];
        Integer[][] FirstBuffer = new Integer[0][0];
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index * 2;
            int id17 = index * 2 + 1;
            if (id17 < size) {
                if (array[ArrayIndex] > array[id17]) {
                    ZeroBuffer[index][0] = array[id17];
                    ZeroBuffer[index][1] = array[ArrayIndex];
                } else {
                    ZeroBuffer[index][0] = array[ArrayIndex];
                    ZeroBuffer[index][1] = array[id17];
                }
            } else {
                ZeroBuffer[index][0] = array[ArrayIndex];
            }
        }
        boolean position = false;
        int pointer0, pointer, pointer1, number = 4, NewPointer, count;
        Integer[][] NewBuffer;
        Integer[][] OldBuffer;
        length = (size / 4) + ((size % 4) == 0 ? 0 : 1);
        while (true) {
            pointer0 = 0;
            count = (number / 2) - 1;
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
            length = length / 2 + length % 2;
            number *= 2;
        }
    }

    private static void ShellSort(int[] array) {
        int j;
        for (int gap = array.length / 2; gap > 0; gap /= 2) {
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
        for (int i = array.length / 2 - 1; i >= 0; i--)
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
        return 2 * i + 1;
    }

    private static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    private static void MergeSort(int[] array, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
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

    private static void id4(int[] elements) {
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

    public static void id1(boolean fileInput) {
        IO.fileInput = fileInput;
    }

    public static void id16(boolean fileOutput) {
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

    protected static int[] id7(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToInt(Integer::parseInt).toArray();
    }

    protected static long[] id2(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToLong(Long::parseLong).toArray();
    }

    protected static String[] id8(String split) throws Exception {
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
        read.close();
        write.close();
    }
}

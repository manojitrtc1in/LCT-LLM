


import java.io.*;
import java.lang.*;
import java.util.*;

public class Main extends IO {

    public static void main(String[] args) throws Exception {
        int[] quantity = id22(" ");
        int[] base = FastSort.id7(id22(" "), quantity[0], 3);
        long sum = 0;
        int start = quantity[0] >>> 1;
        for (int i = start; i < quantity[0] - 1; i++){
            sum += (base[i + 1] - base[i]) * ((long) i - start + 1);
            if (sum == quantity[1]){
                System.out.print(base[i + 1]);
                return;
            }else if (sum > quantity[1]){
                sum -= (base[i + 1] - base[i]) * ((long) i - start + 1);
                System.out.print(base[i] + (quantity[1] - sum) / (i + 1 - start));
                return;
            }
        }
        System.out.print(base[quantity[0] - 1] + (quantity[1] - sum)/(quantity[0] - start));
    }
}

class math {

    public static int gcd(int a, int b) { 

        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static float gcd(float a, float b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static double gcd(double a, double b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static double lcm(double a, double b) { 

        return a / gcd(a, b) * b;
    }

    public static float lcm(float a, float b) { 

        return a / gcd(a, b) * b;
    }

    public static int lcm(int a, int b) { 

        return a / gcd(a, b) * b;
    }

    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    public static double log(double value, int base) {
        return Math.log(value) / Math.log(base);
    }
}

class Fraction<T extends Number> extends Pair {

    private Fraction(T dividend, T divider) {
        super(dividend, divider);
        reduce();
    }

    public static <K extends Number> Fraction<K> createDivision(K dividend, K divider) {
        return new Fraction<>(dividend, divider);
    }

    public void reduce() {
        if (id21() instanceof Integer) {
            Integer Dividend = (Integer) id21();
            Integer Divider = (Integer) id12();
            int gcd = math.gcd(Dividend, Divider);
            id9(Dividend / gcd);
            id1(Divider / gcd);
        } else if (id21() instanceof Long) {
            Long Dividend = (Long) id21();
            Long Divider = (Long) id12();
            long gcd = math.gcd(Dividend, Divider);
            id9(Dividend / gcd);
            id1(Divider / gcd);
        } else if (id21() instanceof Float) {
            Float Dividend = (Float) id21();
            Float Divider = (Float) id12();
            float gcd = math.gcd(Dividend, Divider);
            id9(Dividend / gcd);
            id1(Divider / gcd);
        } else if (id21() instanceof Double) {
            Double Dividend = (Double) id21();
            Double Divider = (Double) id12();
            double gcd = math.gcd(Dividend, Divider);
            id9(Dividend / gcd);
            id1(Divider / gcd);
        }
    }

    public void id4(Fraction number) throws UnsupportedOperationException {
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
                id9((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                id1(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createDivision((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;

        } else if (id21() instanceof Long && number.id21() instanceof Long) {
            Long Dividend = (Long) id21();
            Long Divider = (Long) id12();
            Long Dividend1 = (Long) number.id21();
            Long Divider1 = (Long) number.id12();
            Long lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                id9((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                id1(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createDivision((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;
        } else if (id21() instanceof Float && number.id21() instanceof Float) {
            Float Dividend = (Float) id21();
            Float Divider = (Float) id12();
            Float Dividend1 = (Float) number.id21();
            Float Divider1 = (Float) number.id12();
            Float lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                id9((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                id1(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createDivision((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;
        } else if (id21() instanceof Double && number.id21() instanceof Double) {
            Double Dividend = (Double) id21();
            Double Divider = (Double) id12();
            Double Dividend1 = (Double) number.id21();
            Double Divider1 = (Double) number.id12();
            Double lcm = math.lcm(Divider, Divider1);
            if (function == 0) {
                id9((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
                id1(lcm);
                reduce();
                return null;
            }
            Fraction result = Fraction.createDivision((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1, lcm);
            result.reduce();
            return result;
        } else {
            throw new UnsupportedOperationException();
        }
    }

    public Fraction id2(Fraction number) {
        return add(number, 1);
    }

    public void id14(Fraction number) throws UnsupportedOperationException {
        multiply(number, 0);
    }

    public Fraction id15(Fraction number) throws UnsupportedOperationException {
        return multiply(number, 1);
    }

    private Fraction multiply(Fraction number, int function) throws UnsupportedOperationException {
        if (id21() instanceof Integer && number.id21() instanceof Integer) {
            Integer first = (Integer) id21() * (Integer) number.id21();
            Integer second = (Integer) id12() * (Integer) number.id12();
            if (function == 0) {
                id9(first);
                id1(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createDivision(first, second);
            answer.reduce();
            return answer;
        } else if (id21() instanceof Long && number.id21() instanceof Long) {
            Long first = (Long) id21() * (Long) number.id21();
            Long second = (Long) id12() * (Long) number.id12();
            if (function == 0) {
                id9(first);
                id1(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createDivision(first, second);
            answer.reduce();
            return answer;

        } else if (id21() instanceof Float && number.id21() instanceof Float) {
            Float first = (Float) id21() * (Float) number.id21();
            Float second = (Float) id12() * (Float) number.id12();
            if (function == 0) {
                id9(first);
                id1(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createDivision(first, second);
            answer.reduce();
            return answer;
        } else if (id21() instanceof Double && number.id21() instanceof Double) {
            Double first = (Double) id21() * (Double) number.id21();
            Double second = (Double) id12() * (Double) number.id12();
            if (function == 0) {
                id9(first);
                id1(second);
                reduce();
                return null;
            }
            Fraction answer = Fraction.createDivision(first, second);
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

    protected static <K, V> Pair<K, V> createPair(K element, V element1) {
        return new Pair<>(element, element1);
    }

    public T id21() {
        return first;
    }

    public T1 id12() {
        return second;
    }

    public void id9(T element) {
        first = element;
    }

    public void id1(T1 element) {
        second = element;
    }

    @Override
    public Pair<T, T1> clone() {
        return createPair(id21(), id12());
    }

    @Override
    public int hashCode() {
        return 1;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Pair) {
            return (id21() == ((Pair) obj).id21()) && (id12() == ((Pair) obj).id12());
        }
        return false;
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

    public void start(int length) {
        used = new boolean[length];
        ancestor = new Integer[length];
        ancestor[0] = -1;
        quantity = 0;
    }

    public void id8(int length, int quantity) throws Exception {
        base = new int[length][];
        List<ArrayList<Integer>> inputBase = new ArrayList<>();
        for (int i = 0; i < length; i++) {
            inputBase.add(new ArrayList<>());
        }
        Array x = (int[] input) -> {
            inputBase.get(input[0] - 1).add(input[1] - 1);
            

            inputBase.get(input[1] - 1).add(input[0] - 1);
            

        };
        for (int i = 0; i < quantity; i++) {
            x.useArray(IO.id22(" "));
        }
        for (int i = 0; i < length; i++) {
            base[i] = inputBase.get(i).stream().mapToInt(Integer::intValue).toArray();
        }
        start(length);
    }

    public void id11(int length, int not) throws Exception {
        base = new int[length][];
        List<Integer> buffer = new ArrayList<>();
        int[] InputArray;
        for (int i = 0; i < length; i++) {
            InputArray = IO.id22(" ");
            for (int index = 0; index < length; index++) {
                if (i != index && InputArray[index] != not) {
                    buffer.add(index);
                    buffer.add(InputArray[index]);
                }
            }
            base[i] = buffer.stream().mapToInt(element -> element).toArray();
            buffer.clear();
        }
        start(length);
    }

    public void dfs(int position) throws Exception {
        used[position] = true;
        quantity++;
        int next;
        for (int index = 0; index < base[position].length; index += 2) {
            next = base[position][index];
            if (!used[next]) {
                ancestor[next] = position;
                dfs(next);
            } else {
                if (next != ancestor[position]) { 

                    throw new Exception();
                }
            }
        }
    }

    public static int getInt(int[] a) {
        return a[1];
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

        Queue<int[]> queue = new PriorityQueue<>((int[] first, int[] second) -> Integer.compare(first[1], second[1]));
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

    public boolean id13(int[][] base, int length, int dont) {
        for (int k = 0; k < length; k++) {
            for (int i = 0; i < length; i++) {
                for (int j = 0; j < length; j++) {
                    if (base[i][k] == dont || base[k][j] == dont) {
                        continue;
                    }
                    int total = base[i][k] + base[k][j];
                    if (base[i][j] != dont) {
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


    public static void id17(int[] array, int length, int id16) {
        sort(array, id16, length);
    }

    public static int[] id7(int[] array, int length, int id16) {
        int[] base = array.clone();
        sort(base, id16, length);
        return base;
    }

    private static void sort(int[] array, int id16, int length) {
        if (id16 < 0 || id16 > 4) {
            Random random = new Random();
            id16 = random.nextInt(4);
        }
        if (id16 == 0) {
            ShellSort(array);
        } else if (id16 == 1) {
            HeapSort(array);
        } else if (id16 == 2) {
            MergeSort(array, 0, length - 1);
        } else if (id16 == 3) {
            id10(array, length);
        } else if (id16 == 4) {
            id5(array);
        }
    }

    private static void id10(int[] array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size / 2) + ((size % 2) == 0 ? 0 : 1);
        Integer[][] ZeroBuffer = new Integer[length + length % 2][2];
        Integer[][] FirstBuffer = new Integer[0][0];
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index * 2;
            int id20 = index * 2 + 1;
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

    private static void id5(int[] elements) {
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
    private static boolean FileInput = false;
    private static BufferedWriter write;
    private static boolean FileOutput = false;

    public static void readClose() throws Exception {
        read.close();
    }

    public static void writeClose() throws Exception {
        write.close();
    }

    public static void id3(boolean id0) {
        FileInput = id0;
    }

    public static void id18(boolean id23) {
        FileOutput = id23;
    }

    private static void startInput() {
        try {
            read = new BufferedReader(FileInput ? new FileReader("input.txt") : new InputStreamReader(System.in));
        } catch (Exception error) {
        }
    }

    private static void startOutput() {
        try {
            write = new BufferedWriter(FileOutput ? new FileWriter("output.txt") : new OutputStreamWriter(System.out));
        } catch (Exception error) {
        }
    }

    public static int ReadInt() throws Exception {
        if (read == null) {
            startInput();
        }
        return Integer.parseInt(read.readLine());
    }

    public static long ReadLong() throws Exception {
        if (read == null) {
            startInput();
        }
        return Long.parseLong(read.readLine());
    }

    public static String ReadString() throws Exception {
        if (read == null) {
            startInput();
        }
        return read.readLine();
    }

    public static int[] id22(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToInt(Integer::parseInt).toArray();
    }

    public static long[] id19(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToLong(Long::parseLong).toArray();
    }

    public static String[] id6(String split) throws IOException {
        if (read == null) {
            startInput();
        }
        return read.readLine().split(split);
    }

    public static void WriteArray(int[] array, String split, String end) {
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
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteArray(Integer[] array, String split, String end) {
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
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteArray(long[] array, String split, String end) {
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
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteArray(Long[] array, String split, String end) {
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
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteArray(String[] array, String split, String end) {
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
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteArray(boolean[] array, String split, String end) {
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
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteInt(int number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Integer.toString(number));
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteInt(Integer number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Integer.toString(number));
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteLong(long number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Long.toString(number));
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteLong(Long number, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Long.toString(number));
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteString(String word, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteChar(char word, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteChar(Character word, String end) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(end);
        } catch (Exception error) {
        }
    }

    public static void WriteEnter() {
        if (write == null) {
            startOutput();
        }
        try {
            write.newLine();
        } catch (Exception e) {
        }
    }

    public static void print() throws Exception {
        print(true);
    }

    public static void print(boolean close) throws Exception {
        if (write == null) {
            return;
        }
        write.flush();
        if (close) {
            read.close();
            write.close();
        }
    }
}

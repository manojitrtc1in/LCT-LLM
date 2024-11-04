


import java.io.*;
import java.lang.*;
import java.util.*;

public class Main extends id5 {

    public static void main(String[] args) throws Exception {
        int quantity = ReadInt();
        int[] size = id16(" ");
        Integer[][] base = new Integer[quantity][2];
        for (int index = 0; index < quantity * 2; index++){
            if (base[size[index] - 1][0] == null) {
                base[size[index] - 1][0] = index;
            }else{
                base[size[index] - 1][1] = index;
            }
        }
        long answer = base[0][0] + base[0][1];
        for (int index = 1; index < quantity; index++){
            answer += (Math.abs(base[index][0] - base[index - 1][0]));
            answer += (Math.abs(base[index][1] - base[index - 1][1]));
        }
        WriteLong(answer, null);
        method.exit();
    }

}

class method {

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

    protected static void exit() throws Exception {
        if (id5.write == null) {
            return;
        }
        id5.write.flush();
        id5.read.close();
        id5.write.close();
    }
}

class Division<T> extends Pair {

    private Division(T dividend, T divider) {
        super(dividend, divider);
        reduce();
    }

    protected static <K> Division<K> createDivision(K dividend, K divider) {
        return new Division<K>(dividend, divider);
    }

    protected void reduce() {
        if (id15() instanceof Integer) {
            Integer Dividend = (Integer) id15();
            Integer Divider = (Integer) id8();
            int gcd = method.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id15() instanceof Long) {
            Long Dividend = (Long) id15();
            Long Divider = (Long) id8();
            long gcd = method.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id15() instanceof Float) {
            Float Dividend = (Float) id15();
            Float Divider = (Float) id8();
            float gcd = method.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        } else if (id15() instanceof Double) {
            Double Dividend = (Double) id15();
            Double Divider = (Double) id8();
            double gcd = method.gcd(Dividend, Divider);
            setFirst(Dividend / gcd);
            setSecond(Divider / gcd);
        }

    }

    protected void id0(Division number) throws UnsupportedOperationException {
        if (id15() instanceof Integer && id8() instanceof Integer && number.id15() instanceof Integer && number.id8() instanceof Integer) {
            Integer Dividend = (Integer) id15();
            Integer Divider = (Integer) id8();
            Integer Dividend1 = (Integer) number.id15();
            Integer Divider1 = (Integer) number.id8();
            Integer lcm = method.lcm(Divider, Divider1);
            setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
            setSecond(lcm);
            reduce();
        } else if (id15() instanceof Long && id8() instanceof Long && number.id15() instanceof Long && number.id8() instanceof Long) {
            Long Dividend = (Long) id15();
            Long Divider = (Long) id8();
            Long Dividend1 = (Long) number.id15();
            Long Divider1 = (Long) number.id8();
            Long lcm = method.lcm(Divider, Divider1);
            setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
            setSecond(lcm);
            reduce();
        } else if (id15() instanceof Float && id8() instanceof Float && number.id15() instanceof Float && number.id8() instanceof Float) {
            Float Dividend = (Float) id15();
            Float Divider = (Float) id8();
            Float Dividend1 = (Float) number.id15();
            Float Divider1 = (Float) number.id8();
            Float lcm = method.lcm(Divider, Divider1);
            setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
            setSecond(lcm);
        } else if (id15() instanceof Double && id8() instanceof Double && number.id15() instanceof Double && number.id8() instanceof Double) {
            Double Dividend = (Double) id15();
            Double Divider = (Double) id8();
            Double Dividend1 = (Double) number.id15();
            Double Divider1 = (Double) number.id8();
            Double lcm = method.lcm(Divider, Divider1);
            setFirst((lcm / Divider) * Dividend + (lcm / Divider1) * Dividend1);
            setSecond(lcm);
        } else {
            throw new UnsupportedOperationException();
        }
    }

}

class Pair<T, T1> {

    private T first;
    private T1 second;

    Pair(T obj, T1 obj1) {
        this.first = obj;
        this.second = obj1;
    }

    protected static <K, V> Pair<K, V> createPair(K element, V element1) {
        return new Pair<>(element, element1);
    }

    protected T id15() {
        return first;
    }

    protected T1 id8() {
        return second;
    }

    protected void setFirst(T element) {
        first = element;
    }

    protected void setSecond(T1 element) {
        second = element;
    }

    @Override
    public int hashCode() {
        return 1;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Pair) {
            return (id15() == ((Division) obj).id15()) && (id8() == ((Division) obj).id8());
        }
        return false;
    }

}

class graph {

    private static int[][] base;
    private static boolean[] used;
    protected static int quantity = 0;
    private static Integer[] pred;

    protected static void start(int length) {
        used = new boolean[length];
        pred = new Integer[length];
    }

    protected static void id17(int length) throws Exception {
        start(length);
        base = new int[length][];
        int FirstSize, SecondSize;
        int[] rib, FirstArray, SecondArray, id9, id7;
        for (int i = 0; i < length; i++) {
            rib = Arrays.stream(id5.id16(" ")).map(element -> element - 1).toArray();
            FirstArray = base[rib[0]];
            SecondArray = base[rib[1]];
            if (FirstArray == null) {
                FirstSize = 0;
            } else {
                FirstSize = FirstArray.length;
            }
            if (SecondArray == null) {
                SecondSize = 0;
            } else {
                SecondSize = SecondArray.length;
            }
            id9 = new int[FirstSize + 2];
            id7 = new int[SecondSize + 2];
            for (int index = 0; index < Math.max(FirstSize, SecondSize); index++) {
                if (index < FirstSize) {
                    id9[index] = FirstArray[index];
                }
                if (index < SecondSize) {
                    id7[index] = SecondArray[index];
                }
            }
            id9[FirstSize] = rib[1];
            id7[SecondSize] = rib[0];
            id9[FirstSize + 1] = 1;
            id7[SecondSize + 1] = 1;
            base[rib[0]] = id9;
            base[rib[1]] = id7;
        }
    }

    protected static void id1(int length, int dont) throws Exception {
        start(length);
        base = new int[length][];
        List<Integer> buffer = new ArrayList<>();
        int[] InputArray;
        for (int i = 0; i < length; i++) {
            InputArray = id5.id16(" ");
            for (int index = 0; index < length; index++) {
                if (i != index && InputArray[index] != dont) {
                    buffer.add(index);
                    buffer.add(InputArray[index]);
                }
            }
            base[i] = buffer.stream().mapToInt(element -> element).toArray();
            buffer.clear();
        }
    }

    protected static void dfs(int position) throws Exception {
        used[position] = true;
        quantity++;
        int next;
        for (int index = 0; index < base[position].length; index += 2) {
            next = base[position][index];
            if (!used[next]) {
                pred[next] = position;
                dfs(next);
            } else {
                if (next != pred[position]) { 

                    throw new Exception();
                }
            }
        }
    }

    protected static int dijkstra(int start, int stop, int size) {
        start--;
        stop--;
        int[] dist = new int[size];
        for (int i = 0; i < size; i++) {
            if (i != start) {
                dist[i] = Integer.MAX_VALUE;
            }
            pred[i] = start;
        }
        Queue<int[]> queue = new PriorityQueue<>((int[] first, int[] second) -> Integer.compare(first[1], second[1]));
        queue.add(new int[]{start, 0});
        int position;
        int[] GetQueue;
        while (queue.size() != 0) {
            GetQueue = queue.poll();
            position = GetQueue[0];
            if (GetQueue[1] > dist[position]) {
                continue;
            }
            for (int index = 0; index < base[position].length; index += 2) {
                if (dist[position] + base[position][index + 1] < dist[base[position][index]] && !used[base[position][index]]) {
                    dist[base[position][index]] = dist[position] + base[position][index + 1];
                    pred[base[position][index]] = position;
                    queue.add(new int[]{base[position][index], dist[base[position][index]]});
                }
            }
            used[position] = true;
        }
        return dist[stop] == Integer.MAX_VALUE ? -1 : dist[stop];
    }

    protected static boolean id10(int[][] base, int length, int dont) {
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

class FastSort {


    protected static void id12(int[] array, int length, int id11) {
        sort(array, id11, length);
    }

    protected static int[] id4(int[] array, int length, int id11) {
        sort(array, id11, length);
        return array;
    }

    private static void sort(int[] array, int id11, int length) {
        if (id11 < 0 || id11 > 4) {
            Random random = new Random();
            id11 = random.nextInt(4);
        }
        if (id11 == 0) {
            ShellSort(array);
        } else if (id11 == 1) {
            HeapSort(array);
        } else if (id11 == 2) {
            MergeSort(array, 0, length - 1);
        } else if (id11 == 3) {
            id6(array, length);
        } else if (id11 == 4) {
            id2(array);
        }
    }

    private static void id6(int[] array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size / 2) + ((size % 2) == 0 ? 0 : 1);
        Integer[][] ZeroBuffer = new Integer[length + length % 2][2];
        Integer[][] FirstBuffer = new Integer[0][0];
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index * 2;
            int id14 = index * 2 + 1;
            if (id14 < size) {
                if (array[ArrayIndex] > array[id14]) {
                    ZeroBuffer[index][0] = array[id14];
                    ZeroBuffer[index][1] = array[ArrayIndex];
                } else {
                    ZeroBuffer[index][0] = array[ArrayIndex];
                    ZeroBuffer[index][1] = array[id14];
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

    private static void id2(int[] elements) {
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

class id5 {

    protected static BufferedReader read;
    protected static boolean FileInput = false;
    protected static BufferedWriter write;
    protected static boolean FileOutput = false;

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

    protected static int ReadInt() throws Exception {
        if (read == null) {
            startInput();
        }
        return Integer.parseInt(read.readLine());
    }

    protected static long ReadLong() throws Exception {
        if (read == null) {
            startInput();
        }
        return Long.parseLong(read.readLine());
    }

    protected static String ReadString() throws Exception {
        if (read == null) {
            startInput();
        }
        return read.readLine();
    }

    protected static int[] id16(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToInt(Integer::parseInt).toArray();
    }

    protected static long[] id13(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return Arrays.stream(read.readLine().split(split)).mapToLong(Long::parseLong).toArray();
    }

    protected static String[] id3(String split) throws Exception {
        if (read == null) {
            startInput();
        }
        return read.readLine().split(split);
    }

    protected static void WriteArray(int[] array, String split) {
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
        } catch (Exception error) {
        }
    }

    protected static void WriteArray(long[] array, String split) {
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
        } catch (Exception error) {
        }
    }

    public static void WriteArray(String[] array, String split) {
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
        } catch (Exception error) {
        }
    }

    protected static void WriteArray(boolean[] array, String split) {
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
        } catch (Exception error) {
        }
    }

    protected static void WriteInt(int number, String split) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Integer.toString(number));
            write.write(split);
        } catch (Exception error) {
        }
    }

    protected static void WriteString(String word, String split) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(word);
            write.write(split);
        } catch (Exception error) {
        }
    }

    protected static void WriteLong(Long number, String split) {
        if (write == null) {
            startOutput();
        }
        try {
            write.write(Long.toString(number));
            write.write(split);
        } catch (Exception error) {
        }
    }

    protected static void WriteEnter() {
        if (write == null) {
            startOutput();
        }
        try {
            write.newLine();
        } catch (Exception e) {
        }
    }
}
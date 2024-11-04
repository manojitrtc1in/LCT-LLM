


import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {

    public static Input input;
    public static Output output;
    private static boolean check;
    private static int i1;

    public static void main(String[] args) throws Exception {
        input = new Input();
        output = new Output();
        int[] size = input.ReadArrayInt(" ");
        int[][] base = new int[size[0]][];
        int[][] base1 = new int[size[0]][];
        for (int i = 0; i < size[0]; i++) {
            base[i] = input.ReadArrayInt(" ");
        }
        for (int i = 0; i < size[0]; i++) {
            base1[i] = input.ReadArrayInt(" ");
        }
        int i2 = 0;
        Queue<Integer> queue = new PriorityQueue<>();
        Queue<Integer> queue1 = new PriorityQueue<>();
        for (int i = 0; i < size[1]; i++) {
            try {
                i1 = 0;
                for (int index = i; index >= 0; index--) {
                    queue.add(base[index][i1]);
                    queue1.add(base1[index][i1]);
                    i1++;
                }
            } catch (Exception e) {
                try {
                    i2 = (i1 == 0 ? i2 : i1);
                    for (int index = --i; index >= 0; index--) {
                        queue.add(base[index][i2]);
                        queue1.add(base1[index][i2]);
                        i2++;
                        i1++;
                    }
                }catch (Exception E){break;}
            }
            check = false;
            for (int index = 0; index < i1; index++) {
                if (!queue.poll().equals(queue1.poll())) {
                    check = true;
                }
            }
            if (!check) {
                queue.clear();
                queue1.clear();
            } else {
                System.out.println("NO");
                return;
            }
        }
        for (int i = 1; i < size[0]; i++) {
            try {
                int i1 = size[1] - 1;
                for (int index = i; index < size[0]; index++) {
                    queue.add(base[index][i1]);
                    queue1.add(base1[index][i1]);
                    i1--;
                }
            } catch (Exception e) {
            }
            check = false;
            int length = queue.size();
            for (int index = 0; index < length; index++) {
                if (!queue.poll().equals(queue1.poll())) {
                    check = true;
                }
            }
            if (!check) {
                queue.clear();
                queue1.clear();
            } else {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}


class method {

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

    public static int lcm(int a, int b) { 

        return a / gcd(a, b) * b;
    }

    public static long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }

    public static void exit() throws Exception {
        Main.output.write.flush();
        Main.input.read.close();
        Main.output.write.close();
    }
}

class graph {

    private static int[][] base;
    private static boolean[] used;
    public static int quantity = 0;
    private static Integer[] pred;

    public static void start(int length) {
        used = new boolean[length];
        pred = new Integer[length];
    }

    public static void RibMatrixToDefault(int length) throws Exception {
        start(length);
        base = new int[length][];
        int FirstSize;
        int SecondSize;
        int[] rib;
        int[] FirstArray;
        int[] SecondArray;
        int[] NewFirstArray;
        int[] NewSecondArray;
        for (int i = 0; i < length; i++) {
            rib = Arrays.stream(Main.input.ReadArrayInt(" ")).map(element -> element - 1).toArray();
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
            NewFirstArray = new int[FirstSize + 2];
            NewSecondArray = new int[SecondSize + 2];
            for (int index = 0; index < Math.max(FirstSize, SecondSize); index++) {
                if (index < FirstSize) {
                    NewFirstArray[index] = FirstArray[index];
                }
                if (index < SecondSize) {
                    NewSecondArray[index] = SecondArray[index];
                }
            }
            NewFirstArray[FirstSize] = rib[1];
            NewSecondArray[SecondSize] = rib[0];
            NewFirstArray[FirstSize + 1] = 1;
            NewSecondArray[SecondSize + 1] = 1;
            base[rib[0]] = NewFirstArray;
            base[rib[1]] = NewSecondArray;
        }
    }

    public static void AdjacencyMatrixToDefault(int length, int dont) throws Exception {
        start(length);
        base = new int[length][];
        List<Integer> buffer = new ArrayList<>();
        int[] InputArray;
        for (int i = 0; i < length; i++) {
            InputArray = Main.input.ReadArrayInt(" ");
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

    public static void dfs(int position) throws Exception {
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

    public static int dijkstra(int start, int stop, int size) {
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

    public static boolean FloydWarshall(int[][] base, int length, int dont) {
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

    public static void SortWithoutReturn(int[] array, int ShellHeapMergeMyInsertionSort, int length) {
        sort(array, ShellHeapMergeMyInsertionSort, length);
    }

    public static int[] SortWithReturn(int[] array, int ShellHeapMergeMyInsertionSort, int length) {
        sort(array, ShellHeapMergeMyInsertionSort, length);
        return array;
    }

    private static void sort(int[] array, int ShellHeapMergeMyInsertionSort, int length) {
        if (ShellHeapMergeMyInsertionSort < 0 || ShellHeapMergeMyInsertionSort > 4) {
            Random random = new Random();
            ShellHeapMergeMyInsertionSort = random.nextInt(4);
        }
        if (ShellHeapMergeMyInsertionSort == 0) {
            ShellSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 1) {
            HeapSort(array);
        } else if (ShellHeapMergeMyInsertionSort == 2) {
            MergeSort(array, 0, length - 1);
        } else if (ShellHeapMergeMyInsertionSort == 3) {
            StraightMergeSort(array, length);
        } else if (ShellHeapMergeMyInsertionSort == 4) {
            insertionSort(array);
        }
    }

    private static void StraightMergeSort(int[] array, int size) {
        if (size == 0) {
            return;
        }
        int length = (size / 2) + ((size % 2) == 0 ? 0 : 1);
        Integer[][] ZeroBuffer = new Integer[length + length % 2][2];
        Integer[][] FirstBuffer = new Integer[0][0];
        for (int index = 0; index < length; index++) {
            int ArrayIndex = index * 2;
            int NextArrayIndex = index * 2 + 1;
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
        int pointer0;
        int pointer;
        int pointer1;
        int number = 4;
        int NewPointer;
        int count;
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

    public static void ShellSort(int[] array) {
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

class Input {

    public BufferedReader read;
    public static boolean FileInput = false;

    Input() {
        try {
            read = new BufferedReader(FileInput ? new FileReader("input.txt") : new InputStreamReader(System.in));
        } catch (Exception error) {
        }
    }

    public int ReadInt() throws Exception {
        return Integer.parseInt(read.readLine());
    }

    public long ReadLong() throws Exception {
        return Long.parseLong(read.readLine());
    }

    public String ReadString() throws Exception {
        return read.readLine();
    }

    public int[] ReadArrayInt(String split) throws Exception {
        return Arrays.stream(read.readLine().split(split)).mapToInt(Integer::parseInt).toArray();
    }

    public long[] ReadArrayLong(String split) throws Exception {
        return Arrays.stream(read.readLine().split(split)).mapToLong(Long::parseLong).toArray();
    }

    public String[] ReadArrayString(String split) throws Exception {
        return read.readLine().split(split);
    }
}

class Output {

    public BufferedWriter write;
    public static boolean FileOutput = false;

    Output() {
        try {
            write = new BufferedWriter(FileOutput ? new FileWriter("output.txt") : new OutputStreamWriter(System.out));
        } catch (Exception error) {
        }
    }

    public void WriteArray(int[] array, String split) {
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

    public void WriteArray(long[] array, String split) {
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

    public void WriteArray(String[] array, String split) {
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

    public void WriteArray(boolean[] array, String split) {
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

    public void WriteInt(int number, String split) {
        try {
            write.write(Integer.toString(number));
            write.write(split);
        } catch (Exception error) {
        }
    }

    public void WriteString(String word, String split) {
        try {
            write.write(word);
            write.write(split);
        } catch (Exception error) {
        }
    }

    public void WriteLong(Long number, String split) {
        try {
            write.write(Long.toString(number));
            write.write(split);
        } catch (Exception error) {
        }
    }

    public void WriteEnter() {
        try {
            write.newLine();
        } catch (Exception e) {
        }
    }
}
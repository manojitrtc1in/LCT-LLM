


import javax.swing.text.html.HTMLDocument;
import java.io.*;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    

    

    static int m;

    public static void main(String[] args) {


        

        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        OutputStream fOut = System.out;
        Scanner fin = new Scanner(System.in);
        try {
            fin = new Scanner(new FileInputStream("anniversary.in"));
        } catch (Exception ignored) {
        }
        try {
            fOut = new FileOutputStream("anniversary.out");
        } catch (Exception ignored) {
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        PrintWriter fout = new PrintWriter(fOut);


        

        int cases = in.nextInt();
        for (int j = 0; j < cases; j++) {
            int length = in.nextInt();
            String string = in.next();
            char max[] = new char[50010], min[] = new char[50010];
            int maxIndex = 0, minIndex = 0;
            boolean moreOne = false;
            for (int i = 0; i < length; i++) {
                if (!moreOne) {
                    if (string.charAt(i) == '0') {
                        max[maxIndex] = '0';
                        maxIndex++;
                        min[minIndex] = '0';
                        minIndex++;
                    }
                    if (string.charAt(i) == '1') {
                        max[maxIndex] = '1';
                        maxIndex++;
                        min[minIndex] = '0';
                        minIndex++;
                        moreOne = true;
                    }
                    if (string.charAt(i) == '2') {
                        max[maxIndex] = '1';
                        maxIndex++;
                        min[minIndex] = '1';
                        minIndex++;
                    }

                } else {
                    if (string.charAt(i) == '0') {
                        max[maxIndex] = '0';
                        maxIndex++;
                        min[minIndex] = '0';
                        minIndex++;
                    }
                    if (string.charAt(i) == '1') {
                        max[maxIndex] = '0';
                        maxIndex++;
                        min[minIndex] = '1';
                        minIndex++;
                    }
                    if (string.charAt(i) == '2') {
                        max[maxIndex] = '0';
                        maxIndex++;
                        min[minIndex] = '2';
                        minIndex++;
                    }
                }

            }
            for (int i = 0; i < maxIndex; i++) {
                if ((i != 0) || max[i] != '0')
                    out.print(max[i]);
            }
            out.println();
            for (int i = 0; i < minIndex; i++) {
                if ((i != 0) || min[i] != '0')
                out.print(min[i]);
            }
            out.println();
        }


        out.flush();
        out.close();
        fout.close();
    }

    public static void ansA() {
        
    }

    public static void ansB() {
        
    }


    public static void heapSort(long[] a) {
        for (int i = a.length / 2 - 1; i >= 0; i--) {
            adjustHeap(a, i, a.length);
        }
        for (int j = a.length - 1; j > 0; j--) {
            swap(a, 0, j);
            adjustHeap(a, 0, j);
        }

    }

    public static void adjustHeap(long[] a, int i, int length) {
        long temp = a[i];
        for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {
            if (k + 1 < length && a[k] < a[k + 1]) {
                k++;
            }
            if (a[k] > temp) {
                a[i] = a[k];
                i = k;
            } else {
                break;
            }
        }
        a[i] = temp;
    }

    public static void swap(long[] a, int a1, int a2) {
        long temp = a[a1];
        a[a1] = a[a2];
        a[a2] = temp;
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char[] nextCharArray() {
            return next().toCharArray();
        }
    }

    public static int dp(int a[]) {
        int dp[][] = new int[a.length / 2 + 1][a.length / 2 + 1];

        for (int j = 1; j < m; j++) {
            for (int i = 0; i <= a.length / 2 - j; i++) {
                int total = 0;
                for (int k = 0; k < j; k++) {
                    total += a[2 * i + k];
                }
                dp[i + 1][j] = total;

            }
        }
        for (int j = 2; j <= a.length / 2; j++) {
            for (int i = 1; i <= a.length / 2 - j + 1; i++) {
                for (int k = i; k < j; k++) {
                    int ans = dp[i][k] + dp[i + k][j - k];
                    if (ans > dp[i][j]) dp[i][j] = ans;
                }

            }
        }
        return dp[1][a.length / 2];
    }

    public static void calculate() {
        Scanner in = new Scanner(System.in);
        for (int test = 0; test < 10; test++) {
            String string = in.next();

            while (string.contains("++") || string.contains("+-") || string.contains("-+") || string.contains("--")) {
                string = string.replace("++", "+");
                string = string.replace("+-", "-");
                string = string.replace("-+", "-");
                string = string.replace("--", "+");
            }

            string = string.replace("-", "m");
            string = string.replace("(m", "(-");
            string = string.replace("~m", "+~-");
            string = string.replace("m~", "+-~");
            if (string.charAt(0) == 'm') string = string.replaceFirst("m", "-");

            while (string.contains(")") && string.contains("(")) {
                int right = string.indexOf(")");
                String sub = string.substring(0, right);
                int left = sub.lastIndexOf("(");
                string = string.substring(0, left) + calculate(string.substring(left + 1, right)) + string.substring(right + 1);
            }
            string = calculate(string);
            while (string.contains("++") || string.contains("+-") || string.contains("-+") || string.contains("--")) {
                string = string.replace("++", "");
                string = string.replace("+-", "-");
                string = string.replace("-+", "-");
                string = string.replace("--", "");
            }
            System.out.println(string);
            System.out.flush();
        }
    }

    public static String calculate(String string) {
        int index = -1;

        String sub = string;
        while (sub.contains("~+") || sub.contains("++") || sub.contains("+m") || sub.contains("m+") || sub.contains("mm") || sub.contains("--")) {
            sub = sub.replace("++", "+");
            sub = sub.replace("+m", "m");
            sub = sub.replace("m+", "m");
            sub = sub.replace("mm", "+");
            sub = sub.replace("--", "+");
            sub = sub.replace("~+", "~");
        }
        while (sub.contains("~")) {
            int index1 = sub.indexOf("~");
            int index2 = index1 + 1;
            while ((int) sub.charAt(index2) < 58 && (int) sub.charAt(index2) > 47 || (int) sub.charAt(index2) == 45) {
                index2++;
                if (index2 > sub.length() - 1) break;
            }
            sub = sub.substring(0, index1) + ~Integer.parseInt(sub.substring(index1 + 1, index2)) + sub.substring(index2);
        }

        while (sub.contains("*")) {
            int index1 = sub.indexOf("*");
            int index2 = index1 + 1;
            int index3 = index1 - 1;
            while ((int) sub.charAt(index3) < 58 && (int) sub.charAt(index3) > 47 || (int) sub.charAt(index3) == 45) {
                index3--;
                if (index3 < 0) break;
            }
            while ((int) sub.charAt(index2) < 58 && (int) sub.charAt(index2) > 47 || (int) sub.charAt(index2) == 45) {
                index2++;
                if (index2 > sub.length() - 1) break;
            }
            sub = sub.substring(0, index3 + 1) + Integer.parseInt(sub.substring(index3 + 1, index1)) * Integer.parseInt(sub.substring(index1 + 1, index2)) + sub.substring(index2);
        }

        while (sub.contains("++") || sub.contains("+m") || sub.contains("m+") || sub.contains("mm") || sub.contains("--")) {
            sub = sub.replace("++", "+");
            sub = sub.replace("+m", "m");
            sub = sub.replace("m+", "m");
            sub = sub.replace("mm", "+");
            sub = sub.replace("--", "+");
        }

        while (sub.contains("+") || sub.contains("m")) {

            boolean add = sub.indexOf("+") < sub.indexOf("m");

            int index1 = Math.min(sub.indexOf("+"), sub.indexOf("m"));

            if (!sub.contains("+")) {
                index1 = sub.indexOf("m");
                add = false;
            }
            if (!sub.contains("m")) {
                index1 = sub.indexOf("+");
                add = true;
            }
            if (sub.contains("+") && (sub.indexOf("+") == 0 || !((sub.charAt(sub.indexOf("+") - 1) == 45 || sub.charAt(sub.indexOf("+") - 1) > 47 && sub.charAt(sub.indexOf("+") - 1) < 58)))) {
                sub = sub.substring(0, sub.indexOf("+")) + sub.substring(sub.indexOf("+") + 1);
                continue;
            }

            int index2 = index1 + 1;
            int index3 = index1 - 1;
            while ((int) sub.charAt(index3) < 58 && (int) sub.charAt(index3) > 47 || (int) sub.charAt(index3) == 45) {
                index3--;
                if (index3 < 0) break;
            }
            while ((int) sub.charAt(index2) < 58 && (int) sub.charAt(index2) > 47 || (int) sub.charAt(index2) == 45) {
                index2++;
                if (index2 > sub.length() - 1) break;
            }
            if (add)
                sub = sub.substring(0, index3 + 1) + (Integer.parseInt(sub.substring(index3 + 1, index1)) + Integer.parseInt(sub.substring(index1 + 1, index2))) + sub.substring(index2);
            else
                sub = sub.substring(0, index3 + 1) + (Integer.parseInt(sub.substring(index3 + 1, index1)) - Integer.parseInt(sub.substring(index1 + 1, index2))) + sub.substring(index2);

        }
        while (sub.contains("&")) {
            int index1 = sub.indexOf("&");
            int index2 = index1 + 1;
            int index3 = index1 - 1;
            while ((int) sub.charAt(index3) < 58 && (int) sub.charAt(index3) > 47 || (int) sub.charAt(index3) == 45) {
                index3--;
                if (index3 < 0) break;
            }
            while ((int) sub.charAt(index2) < 58 && (int) sub.charAt(index2) > 47 || (int) sub.charAt(index2) == 45) {
                index2++;
                if (index2 > sub.length() - 1) break;
            }
            sub = sub.substring(0, index3 + 1) + (Integer.parseInt(sub.substring(index3 + 1, index1)) & Integer.parseInt(sub.substring(index1 + 1, index2))) + sub.substring(index2);
        }
        while (sub.contains("^")) {
            int index1 = sub.indexOf("^");
            int index2 = index1 + 1;
            int index3 = index1 - 1;
            while ((int) sub.charAt(index3) < 58 && (int) sub.charAt(index3) > 47 || (int) sub.charAt(index3) == 45) {
                index3--;
                if (index3 < 0) break;
            }
            while ((int) sub.charAt(index2) < 58 && (int) sub.charAt(index2) > 47 || (int) sub.charAt(index2) == 45) {
                index2++;
                if (index2 > sub.length() - 1) break;
            }
            sub = sub.substring(0, index3 + 1) + (Integer.parseInt(sub.substring(index3 + 1, index1)) ^ Integer.parseInt(sub.substring(index1 + 1, index2))) + sub.substring(index2);
        }

        while (sub.contains("|")) {
            int index1 = sub.indexOf("|");
            int index2 = index1 + 1;
            int index3 = index1 - 1;
            while ((int) sub.charAt(index3) < 58 && (int) sub.charAt(index3) > 47 || (int) sub.charAt(index3) == 45) {
                index3--;
                if (index3 < 0) break;
            }
            while ((int) sub.charAt(index2) < 58 && (int) sub.charAt(index2) > 47 || (int) sub.charAt(index2) == 45) {
                index2++;
                if (index2 > sub.length() - 1) break;
            }
            sub = sub.substring(0, index3 + 1) + (Integer.parseInt(sub.substring(index3 + 1, index1)) | Integer.parseInt(sub.substring(index1 + 1, index2))) + sub.substring(index2);
        }
        return sub;
    }


    public static void answerA() {


    }


    public static void answerB316() {
        InputReader fin = new InputReader(System.in);
        PrintWriter fout = new PrintWriter(System.out);
        PrintWriter out = new PrintWriter(System.out);

        int people = fin.nextInt();
        int a = fin.nextInt();
        int b = fin.nextInt();
        if (a == people && b == 0) {
            for (int i = 0; i < people; i++)
                fout.print("B");
            out.flush();
            out.close();
            fout.close();
            return;
        }
        if (b == people && a == 0) {
            for (int i = 0; i < people; i++)
                fout.print("G");
            out.flush();
            out.close();
            fout.close();
            return;
        }
        if (people % 2 == 1) {
            if ((a + b - people) % 2 == 0) {
                int dan = (a + b - people) / 2;
                int dou = b - 2 * dan;
                if (dan == 0 && dou != 0)
                    fout.println("Impossible");
                else {
                    if (people >= dou + dan * 2) {
                        char arr[] = new char[people];
                        arr[0] = 'G';
                        for (int i = 1; i < people; i++) {
                            if (dan - 1 > 0) {
                                dan--;
                                arr[i] = 'B';
                                i++;
                                arr[i] = 'G';
                            } else if (dou > 0) {
                                arr[i] = 'G';
                                dou--;
                            } else {
                                arr[i] = 'B';
                            }
                        }
                        for (int i = 0; i < people; i++) {
                            fout.print(arr[(i * 2) % people]);
                        }
                    } else {
                        fout.println("Impossible");
                    }


                }
            } else {
                fout.println("Impossible");
            }
        }
    }


    public static long overflow(long num, int digit) {
        num = num * num;

        if (digit(num) > digit) {
            digit = digit(num) - digit;
            return MinusDigit(num, digit);
        }
        return num;

    }

    public static long MinusDigit(long number, int digit) {

        while (digit >= 1) {
            number = number / 10;
            digit--;
        }
        return number;
    }

    public static int digit(long num) {
        int digit = 1;
        while (num >= 10) {
            num = num / 10;
            digit++;
        }
        return digit;
    }

    public static int findValue(long[] a, int begin, int end, long value) {

        if (value == a[(begin + end) / 2]) return (begin + end) / 2;
        if (begin == end) return -1;
        if (value > a[(begin + end) / 2]) {
            return findValue(a, (begin + end + 1) / 2, end, value);
        } else {
            return findValue(a, begin, (begin + end - 1) / 2, value);
        }

    }

    public static int findValue(long[][] a, int begin, int end, long value) {

        if (value == a[(begin + end) / 2][1]) return (begin + end) / 2;
        if (begin == end) return -1;
        if (value > a[(begin + end) / 2][1]) {
            return findValue(a, (begin + end + 1) / 2, end, value);
        } else {
            return findValue(a, begin, (begin + end - 1) / 2, value);
        }

    }

    public static int numOfFindValue(long[] a, int begin, int end, int index) {
        long value = a[index];
        int index1 = index;
        int num = 1;
        while (index1 < end) {
            index1++;
            if (a[index1] == value) num++;
            else break;
        }
        while (index > begin) {
            index--;
            if (a[index] == value) num++;
            else break;
        }

        return num;
    }


    public static void heapSort2(int[][] a) {
        for (int i = a.length / 2 - 1; i >= 0; i--) {
            adjustHeap2(a, i, a.length);
        }
        for (int j = a.length - 1; j > 0; j--) {
            swap2(a, 0, j);
            adjustHeap2(a, 0, j);
        }

    }

    public static void adjustHeap2(int[][] a, int i, int length) {
        int temp[] = a[i].clone();
        for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {
            if (k + 1 < length && a[k][1] < a[k + 1][1]) {
                k++;
            }
            if (a[k][1] > temp[1]) {
                a[i][0] = a[k][0];
                a[i][1] = a[k][1];
                i = k;
            } else {
                break;
            }
        }
        a[i] = temp.clone();
    }

    public static void swap2(int[][] a, int a1, int a2) {
        int temp[] = new int[2];
        temp[1] = a[a1][1];
        a[a1][1] = a[a2][1];
        a[a2][1] = temp[1];
        temp[0] = a[a1][0];
        a[a1][0] = a[a2][0];
        a[a2][0] = temp[0];

    }

    public static void heapSort2(long[][] a) {
        for (int i = a.length / 2 - 1; i >= 0; i--) {
            adjustHeap2(a, i, a.length);
        }
        for (int j = a.length - 1; j > 0; j--) {
            swap2(a, 0, j);
            adjustHeap2(a, 0, j);
        }

    }

    public static void adjustHeap2(long[][] a, int i, int length) {
        long temp[] = a[i].clone();
        for (int k = i * 2 + 1; k < length; k = k * 2 + 1) {
            if (k + 1 < length && a[k][1] < a[k + 1][1]) {
                k++;
            }
            if (a[k][1] > temp[1]) {
                a[i][0] = a[k][0];
                a[i][1] = a[k][1];
                i = k;
            } else {
                break;
            }
        }
        a[i] = temp.clone();
    }

    public static void swap2(long[][] a, int a1, int a2) {
        long temp[] = new long[2];
        temp[1] = a[a1][1];
        a[a1][1] = a[a2][1];
        a[a2][1] = temp[1];
        temp[0] = a[a1][0];
        a[a1][0] = a[a2][0];
        a[a2][0] = temp[0];

    }


    public static class SingleLinkedList {
        private int size;
        private Node head;

        public SingleLinkedList() {
            size = 0;
            head = null;
        }

        private class Node {
            private Object data;
            private Node next;
            private long datas[];

            public Node(Object data) {
                this.data = data;
            }
        }


        public Object addHead(Object obj) {
            Node newHead = new Node(obj);
            if (size == 0) {
                head = newHead;
            } else {
                newHead.next = head;
                head = newHead;
            }
            size++;
            return obj;
        }

        public Object addHead(Object obj, long a[]) {
            Node newHead = new Node(obj);
            newHead.datas = a;
            if (size == 0) {
                head = newHead;
            } else {
                newHead.next = head;
                head = newHead;
            }
            size++;
            return obj;
        }

        public void addIntSmallToLarge(int a) {
            long bb[] = new long[1];
            addIntSmallToLarge(a, bb);
        }

        public void addIntSmallToLarge(int a, long bb[]) {
            Node newNode = new Node(a);
            newNode.datas = bb;

            if (size == 0) {
                head = newNode;
                size++;
            } else {
                Node b = head;
                if (Integer.parseInt(b.data.toString()) >= a) {
                    addHead(a);
                    return;
                }
                if (size == 1 && Integer.parseInt(b.data.toString()) < a) {
                    b.next = newNode;
                    size++;
                    return;
                }
                for (int i = 1; i < size; i++) {
                    if (b != null && Integer.parseInt(b.data.toString()) <= a && b.next != null && Integer.parseInt(b.next.data.toString()) >= a) {
                        newNode.next = b.next;
                        b.next = newNode;
                        break;
                    }
                    if (b != null)
                        b = b.next;

                    if (i == size - 1 && b != null && Integer.parseInt(b.data.toString()) < a) {
                        b.next = newNode;
                    }
                }
                size++;
            }

        }

        public Object deleteHead() {
            Object obj = head.data;
            head = head.next;
            size--;
            return obj;
        }

        public Node find(Object obj) {
            Node current = head;
            int tempSize = size;
            while (tempSize > 0) {
                if (obj.equals(current.data)) {
                    return current;
                } else {
                    current = current.next;
                }
                tempSize--;
            }
            return null;
        }

        public boolean delete(Object value) {
            if (size == 0) {
                return false;
            }
            Node current = head;
            Node previous = head;
            while (current.data != value) {
                if (current.next == null) {
                    return false;
                } else {
                    previous = current;
                    current = current.next;
                }
            }
            if (current == head) {
                head = current.next;
                size--;
            } else {
                previous.next = current.next;
                size--;
            }
            return true;
        }

        public Object deleteIndex(int index) {
            if (size == 0) {
                return null;
            }
            Node current = head;
            Node previous = head;
            int i = 1;
            while (i != index) {
                i++;
                if (current.next == null) {
                    return null;
                } else {
                    previous = current;
                    current = current.next;
                }
            }
            if (current == head) {
                head = current.next;
                size--;
            } else {
                previous.next = current.next;
                size--;
            }
            return current.data;
        }


        public boolean isEmpty() {
            return (size == 0);
        }

        public void display() {
            if (size > 0) {
                Node node = head;
                while (true) {
                    if (node.next == null) {
                        System.out.print(node.data);
                        break;
                    } else {
                        System.out.print(node.data + "->");
                    }
                    node = node.next;
                }
                System.out.println();
            } else {
                System.out.println("NULL");
            }
        }

        public void displayWithoutGap() {
            if (size > 0) {
                Node node = head;
                while (true) {
                    if (node.next == null) {
                        System.out.print(node.data);
                        break;
                    } else {
                        System.out.print(node.data);
                    }
                    node = node.next;
                }
                System.out.println();
            } else {
                System.out.println("NULL");
            }
        }

    }

    public static class DoubleLinkedList {
        private int size;
        private Node head;
        private Node end;

        public DoubleLinkedList() {
            size = 0;
            head = new Node();
            end = new Node();
        }

        private class Node {
            private Object data;
            private Node next;
            private Node pre;

            public Node(Object data) {
                this.data = data;
            }

            public Node() {
            }
        }


        public Object addHead(Object obj) {
            Node newHead = new Node(obj);
            if (size == 0) {
                head.next = newHead;
                newHead.pre = head;
                newHead.next = end;
                end.pre = newHead;

            } else {
                newHead.next = head.next;
                newHead.next.pre = newHead;
                head.next = newHead;
                newHead.pre = head;
            }
            size++;
            return obj;
        }

        public Object add(int index, Object obj) {
            if (index > size + 1) {
                System.out.println("index out of size");
                return false;
            }
            Node newHead = new Node(obj);
            if (size == 0) {
                head.next = newHead;
                newHead.pre = head;
                newHead.next = end;
                end.pre = newHead;

            } else {
                Node current = head;
                for (int i = 1; i < index; i++) {
                    current = current.next;
                }
                newHead.next = current.next;
                newHead.pre = current;
                current.next = newHead;
                newHead.next.pre = newHead;
            }
            size++;
            return obj;
        }

        public void exchange(int begin1, int end1, int begin2, int end2) {
            Node begin11 = findByIndex(begin1);
            Node begin12 = findByIndex(begin2);
            Node end11 = findByIndex(end1);
            Node end12 = findByIndex(end1);
            begin11.pre.next = begin12;
            begin12.pre.next = begin11;
            end11.next.pre = end12;
            end12.next.pre = end11;
            Node a = begin11.pre;
            begin11.pre = begin12.pre;
            begin12.pre = a;
            Node b = end11.next;
            end11.next = end12.next;
            end12.next = b;
        }

        public void exchange(Node begin11, Node end11, Node begin12, Node end12) {

            begin11.pre.next = begin12;
            begin12.pre.next = begin11;
            end11.next.pre = end12;
            end12.next.pre = end11;
            Node a = begin11.pre;
            begin11.pre = begin12.pre;
            begin12.pre = a;
            Node b = end11.next;
            end11.next = end12.next;
            end12.next = b;
        }

        public Object addTail(Object obj) {
            Node newTail = new Node(obj);
            if (size == 0) {
                head.next = newTail;
                newTail.pre = head;
                newTail.next = end;
                end.pre = newTail;
            } else {
                newTail.pre = end.pre;
                newTail.pre.next = newTail;
                end.pre = newTail;
                newTail.next = end;
            }
            size++;
            return obj;
        }


        public Node find(Object obj) {
            Node current = head.next;
            int tempSize = size;
            while (tempSize > 0) {
                if (obj.equals(current.data)) {
                    return current;
                } else {
                    current = current.next;
                }
                tempSize--;
            }
            return null;
        }

        public Node findByIndex(int index) {
            if (index > size) return null;
            index++;
            if (size == 0) {
                return null;
            }
            Node current = head;
            Node previous = head;
            int i = 1;
            while (i != index) {
                i++;
                if (current.next == null) {
                    return null;
                } else {
                    previous = current;
                    current = current.next;
                }
            }

            return current;
        }

        public boolean delete(Object value) {
            if (size == 0) {
                return false;
            }
            Node current = head.next;
            Node previous = head.next;
            while (current.data != value) {
                if (current.next == null) {
                    return false;
                } else {
                    previous = current;
                    current = current.next;
                }
            }
            if (current == head.next) {
                head.next = current.next;
                size--;
            } else {
                previous.next = current.next;
                size--;
            }
            if (current == end.pre) {
                end.pre = current.pre;
            } else {
                current.next.pre = previous;
            }
            return true;
        }

        public boolean deleteIndex(int index) {
            if (index > size) return false;
            index++;
            if (size == 0) {
                return false;
            }
            Node current = head;
            Node previous = head;
            int i = 1;
            while (i != index) {
                i++;
                if (current.next == null) {
                    return false;
                } else {
                    previous = current;
                    current = current.next;
                }
            }
            if (current == head.next) {
                head.next = current.next;
            } else {
                previous.next = current.next;
            }
            if (current == end.pre) {
                end.pre = current.pre;
            } else {
                current.next.pre = previous;
            }

            size--;
            return true;
        }

        public void display(boolean oneToN) {
            if (oneToN) {
                if (size > 0) {
                    Node node = head.next;
                    while (node != null) {
                        if (node.next == end) {
                            System.out.print(node.data);
                            break;
                        } else {
                            System.out.print(node.data + "→");
                        }
                        node = node.next;
                    }
                    System.out.println();
                } else {
                    System.out.println("NULL");
                }
            } else {
                if (size > 0) {
                    Node node = end.pre;
                    while (node != null) {
                        if (node.pre == head) {
                            System.out.print(node.data);
                            break;
                        } else {
                            System.out.print(node.data + "←");
                        }
                        node = node.pre;
                    }
                    System.out.println();
                } else {
                    System.out.println("NULL");
                }
            }
        }

        public void displayWithoutGap(boolean oneToN) {
            if (oneToN) {
                if (size > 0) {
                    Node node = head.next;
                    while (node != null) {
                        if (node.next == end) {
                            System.out.print(node.data + " ");
                            break;
                        } else {
                            System.out.print(node.data + " ");
                        }
                        node = node.next;
                    }
                    System.out.println();
                } else {
                    System.out.println("");
                }
            } else {
                if (size > 0) {
                    Node node = end.pre;
                    while (node != null) {
                        if (node.pre == head) {
                            System.out.print(node.data);
                            break;
                        } else {
                            System.out.print(node.data);
                        }
                        node = node.pre;
                    }
                    System.out.println();
                } else {
                    System.out.println("");
                }
            }
        }

    }
}

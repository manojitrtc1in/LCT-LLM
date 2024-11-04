


import javax.swing.text.html.HTMLDocument;
import java.io.*;
import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    

    


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


        int testcase = in.nextInt();
        for (int test = 0; test < testcase; test++) {
            int num = in.nextInt();
            long min = 999999999999999999L;
            long a[] = new long[num];
            long b[] = new long[num];
            for(int i=0;i<num;i++){
                a[i]=in.nextLong();
                b[(i+1)%num]=in.nextLong();
            }
            long ans=0;
            for(int i=0;i<num;i++){
                long del=a[i]-b[i];
                del=del>0?del:0;
                ans+=del;
                if(a[i]-del<min)min=a[i]-del;
            }
            out.println(ans+min);

        }

        out.flush();
        out.close();
        fout.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public boolean hasNext() {
            try {
                String string = reader.readLine();
                if (string == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(string);
                return tokenizer.hasMoreTokens();
            } catch (IOException e) {
                return false;
            }
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

        public char[] id6() {
            return next().toCharArray();
        }
    }

    public static class AVLNode {

        public AVLNode parent;
        public AVLNode leftChild, rightChild;
        public int data;

        public AVLNode(AVLNode parent, AVLNode leftChild, AVLNode rightChild, int data) {
            this.parent = parent;
            this.leftChild = leftChild;
            this.rightChild = rightChild;
            this.data = data;
        }

        public AVLNode(int data) {
            this(null, null, null, data);
        }

        public AVLNode(AVLNode parent, int data) {
            this.parent = parent;
            this.data = data;
        }
    }

    public static class AVLTree {

        private AVLNode root;
        private final int LEFT = 1;
        private final int RIGHT = -1;
        private final int MAX_LEFT = 2;
        private final int MAX_RIGHT = -2;

        
        public void put(int data) {
            putData(root, data);
        }

        private boolean putData(AVLNode node, int data) {
            if (node == null) {
                node = new AVLNode(data);
                root = node;
                return true;
            }
            int t;
            AVLNode p;
            AVLNode temp = node;
            do {
                p = temp;
                t = temp.data - data;
                if (t < 0) {
                    temp = temp.rightChild;
                } else if (t > 0) {
                    temp = temp.leftChild;
                } else {
                    return false;
                }
            } while (temp != null);

            if (t < 0) {
                p.rightChild = new AVLNode(p, data);
            } else if (t > 0) {
                p.leftChild = new AVLNode(p, data);
            }
            rebuild(p);
            return true;

        }

        
        public void rebuild(AVLNode node) {
            while (node != null) {
                if (id14(node) == MAX_LEFT) {
                    id18(node, LEFT);
                } else if (id14(node) == MAX_RIGHT) {
                    id18(node, RIGHT);
                }
                node = node.parent;
            }
        }


        
        public void id18(AVLNode node, int type) {
            if (type == LEFT) {
                AVLNode leftChild = node.leftChild;
                if (leftChild.leftChild != null) {  

                    rightRotation(node);
                } else if (leftChild.rightChild != null) {   

                    leftRotation(leftChild);
                    rightRotation(node);
                }
            } else if (type == RIGHT) {
                AVLNode rightChild = node.rightChild;
                if (rightChild.rightChild != null) {   

                    leftRotation(node);
                } else if (rightChild.leftChild != null) {   

                    rightRotation(rightChild);
                    leftRotation(node);
                }
            }
        }


        
        public AVLNode rightRotation(AVLNode node) {
            if (node != null) {

                AVLNode leftChild = node.leftChild;
                node.leftChild = leftChild.rightChild;
                

                if (leftChild.rightChild != null) {
                    leftChild.rightChild.parent = node;
                }
                leftChild.parent = node.parent;
                if (node.parent == null) {
                    this.root = leftChild;
                } else if (node.parent.rightChild == node) {  

                    node.parent.rightChild = leftChild;
                } else if (node.parent.leftChild == node) {
                    node.parent.leftChild = leftChild;
                }

                leftChild.rightChild = node;
                node.parent = leftChild;
                return leftChild;
            }

            return null;
        }

        
        public AVLNode leftRotation(AVLNode node) {

            if (node != null) {
                AVLNode rightChild = node.rightChild;
                node.rightChild = rightChild.leftChild;
                if (rightChild.leftChild != null) {
                    rightChild.leftChild.parent = node;
                }
                rightChild.parent = node.parent;
                if (node.parent == null) {
                    this.root = rightChild;
                } else if (node.parent.rightChild == node) {
                    node.parent.rightChild = rightChild;
                } else if (node.parent.leftChild == node) {
                    node.parent.leftChild = rightChild;
                }
                rightChild.leftChild = node;
                node.parent = rightChild;
                return rightChild;
            }

            return null;
        }


        public int id14(AVLNode node) {
            if (node != null) {
                return id11(node);
            }
            return 0;
        }

        private int id11(AVLNode node) {
            if (node == null) {
                return 0;
            }
            return id16(node.leftChild) - id16(node.rightChild);
        }

        private int id16(AVLNode node) {
            if (node == null) {
                return 0;
            }
            return 1 + Math.max(id16(node.leftChild), id16(node.rightChild));
        }


        
        public void id0() {
            this.id0(this.root);
        }

        public void id0(AVLNode node) {
            if (node != null) {
                this.id0(node.leftChild);
                System.out.print(node.data + ", ");
                this.id0(node.rightChild);
            }
        }


        public boolean delete(int val) {
            AVLNode node = getNode(val);
            if (node == null) {
                return false;
            }
            boolean flag = false;
            AVLNode p = null;
            AVLNode parent = node.parent;
            AVLNode leftChild = node.leftChild;
            AVLNode rightChild = node.rightChild;
            if (leftChild == null && rightChild == null) {
                if (parent != null) {
                    if (parent.leftChild == node) {
                        parent.leftChild = null;
                    } else if (parent.rightChild == node) {
                        parent.rightChild = null;
                    }
                } else {
                    this.root = null;
                }

                p = parent;
                node = null;
                flag = true;
            } else if (leftChild == null && rightChild != null) {
                if (parent != null && parent.data > val) {
                    parent.leftChild = rightChild;
                } else if (parent != null && parent.data < val) {
                    parent.rightChild = rightChild;
                } else {
                    this.root = rightChild;
                }
                p = parent;
                node = null;
                flag = true;
            } else if (leftChild != null && rightChild == null) {
                if (parent != null && parent.data > val) {
                    parent.leftChild = leftChild;
                } else if (parent != null && parent.data < val) {
                    parent.rightChild = leftChild;
                } else {
                    this.root = leftChild;
                }

                p = parent;
                node = null;
                flag = true;
            } else if (leftChild != null && rightChild != null) {
                AVLNode successor = id7(node);
                int tempData = successor.data;
                if (delete(tempData)) {
                    node.data = tempData;
                }
                p = successor;
                successor = null;
                flag = true;
            }

            if (flag) {
                this.rebuild(p);
            }
            return flag;
        }


        public AVLNode getNode(int key) {

            AVLNode node = root;
            int t;
            do {
                t = node.data - key;
                if (t > 0) {
                    node = node.leftChild;
                } else if (t < 0) {
                    node = node.rightChild;
                } else {
                    return node;
                }
            } while (node != null);
            return null;
        }


        public AVLNode id7(AVLNode node) {
            if (node.rightChild != null) {
                AVLNode rightChild = node.rightChild;
                while (rightChild.leftChild != null) {
                    rightChild = rightChild.leftChild;
                }
                return rightChild;
            }
            AVLNode parent = node.parent;
            while (parent != null && (node == parent.rightChild)) {
                node = parent;
                parent = parent.parent;
            }
            return parent;
        }


        public void id20() {
            if (this.root == null) {
                return;
            }
            Queue<AVLNode> queue = new LinkedList<>();
            AVLNode temp = null;
            queue.add(this.root);
            while (!queue.isEmpty()) {
                temp = queue.poll();
                System.out.println("当前节点值：" + temp.data + ", BF：" + id14(temp));
                if (temp.leftChild != null) {
                    queue.add(temp.leftChild);
                }
                if (temp.rightChild != null) {
                    queue.add(temp.rightChild);
                }
            }
        }
    }

    public static void ansA() {
        
    }

    public static void ansB() {
        
    }

    public static class BinaryHeap {

        public BinaryHeap() {
            this(id17);
        }

        public BinaryHeap(Comparable[] items) {
            currentSize = items.length;
            array = new Comparable[(currentSize + 2) * 11 / 10];

            int i = 1;
            for (Comparable item : items) {
                array[i++] = item;
            }
            buildHeap();
        }

        public BinaryHeap(int capacity) {
            currentSize = 0;
            array = new Comparable[capacity + 1];
        }

        public void insert(Comparable x) {

            int hole = ++currentSize;
            for (; hole > 1 && x.compareTo(array[hole / 2]) < 0; hole /= 2)
                array[hole] = array[hole / 2];
            array[hole] = x;
        }

        public Comparable findMin() {
            if (isEmpty())
                return null;
            return array[1];
        }

        public Comparable deleteMin() {
            if (isEmpty())
                return null;

            Comparable minItem = findMin();
            array[1] = array[currentSize--];
            id8(1);

            return minItem;
        }

        private void buildHeap() {
            for (int i = currentSize / 2; i > 0; i--)
                id8(i);
        }

        public boolean isEmpty() {
            return currentSize == 0;
        }

        public boolean isFull() {
            return currentSize == array.length - 1;
        }

        public void makeEmpty() {
            currentSize = 0;
        }

        private static final int id17 = 100;
        private int currentSize;      

        private Comparable[] array; 


        private void id8(int hole) {
            int child;
            Comparable tmp = array[hole];

            for (; hole * 2 <= currentSize; hole = child) {
                child = hole * 2;
                if (child != currentSize && array[child + 1].compareTo(array[child]) < 0)
                    child++;
                if (array[child].compareTo(tmp) < 0)
                    array[hole] = array[child];
                else
                    break;
            }
            array[hole] = tmp;
        }
    }

    public static class stack {

        stack() {
            stackTop = -1;
            id1 = -1;
        }

        void push(int x) {
            stackTop++;
            if (stackTop >= 1000000)
                ;  

            else {
                stackItem[stackTop] = x;
                if (x > Max()) {
                    id9[stackTop] = id1;
                    id1 = stackTop;
                } else
                    id9[stackTop] = -1;
            }
        }

        int Pop() {
            int ret;

            ret = stackItem[stackTop];
            if (stackTop == id1) {
                id1 = id9[stackTop];
            }
            stackTop--;

            return ret;
        }

        int Max() {
            if (id1 >= 0)
                return stackItem[id1];
            else
                return -99999;
        }

        int stackItem[] = new int[1000000];
        int stackTop;
        int id9[] = new int[1000000];
        int id1;
    }

    ;

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


    static int m;

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

    public static int id12(long[] a, int begin, int end, int index) {
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

    public static void id4(int[][] a) {
        for (int i = a.length / 2 - 1; i >= 0; i--) {
            id2(a, i, a.length);
        }
        for (int j = a.length - 1; j > 0; j--) {
            swap2(a, 0, j);
            id2(a, 0, j);
        }

    }

    public static void id2(int[][] a, int i, int length) {
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

    public static void id4(long[][] a) {
        for (int i = a.length / 2 - 1; i >= 0; i--) {
            id2(a, i, a.length);
        }
        for (int j = a.length - 1; j > 0; j--) {
            swap2(a, 0, j);
            id2(a, 0, j);
        }

    }

    public static void id2(long[][] a, int i, int length) {
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

    public static class id13 {
        private int size;
        private Node head;

        public id13() {
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

        public void id10(int a) {
            long bb[] = new long[1];
            id10(a, bb);
        }

        public void id10(int a, long bb[]) {
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

        public void id5() {
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

    public static class id3 {
        private int size;
        private Node head;
        private Node end;

        public id3() {
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
            Node begin11 = id19(begin1);
            Node begin12 = id19(begin2);
            Node end11 = id19(end1);
            Node end12 = id19(end1);
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

        public Node id19(int index) {
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

        public void display(boolean id15) {
            if (id15) {
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

        public void id5(boolean id15) {
            if (id15) {
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
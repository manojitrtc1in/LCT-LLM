
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.Set;
import java.util.HashSet;

public class id8 {

    static Scanner in = new Scanner();

    static PrintWriter out = new PrintWriter(System.out);

    static StringBuilder ans = new StringBuilder();

    static int testCases, n, k, count = 0;

    static char x[], y[];

    static long a[], b[];

    static char ch;

    static long height;

    static int id5(int power[], long height) {

        int i = 0;

        int power_index = 0;

        while (i < n) {

            if (height > a[i]) {

                height += a[i] / 2L;

                ++i;

            } else if (power_index < 3) {

                height *= power[power_index++];

            } else {

                break;

            }

        }

        return i;

    }

    static void id5(int t) {

        
        

        sort(a, 0, n - 1);

        long copy_height = height * 2L;
        copy_height *= 2L;
        copy_height *= 3L;

        if (a[0] > copy_height) {

            ans.append(0);

            if (t != testCases) {

                ans.append("\n");

            }

            return;

        }

        int id2 = id5(new int[]{2, 2, 3}, height);
        int id4 = id5(new int[]{3, 2, 2}, height);
        int id0 = id5(new int[]{2, 3, 2}, height);

        int final_ans = Math.max(id2, Math.max(id4, id0));

        ans.append(final_ans);

        if (t != testCases) {

            ans.append("\n");

        }

    }

    static void id3(int t) {

        n = a.length;

        if (a[n - 1] == a[n - 2]) {

            ans.append(0);

        } else {

            if (!(a[n - 1] >= a[0] && a[n - 1] <= a[1])) {

                ans.append(-1);

            } else {

                if (a[n - 2] < a[n - 1]) {

                    if ((a[n - 2] + a[2] == a[n - 1]) || (a[n - 2] + a[2] < a[n - 1])) {

                        ans.append(1);

                    } else if ((a[n - 1] + a[2] <= a[1]) || (a[n - 2] - a[2] >= a[0])) {

                        ans.append(2);

                    } else if (a[n - 1] - a[0] >= a[2] && a[n - 2] + a[2] <= a[1]) {

                        ans.append(3);

                    } else {

                        

                        ans.append(-1);

                    }

                    if (t != testCases) {

                        ans.append("\n");

                    }

                    return;

                }

                long ax = a[n - 2] - a[2];
                long bx = a[n - 1] - a[2];

                long id7 = a[n - 2] + a[2];
                long rb = a[1] - a[n - 1];

                if (ax == a[n - 1] || ax > a[n - 1]) {

                    ans.append(1);

                } else if (bx >= a[0] || id7 <= a[1]) {

                    ans.append(2);

                } else if (rb >= a[2] && ax >= a[0]) {

                    ans.append(3);

                } else {

                    

                    ans.append(-1);

                }

            }

        }

        if (t != testCases) {

            ans.append("\n");

        }

    }

    static void id13(int t) {

        Set<Long> set = new HashSet<>();

        long max = 0;

        for (long i : a) {

            set.add(i);

            max = Math.max(i, max);

        }

        long number = 1L;

        long sum = 0L;

        while (true) {

            if (set.contains(number)) {

                ++number;
                continue;

            }

            set.add((long) number);

            sum += number;

            

            if (sum == k) {

                boolean ok = true;

                for (int i = (int) number; i <= (int) max; ++i) {

                    if (!set.contains((long) i)) {

                        ok = false;
                        break;

                    }

                }

                if (ok) {

                    ans.append("YES");

                } else {

                    

                    ans.append("NO");

                }

                if (t != testCases) {

                    ans.append("\n");

                }

                return;

            }

            ++number;

            if (sum > k) {

                ans.append("NO");

                

                break;

            }

        }

        

        if (t != testCases) {

            ans.append("\n");

        }

    }

    static void id1(int t) {

        n = x.length;

        StringBuilder sb = new StringBuilder();

        for (int i = 1; i <= 60; ++i) {

            sb.append("Yes");

        }

        if (sb.toString().contains(new String(x))) {

            ans.append("YES");

        } else {

            ans.append("NO");

        }

        if (t != testCases) {

            ans.append("\n");

        }

    }

    public static void main(String[] Priya) throws IOException {

        testCases = in.nextInt();

        for (int t = 0; t < testCases; ++t) {

            
 
 
            n = in.nextInt();

            height = in.nextLong();

            a = new long[n];

            for (int i = 0; i < n; ++i) {

                a[i] = in.nextLong();

            }

            id5(t + 1);

        }

        out.print(ans.toString());
        out.flush();

    }

    static class pair implements Comparable<pair> {

        long value;
        int index;

        public pair(long value, int index) {

            this.value = value;
            this.index = index;

        }

        @Override
        public int compareTo(pair p) {

            if (this.value > p.value) {

                return 1;

            } else if (this.value < p.value) {

                return -1;

            }

            return 0;

        }

    }

    static long pow(long value, long power) {

        long pow_value = 1L;

        while (power > 0L) {

            if (power % 2L == 1L) {

                pow_value *= value;

            }

            value *= value;

            power /= 2L;

        }

        return pow_value;

    }

    static int upper_bound(long arr[], int N, long X) {
        int mid;

        int low = 0;
        int high = N;

        while (low < high) {

            mid = low + (high - low) / 2;

            if (X >= arr[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        if (low < N && arr[low] <= X) {
            low++;
        }

        return low;
    }

    static int lower_bound(long a[], long value) {

        int n = a.length;

        int l = 0, r = n - 1;

        while (r > l) {

            int mid = (l + r) / 2;

            if (a[mid] >= value) {

                r = mid;

            } else {

                l = mid + 1;

            }

        }

        if (n > l && a[l] < value) {
            ++l;
        }

        return l;

    }

    static long gcd(long a, long b) {

        if (b == 0) {

            return a;

        }

        return gcd(b, a % b);

    }

    static int search(long a[], long x, int last) {

        int i = 0, j = last;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (a[mid] == x) {
                return mid;
            }

            if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }

        return -1;

    }

    static void swap(long a[], int i, int j) {

        long temp = a[i];
        a[i] = a[j];
        a[j] = temp;

    }

    static void reverse(long a[]) {

        int n = a.length;

        for (int i = 0; i < n / 2; ++i) {

            swap(a, i, n - i - 1);

        }

    }

    static long max(long a[], int i, int n, long max) {

        if (i > n) {

            return max;

        }

        max = Math.max(a[i], max);

        return max(a, i + 1, n, max);

    }

    static long min(long a[], int i, int n, long max) {

        if (i > n) {

            return max;

        }

        max = Math.min(a[i], max);

        return max(a, i + 1, n, max);

    }

    static void printArray(long a[]) {

        for (long i : a) {

            System.out.print(i + " ");

        }

        System.out.println();

    }

    static boolean id10(String str1, String str2) {

        int n1 = str1.length(), n2 = str2.length();

        if (n1 < n2) {
            return true;
        }
        if (n2 < n1) {
            return false;
        }

        for (int i = 0; i < n1; i++) {
            if (str1.charAt(i) < str2.charAt(i)) {
                return true;
            } else if (str1.charAt(i) > str2.charAt(i)) {
                return false;
            }
        }
        return false;
    }

    static String sub(String str1, String str2) {

        if (id10(str1, str2)) {
            String t = str1;
            str1 = str2;
            str2 = t;
        }

        String str = "";

        int n1 = str1.length(), n2 = str2.length();
        int diff = n1 - n2;

        int carry = 0;

        for (int i = n2 - 1; i >= 0; i--) {

            int sub
                    = (((int) str1.charAt(i + diff) - (int) '0')
                    - ((int) str2.charAt(i) - (int) '0')
                    - carry);
            if (sub < 0) {
                sub = sub + 10;
                carry = 1;
            } else {
                carry = 0;
            }

            str += String.valueOf(sub);
        }

        for (int i = n1 - n2 - 1; i >= 0; i--) {
            if (str1.charAt(i) == '0' && carry > 0) {
                str += "9";
                continue;
            }
            int sub = (((int) str1.charAt(i) - (int) '0')
                    - carry);
            if (i > 0 || sub > 0) {
                str += String.valueOf(sub);
            }
            carry = 0;
        }

        return new StringBuilder(str).reverse().toString();
    }

    static String sum(String str1, String str2) {

        if (str1.length() > str2.length()) {
            String t = str1;
            str1 = str2;
            str2 = t;
        }

        String str = "";

        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        int carry = 0;

        for (int i = n1 - 1; i >= 0; i--) {

            int sum = ((int) (str1.charAt(i) - '0')
                    + (int) (str2.charAt(i + diff) - '0') + carry);
            str += (char) (sum % 10 + '0');
            carry = sum / 10;
        }

        for (int i = n2 - n1 - 1; i >= 0; i--) {
            int sum = ((int) (str2.charAt(i) - '0') + carry);
            str += (char) (sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry > 0) {
            str += (char) (carry + '0');
        }

        return new StringBuilder(str).reverse().toString();
    }

    static long detect_sum(int i, long a[], long sum) {

        if (i >= a.length) {

            return sum;

        }

        return detect_sum(i + 1, a, sum + a[i]);

    }

    static String mul(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0 || len2 == 0) {
            return "0";
        }

        int result[] = new int[len1 + len2];

        int id6 = 0;
        int id12 = 0;

        for (int i = len1 - 1; i >= 0; i--) {
            int carry = 0;
            int n1 = num1.charAt(i) - '0';

            id12 = 0;

            for (int j = len2 - 1; j >= 0; j--) {

                int n2 = num2.charAt(j) - '0';

                int sum = n1 * n2 + result[id6 + id12] + carry;

                carry = sum / 10;

                result[id6 + id12] = sum % 10;

                id12++;
            }

            if (carry > 0) {
                result[id6 + id12] += carry;
            }

            id6++;
        }

        int i = result.length - 1;
        while (i >= 0 && result[i] == 0) {
            i--;
        }

        if (i == -1) {
            return "0";
        }

        String s = "";

        while (i >= 0) {
            s += (result[i--]);
        }

        return s;

    }

    static class Node<T> {

        T data;

        Node<T> next;

        public Node() {

            this.next = null;

        }

        public Node(T data) {

            this.data = data;

            this.next = null;

        }

        public T getData() {
            return data;
        }

        public void setData(T data) {
            this.data = data;
        }

        public Node<T> getNext() {
            return next;
        }

        public void setNext(Node<T> next) {
            this.next = next;
        }

        @Override
        public String toString() {

            return this.getData().toString() + "  ";

        }

    }

    static class id9<T> {

        Node<T> head, tail;

        int len;

        public id9() {

            this.head = null;

            this.tail = null;

            this.len = 0;

        }

        int size() {

            return len;

        }

        boolean isEmpty() {

            return len == 0 || head == null || tail == null;

        }

        int indexOf(T data) {

            if (isEmpty()) {

                throw new ArrayIndexOutOfBoundsException();

            }

            Node<T> temp = head;

            int index = -1, i = 0;

            while (temp != null) {

                if (temp.getData() == data) {

                    index = i;

                }

                i++;

                temp = temp.getNext();

            }

            return index;

        }

        void add(T data) {

            Node<T> newNode = new Node<>(data);

            if (isEmpty()) {

                head = newNode;

                tail = newNode;

                len++;

            } else {

                tail.setNext(newNode);

                tail = newNode;

                len++;

            }

        }

        void see() {

            if (isEmpty()) {

                throw new ArrayIndexOutOfBoundsException();

            }

            Node<T> temp = head;

            while (temp != null) {

                System.out.print(temp.getData().toString() + " ");
                


                temp = temp.getNext();

            }

            System.out.println();
            


        }

        void id11(T data) {

            Node<T> newNode = new Node<>(data);

            Node<T> temp = head;

            if (isEmpty()) {

                head = newNode;
                tail = newNode;

                len++;

            } else {

                newNode.setNext(temp);

                head = newNode;

                len++;

            }

        }

        T get(int index) {

            if (isEmpty() || index >= len) {

                throw new ArrayIndexOutOfBoundsException();

            }

            if (index == 0) {

                return head.getData();

            }

            Node<T> temp = head;

            int i = 0;

            T data = null;

            while (temp != null) {

                if (i == index) {

                    data = temp.getData();

                }

                i++;

                temp = temp.getNext();

            }

            return data;

        }

        void addAt(T data, int index) {

            if (index >= len) {

                throw new ArrayIndexOutOfBoundsException();

            }

            Node<T> newNode = new Node<>(data);

            int i = 0;

            Node<T> temp = head;

            while (temp.next != null) {

                if (i == index) {

                    newNode.setNext(temp.next);

                    temp.next = newNode;

                }

                i++;

                temp = temp.getNext();

            }

            

            len++;

        }

        void popFront() {

            if (isEmpty()) {

                

                throw new ArrayIndexOutOfBoundsException();

            }

            if (head == tail) {

                head = null;
                tail = null;

            } else {

                head = head.getNext();

            }

            len--;

        }

        void removeAt(int index) {

            if (index >= len) {

                throw new ArrayIndexOutOfBoundsException();

            }

            if (index == 0) {

                this.popFront();

                return;

            }

            Node<T> temp = head;

            int i = 0;

            Node<T> n = new Node<>();

            while (temp != null) {

                if (i == index) {

                    n.next = temp.next;

                    temp.next = n;

                    break;

                }

                i++;

                n = temp;

                temp = temp.getNext();

            }

            tail = n;

            --len;

        }

        void clearAll() {

            this.head = null;
            this.tail = null;

        }

    }

    static void merge(long a[], int left, int right, int mid) {

        int n1 = mid - left + 1, n2 = right - mid;

        long L[] = new long[n1];

        long R[] = new long[n2];

        for (int i = 0; i < n1; i++) {

            L[i] = a[left + i];

        }

        for (int i = 0; i < n2; i++) {

            R[i] = a[mid + 1 + i];

        }

        int i = 0, j = 0, k1 = left;

        while (i < n1 && j < n2) {

            if (L[i] <= R[j]) {

                a[k1] = L[i];

                i++;

            } else {

                a[k1] = R[j];

                j++;

            }

            k1++;

        }

        while (i < n1) {

            a[k1] = L[i];

            i++;

            k1++;

        }

        while (j < n2) {

            a[k1] = R[j];

            j++;
            k1++;

        }

    }

    static void sort(long a[], int left, int right) {

        if (left >= right) {

            return;

        }

        int mid = (left + right) / 2;

        sort(a, left, mid);

        sort(a, mid + 1, right);

        merge(a, left, right, mid);

    }

    static class Scanner {

        BufferedReader in;
        StringTokenizer st;

        public Scanner() {

            in = new BufferedReader(new InputStreamReader(System.in));

        }

        String next() throws IOException {

            while (st == null || !st.hasMoreElements()) {

                st = new StringTokenizer(in.readLine());

            }

            return st.nextToken();

        }

        String nextLine() throws IOException {

            return in.readLine();

        }

        int nextInt() throws IOException {

            return Integer.parseInt(next());

        }

        double nextDouble() throws IOException {

            return Double.parseDouble(next());

        }

        long nextLong() throws IOException {

            return Long.parseLong(next());

        }

        void close() throws IOException {

            in.close();

        }

    }

}
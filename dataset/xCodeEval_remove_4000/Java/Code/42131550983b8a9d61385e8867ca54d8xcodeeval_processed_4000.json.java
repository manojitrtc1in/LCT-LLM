
 
import java.util.*;
 
public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            String a = in.next();
            String b = in.next();
            int x = 0;
            int L = 0;
            int m = 0;
            int s = 0;
            int x1 = 0;
            int L1 = 0;
            int m1 = 0;
            int s1 = 0;
            for (int i = 0; i < a.length(); i++) {
                if (a.charAt(i) == 'X') {
                    x++;
                } else if (a.charAt(i) == 'L') {
                    L++;
                } else if (a.charAt(i) == 'M') {
                    m++;
                } else {
                    s++;
                }
            }
            for (int i = 0; i < b.length(); i++) {
                if (b.charAt(i) == 'X') {
                    x1++;
                } else if (b.charAt(i) == 'L') {
                    L1++;
                } else if (b.charAt(i) == 'M') {
                    m1++;
                } else {
                    s1++;
                }
            }
            if (L > L1) {
                System.out.println(">");
            } else if (L < L1) {
                System.out.println("<");
            } else {
                if (m > m1) {
                    System.out.println(">");
                } else if (m < m1) {
                    System.out.println("<");
                } else {
                    if (s > s1) {
                        System.out.println(">");
                    } else if (s < s1) {
                        System.out.println("<");
                    } else {
                        if (x > x1 && (L == L1 && L1 != 0)) {
                            System.out.println(">");
                        } else if (x < x1 && (L == L1 && L != 0)) {
                            System.out.println("<");
                        } else if (x < x1 && (s == s1 && s != 0)) {
                            System.out.println(">");
                        } else if (x > x1 && (s == s1 && s != 0)) {
                            System.out.println("<");
                        } else System.out.println("=");
                    }
                }
            }
        }
    }
 
    public class ListNode<E> {
        private E value;
        private Ex3.ListNode next;
 
        public ListNode(E newVal, Ex3.ListNode<E> newNext) {
            this.value = newVal;
            this.next = newNext;
        }
 
        public E getValue() {
            return this.value;
        }
 
        public Ex3.ListNode<E> getNext() {
            return this.next;
        }
 
        public void setValue(E newValue) {
            this.value = newValue;
        }
 
        public void setNext(Ex3.ListNode<E> newNext) {
            this.next = newNext;
        }
    }
}
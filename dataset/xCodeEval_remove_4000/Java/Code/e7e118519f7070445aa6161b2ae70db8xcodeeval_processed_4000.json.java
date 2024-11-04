
 
import java.util.*;
 
public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
 
            if (x == 3) {
                System.out.println(-1);
            } else {
                if (x % 2 == 0) {
                    for (int i = x; i >= 1; i--) {
                        System.out.print(i + " ");
                    }
                    System.out.println();
                } else {
                    int w = x / 2 + 1;
                    for (int i = x; i > w; i--) {
                        System.out.print(i + " ");
                    }
                    for (int i = 1; i < w + 1; i++) {
                        System.out.print(i + " ");
                    }
                    System.out.println();
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


import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            String str = in.next();
            HashSet<String> set = new HashSet<String>();
            for (int i = 0; i < str.length(); i++) {
                set.add(String.valueOf(str.charAt(i)));
            }
            System.out.println(2*(set.size()) + (str.length()-set.size()));
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

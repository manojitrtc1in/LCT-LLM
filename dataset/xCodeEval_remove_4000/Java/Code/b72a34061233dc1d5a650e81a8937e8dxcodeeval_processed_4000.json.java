

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int oo = 0; oo < t; oo++) {
            int x = in.nextInt();


































            if(x >= 1900){
                System.out.println("Division 1");
            }else if(x >=1600 && x <= 1899){
                System.out.println("Division 2");
            }else if(x >= 1400 && x <= 1599){
                System.out.println("Division 3");
            }else if(x <= 1399){
                System.out.println("Division 4");
            }


        }
    }


    public class ListNode<E> {
        private E value;
        private ListNode next;

        public ListNode(E newVal, ListNode<E> newNext) {
            value = newVal;
            next = newNext;
        }

        public E getValue() {
            return value;
        }

        public ListNode<E> getNext() {
            return next;
        }

        public void setValue(E newValue) {
            value = newValue;
        }

        public void setNext(ListNode<E> newNext) {
            next = newNext;
        }
    }
}
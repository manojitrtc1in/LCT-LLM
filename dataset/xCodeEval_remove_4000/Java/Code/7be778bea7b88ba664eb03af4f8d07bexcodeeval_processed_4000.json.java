

import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int oo = 0; oo < t; oo++) {
            int x = in.nextInt();
            int a[] = new int[x];
            int b[] = new int[x];
            ArrayList<Integer> a1 = new ArrayList<>();
            ArrayList<Integer> b1 = new ArrayList<>();
            for (int i = 0; i < x; i++) {
                a[i] = in.nextInt();
            }
            for(int i = 0; i < x; i++){
                b[i] = in.nextInt();
                if(a[i] == 0){
                    a1.add(b[i]);
                }else {
                    b1.add(b[i]);
                }
            }
            a1.sort(Collections.reverseOrder());
            b1.sort(Collections.reverseOrder());
            long cout = 0;
            int min = Math.min(a1.size(),b1.size());
            int max = Math.max(a1.size(),b1.size());
            for (int i = 0; i < min; i++) {
                if (i != min - 1 || min != max) {
                    cout += (2L * a1.get(i));
                    cout += (2L * b1.get(i));
                } else {
                    cout += (Math.max(2L * a1.get(i), 2L * b1.get(i)));
                    cout += (Math.min(a1.get(i), b1.get(i)));
                }
            }
            for (int i = min; i < max; i++) {
                if (i < b1.size()) {
                    cout += b1.get(i);
                }
                else {cout += a1.get(i);}
            }
            System.out.println(cout);
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
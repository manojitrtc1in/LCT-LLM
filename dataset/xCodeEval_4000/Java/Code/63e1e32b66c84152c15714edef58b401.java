    

    import java.util.*;

    public class Ex3 {
        public static void main(String[] args) {
            Scanner in = new Scanner(System.in);
            int t = in.nextInt();
            for (int oo = 0; oo < t; oo++) {
                int n = in.nextInt();
                int m = in.nextInt();
                if(n == 1 && m == 1){
                    System.out.println("1 1");
                }else if(n == 1 && m == 2){
                    System.out.println("1 2");
                }else if(n == 2 && m == 1){
                    System.out.println("2 1");
                }else if(n == 2 && m ==3 || n == 3 && m ==2|| n==3 && m==3){
                    System.out.println("2 2");
                }else if(n == 3 && m == 4 || n == 4 && m == 3){
                    System.out.println("1 1");
                }else {
                    System.out.println("1 1");
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

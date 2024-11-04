
import java.util.*;
public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            int x = in.nextInt();
            int arr[] = new int[x];
            for(int i = 0; i < arr.length; i++){
                arr[i] = in.nextInt();
            }
            Arrays.sort(arr);
            int cout = 0;
            for(int i = 1; i < arr.length; i++){
                cout += arr[i] - arr[0];
            }
            System.out.println(cout);
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



import java.util.*;

public class Ex3 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        for (int t = 0; t < q; t++) {
            String arr[] = new String[8];
            for(int i = 0; i < 8; i++){
                arr[i] = in.next();
            }

            int cout = 0;
            int cout11 = 0;

            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(arr[i].charAt(j) == 'R'){
                        cout++;
                    }
                }
                if(cout > 7){
                    System.out.println("R");
                    break;
                }
                cout = 0;
            }

            for(int i = 0; i < 8; i++){
                for(int j = 0; j < 8; j++){
                    if(arr[j].charAt(i) == 'B'){
                        cout11++;
                    }
                }
                if(cout11 > 7){
                    System.out.println("B");
                    break;
                }
                cout11 = 0;
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
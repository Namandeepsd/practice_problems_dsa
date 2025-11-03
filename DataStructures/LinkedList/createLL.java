
class Node{
    int data;
    Node next;

    Node (int data1, Node next1){
        data = data1;
        next= next1;
    }

    Node (int data1){
        data = data1;
        next= null;
    }
}


public class createLL{
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5};
        Node y = new Node(arr[0]);
        System.out.println(y.data);
    }
}


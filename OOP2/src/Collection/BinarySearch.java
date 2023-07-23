package Collection;
import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int []arr=new int[10];
        for(int i=0;i<10;i++) arr[i]=sc.nextInt();
        int index=Arrays.binarySearch(arr,8);
        System.out.println("Index: "+index);
    }
}

package Generics;

import java.util.ArrayList;
import java.util.List;

public class RunPrinter {
    public static void main(String[] args) {
        ArrayList<Integer> arrayList=new ArrayList<>();
        arrayList.add(1412);
        arrayList.add(2083);

        Printer<Integer> myprinter=new Printer(arrayList);
        myprinter.print();

        shout("misty");
        shout(2083);

        printList(arrayList);
        List<String> names=new ArrayList<>();
        names.add("oni");
        names.add("misty");

        printList(names);


    }
    public static <T> void shout(T toShout){
        System.out.println(toShout+"!!!");
    }
    public static void printList(List<?> arraylist){
        System.out.println(arraylist);
    }
}

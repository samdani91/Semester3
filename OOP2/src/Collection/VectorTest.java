package Collection;

import java.util.Collections;
import java.util.NoSuchElementException;
import java.util.Vector;

public class VectorTest {
    public static String[] colors ={"Red","Blue","Green","White","Purple","Cyan","Orange","Yellow","Black","Grey"};
    public static String[] colors2 ={"Pink", "Brown", "Gold", "Indigo", "Magenta", "Teal", "Lavender", "Maroon", "Turquoise", "Coral"};

    public VectorTest() {
        Vector<String>vector= new Vector<>();
        Vector<String>vector2= new Vector<>();
        Vector<String>toFill=new Vector<>();
        //printVector(vector);
        //System.out.println("Size and capacity:"+vector.size()+" "+vector.capacity());

        for(String color:colors){
            vector.add(color);
            toFill.add(color);

        }
        for(String color:colors2){
            vector2.add(color);
        }
        printVector(vector);
//        System.out.println("Size and capacity:"+vector.size()+" "+vector.capacity());
//
//        vector.add("Navy blue");
//        System.out.println("Size and capacity:"+vector.size()+" "+vector.capacity());

//        try{
//            System.out.println("First element:"+vector.firstElement());
//            System.out.println("Last element:"+vector.lastElement());
//        }catch (NoSuchElementException exception){
//            exception.printStackTrace();
//        }
//
//        if(vector.contains("Red")) System.out.println("\"Red\" Found at "+vector.indexOf("Red"));
//        else System.err.println("Red not found");

//        vector.remove("Red");
//        System.out.println("\"Red\" has been removed");
//        printVector(vector);

        //System.out.println("Size and capacity:"+vector.size()+" "+vector.capacity());

        //usages of methods
        //sort
        System.out.println();
        Collections.sort(vector);
        System.out.println("Sorted:");
        printVector(vector);
        System.out.println();

        //binarySearch
        int check= Collections.binarySearch(vector,"Red");
        if(check>=0) System.out.println("Red found at "+check);
        else System.out.println("Red not found");
        System.out.println();

        //reverse
        Collections.reverse(vector);
        System.out.println("Reversed:");
        printVector(vector);
        System.out.println();

        //shuffle
        System.out.println("Shuffled");
        Collections.shuffle(vector);
        printVector(vector);
        System.out.println();

        //fill
        //Collections.fill method expects a non-empty list to fill with the given value.
        System.out.println("Filled:");
        Collections.fill(toFill,"Pink");
        printVector(toFill);
        System.out.println();

        //copy
        Vector<String>copied=new Vector<>(vector.size());
        Collections.copy(vector,copied);
        System.out.println("Copied:");
        printVector(copied);
        System.out.println();

        //find minimum
        String min=Collections.min(vector);
        System.out.println("Minimum:"+min);
        System.out.println();

        //find maximum
        String max=Collections.max(vector);
        System.out.println("Maximum:"+max);
        System.out.println();

        //frequency
        System.out.println("Frequency: "+Collections.frequency(vector,"Red"));
        System.out.println();

        //disjoint
        System.out.println("Checking common");
        boolean check2=Collections.disjoint(vector,vector2);
        if(check2){
            System.out.println("No common elements between vector and vector2");
        }else{
            System.out.println("Common elements found between vector and vector2");
        }
        System.out.println();


    }
    public static void printVector(Vector<String>vector){
        if(vector.isEmpty()) System.err.println("Vector is empty");
        else {
            System.out.print("Vector contains: ");
            for (String color : vector) {
                System.out.print(color+" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        new VectorTest();
    }
}
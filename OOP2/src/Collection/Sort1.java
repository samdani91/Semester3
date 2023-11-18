package Collection;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class Sort1 {
    private static final String suits[]=
            {"Hearts","Diamonds","Clubs","Spades"};

    public void printElements(){
        List<String> list= Arrays.asList(suits);
        System.out.println("Unsorted"+list);

        Collections.sort(list);
        System.out.println("Sorted:"+list);
    }

    public static void main(String[] args) {
        Sort1 sort1=new Sort1();
        sort1.printElements();
    }
}

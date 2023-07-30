package Collection;
import java.util.*;

public class CommonProgrammingError {
    private final String[] color={"black", "yellow", "green", "blue", "violet", "silver"};

    public CommonProgrammingError(){
        List <String>list=new LinkedList<>();
        list.add("red");
        list.add("white");

        //color=list.toArray(color);
        System.arraycopy(list.toArray(new String[list.size()]),0,color,0,list.size());

        for(String ele:color){
            System.out.println(ele);
        }
    }

    public static void main(String[] args) {
        new CommonProgrammingError();
    }
}

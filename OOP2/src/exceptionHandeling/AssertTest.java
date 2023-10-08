import java.util.Scanner;

public class AssertTest {
    //page 90
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.print("Enter a number between 0 and 10:");
        int number=input.nextInt();

        //assert that the absolute value is >=0
        assert(number>=0 && number<=10): "bad number: "+number;

        System.out.println("You entered "+number);
    }
}

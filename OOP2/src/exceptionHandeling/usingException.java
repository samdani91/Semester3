package exceptionHandeling;

public class usingException {
    public static void main(String[] args) {
        int a=4;
        int b=0;
        int division;
        try {
            division=a/b;
        }catch (Exception exception){
            System.out.println(exception);
        }
//        finally {
//            System.out.println("Division:" + a / b);
//        }
    }
}

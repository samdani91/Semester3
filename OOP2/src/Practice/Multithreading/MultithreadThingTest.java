package Practice.Multithreading;

public class MultithreadThingTest {
    public static void main(String[] args) {

        for(int i=1;i<=3;i++){
            MultithreadThing myThing=new MultithreadThing(i);
            Thread myThread=new Thread(myThing);//if we use implements runnable
            myThread.start();
            /*try {
                myThread.join();       //waits till one thread is done
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }*/

            //System.out.println(myThread.isAlive());
        }

//        throw new RuntimeException();

        /*MultithreadThing myThing=new MultithreadThing(1);
        MultithreadThing myThing2=new MultithreadThing(2);

        myThing.start();
        myThing2.start();*/
    }
}

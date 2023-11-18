package Generics;

public class Printer<T> {

    T toShow;
    public Printer(T toShow){
        this.toShow=toShow;
    }
    public void print(){
        System.out.println(toShow);
    }
}

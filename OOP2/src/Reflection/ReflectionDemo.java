package Reflection;

import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class ReflectionDemo {
    public static void main(String[] args) throws Exception{
        Cat myCat=new Cat("Tom",6);

        System.out.println("Before:"+myCat.getName());
        Field[] catFields=myCat.getClass().getDeclaredFields();

        for(Field field:catFields){
//            System.out.println(field.getName());
            if(field.getName().equals("name")){
                field.setAccessible(true);
                field.set(myCat,"Lala");
            }
        }

        System.out.println("After:"+myCat.getName());

        Method[] catMethods=myCat.getClass().getMethods();
        for(Method method:catMethods){
            System.out.println(method.getName());
            if(method.getName().equals("heyThisIsPrivate")){
                method.setAccessible(true);//for static null
                method.invoke(myCat);
            }
        }
    }
}

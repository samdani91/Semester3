package File;

import java.io.*;

public class ReadSequentialFile {
    private ObjectInputStream input;

    public void openFile(){
        try{
            input=new ObjectInputStream(new FileInputStream("/home/samdani1412/Desktop/Semester3/OOP2/src/File/clients.ser"));
        }catch (IOException ioException){
            System.err.println("Error Opening FIle");
        }
    }

    public void readRecords(){
        AccountRecordSerializable record;
        System.out.println("Acoount  First Name  Last Name Balance");

        try{
            while(true){
                record=(AccountRecordSerializable) input.readObject();

                System.out.println(record.getAccount()+"  "+record.getFirstName()+"  "+record.getLastName()+"  "+record.getBalance());
            }
        }catch (EOFException eofException){
            return;
        }catch(ClassNotFoundException classNotFoundException){
            System.err.println("Unable to create object.");
        }catch (IOException ioException){
            System.err.println("Error during read from file.");
        }
    }

    public void closeFile(){
        try{
            if(input!=null) input.close();
        }catch (IOException ioException){
            System.err.println("Error closing File");
            System.exit(1);
        }
    }
}

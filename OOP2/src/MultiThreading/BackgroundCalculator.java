package MultiThreading;

import javax.swing.*;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.concurrent.ExecutionException;

public class BackgroundCalculator extends SwingWorker<String,Object> {
    private final int n;
    private final JLabel resultJLabel;

    private long[] dp=new long[205];


    public BackgroundCalculator(int number,JLabel label){
        n=number;
        resultJLabel=label;
    }


    @Override
    public String doInBackground() throws Exception {
        Arrays.fill(dp, -1);
        long nthFib= fibonacci(n);
        return String.valueOf(nthFib);
    }

    protected void done(){

        try {
            resultJLabel.setText(get());
        } catch (InterruptedException e) {
            resultJLabel.setText("Interrupted while waiting for results.");
        } catch (ExecutionException e) {
            resultJLabel.setText("Error encountered while performing calculation.");
        }
    }
    public long fibonacci(int n){
        if(n<=1) {
            return dp[n]=n;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fibonacci(n-1)+fibonacci(n-2);
    }
}

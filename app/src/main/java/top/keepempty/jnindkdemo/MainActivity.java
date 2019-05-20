package top.keepempty.jnindkdemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        testBase();

    }

    private void testBase(){
        boolean b = JNIBaseUtils.passBooleanReturnBoolean(true);
        byte b1 = JNIBaseUtils.passByteReturnByte((byte) 10);
        char c = JNIBaseUtils.passCharReturnChar('#');
        short s = JNIBaseUtils.passShortReturnShort((short) 100);
        int i = JNIBaseUtils.passIntReturnInt(1000);
        long l = JNIBaseUtils.passLongReturnLong(234234242L);
        float f = JNIBaseUtils.passFloatReturnFloat(10.0f);
        double d = JNIBaseUtils.passDoubleReturnDouble(11.11);

        String string = JNIBaseUtils.passStringReturnString("hello");


        // 在Java中打印输出
        Log.i("MainActivity","boolean: "+b);
        Log.i("MainActivity","byte: "+b1);
        Log.i("MainActivity","char: "+c);
        Log.i("MainActivity","short: "+s);
        Log.i("MainActivity","int: "+i);
        Log.i("MainActivity","long: "+l);
        Log.i("MainActivity","float: "+f);
        Log.i("MainActivity","double: "+d);
        Log.i("MainActivity","String: "+string);
    }

    private void testReg(){
        JNIRegUtils.getString();
        JNIRegUtils.getTwoSum(2,3);
        JNIRegUtils.printlnString("Hello","JNI");
    }


}

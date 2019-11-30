package top.keepempty.jnindkdemo;

import android.util.Log;

public class JNICallJMUtils {

    private static String message = "message1";

    private String message1 = "msg1";

    static {

        System.loadLibrary("JNICallJM");
    }

    public static native String sayHello();


    public static void staticMethod(String msg){
        Log.i("JNICallJMUtils", msg);
        Log.i("JNICallJMUtils", message);
    }

    public void javaMethod(String msg){
        Log.i("JNICallJMUtils",msg);
        Log.i("JNICallJMUtils",message1);
    }

    public static native void callJavaMethod(int i);

    public static native void callJavaStaticMethod(int i);
}

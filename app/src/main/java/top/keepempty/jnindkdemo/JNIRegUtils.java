package top.keepempty.jnindkdemo;


/**
 * @author frey
 * JNI动态注册demo
 */
public class JNIRegUtils {


    public static native String getString();

    public static native void printlnString(String str1,String str2);

    public static native int getTwoSum(int a,int b);

    public static native int init_confing_test(int a);


    static {
        System.loadLibrary("jni_reg");
    }
}

package top.keepempty.jnindkdemo;

/**
 * 说明：
 * 作者：fu.xie
 * 版本：
 * 创建日期：2019/5/20 17:46
 */
public class JNIBaseUtils {

    // 定义本地方法
    public static native boolean passBooleanReturnBoolean(boolean b);
    public static native byte passByteReturnByte(byte b);
    public static native char passCharReturnChar(char c);
    public static native short passShortReturnShort(short s);
    public static native int passIntReturnInt(int i);
    public static native long passLongReturnLong(long l);
    public static native float passFloatReturnFloat(float f);
    public static native double passDoubleReturnDouble(double d);

    public static native String passStringReturnString(String string);

    static {
        System.loadLibrary("JNIBase");
    }
}

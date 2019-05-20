#include <jni.h>
#include <string>
#include <android/log.h>
#include "include/JNIBase.h"

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passBooleanReturnBoolean
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passBooleanReturnBoolean
        (JNIEnv *, jobject, jboolean b){

    LOGI("%d in %d bytes", b, sizeof(b));

    return !b;

}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passByteReturnByte
 * Signature: (B)B
 */
JNIEXPORT jbyte JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passByteReturnByte
        (JNIEnv *, jobject, jbyte b){
    LOGI("%d in %d bytes", b, sizeof(b));
    return b+1;
}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passCharReturnChar
 * Signature: (C)C
 */
JNIEXPORT jchar JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passCharReturnChar
        (JNIEnv *, jobject, jchar c){

    LOGI("%d in %d bytes", c, sizeof(c));
    c = '*';
    return c;
}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passShortReturnShort
 * Signature: (S)S
 */
JNIEXPORT jshort JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passShortReturnShort
        (JNIEnv *, jobject, jshort s){

    LOGI("%d in %d bytes", s, sizeof(s));

    return s - 1;
}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passIntReturnInt
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passIntReturnInt
        (JNIEnv *, jobject, jint i){

    LOGI("%d in %d bytes", i, sizeof(i));

    return i + 1;
}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passLongReturnLong
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passLongReturnLong
        (JNIEnv *, jobject, jlong l){
    LOGI("%d in %d bytes", l, sizeof(l));

    return l + 1;
}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passFloatReturnFloat
 * Signature: (F)F
 */
JNIEXPORT jfloat JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passFloatReturnFloat
        (JNIEnv *, jobject, jfloat f){
    LOGI("%d in %d bytes", f, sizeof(f));

    return f + 1.5;
}

/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passDoubleReturnDouble
 * Signature: (D)D
 */
JNIEXPORT jdouble JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passDoubleReturnDouble
        (JNIEnv *, jobject, jdouble d){

    LOGI("%d in %d bytes", d, sizeof(d));

    return d + 1.5;
}


/*
 * Class:     top_keepempty_jnindkdemo_JNIBaseUtils
 * Method:    passStringReturnString
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_top_keepempty_jnindkdemo_JNIBaseUtils_passStringReturnString
   (JNIEnv * env, jobject, jstring pStr){

      // 测试直接输入Java字符串，因为编码格式的不同，这里会报错
      //LOGI("print jstring : %s",s);

      const char *jstr;
      jboolean *isCopy;

      //GetStringUTFChars使用
      jstr = env->GetStringUTFChars(pStr, isCopy);
      // 不要忘记检测，否则分配内存失败会抛出异常
      if(jstr==NULL){
          LOGI("cannot convert jstring to utf-8 string");
          return NULL;
      }
      LOGI("print UTF-8 string ：%s,%d",jstr,isCopy);

      //GetStringUTFLength使用
      jsize length = env->GetStringUTFLength(pStr);
      LOGI("UTF-8 string length (number of bytes):%d == %d",length,strlen(jstr));
      LOGI("UTF-8 string end with :%d %d",jstr[length],jstr[length]+1);

      //ReleaseStringUTFChars使用
      env-> ReleaseStringUTFChars(pStr,jstr);

      //GetStringUTFRegion使用
      char nativeStr[100];
      env->GetStringUTFRegion(pStr, 0, length, nativeStr);
      LOGI("*jstring converted to UTF-8 string and copied to native buffer :%s",nativeStr);

      //NewStringUTF使用，在JNI中创建一个UTF字符串
      const char* newStr = "Test ndk 安卓";
      jstring ret = env->NewStringUTF(newStr);
      jsize newStrlen = env->GetStringUTFLength(ret);
      LOGI("UTF-8 string with Chinese characters :%s ,string length (number of bytes) %d=%d",newStr,newStrlen,strlen(newStr));
      return ret;
  }
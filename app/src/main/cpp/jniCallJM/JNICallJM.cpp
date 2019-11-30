#include <jni.h>
#include <string>
#include <android/log.h>
#include "include/JNICallJM.h"

/*
* Class:     top_keepempty_jnindkdemo_JNICallJMUtils
* Method:    sayHello
* Signature: ()V
*/
JNIEXPORT jstring JNICALL Java_top_keepempty_jnindkdemo_JNICallJMUtils_sayHello
        (JNIEnv * env, jclass jclass1){

    LOGI("hello, from c");

    return env->NewStringUTF("hello, this is from c msg... ");
}

/*
 * Class:     top_keepempty_jnindkdemo_JNICallJMUtils
 * Method:    callJavaMethod
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_top_keepempty_jnindkdemo_JNICallJMUtils_callJavaMethod
        (JNIEnv * env, jclass jclass1, jint jint1){


    jclass jclass_sayHello = env->FindClass("top/keepempty/jnindkdemo/JNICallJMUtils");
    if(jclass_sayHello ==NULL){
        return;
    }

    jmethodID  jmethodID1 = env->GetMethodID(jclass_sayHello,"javaMethod","(Ljava/lang/String;)V");
    if(jmethodID1 == NULL){
        return;
    }
    // 找到对应的构造方法
    jmethodID jmethodID_construct = env->GetMethodID(jclass_sayHello,"<init>","()V");
    if(jmethodID_construct ==NULL){
        return;
    }

    // 创建一个新的对象
    jobject jobject1 = env->NewObject(jclass_sayHello,jmethodID_construct,NULL);
    if(jobject1 ==NULL){
        return;
    }

    // 修改Java中变量的值，先获取变量名
    jfieldID javaFile = env->GetFieldID(jclass_sayHello,"message1","Ljava/lang/String;");
    if(javaFile == NULL){
        return;
    }
    // 修改变量值
    jstring jstring1 = env->NewStringUTF("modify java filed");
    if(jstring1 ==NULL){
        return;
    }
    // 设置变量的值
    env->SetObjectField(jobject1,javaFile,jstring1);

    // 调用Java中的实例方法
    jstring jmsg = env->NewStringUTF("call java method");
    env->CallVoidMethod(jobject1,jmethodID1,jmsg);

    env->DeleteLocalRef(jclass_sayHello);
    env->DeleteLocalRef(jobject1);
    env->DeleteLocalRef(jmsg);
    env->DeleteLocalRef(jstring1);


}

/*
 * Class:     top_keepempty_jnindkdemo_JNICallJMUtils
 * Method:    callJavaStaticMethod
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_top_keepempty_jnindkdemo_JNICallJMUtils_callJavaStaticMethod
        (JNIEnv * env, jclass jclass1, jint jint1){


    jclass jclass_sayHello = env->FindClass("top/keepempty/jnindkdemo/JNICallJMUtils");
    if(jclass_sayHello ==NULL){
        return;
    }

    jmethodID jmethod_sayHello = env->GetStaticMethodID(jclass_sayHello,"staticMethod","(Ljava/lang/String;)V");
    if(jmethod_sayHello == NULL){
        return;
    }

    // 修改Java类中静态变量的值
    jfieldID  jfieldID1 = env->GetStaticFieldID(jclass_sayHello,"message","Ljava/lang/String;");
    if(jfieldID1 ==NULL){
        return;
    }
    // 创建新的值
    jstring  jstring1 = env->NewStringUTF("modify the static filed");
    if(jstring1 ==NULL){
        return;
    }
    // 将native创建的值设置Java中
    env->SetStaticObjectField(jclass_sayHello,jfieldID1,jstring1);

    jstring jstr = env->NewStringUTF("native call java static method");
    if(jstr == NULL){
        return;
    }
    env->CallStaticVoidMethod(jclass_sayHello,jmethod_sayHello,jstr);

    env->DeleteLocalRef(jclass_sayHello);
    env->DeleteLocalRef(jstr);
    env->DeleteLocalRef(jstring1);


}
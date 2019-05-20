#include <jni.h>
#include <string>
#include <android/log.h>
#include "include/JNIUtils.h"

static const char* classPathName="top/keepempty/jnindkdemo/JNIRegUtils";

jint twoSum(JNIEnv *env, jobject jobject1, jint a,jint b){
    LOGI("TWO SUM : %d", a+b);
    return a + b;
}

jstring getStr(JNIEnv *env,jclass jclass1){
    LOGI("From C++");
    return env->NewStringUTF("From C++");
}

void printlnStr(JNIEnv *env,jobject jobject1,jstring jstring1,jstring jstring2){
    LOGI("printlnStr");
}

const JNINativeMethod gMethods[] = {
        {"getString", "()Ljava/lang/String;", (void*)getStr},
        {"printlnString", "(Ljava/lang/String;Ljava/lang/String;)V", (void*)printlnStr},
        {"getTwoSum","(II)I",(void*)twoSum}
};


JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved){
    LOGI("Jni_OnLoad");
    JNIEnv* env = NULL;
    //从JavaVM获取JNIEnv，一般使用1.4的版本
    if(vm->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK)
        return -1;
    jclass clazz = env->FindClass(classPathName);
    if (!clazz){
        LOGI("Can't find %s",classPathName);
        return -1;
    }
    if(env->RegisterNatives(clazz, gMethods, sizeof(gMethods)/sizeof(gMethods[0])))
    {
        LOGI("register native method failed!\n");
        return -1;
    }
    return JNI_VERSION_1_4;
}



jint callJava(JNIEnv *env,jobject jobject1,jint a,jint b){
    jclass jc = env -> FindClass(classPathName);
    jmethodID  jmethodID1= env ->GetMethodID(jc,"methodid add","(II)I");
    jobject obj = env ->AllocObject(jc);
    jint result = env ->CallIntMethod(obj,jmethodID1,a,b);
    env ->DeleteLocalRef(obj);
    return result;

}
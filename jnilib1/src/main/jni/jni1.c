#include "com_example_jhindin_jni1_Jni1Wrapper.h"

#include <dlfcn.h>
#include <stdio.h>
#include <android/log.h>

char *(*pGetString)(void);

JNIEXPORT jstring JNICALL Java_com_example_jhindin_jni1_Jni1Wrapper_getStringP
  (JNIEnv *env, jclass clazz)
{
    return (*env)->NewStringUTF(env, pGetString ? pGetString() : "indirect JNI failed");
}

void __init(void)
{
    void *libHandler;

    __android_log_write(ANDROID_LOG_VERBOSE, "JNI1", "Init function called" );

    libHandler = dlopen("libjnilib2.so", RTLD_LAZY);
    if (!libHandler) {
        __android_log_write(ANDROID_LOG_VERBOSE, "JNI1", "dlopen libjnilib2.so failed" );
        return;
    } else {
        __android_log_write(ANDROID_LOG_VERBOSE, "JNI1", "dlopen libjinlib2.so passed" );
    }

    pGetString = (char *(*)(void)) dlsym(libHandler, "getString");

    if (!pGetString) {
        __android_log_write(ANDROID_LOG_VERBOSE, "JNI1", "getString resolution failed" );
        return;
    }

}
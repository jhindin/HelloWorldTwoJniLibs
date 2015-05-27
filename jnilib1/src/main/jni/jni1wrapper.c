#include "com_example_jhindin_jni1_Jni1Wrapper.h"

JNIEXPORT jstring JNICALL Java_com_example_jhindin_jni1_Jni1Wrapper_getString
  (JNIEnv *env, jclass clazz)
{
    return (*env)->NewStringUTF(env, "Hello from JNI");
}
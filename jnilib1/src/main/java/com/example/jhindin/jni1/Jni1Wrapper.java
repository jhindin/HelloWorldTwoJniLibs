package com.example.jhindin.jni1;

/**
 * Created by jhindin on 27/05/15.
 */
public class Jni1Wrapper {
    public static  native String getString();

    static {
        System.loadLibrary("jnilib1");
    }
}

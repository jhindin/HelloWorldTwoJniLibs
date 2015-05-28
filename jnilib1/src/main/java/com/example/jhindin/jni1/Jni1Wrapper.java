package com.example.jhindin.jni1;

/**
 * Created by jhindin on 27/05/15.
 */
public class Jni1Wrapper {
    public static  native String getStringP();
    static boolean loaded = false;
    public static String getString()
    {
        if (loaded)
            return getStringP();
        else
            return "JNI failed!";
    }



    static {

        try {
            System.out.println("Loading jnilib1");
            System.loadLibrary("jnilib1");
            loaded = true;
            System.out.println("Loaded jnilib1");
        } catch (Throwable ex) {
            ex.printStackTrace(System.out);
        }
    }
}

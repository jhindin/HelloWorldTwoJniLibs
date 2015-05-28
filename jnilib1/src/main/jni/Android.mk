LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := jnilib1
LOCAL_SRC_FILES := jni1.c

LOCAL_LDFLAGS := -Wl,-init,__init -llog



include $(BUILD_SHARED_LIBRARY)

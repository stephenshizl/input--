
LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE_PATH := $(LOCAL_PATH)/../../../../../../out
LOCAL_SHARED_LIBRARIES += libcutils libutils 
LOCAL_LDLIBS += -llog
LOCAL_SRC_FILES:= \/par    test_socket_client.c
LOCAL_MODULE_TAGS:= optional
LOCAL_MODULE := test_socket_client
include $(BUILD_EXECUTABLE)

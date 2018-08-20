# MY_CPP_LIST := $(wildcard $(LOCAL_PATH)/*.cpp)
# MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/src/*.cpp)
# MY_CPP_LIST += $(wildcard $(LOCAL_PATH)/src/xxx/*.cpp)
# 
# LOCAL_SRC_FILES := $(MY_CPP_LIST:$(LOCAL_PATH)/%=%)


LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

# All source files in the scanned directory
MY_FILES_PATH  :=  $(LOCAL_PATH) \
                   $(LOCAL_PATH)/../../Classes
MY_FILES_SUFFIX := %.cpp %.c %.cc
My_All_Files := $(foreach src_path,$(MY_FILES_PATH), $(shell find "$(src_path)" -type f) ) 
My_All_Files := $(My_All_Files:$(MY_CPP_PATH)/./%=$(MY_CPP_PATH)%)
MY_SRC_LIST  := $(filter $(MY_FILES_SUFFIX),$(My_All_Files)) 
MY_SRC_LIST  := $(MY_SRC_LIST:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES := $(MY_SRC_LIST)
#====================================
LOCAL_C_INCLUDES += $(LOCAL_PATH)/inc

LOCAL_LDLIBS    := -lm -llog
LOCAL_MODULE := libadas
include $(BUILD_SHARED_LIBRARY)

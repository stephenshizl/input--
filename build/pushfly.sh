
source ./env_entry.sh
adb  wait-for-device remount
adb push $DBG_OUT_RELEASE_PATH/$BOARD_VERSION/out /flysystem/lib/out
adb push $DBG_ANDROID_OUT_PATH/lidbg_servicer /flysystem/bin/lidbg_servicer
adb shell chmod 777 /flysystem/bin/lidbg_servicer
adb shell rm -r /system/lib/modules/out

#=======================================================================================
#	FileName    : 
#	Description : Make ALL
#       Date:         2012/02/03
#=======================================================================================
source ./env_entry.sh
#version choose
	case "$1" in
	v1) 	
	echo "EXTRA_CFLAGS += -DBOARD_V1" > $DBG_ROOT_PATH/build_cfg.mk
	echo "v1";;

	v2) 
	echo "EXTRA_CFLAGS += -DBOARD_V2" > $DBG_ROOT_PATH/build_cfg.mk
	echo "v2";;
	*)
	echo -e "\033[41;37m  ===============support table====================\033[0m "  
	echo "v1"
	echo "v2"
	echo "dbg"
	echo "rel"
	echo "  "
	echo -e "check your input: \033[41;37m  $1 $2  \033[0m"
	exit;;
	esac 

# dbg choose
	case "$2" in
	dbg) 
	echo "EXTRA_CFLAGS += -DFLY_DEBUG" >> $DBG_ROOT_PATH/build_cfg.mk
	echo "dbg";;

	rel) 
	echo "EXTRA_CFLAGS += -DFLY_RELEASE" >> $DBG_ROOT_PATH/build_cfg.mk
	echo "rel";;
	*)
	echo -e "\033[41;37m  ===============support table====================\033[0m "  
	echo "v1"
	echo "v2"
	echo "dbg"
	echo "rel"
	echo "  "
	echo -e "check your input: \033[41;37m  $1 $2  \033[0m"
	exit;;
	esac


#cd shell
./all_make.sh
#adb wait-for-device remount
#adb remount
#adb push ./out /system/lib/modules/out
#adb reboot

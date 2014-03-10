cd ../build
chmod 777 -R ./
source ./env_entry.sh
./build_cfg.sh $DBG_SOC $BUILD_VERSION 
./clean.sh
cd $DBG_HAL_PATH/$DBG_SOC
./build_all.sh

cd -
./build.sh

if [ "$1" = "" ]; then
	echo "exit"
else
	apt-get install expect

	cd $UPDATA_BIN_DIR
	pwd
	git reset --hard
	expect $DBG_TOOLS_PATH/pull
	cp -r $DBG_OUT_PATH  $UPDATA_BIN_DIR
	cp -r $DBG_OUT_PATH/*.so  $UPDATA_BIN_DIR/hw
	git add .
	git add -f ./
	git commit -am $1
	expect $DBG_TOOLS_PATH/push
	gitk &
fi


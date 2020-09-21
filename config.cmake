
SET(CMAKE_SYSTEM_NAME Linux)

#指定交叉编译器路径
SET(TOOLCHAIN_DIR "/opt/goke/ct_uClibc/4.6.1/usr")
set(TOOLCHAIN_HOST "${TOOLCHAIN_DIR}/bin/arm-goke-linux-uclibcgnueabi")

set(CMAKE_CXX_COMPILER ${TOOLCHAIN_HOST}-g++)
set(CMAKE_C_COMPILER   ${TOOLCHAIN_HOST}-gcc)

SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
 ${TOOLCHAIN_DIR}/include
 ${TOOLCHAIN_DIR}/lib )

#从来不在指定目录下查找工具程序
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#只在指定目录下查找库文件
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#只在指定目录下查找头文件
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#add_definitions(-D IOT_ATOMIC_USE_PORT=1)
#set(IOT_NETWORK_USE_OPENSSL 1)
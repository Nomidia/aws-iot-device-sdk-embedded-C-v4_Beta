
# 参考 https://cmake.org/cmake/help/v3.22/manual/cmake-toolchains.7.html#cross-compiling-for-linux
SET(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# 指定交叉编译器路径
SET(TOOLCHAIN_DIR "/opt/sigmaStar/arm-buildroot-linux-uclibcgnueabihf-4.9.4-uclibc-1.0.31/")
set(TOOLCHAIN_HOST "${TOOLCHAIN_DIR}/bin/arm-buildroot-linux-uclibcgnueabihf")

set(CMAKE_CXX_COMPILER ${TOOLCHAIN_HOST}-g++)
set(CMAKE_C_COMPILER   ${TOOLCHAIN_HOST}-gcc)

SET(CMAKE_FIND_ROOT_PATH  ${TOOLCHAIN_DIR}
 ${TOOLCHAIN_DIR}/include
 ${TOOLCHAIN_DIR}/lib )

# 从来不在指定目录下查找工具程序
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# 只在指定目录下查找库文件
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
# 只在指定目录下查找头文件
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


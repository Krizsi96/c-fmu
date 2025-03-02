#!/bin/bash

FMU_NAME="SimpleFMU_CoSim.fmu"
BUILD_DIR_WIN="win-builddir"
BUILD_DIR_LINUX="linux-builddir"
BIN_LINUX="binaries/linux64"
BIN_WINDOWS="binaries/win64"

meson setup "$BUILD_DIR_LINUX" --wipe
meson setup "$BUILD_DIR_WIN" --cross-file windows-x86_64-cross.txt --wipe

meson compile -C $BUILD_DIR_LINUX
meson compile -C $BUILD_DIR_WIN

mkdir -p "$BIN_LINUX"
mkdir -p "$BIN_WINDOWS"

cp "$BUILD_DIR_LINUX/libsimple_fmu.so" "$BIN_LINUX/simple_fmu.so"
cp "$BUILD_DIR_WIN/libsimple_fmu.dll" "$BIN_WINDOWS/simple_fmu.dll"

zip -r $FMU_NAME modelDescription.xml binaries/
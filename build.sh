#!/bin/bash
export ARCH=arm64
export CROSS_COMPILE=aarch64-linux-gnu-
make -j8 ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu-
make dtbs

#Run Kernel+Busybox
#qemu-system-arm -M vexpress-a9 -smp 4 -m 1024M -kernel arch/arm/boot/zImage -append "rdinit=/linuxrc console=ttyAMA0 loglevel=8" -dtb arch/arm/boot/dts/vexpress-v2p-ca9.dtb -nographic

qemu-system-aarch64 -machine virt -cpu cortex-a57 -machine type=virt -smp 2 -m 2048 -kernel arch/arm64/boot/Image --append "rdinit=/linuxrc console=ttyAMA0 loglevel=8" -nographic



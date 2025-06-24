#!/bin/sh

qemu-system-i386 \
    -m 64 \
    -kernel ./linux-3.7.1/arch/x86/boot/bzImage \
    -nographic \
    -append "console=ttyS0" \
    -monitor /dev/null \
    -initrd initramfs.cpio

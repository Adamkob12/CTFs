#!/bin/sh

echo "~~~"
echo "Starting kernel in debug, connect from gdb usin target remote :1234"
echo "Run gdb on the vmlinux file"
echo "~~~"

qemu-system-i386 \
    -m 64 \
    -kernel ./linux-3.11.4/arch/x86/boot/bzImage \
    -nographic \
    -append "console=ttyS0 kdb" \
    -monitor /dev/null \
    -initrd initramfs.cpio -s -S

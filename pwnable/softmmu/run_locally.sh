#! /bin/bash

qemu-system-i386 \
    -m 64 -kernel p/bzImage -initrd p/ramdisk.img \
    -append 'root=/dev/ram0 rw console=ttyS0 -rdinit=/sbin/init' \
    -serial pty \
    -nographic # -serial mon:stdio \

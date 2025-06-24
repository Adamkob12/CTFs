FROM ubuntu:16.04

RUN apt-get update && apt-get install -y \
    build-essential libncurses5-dev make git wget xz-utils bison flex libssl-dev bc \
    gdb qemu-system-i386 gcc-5 exuberant-ctags gcc-4.9

WORKDIR /kernel-build

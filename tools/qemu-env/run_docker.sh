#! /bin/bash

# We need an Ubuntu 16 machine to compile the kernel

sudo docker run -v .:/kernel-build -it ubuntu-kernel-build /bin/bash

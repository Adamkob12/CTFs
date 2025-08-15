#!/bin/bash

echo "base64 /kcrc.ko" |
    socat -u - "/dev/pts/5",raw,echo=0

socat -u "/dev/pts/5",raw,echo=0 - > kcrc.ko.b64

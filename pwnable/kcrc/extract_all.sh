#!/bin/sh

sshpass -p $(cat ../syscall/flag) scp -P 2222 kcrc@pwnable.kr:~/* ./extract/

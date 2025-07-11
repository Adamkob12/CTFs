#!/bin/sh

sshpass -p $(cat ../syscall/flag) ssh exynos@pwnable.kr -p2222

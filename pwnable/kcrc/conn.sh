#!/bin/sh

sshpass -p $(cat ../syscall/flag) ssh kcrc@pwnable.kr -p2222

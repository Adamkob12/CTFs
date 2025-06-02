#!/bin/sh

sshpass -p $(cat ../syscall/flag) ssh towelroot@pwnable.kr -p2222

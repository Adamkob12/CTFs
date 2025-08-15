#!/bin/sh

sshpass -p $(cat ../syscall/flag) ssh softmmu@pwnable.kr -p2222

#!/bin/sh

sshpass -p $(cat ../cmd1/flag) ssh cmd2@pwnable.kr -p2222

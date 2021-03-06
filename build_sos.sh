#!/bin/bash

help() {
    echo "usage: $0 "
    echo -e "\t\t[--debug] CFLAGS+=-DDEBUG"
    echo -e "\t\t[--help]"
}

#default build config
cflags=""

while [ ! -z "$1" ]; do
    case "$1" in
        "--debug")
            cflag="-DDEBUG"
            shift
            ;;
        "--help")
            help
            shift
            exit 0
            ;;
        *)
            echo "illegal param $1"
            shift
            help
            exit 1
            ;;
    esac
done

echo "cflags=$cflag"
CPU_NUM=$(cat /proc/cpuinfo | grep processor | wc -l)
make cflags=$cflag -j ${CPU_NUM}

if [ $? -eq 0 ]; then
    echo -e "\033[32mbuild ok!\033[0"
else
    echo -e "\033[31mbuild failed!\033[0"
fi


#!/usr/bin/env bash
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)


CURR_DIR=$(pwd)
CMAKE_DIR="/home/zombiesalad/Desktop/code/TheRayTracerChallenge"
cd "${CMAKE_DIR}/build/"



if [ $? -ne 0 ]; then
    echo "${RED}ERROR cding into build dir"
    echo "EXITING SCRIPT${RESET}"
    exit 1
fi
pwd

make clean

read -p "${GREEN}About to NUKE $(pwd). ARE YOU SURE? " -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]
then
    rm -v -r "${CMAKE_DIR}/build/" 
fi
mkdir "${CMAKE_DIR}/build"


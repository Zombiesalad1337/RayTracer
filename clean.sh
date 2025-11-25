#!/usr/bin/env bash
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
RESET=$(tput sgr0)

CMAKE_DIR="$(pwd)"

cd "${CMAKE_DIR}/build/" || {
    echo "${RED}ERROR cding into build dir"
    echo "EXITING SCRIPT${RESET}"
    exit 1
}

pwd

make clean

read -p "${GREEN}About to NUKE $(pwd). ARE YOU SURE? " -n 1 -r
echo ""
if [[ $REPLY =~ ^[Yy]$ ]]; then
    rm -v -r "${CMAKE_DIR}/build/"
fi

mkdir "${CMAKE_DIR}/build"

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

cmake "${CMAKE_DIR}"
make -j4 --directory "${CMAKE_DIR}/build/"
"${CMAKE_DIR}/bin/main"

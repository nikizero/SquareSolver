#!/bin/bash

make clean
clear
make -f Makefile all
echo -e "\n Chose the mod: '--start' or '--test'"
read mod
./mipt $mod

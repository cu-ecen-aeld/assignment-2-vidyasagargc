#!/bin/bash

writefile=$1
writestr=$2

mkdir -p $writefile
touch $writefile/$writestr

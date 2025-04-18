#!/bin/bash
set -x
filesdir=$1
searchstr=$2

if [ -z ${filesdir} ]; then
	return 1
elif [ -z ${searchstr} ]; then
	return 1
fi

files=$(find ${filesdir} -iname ${searchstr})
files_count=$(grep -rR AELD_IS_FUN /tmp/aeld-data|wc -l)

echo "no. of files found ${files_count}"
echo "The number of files are ${files_count} and the number of matching lines are ${files_count}"

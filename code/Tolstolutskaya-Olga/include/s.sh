#!/bin/bash
path=$1

find $path -type f | while read FILENAME; do
	cat "$FILENAME" | sed 's/.$//' > tmp
	cat tmp > "$FILENAME"
	rm tmp
	echo "$FILENAME"
done
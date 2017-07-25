#!/bin/sh

cd 45/ ;

i=0;

for file in $(ls -rt);
do
	mv "${file}" "${i}.jpg";
	i=$(($i+1));
done


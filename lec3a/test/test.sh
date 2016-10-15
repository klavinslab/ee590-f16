#!/bin/sh

for test in *.x
do
  printf $test
  if ./$test; then
    printf "\e[32m ... ok\n\e[39m"
  else
    printf "\e[31m ... error\n\e[39m"
  fi
done

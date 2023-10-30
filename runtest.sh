#!/bin/sh

for testfile in test/printer/good*.bminor
do
	if ./bminor --print $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

# for testfile in test/printer/bad*.bminor
# do
# 	if ./bminor --print $testfile > $testfile.out
# 	then
# 		echo "$testfile success (INCORRECT)"
# 	else
# 		echo "$testfile failure (as expected)"
# 	fi
# done
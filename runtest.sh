#!/bin/sh

for testfile in test/codegen/good*.bminor
do
	if ./bminor --codegen $testfile > $testfile.out
	then
		echo "$testfile success (as expected)"
	else
		echo "$testfile failure (INCORRECT)"
	fi
done

# for testfile in test/typechecker/bad*.bminor
# do
# 	if ./bminor --typecheck $testfile > $testfile.out
# 	then
# 		echo "$testfile success (INCORRECT)"
# 	else
# 		echo "$testfile failure (as expected)"
# 	fi
# done
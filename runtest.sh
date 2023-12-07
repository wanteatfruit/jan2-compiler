#!/bin/sh
for testfile in ./test/codegen/good*.bminor
do
	if ./bminor --codegen $testfile $testfile.s >> $testfile.out
	then
		gcc -g $testfile.s library.c -o $testfile.exe
		echo -e "----------------EXECUTION OUTPUT----------------" > $testfile.out
		./$testfile.exe >> $testfile.out
		echo -e "\n----------------MAIN OUTPUT----------------\n$?" >> $testfile.out
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
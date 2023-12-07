#!/bin/sh

for testfile in test/codegen/good*.bminor
do
	output_file="${testfile}.s"
	if ./bminor --codegen $testfile $output_file > $testfile.out
	then
		echo "$testfile codegen success (as expected)"
	else
		echo "$testfile codegen failure (INCORRECT)"
	fi
done

for asmfile in test/codegen/good*.bminor.s
do
	if gcc -g ${asmfile} library.c -o ${asmfile%%.*}_bin
	then
		echo "$asmfile gcc success (as expected)"
	else
		echo "$asmfile gcc failure (INCORRECT)"
	fi
done

for binfile in test/codegen/good*_bin
do
	if ./${binfile} > ${binfile}.out
	then
		echo "$binfile run success (as expected), output = $?"
	else
		echo "$binfile run failure (INCORRECT)"
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
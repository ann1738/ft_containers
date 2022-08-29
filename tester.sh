#!/bin/bash

# Colors
Black='\033[0;30m'        # Black
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White

TEST_DIR="tests/"

CXX_FLAGS="-Wall -Wextra -Werror -std=c++98" 
TEST_FLAG="-D TESTING=1"

EXEC_NAME=test

FT_LOG_DIR=ft_logs
STD_LOG_DIR=std_logs
DIFF_DIR=diffs

PERFORMANCE_DIR="tests/performance"
PERFORMANCE_EXEC="performance"

ARGS_LENGTH=$#

function checkInput()
{
	if [[ $1 == "vector" ]] || [[ $1 == "map" ]] || [[ $1 == "stack" ]] || [[ $1 == "set" ]]; then
		return 0
	fi
	return 1
}

#######################################
# Colors and prints string
# Arguments:
#   $1: color
#	$2: string
#######################################
function	colorPrint()
{
	printf "$1$2\033[0m\n"
}

function ifExist() 
{
	if [[ -d $1 ]]; then
		return 1
	else
		return 0
	fi
}

#######################################
# Enables performance testing
# Arguments:
#   $1: first user argument
#######################################
function checkPerformanceTest()
{
	if [[ $1 == "performance" ]]; then
		TEST_FILES=($(find $PERFORMANCE_DIR | grep \.cpp | sort))
		length=${#TEST_FILES[@]}

		for (( i=0; i < ${length}; i++ ))  
		do
			temp=${TEST_FILES[$i]##*/}		#removes the path
			temp=${temp%%.*}				#removes the extension 
			temp=${temp%_*}					#removes "_perf"

			colorPrint $Purple "************* Testing ft::$temp's performance *************"
			compileTestFileWithFt ${TEST_FILES[$i]} $PERFORMANCE_EXEC
			./$PERFORMANCE_EXEC
			echo
			colorPrint $Yellow "************* Testing std::$temp's performance *************"
			compileTestFileWithStd ${TEST_FILES[$i]} $PERFORMANCE_EXEC
			./$PERFORMANCE_EXEC
			echo
			echo
			echo
		done
		colorPrint $Purple "\t************* ************* *************"
		rm -f $PERFORMANCE_EXEC
		exit 0
	fi
}

#######################################
# Creates directories for logs and diff
#######################################
function createLogDiffDirs()
{
	ifExist $FT_LOG_DIR
	if [[ $? -eq 0 ]]; then mkdir $FT_LOG_DIR; fi

	ifExist $STD_LOG_DIR
	if [[ $? -eq 0 ]]; then mkdir $STD_LOG_DIR; fi

	ifExist $DIFF_DIR
	if [[ $? -eq 0 ]]; then mkdir $DIFF_DIR; fi
}

function assessAndReportIfTestPassed()
{
	temp=${1##*/}		#removes the path
	temp=${temp%%.*}	#removes the extension 
	temp=${temp%_*}		#removes the _vector/_set...
	if [[ $2 == "0" ]] ; then exit_code=✅; else exit_code=❌; fi
	if [[ ! -s $1 ]]; then
		printf "%-20s: COMPILE: $exit_code | OUTPUT: ✅\n" "$temp.cpp"
		rm -f $1
	else
		printf "%-20s: COMPILE: $exit_code | OUTPUT: ❌\n" "$temp.cpp"
		# printf "Returned: %-20s\n" "$(cat $1 | grep "<" | cut -d' ' -f2-)"
		# printf "Expected: %-20s\n" "$(cat $1 | grep ">" | cut -d' ' -f2-)"
	fi
}

function compileTestFileWithFt()
{
	g++ ${CXX_FLAGS} $1 -o $2 2>/dev/null
}

function compileTestFileWithStd()
{
	g++ ${CXX_FLAGS} ${TEST_FLAG} $1 -o $2 2>/dev/null
}

#######################################
# Runs test files in a given directory
# Arguments:
#   $1: directory of the test files
#######################################
function runTestsInDir()
{
	TEST_FILES=($(find $1 | grep \.cpp | sort))
	length=${#TEST_FILES[@]}

	container_name="$(basename $(dirname ${TEST_FILES[$i]}))"

	for (( i=0; i < ${length}; i++ ))  
	do
		file_name="$(basename ${TEST_FILES[$i]} .cpp)"
		compileTestFileWithFt ${TEST_FILES[$i]} $EXEC_NAME 
		ft_exit_code=$?
		./$EXEC_NAME > "${FT_LOG_DIR}/${file_name}.${container_name}.log"

		compileTestFileWithStd ${TEST_FILES[$i]} $EXEC_NAME
		./$EXEC_NAME > "${STD_LOG_DIR}/${file_name}.${container_name}.log"
		
		diff "${FT_LOG_DIR}/${file_name}.${container_name}.log" "${STD_LOG_DIR}/${file_name}.${container_name}.log" > "${DIFF_DIR}/${file_name}_${container_name}.diff"

		assessAndReportIfTestPassed "${DIFF_DIR}/${file_name}_${container_name}.diff" $ft_exit_code
	done
	rm -f $EXEC_NAME
}

#####	START OF SCRIPT		#####

# check number of arguments
if [ $ARGS_LENGTH == 0 ]; then 
	colorPrint $Red "Invalid Input"
	colorPrint $Purple "./<script> <container1> <container2> ...";
	exit ;
fi

# check if the user requested a performance test
if [ $ARGS_LENGTH == 1 ]; then 
	checkPerformanceTest $1
fi

# create directories for logs and diffs
createLogDiffDirs

# run test files
for i; do
	if ! $(checkInput $i) ; then colorPrint $Red  "$i: invalid input"; exit ; fi
	colorPrint $Cyan "*****************************************************************************************************"
	colorPrint $Cyan "*                                           Testing $i:\t                                    *"
	colorPrint $Cyan "*****************************************************************************************************"
	runTestsInDir "$TEST_DIR/$i"
done

#####	END OF SCRIPT		#####
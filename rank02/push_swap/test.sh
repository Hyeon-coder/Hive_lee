#!/bin/bash

# push_swap 실행 파일 경로 (필요에 따라 수정)
PUSH_SWAP=./push_swap
VALGRIND="valgrind --suppressions=macos.supp --leak-check=full --show-leak-kinds=all"

# OS 감지 (Mac vs Linux)
if [[ "$OSTYPE" == "darwin"* ]]; then
    ECHO_CMD="printf"
    BLUE="\033[34m"
    RED="\033[31m"
    RESET="\033[0m"
else
    ECHO_CMD="echo -e"
    BLUE="\e[34m"
    RED="\e[31m"
    RESET="\e[0m"
fi

$ECHO_CMD "${BLUE}===== NORMAL EXECUTION TESTS =====${RESET}"

$ECHO_CMD "${BLUE}Test 1: Normal execution (unsorted input)${RESET}"
$VALGRIND $PUSH_SWAP "9 3 -7 -3 10"

$ECHO_CMD "${BLUE}Test 2: Normal execution (already sorted)${RESET}"
$VALGRIND $PUSH_SWAP "1 2 3 4 5"

$ECHO_CMD "${BLUE}Test 3: Normal execution (Quoted & Unquoted numbers)${RESET}"
$VALGRIND $PUSH_SWAP "1" 2 "3"

$ECHO_CMD "${BLUE}Test 4: Normal execution (100 random numbers)${RESET}"
ARG=$(seq -100000 100000 | sort -R | head -n 100 | tr '\n' ' ')
$VALGRIND $PUSH_SWAP $ARG | wc -l

$ECHO_CMD "${BLUE}Test 5: Normal execution (500 random numbers)${RESET}"
ARG=$(seq -100000 100000 | sort -R | head -n 500 | tr '\n' ' ')
$VALGRIND $PUSH_SWAP $ARG | wc -l

$ECHO_CMD "${BLUE}Test 6: Normal execution (1000 already sorted numbers)${RESET}"
ARG=$(seq -500 499 | tr '\n' ' ')
$VALGRIND $PUSH_SWAP $ARG | wc -l

$ECHO_CMD "${RED}===== ERROR TESTS =====${RESET}"

$ECHO_CMD "${RED}Test 7: Error (Non-numeric input)${RESET}"
$VALGRIND $PUSH_SWAP "1 2 a" 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 8: Error (Duplicate numbers)${RESET}"
$VALGRIND $PUSH_SWAP "1 2 3 3" 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 9: Error (Mixed quoted & unquoted input)${RESET}"
$VALGRIND $PUSH_SWAP "1 2" a 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 10: Error (Quoted & Unquoted mix with non-numeric)${RESET}"
$VALGRIND $PUSH_SWAP "1" 2 "3" 4 a 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 11: Error (Out-of-range numbers)${RESET}"
$VALGRIND $PUSH_SWAP "2147483648 -2147483649" 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 12: Error (Empty input)${RESET}"
$VALGRIND $PUSH_SWAP "" 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 13: Error (Only spaces as input)${RESET}"
$VALGRIND $PUSH_SWAP "   " 2>/dev/null || echo "Error"

$ECHO_CMD "${RED}Test 14: Error (Only signs, no numbers)${RESET}"
$VALGRIND $PUSH_SWAP "- +" 2>/dev/null || echo "Error"


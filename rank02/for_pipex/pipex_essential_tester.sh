#!/bin/bash

source test.sh
source utils.sh

set_flags "$@"
trap 'kill 0;' SIGINT

PIPEX_DIR=$(pwd)
TIMEOUT=7

rm -rf outfiles
mkdir -p outfiles infiles
echo -n > last_err_log.txt

# Create infile examples
echo -e "hello\nworld\nthis is a test\n42Helsinki" > infiles/basic.txt
touch infiles/empty.txt
echo "temp" > outfiles/outfile_existing.txt
chmod 000 infiles/no_permission_infile.txt 2>/dev/null || touch infiles/no_permission_infile.txt && chmod 000 infiles/no_permission_infile.txt
touch outfiles/no_permission_outfile.txt && chmod 000 outfiles/no_permission_outfile.txt

tester_setup

print_header "MANDATORY TESTS - PIPEX ONLY"

# ✅ Normal operation
test "infiles/basic.txt" "cat" "grep hello" "outfiles/out1"
test "infiles/basic.txt" "ls -la" "wc -l" "outfiles/out2"
test "infiles/empty.txt" "cat" "cat" "outfiles/out3"
test "infiles/basic.txt" "grep test" "wc -c" "outfiles/out4"

# ❌ Invalid commands
test "infiles/basic.txt" "nonexistingcmd" "cat" "outfiles/out5"
test "infiles/basic.txt" "cat" "nonexistingcmd" "outfiles/out6"

# ❌ Invalid infile / outfile
test "nonexistingfile.txt" "cat" "cat" "outfiles/out7"
test "infiles/no_permission_infile.txt" "cat" "cat" "outfiles/out8"
test "infiles/basic.txt" "cat" "cat" "outfiles/no_permission_outfile.txt"

# 🧪 Edge cases for ft_split/cmd parsing
test "infiles/basic.txt" "" "cat" "outfiles/out9"
test "infiles/basic.txt" "cat" "" "outfiles/out10"
test "infiles/basic.txt" " " "cat" "outfiles/out11"
test "infiles/basic.txt" "cat" " " "outfiles/out12"

# ✔️ Mixed logic
test "infiles/basic.txt" "echo hello" "grep h" "outfiles/out13"
test "infiles/basic.txt" "grep 42" "wc -l" "outfiles/out14"
test "infiles/basic.txt" "cat -e" "cat -e" "outfiles/out15"

# ✔️ Overwrite existing file
test "infiles/basic.txt" "cat" "cat" "outfiles/outfile_existing.txt"

if (( ${HIDE_LOG} == 0 )); then print_err_log; fi

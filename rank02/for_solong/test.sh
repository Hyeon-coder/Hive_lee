#!/bin/bash

# Show usage info if no mode is provided
if [ "$1" = "" ]; then
    echo "Usage: ./test_maps.sh [mode]"
    echo "Available modes:"
    echo "  run    - Run the game normally"
    echo "  leak  - Run with full valgrind leak check output"
    exit 1
fi

MODE="$1"

# ANSI colors
COLOR_BLUE="\033[1;34m"
COLOR_RESET="\033[0m"

# Function to run tests on each .ber map file
run_maps() {
    echo -e "\n$2"
    for file in $1/*.ber; do
        echo -e "${COLOR_BLUE}== $file ==${COLOR_RESET}"
        case "$MODE" in
            run)
                ./so_long "$file"
                ;;
            leak)
                valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=mlx.supp ./so_long "$file"
                ;;
        esac
        echo ""
    done
}

# Run the tests on both valid and invalid maps
run_maps "maps_valid" "VALID MAPS"
run_maps "maps_err"   "INVALID MAPS"

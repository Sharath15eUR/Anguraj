#!/bin/bash

# Log file for errors
ERROR_LOG="errors.log"

# Recursive function to search for files containing a keyword
search_recursive() {
    local dir="$1"
    local keyword="$2"
    
    for file in "$dir"/*; do
        if [ -d "$file" ]; then
            search_recursive "$file" "$keyword"  # Recursive call
        elif [ -f "$file" ]; then
            grep -l "$keyword" "$file" 2>/dev/null && echo "Found in: $file"
        fi
    done
}

# Display help menu using Here Document
show_help() {
    cat << EOF
Usage: $0 [OPTIONS]

Options:
  -d <directory>   Search recursively in a directory for a keyword.
  -k <keyword>     Keyword to search for.
  -f <file>        Search for a keyword in a specific file.
  --help           Display this help menu.

Example:
  $0 -d logs -k error
  $0 -f script.sh -k TODO
EOF
}

# Validate input using regular expressions
validate_input() {
    local keyword="$1"
    if [[ -z "$keyword" || ! "$keyword" =~ ^[a-zA-Z0-9_-]+$ ]]; then
        echo "Error: Invalid or empty keyword" | tee -a "$ERROR_LOG"
        exit 1
    fi
}

# Command-line argument handling
while getopts ":d:k:f:-:" opt; do
    case "$opt" in
        d) directory="$OPTARG" ;;
        k) keyword="$OPTARG" ;;
        f) file="$OPTARG" ;;
        -) case "$OPTARG" in
               help) show_help; exit 0 ;;
               *) echo "Unknown option: --$OPTARG" | tee -a "$ERROR_LOG"; exit 1 ;;
           esac ;;
        ?) echo "Invalid option: -$OPTARG" | tee -a "$ERROR_LOG"; exit 1 ;;
    esac
done

# Ensure at least one required option is set
if [[ -z "$directory" && -z "$file" ]]; then
    echo "Error: Either -d or -f must be provided." | tee -a "$ERROR_LOG"
    exit 1
fi

# Validate keyword input
validate_input "$keyword"

# Search in a directory recursively
if [[ -n "$directory" ]]; then
    if [[ -d "$directory" ]]; then
        search_recursive "$directory" "$keyword"
    else
        echo "Error: Directory '$directory' not found" | tee -a "$ERROR_LOG"
        exit 1
    fi
fi

# Search in a specific file using Here String
if [[ -n "$file" ]]; then
    if [[ -f "$file" ]]; then
        grep "$keyword" <<< "$(cat "$file")" && echo "Keyword found in $file"
    else
        echo "Error: File '$file' not found" | tee -a "$ERROR_LOG"
        exit 1
    fi
fi

# Display execution result
exit_status=$?
echo "Script executed with exit status: $exit_status"

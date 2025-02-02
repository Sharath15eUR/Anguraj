#!/bin/bash

# Check if the input file is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi

# Input file
input_file="$1"

# Ensure input file exists
if [ ! -e "$input_file" ]; then
    echo "Error: Input file '$input_file' does not exist."
    exit 1
fi

# Output file
output_file="output.txt"

# Clear the output file if it exists, or create a new one
> "$output_file"

#filter the lines with search words
grep -w "frame.time\|wlan.fc.type\|wlan.fc.subtype" $input_file > $output_file

#to have feedback of number of lines found
line_count= grep -c "frame.time\|wlan.fc.type\|wlan.fc.subtype" $input_file 

echo "$line_count lines found"
echo "Output saved to $output_file"


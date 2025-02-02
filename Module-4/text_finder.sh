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

# Filter the lines with search words and save to output file
grep -w "frame.time\|wlan.fc.type\|wlan.fc.subtype" "$input_file" > "$output_file"

# Count the number of matching lines
line_count=$(grep -c -w "frame.time\|wlan.fc.type\|wlan.fc.subtype" "$input_file")

# Count the total number of lines in the input file
total_lines=$(wc -l < "$input_file")

# Print results to the terminal
echo "$line_count lines found"
echo "Output saved to $output_file"
echo "Total number of lines in input file: $total_lines"

# Save results to output file
{
    echo "Total number of lines in input file: $total_lines"
    echo "$line_count lines matched"
    echo "Output saved to $output_file"
} >> "$output_file"


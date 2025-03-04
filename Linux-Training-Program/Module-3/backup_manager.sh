#!/bin/bash

# Check if all three arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <source_directory> <backup_directory> <file_extension>"
    exit 1
fi

# Assign command-line arguments to variables
SOURCE_DIR="$1"
BACKUP_DIR="$2"
FILE_EXT="$3"

# Ensure source directory exists
if [ ! -d "$SOURCE_DIR" ]; then
    echo "Error: Source directory '$SOURCE_DIR' does not exist."
    exit 1
fi

# Create backup directory if it does not exist
if [ ! -d "$BACKUP_DIR" ]; then
    mkdir -p "$BACKUP_DIR" || { echo "Error: Failed to create backup directory."; exit 1; }
fi

# Use globbing to find matching files and store them in an array
shopt -s nullglob  # Prevent errors if no matching files are found
FILES=("$SOURCE_DIR"/*"$FILE_EXT")

# Check if there are any matching files
if [ "${#FILES[@]}" -eq 0 ]; then
    echo "No files with extension '$FILE_EXT' found in '$SOURCE_DIR'."
    exit 0
fi

# Export an environment variable to track the number of backed-up files
export BACKUP_COUNT=0
TOTAL_SIZE=0

# Display the files to be backed up
echo "Files to be backed up:"
for FILE in "${FILES[@]}"; do
    FILE_NAME=$(basename "$FILE")
    FILE_SIZE=$(stat -c%s "$FILE")
    echo "  $FILE_NAME - $FILE_SIZE bytes"
done

# Perform the backup
for FILE in "${FILES[@]}"; do
    FILE_NAME=$(basename "$FILE")
    DEST_FILE="$BACKUP_DIR/$FILE_NAME"

    # Check if file exists in the backup directory and compare timestamps
    if [ -e "$DEST_FILE" ]; then
        if [ "$FILE" -nt "$DEST_FILE" ]; then
            cp "$FILE" "$DEST_FILE"
            echo "Updated: $FILE_NAME"
        else
            echo "Skipped (up-to-date): $FILE_NAME"
            continue
        fi
    else
        cp "$FILE" "$DEST_FILE"
        echo "Copied: $FILE_NAME"
    fi

    # Update counters
    BACKUP_COUNT=$((BACKUP_COUNT + 1))
    TOTAL_SIZE=$((TOTAL_SIZE + $(stat -c%s "$FILE")))
done

# Save report
REPORT_FILE="$BACKUP_DIR/backup_report.log"
{
    echo "Backup Summary"
    echo "=============="
    echo "Total files backed up: $BACKUP_COUNT"
    echo "Total size of files: $TOTAL_SIZE bytes"
    echo "Backup directory: $BACKUP_DIR"
    echo "Backup completed at: $(date)"
} > "$REPORT_FILE"

echo "Backup completed. Report saved to: $REPORT_FILE"


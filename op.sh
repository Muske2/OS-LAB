#!/bin/bash

echo "Enter the folder path to change the file extensions: "
read folder_path

echo "Enter the current file extension to be replaced (e.g. txt): "
read old_ext

echo "Enter the new file extension (e.g. py): "
read new_ext

# Loop through all files in the folder with the old extension and rename them with the new extension
for file in "$folder_path"/*."$old_ext"; do
  if [ -f "$file" ]; then
    mv "$file" "${file%.$old_ext}.$new_ext"
    echo "File $file renamed to ${file%.$old_ext}.$new_ext"
  fi
done

#!/bin/bash

echo "Enter folder name:"
read folder_name

c_files_folder="${folder_name}/c_files"
py_files_folder="${folder_name}/py_files"

# Create c_files and py_files directories if they don't exist
mkdir -p "$c_files_folder"
mkdir -p "$py_files_folder"

# Move all .c files to c_files folder
for file in "$folder_name"/*.c; do
  if [ -f "$file" ]; then
    mv "$file" "$c_files_folder"
    echo "Moved $file to $c_files_folder"
  fi
done

# Move all .py files to py_files folder
for file in "$folder_name"/*.py; do
  if [ -f "$file" ]; then
    mv "$file" "$py_files_folder"
    echo "Moved $file to $py_files_folder"
  fi
done

#!/bin/bash

# Check for git repo
if ! git rev-parse --git-dir > /dev/null 2>&1; then
  echo "This is not a git repository."
  exit 1
fi

# Gather changed files
files=$(git status --porcelain | awk '{print $2}')
if [ -z "$files" ]; then
  echo "No changes to commit."
  exit 0
fi

# Convert to array
mapfile -t file_array <<< "$files"
selected_files=()

while true; do
  echo
  echo "Select a file to add:"
  for i in "${!file_array[@]}"; do
    printf "%2d) %s\n" "$((i+1))" "${file_array[i]}"
  done
  echo " a) Add all remaining"
  echo " d) Done selecting files"
  echo " q) Quit"

  read -p "Choice: " choice

  if [[ "$choice" == "q" ]]; then
    echo "Aborting."
    exit 0

  elif [[ "$choice" == "a" ]]; then
    for file in "${file_array[@]}"; do
      selected_files+=("$file")
    done
    break

  elif [[ "$choice" == "d" ]]; then
    break

  elif [[ "$choice" =~ ^[0-9]+$ ]] && (( choice >= 1 && choice <= ${#file_array[@]} )); then
    selected="${file_array[choice-1]}"
    selected_files+=("$selected")
    unset 'file_array[choice-1]'
    file_array=("${file_array[@]}")  # Reindex
    echo "Added: $selected"

  else
    echo "Invalid choice. Try again."
  fi
done

if [ ${#selected_files[@]} -eq 0 ]; then
  echo "No files selected to add. Exiting."
  exit 0
fi

# Add selected files
git add "${selected_files[@]}"

# Commit
read -p "Enter commit message: " msg
if [ -z "$msg" ]; then
  echo "Commit message cannot be empty."
  exit 1
fi

git commit -m "$msg"
git push

echo "Commit and push completed successfully."


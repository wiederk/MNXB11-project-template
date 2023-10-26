#!/bin/bash

#  Specify the input and output file names
input_file="smhi-opendata_1_53430_20231007_155558_Lund.csv"
output_file="processed_data.csv"
temp_file="temp_file.csv"
# Check if the input file exists
if [ ! -f "$input_file" ]; then
    echo "Input file not found: $input_file"
    exit 1
fi

# Use tail to skip the first 3 lines and save the rest to the output file
tail -n +14 "$input_file" > "$temp_file"


# Function to process and clean a line of data
process_data_line() {
  line="$1"
  # Remove leading/trailing spaces and extra semicolons
  line="$(echo "$line" | sed -e 's/^[[:space:]]*//;s/[[:space:]]*$//;s/;;/;/g')"

  # Check if the line contains valid data (skip headers and empty lines)
  if [[ ! "$line" =~ ^[0-9]{4}-[0-9]{2}-[0-9]{2}.* ]]; then
    return
  fi

  # Extract the necessary fields (Date, Time, and Temperature)
  date="$(echo "$line" | cut -d ';' -f 1)"
  time="$(echo "$line" | cut -d ';' -f 2)"
  temperature="$(echo "$line" | cut -d ';' -f 3)"

  # Print the processed data in CSV format
  echo "$date,$time,$temperature"
}
# Process the input file and save the results to the output file
cat "$temp_file" | while IFS= read -r line; do
  process_data_line "$line"
done > "$output_file"


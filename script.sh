#!/bin/bash

# Check if the required arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <client_source> <server_source>"
    exit 1
fi

# Extracting file names without extensions
client_source="${1%.*}"
server_source="${2%.*}"

# Compile the client and server programs
gcc -o $client_source $1
gcc -o $server_source $2

echo "Compilation completed successfully!"

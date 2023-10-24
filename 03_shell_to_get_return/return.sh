#! /bin/bash

# sanity check
if [ "$#" -ne 1 ]; then
    echo "You must supply exactly one argument."
    echo "Example:  $0 /etc"
    exit 1
fi

# check if the file/directory exits
test -e "$1"
if [ "$?" -eq 0 ]; then
    echo "File/directory exits."
elif [ "$?" -eq 1 ]; then
    echo "File/directory does not exits."
    exit 3
else
    echo "Unknow return value from test..."
    exit 1
fi

exit 0
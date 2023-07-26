#! /bin/bash

while getopts 'fh' OPTION; do
    case "$OPTION" in
        h)
            echo "format - uses astyle for code formatting"
            echo ""
            echo "options:"
            echo "-h   show brief help"
            echo "-f   formats code"
            ;;
        f)
            astyle --options=$HOME/astyle_std --suffix=none src/*.cpp src/*.h src/*/*.h src/*/*.cpp
    esac
done
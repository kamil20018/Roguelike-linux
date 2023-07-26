#! /bin/bash

while getopts 'brash' OPTION; do
    case "$OPTION" in
        h)
            echo "run - can set up the cmake project, build it and run it."
            echo ""
            echo "options:"
            echo "-h   show brief help"
            echo "-s   sets the cmake build and source directories"
            echo "-b   builds the project"
            echo "-r   runs the project"
            echo "-a   builds and runs the project"
            ;;
        s)
            mkdir build
            cmake -S . -B build
            ;;
        b)
            cd build
            cmake --build .
            ;;
        r)
            cd build
            ./bin/game
            ;;
        a) 
            cd build
            cmake --build .
            ./bin/game
            ;;
    esac
done
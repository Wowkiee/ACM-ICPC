#!/bin/bash
while true; do
    ./gen > gen.in
    ./sol <gen.in >sol.out
    ./j <gen.in >j.out
    if diff sol.out j.out; then
        printf "AC\n"
    else
        printf "Wa\n"
        exit 0
    fi
done

// sh check.sh
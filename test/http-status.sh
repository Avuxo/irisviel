#!/bin/bash

# get the status code of an HTTP GET to a given request
# args: (url to test)
getStatus(){
    curl -s -I $1 |
        head -n 1 |
        grep -Eo '[0-9]{1,3}' |
        tail -n 1
}

# args: (received value, expected value, test #)
testStatus(){
    if [ "$1" == "$2" ]; then
        echo "Test $3 Passed."
    else
        echo "Test $3 failed."
    fi
}


testStatus `getStatus "http://localhost:8080"` "200" 1
testStatus `getStatus "http://localhost:8080/fake"` "404" 2

#!/usr/bin/env xonsh

from pathlib import Path

def compile_all_cpp():
    for filepath in Path(".").glob("*.cpp"):
        filename = str(filepath)
        output_filename = f"{filename.rsplit('.', 1)[0]}.out"
        ![g++ -std=c++11 @(filename) -o @(output_filename)]

if __name__ == "__main__":
    compile_all_cpp()

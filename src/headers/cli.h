#pragma once

#include <iostream>
#include <string>

class CliArgs{
    public:
        std::string treeFilePath;
        std::string queriesFilePath;
        std::string outputFilePath;
};



CliArgs* parseCliArguments(int argc, char* argv[]);

void printHelpMessage();
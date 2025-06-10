#include "./headers/cli.h"

CliArgs* parseCliArguments(int argc, char* argv[]){
    CliArgs* arguments = new CliArgs();

    for(int i=1; i<argc; i++){
        std::string argument = argv[i];

        if(argument=="-t"){
            arguments->treeFilePath=argv[++i];
        }
        else if(argument=="-i"){
            arguments->queriesFilePath=argv[++i];
        }
        else if(argument=="-o"){
            arguments->outputFilePath=argv[++i];
        }
        else if(argument=="--help"){
            printHelpMessage();
        }
        else{
            std::cout << "unknown argument: " << argument << std::endl;
        }
    }

    bool allNecessaryFlagsSet = !arguments->treeFilePath.empty() && !arguments->queriesFilePath.empty() && !arguments->outputFilePath.empty();
    if(!allNecessaryFlagsSet){
        printHelpMessage();
    }

    return arguments;
}

void printHelpMessage(){
    std::string helpMessage = 
    "Usage: main.exe [OPTIONS] \n\n"
    
    "Options:\n"
    "-t <file>       Specify the input file containing the tree.\n"
    "-i <file>       Specify the input file containing the queries.\n"
    "-o <file>       Specify the output file for the output.\n"
    "--help          Display this help message and exit.\n\n"

    "Example: \n"
    "\t program_name -t tree.txt -i queries.txt -o outputs.txt";
    std::cerr << helpMessage << std::endl;
}
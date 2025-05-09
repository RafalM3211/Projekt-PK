#include "headers/fileHandler.h"

FIleHandler::FIleHandler(std::string treeFile, std::string queriesFile,
                         std::string outputFile) {
  treeStream.open(treeFile, std::fstream::in);
  queriesStream.open(queriesFile, std::fstream::in);
  outputStream.open(outputFile, std::fstream::in);
}
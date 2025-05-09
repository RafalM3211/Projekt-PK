#pragma once

#include <fstream>

class FIleHandler {
 public:
  std::fstream treeStream{};
  std::fstream queriesStream{};
  std::fstream outputStream{};

  FIleHandler(std::string treeFile, std::string queriesFile,
              std::string outputFile);
};
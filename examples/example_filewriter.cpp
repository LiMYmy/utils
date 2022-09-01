#include "file_writer.hpp"

#include <sstream>

int main(int argc, char const *argv[])
{
  FileWriter file_writer("test.txt");

  std::stringstream ss;

  for(int i = 0; i < 1000; i++)
  {
    ss << i << std::endl;
    file_writer.Write(ss.str());
    ss.str("");
  }

  return 0;
}

#pragma once

#include "readerwriterqueue.h"

#include <fstream>
#include <iostream>
#include <thread>

class FileWriter
{
public:
  FileWriter(std::string filename)
    : file_(filename, std::ios::out)
    , queue_(1024)
  {
    if(file_.bad())
    {
      std::cerr << "failed to open " << filename << std::endl;
    }
    else
    {
      write_thread_ = std::thread(&FileWriter::WriteFile, this);
    }
  }

  ~FileWriter()
  {
    run_ = false;
    write_thread_.join();
  }

  void Write(std::string str)
  {
    queue_.enqueue(str);
  }

private:

  void WriteFile()
  {
    std::string temp;

    while (run_)
    {
      while(queue_.try_dequeue(temp))
      {
        file_.write(temp.data(), temp.size());
      }

      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    while(queue_.try_dequeue(temp))
    {
      file_.write(temp.data(), temp.size());
    }
  }

  std::ofstream file_;
  moodycamel::ReaderWriterQueue<std::string> queue_;
  std::thread write_thread_;
  bool run_ = true;
};


#include "Helper/ShellMethod.h"

std::string ExecuteAndRead(std::string command) {
    //open pipe and read the output while executing shell command
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE,   decltype(&pclose)> CommandStream(popen(command.c_str(), "r"), pclose);

    if (!CommandStream) {
        return nullptr;
    }
    while (fgets(buffer.data(), buffer.size(), CommandStream.get()))
    {
      
        result += buffer.data();
    }
    return result;
}

#include "../Headers/ShellMethod.h"

std::string ExecuteAndRead(std::string command) {
    //code is taken from : https://stackoverflow.com/questions/478898/how-do-i-execute-a-command-and-get-the-output-of-the-command-within-c-using-po
    //i will explain it.
    //array to hold the input read from stdout, we wont gonna read the whole input at once 
    //and this variable will hold the parts we read
    std::array<char, 128> buffer;
    //here we gonna store the bytes in buffer variable in every iteration, so by the end of the last iteration
    //we gonna have the full input inside this variable  
    std::string result;
    //shared pointer that will hold the File which represent the pip stream, and the custom Delete
    //decltype(&pclose) convert pclose into type so we can use it to specify the second generic paramater in std::unique_ptr
    std::unique_ptr<FILE,   decltype(&pclose)> CommandStream(popen(command.c_str(), "r"), pclose);
    //Check if the pointer couldn't be created
    if (!CommandStream) {
        return nullptr;
    }
    //read buffer from the pip
    while (fgets(buffer.data(), buffer.size(), CommandStream.get()))
    {
        //put it into result
        result += buffer.data();
    }
    //return the result
    return result;
}
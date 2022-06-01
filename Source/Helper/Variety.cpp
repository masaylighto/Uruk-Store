#include"../../Headers/Helper/Variety.h"
std::string ReadFileText(const std::string & FilePath)
{
    std::ifstream File(FilePath);
    std::string str((std::istreambuf_iterator<char>(File)),std::istreambuf_iterator<char>());
    return str;
}
std::vector<std::string>  SplitString(const std::string & OriginalString,const std::string & Delimiter){

    //vector that will hold the splitted strings
    std::vector<std::string> Parts;
    //when we gonna split we will need a place where we collect the current part character so we could add it into the vector ,because we are reading the original string as char after char,
    std::string Part;
    //current Character 
    std::string Characters;
    //so we could used in substring , for the sake of matching 
    int DelimiterWidth=Delimiter.length();
    // loop through all character in the string
    for (int Index = 0; Index < OriginalString.length(); Index++)
    {  
         Characters=OriginalString.substr(Index,DelimiterWidth);
         //check if the character equal to delimiter 
         //if it is then consider the character in the last iterations since the last time we hit the condition all of them are separated part we gonna ad it into the vec
        if (Characters==Delimiter)
        {
            //adding the part into vector
           Parts.push_back(Part);
           //clear the part so it will be ready to store the new part character in it
           Part.clear();
           // we increase the Index here ,because we need to jump to the index after the delimiter
           //so we add the size of Delimiter minus 1 because we will already increase one every loop iteration
            Index+=DelimiterWidth-1;
           //skip the loop cause if we continue the delimiter will be stored in the Part           
           continue;

        }
        Part+=OriginalString[Index];
    }
    Parts.push_back(Part);
    return Parts;
}

std::string ExecuteAndRead(std::string command) {
    //this part of code is taken from stack over flow, i will explain it.
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
        throw std::runtime_error("popen() failed!");
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

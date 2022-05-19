#include"../../Headers/Helper/Variety.h"
std::string ReadFileText(std::string FilePath)
{
    std::ifstream File(FilePath);
    std::string str((std::istreambuf_iterator<char>(File)),std::istreambuf_iterator<char>());
    return str;
}
std::vector<std::string>  SplitString(std::string OriginalString,char delimiter){

    //vector that will hold the splitted strings
    std::vector<std::string> Parts;
    //when we gonna split we will need a place where we collect the current part character so we could add it into the vector ,because we are reading the original string as char after char,
    std::string Part;
    //current Character 
    char Character;
    // loop through all character in the string
    for (int Index = 0; Index < OriginalString.length(); Index++)
    {  
         Character=OriginalString[Index];
         //check if the character equal to delimiter 
         //if it is then consider the character in the last iterations since the last time we hit the condition all of them are separated part we gonna ad it into the vec
        if (Character==delimiter)
        {
            //adding the part into vector
           Parts.push_back(Part);
           //clear the part so it will be ready to store the new part character in it
           Part.clear();
           //skip the loop cause if we continue the delimiter will be stored in the Part
           continue;
        }
        Part+=Character;
    }
    return Parts;
}
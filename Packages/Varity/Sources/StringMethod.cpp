#include "../Headers/StringMethod.h"

std::vector<std::string>  SplitString(const std::string & OriginalString,const std::string & Delimiter){

    //vector that will hold the splitted strings
    std::vector<std::string> Parts;
    //when we gonna split we will need a place where we collect the current part character so we could add it into the vector ,because we are reading the original string as char after char,
    std::string Part;
    //Used To Compare with Delimiter
    std::string MatchCharacters;
    //so we could used in substring , for the sake of matching 
    int DelimiterWidth=Delimiter.length();
    // loop through all character in the string
    for (int Index = 0; Index < OriginalString.length(); Index++)
    {  
        MatchCharacters=OriginalString.substr(Index,DelimiterWidth);       
         //check if the character equal to delimiter 
         //if it is then consider the character in the last iterations since the last time we hit the condition all of them are separated part we gonna ad it into the vec
        if (MatchCharacters==Delimiter)
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
inline bool IsPartialStringExist(const std::string & OriginalString,const std::string & PartialString ,const int StartIndex)
{   int IndexInPartialString=0;
    int PartialStringLength=PartialString.size();
    char * i=  const_cast<char*>(&OriginalString.data()[StartIndex]);
    i+=StartIndex;   
    for ( ; *i && IndexInPartialString < PartialStringLength ; i++,IndexInPartialString++)
    {
        if (PartialString[IndexInPartialString] != *i)
        {
            return false;
        }        
    }
    return true;
}
// csv reader implementation
// mkrum

#include "readCsv.h"

Reader::Reader(string inFile, int inCol): file(inFile), col(inCol){
}

vector<node> Reader::read(){
    vector<node> temp;
    string line;
    if (file.is_open()){
        while (getline (myfile,line)){
            std::stringstream sstream(line);
            string part;
            node tNode;
            int i = 0;
            while(getline(sstream, part, ',')){
                i++;
                std::string::size_type sz;
                if(i == col){
                    if(isDouble(part)){
                        tNode.ident = std::stod(part, &sz);  
                    } else {

                    }
                } else {
                    if(isDouble(part)){
                        tNode.data.push_back(std::stod(part, &sz));
                    } else {
                        tNode.data.push_back(
                    }
                }
            }
            temp.push_back(tNode);
        }
    }
}
 
bool Reader::isDouble(const char* str){
    char* lastptr = 0;
    std::stod(str, &lastptr);
    if(*lastptr != '\0' || lastptr == str)
        return false;
    else 
        return true;
}

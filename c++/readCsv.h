// reads a CSV and returns a vector
// mkrum

#ifndef READCSV_H
#define READCSV_H

#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;

struct node{
    vector<double> data;
    double ident;
};

class Reader{
    public:
        Reader(string, int);
        bool Reader::isDouble(const char*);
        vector<node> read();
    private:
        ifstream file;
        int col;
};

#endif

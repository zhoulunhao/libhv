#ifndef HV_STRING_H_
#define HV_STRING_H_

#include <string>
#include <vector>

#include "hbase.h"

using std::string;
typedef std::vector<string> StringList;

// std::map<std::string, std::string, StringCaseLess>
class StringCaseLess : public std::binary_function<std::string, std::string, bool> {
public:
    bool operator()(const std::string& lhs, const std::string& rhs) const {
        return stricmp(lhs.c_str(), rhs.c_str()) < 0;
    }
};

#define SPACE_CHARS     " \t\r\n"
#define PAIR_CHARS      "{}[]()<>\"\"\'\'``"

string asprintf(const char* fmt, ...);
StringList split(const string& str, char delim);
string trim(const string& str, const char* chars = SPACE_CHARS);
string trimL(const string& str, const char* chars = SPACE_CHARS);
string trimR(const string& str, const char* chars = SPACE_CHARS);
string trim_pairs(const string& str, const char* pairs = PAIR_CHARS);
string replace(const string& str, const string& find, const string& rep);

// str=/mnt/share/image/test.jpg
// basename=test.jpg
// dirname=/mnt/share/image
// filename=test
// suffixname=jpg
string basename(const string& str);
string dirname(const string& str);
string filename(const string& str);
string suffixname(const string& str);

#endif // HV_STRING_H_

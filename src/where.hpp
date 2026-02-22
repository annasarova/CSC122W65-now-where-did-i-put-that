#include <string>

std::string hello();

/* Character Find */
short find(const std::string& text,char target,
         size_t start = 0,bool caseSensitive = true);
/* String Find*/
short find(const std::string& text,const std::string& pattern,
         size_t start = 0,bool caseSensitive = true);
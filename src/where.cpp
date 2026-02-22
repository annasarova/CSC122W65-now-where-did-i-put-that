#include <string>
/* ===============================
   Character Find
   =============================== */
short find(const std::string& text,char target,
         size_t start = 0,bool caseSensitive = true)
{
    short result = -1;

    if (start < text.size())
    {
        if (!caseSensitive)
        {
            target = static_cast<char>(tolower(static_cast<unsigned char>(target)));
        }

        size_t i = start;
        while (i < text.size() && result == -1)
        {
            char current = text[i];

            if (!caseSensitive)
            {
                current = static_cast<char>(tolower(static_cast<unsigned char>(current)));
            }

            if (current == target)
            {
                result = static_cast<short>(i);
            }
            else
            {
                ++i;
            }
        }
    }
    return result;
}

/* ===============================
   String Find
   =============================== */
short find(const std::string& text,const std::string& pattern,
         size_t start = 0,bool caseSensitive = true)
{
    short result = -1;

    if (start < text.size())
    {
        if (pattern.empty())
        {
            result = static_cast<short>(start);
        }
        else
        {
            size_t t = start, p = 0;
            char tc,pc;
            bool matches = false;
            while (t < text.size() && p < pattern.size())
            {
                tc = text[t];
                if (!caseSensitive)
                {
                    tc = static_cast<char>(tolower(static_cast<unsigned char>(tc)));
                }

                if (pattern[p] == '*' && p + 1 < pattern.size())
                {
                    pc = pattern[p + 1];
                    if (!caseSensitive)
                    {
                        pc = static_cast<char>(tolower(static_cast<unsigned char>(pc)));
                    }
                    if (tc == pc)
                    {
                        ++p;
                    }
                    else
                    {
                        ++t;
                    }
                }
                else if (pattern[p] != '*')
                {
                    pc = pattern[p];
                    if (!caseSensitive)
                    {
                        pc = static_cast<char>(tolower(static_cast<unsigned char>(pc)));
                    }

                    if (tc == pc)
                    {
                        if (!matches)
                        {
                            if (pattern[0] == '*')
                            {
                                result = 0;
                            }
                            else
                            {
                                result = t;
                            }
                        }
                        matches = true;
                        ++t;
                        ++p;
                    }
                    else
                    {
                        result = -1;
                        matches = false;
                        ++t;
                        p = 0;
                    }
                }
                else
                {
                    ++p;
                }
            }

            if (p+1 < pattern.size())
            {
                result = -1;
            }
        }
    }

    return result;
}

#ifndef header_h
#define header_h

#include <iostream>
#include <boost/regex.hpp>
#include <fstream>
#include <string>

using namespace std;
using namespace boost;

namespace FPT{
    // end must not include enter ｛$|$(?!\\n)｝是测试器所有行的结尾，这里用$就行了
    const char* const FIRST_TITLE = "^#([^#]+?)$";  // 标题1 ok
    const char* const SECOND_TITLE = "^##([^#]+?)$";    // 标题2 ok
    const char* const THIRD_TITLE = "^###([^#]+?)$";    // 标题3 ok
    const char* const FORTH_TITLE = "^####([^#]+?)$";   // 标题4 ok
    const char* const FIFTH_TITLE = "^#####([^#]+?)$";   // 标题5 ok
    const char* const SIXTH_TITLE = "^######([^#]+?)$";   // 标题6 ok
    
    const char* const HR = "(-{3,})";   // 分割线 ok
    const char* const BOLD = "\\*\\*([^\\*]+?)\\*\\*";  // 加粗 ok
    const char* const ITALIC = "(?<!\\*)\\*([^\\*]+?)\\*";  // 斜体 ok
    const char* const STRING = "`([^`]+)`"; // 字符串，或是文字中 ok
    // 1name 2link
    const char* const LINK = "\\[(.*?)\\]\\(((http|ftp|https):\\/\\/[\\w\\-_]+(\\.[\\w\\-_]+)+([\\w\\-\\.,@?^=%&amp;:/~\\+#]*[\\w\\-\\@?^=%&amp;/~\\+#])?)\\)"; // 链接 ok
    //const char* const EMAIL = "\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*";
    const char* const QUOTE = "^>(.*?)(?=\\n\\n)";  // 引用 ok
    const char* const CODE = "((^((\\s{4,})|\\t).*?$\\n){1,})"; // 代码，空四格 一段代码 ok
    const char* const PARA = "(?<=\\n)(^[^\\n#].+?)(?=\\n\\n|\\n#)";    // 段落 ok
    const char* const LIST_ITEM = "^-([^-]*?)(?=\\n)";  // 有序列表 ok
    const char* const LIST_BLOCK = "(<LI>.*?)(?=\\n)";   // 无序列表 ?
}

namespace FT{
    const char* const FIRST_TITLE =  "<H1>\\1</H1>";
    const char* const SECOND_TITLE = "<H2>\\1</H2>";
    const char* const THIRD_TITLE =  "<H3>\\1</H3>";
    const char* const FORTH_TITLE =  "<H4>\\1</H4>";
    const char* const FIFTH_TITLE =  "<H5>\\1</H5>";
    const char* const SIXTH_TITLE =  "<H6>\\1</H6>";
    const char* const HR = "<HR>";
    const char* const BOLD = "<STRONG>\\1</STRONG>";
    const char* const ITALIC = "<EM>\\1</EM>";
    const char* const STRING = "<CODE>\\1</CODE>";
    const char* const LINK = "<A href=\"\\2\">\\1</A>";
    const char* const QUOTE = "<BLOCKQUOTE><P>\\1</P></BLOCKQUOTE>";
    const char* const CODE = "<PRE><CODE>\\1</CODE></PRE>";
    const char* const PARA = "<P>\\1</P>";
    const char* const LIST_ITEM = "<LI>\\1</LI>";
    const char* const LIST_BLOCK = "<UL>\\1</UL>";
}

class Md2HtmlFormat
{
public:
    Md2HtmlFormat(){}
    virtual ~Md2HtmlFormat(){}
    string format(const string &srctext);
private:
    string text;
    string styleFile;
    void addRules(string &text,const char *pattern, const char *foramt);
    void addRulesEdit(string &text,const char *pattern, const char *foramt);
};

#endif /* header_h */


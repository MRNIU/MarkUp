
#include "header.h"

string Md2HtmlFormat::format(const string &srctext)
{
    string text = srctext;
    addRules(text, FPT::FIRST_TITLE, FT::FIRST_TITLE);
    addRules(text, FPT::SECOND_TITLE, FT::SECOND_TITLE);
    addRules(text, FPT::THIRD_TITLE, FT::THIRD_TITLE);
    addRules(text, FPT::FORTH_TITLE, FT::FORTH_TITLE);
    addRules(text, FPT::FIFTH_TITLE, FT::FIFTH_TITLE);
    addRules(text, FPT::SIXTH_TITLE, FT::SIXTH_TITLE);
    addRules(text, FPT::HR, FT::HR);
    addRules(text, FPT::ITALIC, FT::ITALIC);
    addRules(text, FPT::BOLD, FT::BOLD);
    addRules(text, FPT::STRING, FT::STRING);
    addRules(text, FPT::LINK, FT::LINK);
    addRules(text, FPT::QUOTE, FT::QUOTE);
    addRules(text, FPT::LIST_ITEM, FT::LIST_ITEM);
    addRules(text, FPT::LIST_BLOCK, FT::LIST_BLOCK);
    addRules(text, FPT::CODE, FT::CODE);
    addRules(text, FPT::PARA, FT::PARA);
    //addRules(text, "\\n\\n(^[^<].*?)\\n\\n", "\\1"); // 段落整理 <br>
    cout << "parser:" <<text << endl;
    return text;
}

void Md2HtmlFormat::addRules(string &text, const char *cpattern, const char *cforamt)
{
    regex pattern(cpattern);
    string format(cforamt);
    text = regex_replace(text, pattern, format);
    // 这时 text 为 html 形式
    // cout<<text<<endl;
}

void Md2HtmlFormat::addRulesEdit(string &text, const char *cpattern, const char *cforamt)
{
    regex pattern(cpattern);
    string format(cforamt);
    text = regex_replace(text, pattern, format);
    
    // cout<<text<<endl;
}


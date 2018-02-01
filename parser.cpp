//
//  parser.cpp
//  MarkDown
//
//  Created by 牛志宏 on 2018/1/27.
//  Copyright © 2018年 牛志宏. All rights reserved.
//

#include "header.h"

string Md2HtmlFormat::format(const string &srctext)
{
    string text = srctext;
    string text_e= srctext;
    /*
     addRules(text, FPT::FIRST_TITLE, FT::FIRST_TITLE); // 标题 1
     addRules(text, FPT::SECOND_TITLE, FT::SECOND_TITLE);    // 标题 2
     addRules(text, FPT::THIRD_TITLE, FT::THIRD_TITLE);  // 标题 3
     addRules(text, FPT::FORTH_TITLE, FT::FORTH_TITLE);  // 标题 4
     addRules(text, FPT::FIFTH_TITLE, FT::FIFTH_TITLE);  // 标题 5
     addRules(text, FPT::SIXTH_TITLE, FT::SIXTH_TITLE);  // 标题 6
     addRules(text, FPT::HR, FT::HR);    // 分割线
     addRules(text, FPT::ITALIC, FT::ITALIC);    // 斜体
     addRules(text, FPT::BOLD, FT::BOLD);    // 粗体
     addRules(text, FPT::STRING, FT::STRING);    // 字符串，或是文字中
     addRules(text, FPT::LINK, FT::LINK);    // 链接
     addRules(text, FPT::QUOTE, FT::QUOTE);  // 引用
     addRules(text, FPT::LIST_ITEM, FT::LIST_ITEM);  //
     addRules(text, FPT::LIST_BLOCK, FT::LIST_BLOCK);    //
     addRules(text, FPT::CODE, FT::CODE);    // 代码，空四格
     addRules(text, FPT::PARA, FT::PARA);    // 段落
     //addRules(text, "\\n\\n(^[^<].*?)\\n\\n", "\\1"); // 段落整理 <br>
     addRules(text, FPT::DEL_LINE, FT::DEL_LINE); // 删除线
     addRules(text, FPT::UNDER_LINE, FT::UNDER_LINE);    // 下划线
     //cout << "parser:" <<text << endl;
     */
    addRulesEdit(text_e, FPT::FIRST_TITLE, EFT::FIRST_TITLE); // 标题 1
    addRulesEdit(text_e, FPT::SECOND_TITLE, EFT::SECOND_TITLE);    // 标题 2
    addRulesEdit(text_e, FPT::THIRD_TITLE, EFT::THIRD_TITLE);  // 标题 3
    addRulesEdit(text_e, FPT::FORTH_TITLE, EFT::FORTH_TITLE);  // 标题 4
    addRulesEdit(text_e, FPT::FIFTH_TITLE, EFT::FIFTH_TITLE);  // 标题 5
    addRulesEdit(text_e, FPT::SIXTH_TITLE, EFT::SIXTH_TITLE);  // 标题 6
    addRulesEdit(text_e, FPT::HR, EFT::HR);    // 分割线
    addRulesEdit(text_e, FPT::ITALIC, EFT::ITALIC);    // 斜体
    addRulesEdit(text_e, FPT::BOLD, EFT::BOLD);    // 粗体
    addRulesEdit(text_e, FPT::STRING, EFT::STRING);    // 字符串，或是文字中
    addRulesEdit(text_e, FPT::LINK, EFT::LINK);    // 链接
    addRulesEdit(text_e, FPT::QUOTE, EFT::QUOTE);  // 引用
    addRulesEdit(text_e, FPT::LIST_ITEM, EFT::LIST_ITEM);  //
    addRulesEdit(text_e, FPT::LIST_BLOCK, EFT::LIST_BLOCK);    //
    addRulesEdit(text_e, FPT::CODE, EFT::CODE);    // 代码，空四格
    addRulesEdit(text_e, FPT::PARA, EFT::PARA);    // 段落
    //addRulesEdit(text_e, "\\n\\n(^[^<].*?)\\n\\n", "\\1"); // 段落整理 <br>
    addRulesEdit(text_e, FPT::DEL_LINE, EFT::DEL_LINE); // 删除线
    addRulesEdit(text_e, FPT::UNDER_LINE, EFT::UNDER_LINE);    // 下划线
    cout<<text_e<<endl;
    return text_e;
}

void Md2HtmlFormat::addRules(string &text, const char *cpattern, const char *cforamt)
{
    regex pattern(cpattern);
    string format(cforamt);
    text = regex_replace(text, pattern, format);
    // 这时 text 为 html 形式
    // cout<<text<<endl;
}

void Md2HtmlFormat::addRulesEdit(string &text_e, const char *cpattern, const char *cforamt)
{
    regex pattern(cpattern);
    string format(cforamt);
    text_e = regex_replace(text_e, pattern, format);
    // cout<<text_e<<endl;
}

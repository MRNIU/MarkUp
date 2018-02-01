//
//  main.cpp
//  MarkDown
//
//  Created by 牛志宏 on 2018/1/27.
//  Copyright © 2018年 牛志宏. All rights reserved.
//

#include "header.h"

int main(int argc, const char * argv[])
{
    // 需要将读写硬盘改为读写文件
    fstream fin;
    fin.open("/Users/nzh/Documents/Program/C:C++/MarkDown/MarkDown/test.md",ifstream::in);
    string src;
    char ch;
    
    while (fin.good())
    {
        fin.get(ch);
        src = src + ch;
    }
    fin.close();
    src.append("\n\n"); // 在文末添加换行
    Md2HtmlFormat md;
    string pre = md.format(src);
    string edit = md.format_e(src);
    fstream fout("/Users/nzh/Documents/Program/C:C++/MarkDown/MarkDown/test.html",ifstream::out);
    
    fout<<"<head><LINK REL=StyleSheet HREF=\"style.css\" TYPE=\"text/css\"><meta charset=\"UTF-8\"></head>"<<endl; // 添加 UTF-8 string encoding.
    fout << pre <<endl;
    fout.close();
    
    return 0;
}


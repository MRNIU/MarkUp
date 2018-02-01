#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "header.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    ui->textBrowser->setSource(QString("qrc:/test.html"));
    qDebug()<<"ok";
}
void MainWindow::on_textEdit_textChanged()
{
    toHtml();
}
bool MainWindow::toHtml()
{
    /*
    // 需要将读写硬盘改为读写文件
    fstream fin;
    fin.open("qrc:/test.md",ifstream::in);

    string src;
    char ch;

    while (fin.good())
    {
        fin.get(ch);
        src = src + ch;
    }

    fin.close();
    */

    std::string cstr;
    QString qstring;
    qstring = ui->textEdit->toPlainText();

    //从QString 到 std::string
    cstr = string((const char *)qstring.toLocal8Bit());

    cstr.append("\n\n"); // 在文末添加换行
    Md2HtmlFormat f;
    string s = f.format(cstr);

    //从std::string 到QString
    qstring = QString(QString::fromLocal8Bit(s.c_str()));
    ui->textBrowser->setText(qstring);

    /*
    fstream fout("qrc:/test.html",ifstream::out);
    fout<<"<meta charset=\"UTF-8\">"<<endl; // 添加 UTF-8 string encoding.
    fout << s <<endl;
    fout.close();
    */

    return true;
}

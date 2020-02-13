#ifndef CLEANINITFILE_H
#define CLEANINITFILE_H

#include <QObject>
#include <QFileInfoList>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <windows.h>
#include <QDateTime>
#include <QDir>

class cleanInitFile : public QObject
{
    Q_OBJECT
public:
    explicit cleanInitFile(QObject *parent = 0);

    //获取某一目录下的文件列表
    QFileInfoList GetFileList(QString& path);

    //分析指定目录下的文件信息
    void FileInfoAnalyzer(QString ftp_dir);


    bool DelDir(const QString &path);
public slots:
    void slot_dosomething();

};

#endif // CLEANINITFILE_H

#include "cleaninitfile.h"

#define CHECKPATH "E:/newjob/invoice"

cleanInitFile::cleanInitFile(QObject *parent) : QObject(parent)
{

}

QFileInfoList cleanInitFile::GetFileList(QString &path)
{
    QDir dir(path);
    QFileInfoList file_list = dir.entryInfoList(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList folder_list = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);

    for (int i = 0; i != folder_list.size(); i++) {
        QString name = folder_list.at(i).absoluteFilePath();
        QFileInfoList child_file_list = GetFileList(name);
        if(child_file_list.isEmpty())
        {
            QDir qdrSubPath(name);
            qdrSubPath.rmpath(name);
            continue;
        }
        file_list.append(child_file_list);
    }

    return folder_list;

}

void cleanInitFile::FileInfoAnalyzer(QString ftp_dir)
{
        QDir dir(ftp_dir);
       // dir.setFilter(QDir::Files | QDir::Dirs|QDir::Hidden | QDir::NoSymLinks);
       // dir.setSorting(QDir::Size | QDir::Reversed);

        QFileInfoList list_sub = GetFileList(ftp_dir);

        for (int i = 0; i < list_sub.size(); ++i) {
            QString filepath;

            QFileInfo fileInfo = list_sub.at(i);
             filepath = fileInfo.filePath();
           DelDir(filepath);

           // filepath += "/" + fileInfo.fileName();
//            if (!filepath.isEmpty()){

//                QFileInfo info(filepath);
//                if (info.exists())    {

//                    //QString file_size = tr("%1").arg(info.size());
//                    QDateTime dt = info.created();
//                    QDateTime currentdt = QDateTime::currentDateTime();
//                    qint64 distance= dt.daysTo(currentdt);

//                   if(distance>=60)
//                   {
//                       DelDir(filepath);
//                   }

                  // dt = info.lastModified();
                   // QString modify_time = tr("%1").arg(dt.toString("yyyy-MM-dd hh:mm:ss"));
                   // QString file_id = tr("%1").arg(i);

                   // qDebug() << "文件名:" << info.fileName() << " 版本:" << file_ver << " 大小(Byte) :" << file_size << " 创建时间 : " << create_time << " 创建时间 : "<<modify_time ;
              //  }
            //}
        }

}

bool cleanInitFile::DelDir(const QString &path)
{
    if (path.isEmpty()){
            return false;
        }
        QDir dir(path);
        if(!dir.exists()){
            return true;
        }

        dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
        QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息

          QDateTime currentdt = QDateTime::currentDateTime();
        foreach (QFileInfo file, fileList){ //遍历文件信息
            if (file.isFile()){ // 是文件，删除
                 QDateTime dt = file.created();
                  qint64 distance= dt.secsTo(currentdt);
                  if(distance>=0)
                  {
                      file.dir().remove(file.fileName());
                  }

            }else{ // 递归删除
                DelDir(file.absoluteFilePath());
            }
        }

        return true; // 删除文件夹
}

void cleanInitFile::slot_dosomething()
{
    FileInfoAnalyzer(CHECKPATH);

}


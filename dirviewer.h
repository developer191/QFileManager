#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QWidget>
#include "abstractpanel.h"
#include <QFileSystemModel>
#include "diskselector.h"

namespace Ui {
class FileViewer;
}

class DirViewer : public AbstractPanel
{
    Q_OBJECT

public:
    explicit DirViewer(QDir dir, QWidget *parent = 0);
    ~DirViewer();
    virtual QDir currentDir();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual bool event(QEvent * event);

public slots:
    virtual void changeDir(QDir dir);

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);
    void openDiskList();

private:
    QDir dir;
    Ui::FileViewer *ui;
    QFileSystemModel * model;
    DiskSelector *selector;
};

#endif // FILEVIEWER_H
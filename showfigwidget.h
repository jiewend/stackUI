#ifndef SHOWFIGWIDGET_H
#define SHOWFIGWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMouseEvent>

namespace Ui {
class ShowFigWidget;
}

class ShowFigWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ShowFigWidget(QWidget *parent = 0);
    void setOwerAndTarget(int ower, int target);
    ~ShowFigWidget();

protected slots:
    void on_pushbuttonclose_clicked();
    void on_pushbuttonopen_clicked();
    void sendPicture();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    Ui::ShowFigWidget *ui;
    int owerChatwindows;
    int targetNode;
    QString filename_;

    QImage drawImage, image;
    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;
};

#endif // SHOWFIGWIDGET_H

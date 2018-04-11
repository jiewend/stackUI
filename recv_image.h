#ifndef RECV_IMAGE_H
#define RECV_IMAGE_H

#include <QDialog>
#include "app_datapackage.h"
#include <QFile>

namespace Ui {
class recv_image;
}

class recv_image : public QDialog
{
    Q_OBJECT

public:
    explicit recv_image(QWidget *parent = 0);
    ~recv_image();

public:
    void recvimage(struct ImagePackage *p_package_recv);
    void handleImageHeader(struct ImageHeader *p_package_recv);
    void handleImageData(struct ImageData *p_package_recv);
    void handleImageHeaderAck(struct ImageHeader *p_package_recv);

public slots:
    void showTestPicture();
    void saveImage();
    void saveImageAS();
    void emptyTemp();

private:
    Ui::recv_image *ui;
    QImage *imageTemp = NULL;
    QFile *imageFileTemp;
    int tmpSourceID = 255;
    uint pictureIDTemp = 256;
    uint Code_K;

};

#endif // RECV_IMAGE_H

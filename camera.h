#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>

namespace Ui {
class Camera;
}

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = 0);
    ~Camera();

public:
    void start_camera();
    int getTargetID();
    void setTargetAndSource(int self, int target);


protected slots:
    void on_pushbutton_close_clicked();
    void captureImage();
    void displayImage(int testint, QImage image);
    void saveImage();
    void isOpenCamera();

signals:
    void sendjpgfilename(QString filename, int targetNode, int selfNode);


private:
    Ui::Camera *ui;
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    QCameraImageCapture *imageCapture;
    int targetNode;
    int selfNode;
};

#endif // CAMERA_H

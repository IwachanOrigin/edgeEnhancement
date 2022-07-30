
#include "mainwindow.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    ui.graphicsView->setScene(&scene);
    QImage inputImg(":/MainWindow/test.jpg");
    QImage rtnImg = this->edgeEnhancement(inputImg, 0.5f);
    QGraphicsPixmapItem *image_item = new QGraphicsPixmapItem(QPixmap::fromImage(rtnImg));
    scene.addItem(image_item);
    ui.graphicsView->setScene(&scene);
}

void MainWindow::closeEvent(QCloseEvent* e)
{
}

void MainWindow::paintEvent(QPaintEvent *e)
{
}

QImage MainWindow::edgeEnhancement(QImage inputImg, float ratio)
{
    QImage rtnImg(inputImg.width(), inputImg.height(), inputImg.format());

    for (int i = 0; i < inputImg.height(); i++)
    {
        for (int j = 0; j < inputImg.width(); j++)
        {
            // y
            int i1 = i - 1;
            int i2 = i + 1;
            // x
            int j1 = j - 1;
            int j2 = j + 1;
            int r = 0;
            int g = 0;
            int b = 0;
            if ((i1 >= 0 && i2 <= inputImg.height() - 1)
                && (j1 >= 0 && j2 <= inputImg.width() - 1))
            {
                int edgeR = 4 * inputImg.pixelColor(j, i).red()
                    - inputImg.pixelColor(j1, i).red()
                    - inputImg.pixelColor(j2, i).red()
                    - inputImg.pixelColor(j, i1).red()
                    - inputImg.pixelColor(j, i2).red();
                r = (int)(inputImg.pixelColor(j, i).red() + edgeR * ratio);
                if (r > 255)
                {
                    r = 255;
                }
                else if (r < 0)
                {
                    r = 0;
                }

                int edgeG = 4 * inputImg.pixelColor(j, i).green()
                    - inputImg.pixelColor(j1, i).green()
                    - inputImg.pixelColor(j2, i).green()
                    - inputImg.pixelColor(j, i1).green()
                    - inputImg.pixelColor(j, i2).green();
                g = (int)(inputImg.pixelColor(j, i).green() + edgeG * ratio);
                if (g > 255)
                {
                    g = 255;
                }
                else if (g < 0)
                {
                    g = 0;
                }

                int edgeB = 4 * inputImg.pixelColor(j, i).blue()
                    - inputImg.pixelColor(j1, i).blue()
                    - inputImg.pixelColor(j2, i).blue()
                    - inputImg.pixelColor(j, i1).blue()
                    - inputImg.pixelColor(j, i2).blue();
                b = (int)(inputImg.pixelColor(j, i).blue() + edgeB * ratio);
                if (b > 255)
                {
                    b = 255;
                }
                else if (b < 0)
                {
                    b = 0;
                }
            }
            rtnImg.setPixel(j, i, qRgb(r, g, b));
        }
    }
    return rtnImg;
}


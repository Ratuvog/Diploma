#ifndef FRAME_H
#define FRAME_H

#include <QWidget>

namespace Ui {
    class Frame;
}

class Plot;
class ReaderInterface;
class MenuDomainView;

class Frame : public QWidget
{
    Q_OBJECT
public:
    Frame(QWidget *parent, ReaderInterface *reader);
    ~Frame();

    void readData();
    void setup(Plot *customPlot);

signals:

public slots:
    void oneClicked();
    void twoClicked();
    void threeClicked();
    void fourClicked();
    void fiveClicked();
    void sixClicked();

    void enterClicked();
    void escClicked();

    void leftClicked();
    void rightClicked();

    void scrollUp();
    void scrollDown();

private:
    void createMenu(MenuDomainView *menu);
    void setFirstInfo(QWidget *widget);
    void setSecondInfo(QWidget *widget);
    void setThirdInfo(QWidget *widget);

private:
    typedef QPair<QVector<double>, QVector<double> > Coords;
    Coords data;
    Ui::Frame *ui;
};

#endif // FRAME_H

#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include "labelprovider.h"
#include "reflectogram.h"

class Plot;
class ReflectogramReaderInterface;
class MenuDomainView;
class CursorGraph;
class DomainModel;

namespace Ui {
    class Frame;
}

class Frame : public QWidget
{
    Q_OBJECT
public:
    Frame(QWidget *parent, ReflectogramReaderInterface *reader);
    ~Frame();

    void readData(ReflectogramReaderInterface *reader);
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

    void cursorUpdated();

private:
    void createMenu(MenuDomainView *menu);

    void selectCursor(CursorGraph *cursor);

    void setFirstInfo(QWidget *widget);
    void setSecondInfo(QWidget *widget);
    void setThirdInfo(QWidget *widget);

private:
    Ui::Frame *ui;

    Reflectogram m_reflectogram;
    LabelProvider m_labelProvider;

    QList<CursorGraph*> m_cursors;
    CursorGraph *m_selectedCursor;
    DomainModel *m_infoModel;
};

#endif // FRAME_H

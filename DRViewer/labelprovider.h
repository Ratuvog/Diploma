#ifndef LABELPROVIDER_H
#define LABELPROVIDER_H

#include <QSet>

class LabelProvider
{
public:
    QString borrowNext();
    void release(const QString &symbol);

private:
    QSet<QString> borrowed;
};

#endif // LABELPROVIDER_H

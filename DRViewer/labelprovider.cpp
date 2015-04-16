#include <QString>
#include "labelprovider.h"

QString LabelProvider::borrowNext()
{
    for(int c = 'A'; c <= 'Z'; c++)
    {
        QString next = QString(QChar(c));
        if (!borrowed.contains(next))
        {
            borrowed.insert(next);
            return next;
        }
    }

    return QString();
}

void LabelProvider::release(const QString &symbol)
{
    borrowed.remove(symbol);
}

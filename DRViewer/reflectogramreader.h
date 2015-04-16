#ifndef REFLECTOGRAMREADER_H
#define REFLECTOGRAMREADER_H

#include <QList>
#include "reader.h"

class ReflectogramReader : public ReflectogramReaderInterface
{
public:
    ReflectogramReader(const QString &fileName);

    bool hasNext() const;
    QPointF nextPoint();

private:
    QList<QPointF>::const_iterator pointer;
    QList<QPointF> data;
};

#endif // REFLECTOGRAMREADER_H

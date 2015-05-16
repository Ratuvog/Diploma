#include "reflectogramreader.h"

#include <QFile>
#include <QTextStream>

ReflectogramReader::ReflectogramReader(const QString &fileName)
{
    if (fileName.isEmpty() || !QFile::exists(fileName))
        return;

    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly))
        return;

    QTextStream stream(&f);
    int size = 0;
    stream >> size;
    for(int i = 0; i < size && !stream.atEnd(); i++)
    {
        double x, y;
        stream >> x >> y;
        data.append(QPointF(x, y));
    }
    pointer = data.constBegin();
}

bool ReflectogramReader::hasNext() const
{
    return pointer != data.constEnd();
}

QPointF ReflectogramReader::nextPoint()
{
    if (hasNext()) {
        QPointF p = *pointer;
        pointer++;
        return p;
    }

    return QPointF();
}

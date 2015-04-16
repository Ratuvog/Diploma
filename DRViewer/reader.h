#ifndef READER
#define READER

#include <QPointF>

class ReflectogramReaderInterface {
public:
    virtual bool hasNext() const = 0;
    virtual QPointF nextPoint() = 0;
};

#endif // READER


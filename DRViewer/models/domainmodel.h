#ifndef DOMAINMODEL_H
#define DOMAINMODEL_H

#include "abstractdomainmodel.h"

class CursorModel;
class Reflectogram;

class DomainModel : public AbstractDomainModel
{
public:
    DomainModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    void setReflectogram(Reflectogram *refl);
    void setCursorA(CursorModel *model);
    void setCursorB(CursorModel *model);

    QVariant data(const QModelIndex &index, int role) const;

    void updateAll();

protected:
    QVariant transform(int domain, const QVariant &data) const;
    QVariant defaultValue(int domain) const;

private:
    CursorModel *cursorA;
    CursorModel *cursorB;
    Reflectogram *m_refl;
};

#endif // DOMAINMODEL_H

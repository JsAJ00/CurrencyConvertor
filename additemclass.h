#ifndef ADDITEMCLASS_H
#define ADDITEMCLASS_H

#include <QVBoxLayout>

#include "topareaclass.h"

class AddItemClass : public QVBoxLayout
{
public:
    AddItemClass();
    void addItem(topAreaClass *);
};

#endif // ADDITEMCLASS_H

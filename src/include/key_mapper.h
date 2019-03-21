#ifndef KEY_MAPPER_H_
#define KEY_MAPPER_H_

#include <QHash>

class KeyMapper
{
public:
    KeyMapper();
    uint FindNativeVirtualKeyCode(Qt::Key);

private:
    QHash<Qt::Key, uint> key_map_;
};

#endif

#ifndef CURSOR_H_
#define CURSOR_H_

#include <QImage>
#include <QPoint>
#include <QVarLengthArray>

struct Cursor
{
  QImage img;
  QPoint pos;
  QVarLengthArray < quint32 > buffer;
};

#endif // CURSOR_H_

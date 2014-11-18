#ifndef GUICHET_H
#define GUICHET_H

#include <QWidget>
#include <QHBoxLayout>

namespace Ui {
class Guichet;
}

class Guichet : public QWidget
{
    Q_OBJECT

public:
    explicit Guichet(QWidget *parent = 0);
    ~Guichet();

private:
    Ui::Guichet *ui;
};

#endif // GUICHET_H

#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QWidget>

namespace Ui {
class chatpage;
}

class chatpage : public QWidget
{
    Q_OBJECT

public:
    explicit chatpage(QWidget *parent = nullptr);
    ~chatpage();

private:
    Ui::chatpage *ui;
};

#endif // CHATPAGE_H

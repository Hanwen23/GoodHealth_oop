#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();

    void paintEvent(QPaintEvent *);

private:
    Ui::SignUp *ui;
};

bool isPasswordWeak(const QString& password);

#endif // SIGNUP_H

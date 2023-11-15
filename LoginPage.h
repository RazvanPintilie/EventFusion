#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget* parent = nullptr);

private slots:
    void onLoginClicked();

private:
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
};

#endif // LOGINPAGE_H


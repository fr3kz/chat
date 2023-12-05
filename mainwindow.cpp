#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "chatpage.h"

#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), apiService(new apiservice(this)), settings("chat","chat")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::login(QString username, QString password)
{

    QJsonObject userform;
    userform["username"] = username;
    userform["password"] = password;

    QJsonDocument user_doc(userform);


    QJsonDocument response = apiService->post_auth("http://127.0.0.1:8000/users/login/",user_doc.toJson());
    QJsonObject jobj = response.object();

    if(jobj.contains("message_error")) {
        qDebug() << jobj["message_error"].toString();
    }else{
        settings.setValue("sessionid",jobj["message"].toString());
        settings.setValue("userid",jobj["userid"].toInt());

        chatpage *chat = new chatpage();
        chat->show();
        hide();
        //this->close();


    }
}

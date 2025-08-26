#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H
#include "services/appdatabase.h"
#include <QObject>


class AppController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(AppController)

public:
    explicit AppController(QObject* parent = nullptr);
    ~AppController();
    void startup();
    void shutdown();

signals:
    void needsSetup();
    void readyWithRoot(QString);

private:
    void scanRoot();

    AppDatabase db_;


};

#endif // APPCONTROLLER_H


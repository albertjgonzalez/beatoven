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
    enum class ConfigState { NeedsSetup, ReadyWithRoot};
signals:
    void needsSetup();
    void readyWithRoot(QString);

private:
    ConfigState state_ {ConfigState::NeedsSetup};

    void scanRoot();

    AppDatabase db_;


};

#endif // APPCONTROLLER_H


#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H
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

private:
    ConfigState state_ {ConfigState::NeedsSetup};

    
signals:


};

#endif // APPCONTROLLER_H


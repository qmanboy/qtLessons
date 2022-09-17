#ifndef HOTKEYS_H
#define HOTKEYS_H

#include <QKeyEvent>

enum class Action
{
    open, save, newDoc, quit, print
};

class HotKey
{
public:
    Qt::Key getKey() const {return key;}
    Qt::KeyboardModifiers getModifier() const {return modifier;};
    QString getDescription() const {return *description;}
    QString getName() const {return name;}
    Action getAction() const {return action;}
    HotKey* getHotKey(){return this;}
    void setKey(Qt::KeyboardModifiers mod, Qt::Key k)
    {
        modifier = mod;
        key = k;
        hotkey = modifier + key;
        name = hotkey.toString().toUpper();
    }
    HotKey(){};
    HotKey(Qt::KeyboardModifiers _modifier, Qt::Key _key, QString* _description, Action _action)
            :modifier(_modifier), key(_key), description(_description), action(_action)
    {
        hotkey = modifier + key;
        name = hotkey.toString().toUpper();
    };

private:
    Qt::KeyboardModifiers modifier ;
    Qt::Key key;
    QKeySequence hotkey;
    QString* description;
    QString name;
    Action action;
};

Q_DECLARE_METATYPE(HotKey);

#endif // HOTKEYS_H

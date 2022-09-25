#include <QtTest>
#include <hotkeys.h>

// add necessary includes here

class UnitTest : public QObject
{
    Q_OBJECT

public:
    UnitTest();
    ~UnitTest();

private slots:
    void init_and_getters_test();
    void set_key_test();

private:
    Qt::KeyboardModifiers t_modifier{};
    Qt::Key t_key{};
    QKeySequence t_sec{};

    QString t_name{};
    QString *t_description{nullptr};
    Action t_action{};

    HotKey t_hotkey;


};

UnitTest::UnitTest()
{
    t_modifier = Qt::KeyboardModifier::ControlModifier;
    t_key = Qt::Key::Key_0;

    t_sec = t_modifier + t_key;
    t_name = t_sec.toString().toUpper();

    t_description = new QString("test_description");
    t_action = Action::open;

    t_hotkey = HotKey(t_modifier, t_key, t_description, t_action);
}

UnitTest::~UnitTest()
{
    delete t_description;
    t_description = nullptr;
}

void UnitTest::init_and_getters_test()
{
    QCOMPARE(t_hotkey.getModifier(), t_modifier);
    QCOMPARE(t_hotkey.getKey(), t_key);
    QCOMPARE(t_hotkey.getDescription(), t_description);
    QCOMPARE(t_hotkey.getAction(), t_action);
    QCOMPARE(t_hotkey.getName(), t_name);
    QCOMPARE(t_hotkey.getHotKey(), &t_hotkey);
    QCOMPARE(t_hotkey.getKeySequence(), t_sec);
}

void UnitTest::set_key_test()
{
    t_modifier = Qt::KeyboardModifier::ControlModifier;
    t_key = Qt::Key::Key_F;
    t_sec = t_modifier + t_key;
    t_name = t_sec.toString().toUpper();

    t_hotkey.setKey(t_modifier, t_key);

    this->init_and_getters_test();
}

QTEST_APPLESS_MAIN(UnitTest)

#include "tst_unittest.moc"

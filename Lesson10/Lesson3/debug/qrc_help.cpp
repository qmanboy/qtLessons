/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.12
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // D:/GB/QtProjects/from/Lesson3/Help/help_text.txt
  0x0,0x0,0x0,0x27,
  0x54,
  0x68,0x69,0x73,0x20,0x69,0x73,0x20,0x61,0x20,0x73,0x69,0x6d,0x70,0x6c,0x65,0x20,
  0x74,0x65,0x78,0x74,0x20,0x65,0x64,0x69,0x74,0x6f,0x72,0x20,0x68,0x65,0x6c,0x70,
  0x66,0x69,0x6c,0x65,0x2e,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // Help
  0x0,0x4,
  0x0,0x4,0xec,0x30,
  0x0,0x48,
  0x0,0x65,0x0,0x6c,0x0,0x70,
    // help_text.txt
  0x0,0xd,
  0x1,0x71,0x97,0x14,
  0x0,0x68,
  0x0,0x65,0x0,0x6c,0x0,0x70,0x0,0x5f,0x0,0x74,0x0,0x65,0x0,0x78,0x0,0x74,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/Help
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/Help/help_text.txt
  0x0,0x0,0x0,0xe,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x83,0x40,0xaf,0x93,0xc0,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_help)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_help)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_help)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_help)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_help)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_help)(); }
   } dummy;
}

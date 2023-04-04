/****************************************************************************
** Meta object code from reading C++ file 'NetConnection.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QtGaokaoSimulatorClient/NetConnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NetConnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NetConnection_t {
    QByteArrayData data[20];
    char stringdata0[215];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NetConnection_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NetConnection_t qt_meta_stringdata_NetConnection = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NetConnection"
QT_MOC_LITERAL(1, 14, 16), // "sigConnectToHost"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 8), // "hostName"
QT_MOC_LITERAL(4, 41, 4), // "port"
QT_MOC_LITERAL(5, 46, 9), // "connected"
QT_MOC_LITERAL(6, 56, 12), // "disconnected"
QT_MOC_LITERAL(7, 69, 5), // "error"
QT_MOC_LITERAL(8, 75, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 104, 11), // "socketError"
QT_MOC_LITERAL(10, 116, 11), // "receiveData"
QT_MOC_LITERAL(11, 128, 4), // "data"
QT_MOC_LITERAL(12, 133, 13), // "connectToHost"
QT_MOC_LITERAL(13, 147, 4), // "init"
QT_MOC_LITERAL(14, 152, 5), // "write"
QT_MOC_LITERAL(15, 158, 9), // "stopTimer"
QT_MOC_LITERAL(16, 168, 11), // "onConnected"
QT_MOC_LITERAL(17, 180, 14), // "onDisconnected"
QT_MOC_LITERAL(18, 195, 7), // "onError"
QT_MOC_LITERAL(19, 203, 11) // "onReadyRead"

    },
    "NetConnection\0sigConnectToHost\0\0"
    "hostName\0port\0connected\0disconnected\0"
    "error\0QAbstractSocket::SocketError\0"
    "socketError\0receiveData\0data\0connectToHost\0"
    "init\0write\0stopTimer\0onConnected\0"
    "onDisconnected\0onError\0onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetConnection[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   79,    2, 0x06 /* Public */,
       5,    0,   84,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
      10,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,   92,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    1,   98,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x0a /* Public */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,
      18,    1,  104,    2, 0x08 /* Private */,
      19,    0,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QByteArray,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,

       0        // eod
};

void NetConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NetConnection *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigConnectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 1: _t->connected(); break;
        case 2: _t->disconnected(); break;
        case 3: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->receiveData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->connectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 6: _t->init(); break;
        case 7: _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 8: _t->stopTimer(); break;
        case 9: _t->onConnected(); break;
        case 10: _t->onDisconnected(); break;
        case 11: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 12: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NetConnection::*)(QString , quint16 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetConnection::sigConnectToHost)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NetConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetConnection::connected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NetConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetConnection::disconnected)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (NetConnection::*)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetConnection::error)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (NetConnection::*)(const QByteArray & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NetConnection::receiveData)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NetConnection::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_NetConnection.data,
    qt_meta_data_NetConnection,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NetConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NetConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NetConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void NetConnection::sigConnectToHost(QString _t1, quint16 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NetConnection::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void NetConnection::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void NetConnection::error(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void NetConnection::receiveData(const QByteArray & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

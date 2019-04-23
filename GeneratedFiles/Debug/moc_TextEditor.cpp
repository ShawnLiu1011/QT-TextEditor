/****************************************************************************
** Meta object code from reading C++ file 'TextEditor.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TextEditor.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TextEditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TextEditor_t {
    QByteArrayData data[23];
    char stringdata0[207];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextEditor_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextEditor_t qt_meta_stringdata_TextEditor = {
    {
QT_MOC_LITERAL(0, 0, 10), // "TextEditor"
QT_MOC_LITERAL(1, 11, 14), // "contentChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "about"
QT_MOC_LITERAL(4, 33, 7), // "fileNew"
QT_MOC_LITERAL(5, 41, 8), // "fileOpen"
QT_MOC_LITERAL(6, 50, 8), // "fileSave"
QT_MOC_LITERAL(7, 59, 10), // "fileSaveAs"
QT_MOC_LITERAL(8, 70, 9), // "fileClose"
QT_MOC_LITERAL(9, 80, 4), // "undo"
QT_MOC_LITERAL(10, 85, 4), // "redo"
QT_MOC_LITERAL(11, 90, 3), // "cut"
QT_MOC_LITERAL(12, 94, 4), // "copy"
QT_MOC_LITERAL(13, 99, 5), // "paste"
QT_MOC_LITERAL(14, 105, 8), // "textBold"
QT_MOC_LITERAL(15, 114, 10), // "textItalic"
QT_MOC_LITERAL(16, 125, 13), // "textUnderline"
QT_MOC_LITERAL(17, 139, 9), // "textColor"
QT_MOC_LITERAL(18, 149, 9), // "filePrint"
QT_MOC_LITERAL(19, 159, 16), // "filePrintPreview"
QT_MOC_LITERAL(20, 176, 12), // "printPreview"
QT_MOC_LITERAL(21, 189, 9), // "QPrinter*"
QT_MOC_LITERAL(22, 199, 7) // "printer"

    },
    "TextEditor\0contentChanged\0\0about\0"
    "fileNew\0fileOpen\0fileSave\0fileSaveAs\0"
    "fileClose\0undo\0redo\0cut\0copy\0paste\0"
    "textBold\0textItalic\0textUnderline\0"
    "textColor\0filePrint\0filePrintPreview\0"
    "printPreview\0QPrinter*\0printer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextEditor[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    1,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,

       0        // eod
};

void TextEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TextEditor *_t = static_cast<TextEditor *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->contentChanged(); break;
        case 1: _t->about(); break;
        case 2: _t->fileNew(); break;
        case 3: _t->fileOpen(); break;
        case 4: { bool _r = _t->fileSave();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: { bool _r = _t->fileSaveAs();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: _t->fileClose(); break;
        case 7: _t->undo(); break;
        case 8: _t->redo(); break;
        case 9: _t->cut(); break;
        case 10: _t->copy(); break;
        case 11: _t->paste(); break;
        case 12: _t->textBold(); break;
        case 13: _t->textItalic(); break;
        case 14: _t->textUnderline(); break;
        case 15: _t->textColor(); break;
        case 16: _t->filePrint(); break;
        case 17: _t->filePrintPreview(); break;
        case 18: _t->printPreview((*reinterpret_cast< QPrinter*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TextEditor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextEditor.data,
      qt_meta_data_TextEditor,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TextEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TextEditor.stringdata0))
        return static_cast<void*>(const_cast< TextEditor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TextEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

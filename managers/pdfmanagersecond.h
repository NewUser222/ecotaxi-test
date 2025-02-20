// #ifndef PDFMANAGERSECOND_H
// #define PDFMANAGERSECOND_H

// #include <QCoreApplication>
// #include <QTextDocument>
// #include <QFile>
// #include <QDir>
// #include <QMessageBox>
// #include <QMimeData>
// #include <QApplication>
// #include <QClipboard>

// #include <QPdfWriter>
// #include <QPrinter>
// #include <QStandardPaths>

// #include <QDate>
#ifndef PDFMANAGERSECOND_H
#define PDFMANAGERSECOND_H

#include <QCoreApplication>
#include <QTextDocument>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QMimeData>
#include <QApplication>
#include <QClipboard>

#include <QString>
#include <QPdfWriter>
#include <QPrinter>
#include <QStandardPaths>

#include <QDate>
#include <QMap>
#include <QStandardItemModel>

#include "qstandarditemmodel.h"
#include "../scripts/columnselectiondialog.h"

// class PDFmanagerSecond
// {
// public:
//     PDFmanagerSecond();

//     // Экспорт данных в PDF по дням
//     // void static exportToPDFByDays(QString title, QDate fromDate, QDate toDate, QList<QStandardItemModel *> models, int start = 1);
//     void static exportToPDFByDays(QString title, QMap<QDate, QList<QStandardItemModel*>> dateModels, int start);



// private:
//     QString static getAppDir();
//     QString static getDesktopDir();

//     QString static getStyleSheet();

//     QString static getHeader(QDate date);
//     QString static getFooter();

//     void static createPDF(QString html, QString title);

//     QString static modelToHTML(QStandardItemModel *model, int start);
// };

// #endif // PDFMANAGERSECOND_H


class PDFmanagerSecond
{
public:
    PDFmanagerSecond();

    // Export reports by day within a date range, creating separate pages per day
    //static void exportToPDFByDays(QString title, QDate fromDate, QDate toDate, const QMap<QDate, QList<QStandardItemModel *>> &dateModels, int start = 1);
    static void exportToPDFByDays(QString title, QMap<QDate, QStandardItemModel*> dateModels, int start = 1);
    // static void exportToPDFByDays(QString title, QMap<QDate, QList<QStandardItemModel *>> dateModels,
    //                               QDate fromDate, QDate toDate, int start = 1);
private:
    static QString getAppDir();
    static QString getDesktopDir();

    static QString getStyleSheet();

    //static QString getHeader(QDateTime reportTime, QDate fromDate, QDate toDate, QDate date);


    static QString getHeader(QDate date);
    static QString getFooter();

    static QString modelToHTML(QStandardItemModel *model, int start);

    static void createPDF(QString html, QString title);
};

#endif // PDFMANAGERSECOND_H

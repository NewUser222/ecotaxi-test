// #include "pdfmanagersecond.h"

// PDFmanagerSecond::PDFmanagerSecond() {}

// QString PDFmanagerSecond::getAppDir()
// {
//     return QCoreApplication::applicationDirPath();
// }

// QString PDFmanagerSecond::getDesktopDir()
// {
//     return QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
// }

// QString PDFmanagerSecond::getStyleSheet()
// {
//     return R"CSS(
//     h1 { color: #007700; text-align: center; }
//     table { width: 100%; border-collapse: collapse; border: 1px solid black; }
//     th, td { border: 1px solid black; padding: 5px; text-align: center; }
//     )CSS";
// }

// QString PDFmanagerSecond::getHeader(QDate date)
// {
//     return "<h1>Данные за " + date.toString("dd.MM.yyyy") + "</h1>";
// }

// QString PDFmanagerSecond::getFooter()
// {
//     return "<br><p>ECO TAXI</p>";
// }

// QString PDFmanagerSecond::modelToHTML(QStandardItemModel *model, int start)
// {
//     QString html = "<table><thead><tr>";

//     if (start == 1)
//         html += "<th>#</th>";

//     for (int i = start; i < model->columnCount(); ++i)
//         html += "<th>" + model->headerData(i, Qt::Horizontal).toString() + "</th>";

//     html += "</tr></thead><tbody>";

//     for (int i = 0; i < model->rowCount(); ++i)
//     {
//         html += "<tr>";
//         if (start == 1)
//             html += "<td>" + QString::number(i + 1) + "</td>";

//         for (int j = start; j < model->columnCount(); ++j)
//             html += "<td>" + model->index(i, j).data(Qt::DisplayRole).toString() + "</td>";

//         html += "</tr>";
//     }

//     html += "</tbody></table>";

//     return html;
// }

// void PDFmanagerSecond::createPDF(QString html, QString title)
// {
//     QString filePath = getDesktopDir() + "/отчеты/" + title + ".pdf";
//     QDir().mkpath(getDesktopDir() + "/отчеты");

//     QPrinter printer(QPrinter::PrinterResolution);
//     printer.setOutputFormat(QPrinter::PdfFormat);
//     printer.setPageSize(QPageSize::A4);
//     printer.setOutputFileName(filePath);

//     QTextDocument doc;
//     doc.setDefaultStyleSheet(getStyleSheet());
//     doc.setHtml(html);
//     doc.setPageSize(printer.pageRect(QPrinter::DevicePixel).size());

//     doc.print(&printer);

//     QMessageBox::information(nullptr, "Экспорт", "Отчет сохранен на рабочем столе в папке \"отчеты\".");
// }


//нерабочая функция
// void PDFmanagerSecond::exportToPDFByDays(QString title, QDate fromDate, QDate toDate, QList<QStandardItemModel *> models, int start)
// {
//     QString html;

//     for (QDate date = fromDate; date <= toDate; date = date.addDays(1))
//     {
//         html += getHeader(date);
//         for (QStandardItemModel *model : models)
//             html += modelToHTML(model, start);
//         html += getFooter() + "<br><br>";
//     }

//     createPDF(html, title);
// }


//нерабочая функция
// void PDFmanagerSecond::exportToPDFByDays(QString title, QDate fromDate, QDate toDate, QList<QStandardItemModel *> models, int start)
// {
//     QString html;

//     // Убедитесь, что список models итерируется синхронно с датами
//     int index = 0;
//     for (QDate date = fromDate; date <= toDate; date = date.addDays(1))
//     {
//         if (index < models.size())  // Добавляем проверку, чтобы не выйти за пределы списка
//         {
//             html += getHeader(date);
//             html += modelToHTML(models[index], start);
//             html += getFooter() + "<br><br>";
//             index++;
//         }
//     }

//     createPDF(html, title);
// }


// void PDFmanagerSecond::exportToPDFByDays(QString title, QMap<QDate, QList<QStandardItemModel*>> dateModels, int start)
// {
//     QString html;

//     // Проходим по каждой дате и выводим все модели для этой даты
//     for (auto it = dateModels.begin(); it != dateModels.end(); ++it)
//     {
//         QDate date = it.key();
//         html += getHeader(date);  // Заголовок с датой

//         QList<QStandardItemModel*> models = it.value();  // Получаем список всех моделей для этой даты

//         for (QStandardItemModel* model : models)  // Перебираем все модели
//         {
//             html += modelToHTML(model, start);  // Добавляем каждую модель в HTML
//             html += "<br>";  // Добавляем разделитель между таблицами
//         }

//         html += getFooter() + "<br><br>";  // Нижний колонтитул и разрыв строки
//     }

//     createPDF(html, title);  // Генерируем PDF-файл
// }
#include "pdfmanagersecond.h"

PDFmanagerSecond::PDFmanagerSecond() {}

QString PDFmanagerSecond::getAppDir() { return QCoreApplication::applicationDirPath(); }
QString PDFmanagerSecond::getDesktopDir() { return QStandardPaths::writableLocation(QStandardPaths::DesktopLocation); }

QString PDFmanagerSecond::getStyleSheet() {
    return R"S(
    h1 { color: #007700; text-align: center; }
    table { width: 100%; border-collapse: collapse; margin: 0 auto; }
    table, th, td { border: 1px solid black; text-align: center; padding: 5px; }
    )S";
}

QString PDFmanagerSecond::getHeader(QDate date) {
    return "<h1>Данные за " + date.toString("dd.MM.yyyy") + "</h1>";
}
// QString PDFmanagerSecond::getHeader(QDateTime reportTime, QDate fromDate, QDate toDate,  QDate date = QDate())
// {
//     QString header = "<div style='text-align: center;'>"
//                      "<p>" + reportTime.toString("dd.MM.yyyy HH:mm:ss") + "</p>"
//                                                                     "<h1 style='color: #007700;'>ECO TAXI</h1>"
//                                                                     "<h2><b>Отчет по дням</b></h2>"
//                                                                     "<p>" + fromDate.toString("dd.MM.yyyy") + " - " + toDate.toString("dd.MM.yyyy") + "</p>";

//     // Если передана конкретная дата, добавляем заголовок для этой даты
//     if (date.isValid()) {
//         header += "<h1>Данные за " + date.toString("dd.MM.yyyy") + "</h1>";
//     }

//     header += "</div><br>";

//     return header;
// }






QString PDFmanagerSecond::getFooter() {
    return "<br><p>ECO TAXI</p>";
}

QString PDFmanagerSecond::modelToHTML(QStandardItemModel *model, int start)
{
    QString html = "<div style='width: 100%; margin: 20px 0;'>";
    html += "<table>";

    html += "<thead><tr>";
    if (start == 1)
        html += "<th>#</th>";

    for (int i = start; i < model->columnCount(); i++)
        html += "<th>" + model->headerData(i, Qt::Horizontal).toString() + "</th>";

    html += "</tr></thead><tbody>";

    for (int i = 0; i < model->rowCount(); i++)
    {
        html += "<tr>";
        if (start == 1)
            html += "<td>" + QString::number(i + 1) + "</td>";

        for (int j = start; j < model->columnCount(); j++)
            html += "<td>" + model->index(i, j).data(Qt::DisplayRole).toString() + "</td>";

        html += "</tr>";
    }

    html += "</tbody></table></div>";
    return html;
}

// void PDFmanagerSecond::createPDF(QString html, QString title)
// {
//     QApplication::setOverrideCursor(Qt::WaitCursor);

//     QString filePath = getDesktopDir() + "/отчеты/" + title.replace(" ", "_") + ".pdf";
//     QPrinter printer(QPrinter::PrinterResolution);
//     printer.setOutputFormat(QPrinter::PdfFormat);
//     printer.setPageSize(QPageSize::A4);
//     printer.setOutputFileName(filePath);

//     QTextDocument doc;
//     doc.setDefaultStyleSheet(getStyleSheet());
//     doc.setHtml(html);
//     doc.setPageSize(printer.pageRect(QPrinter::DevicePixel).size());

//     doc.print(&printer);

//     QApplication::restoreOverrideCursor();

//     QMessageBox popup;
//     popup.setTextFormat(Qt::MarkdownText);
//     popup.setText("Отчет сохранен в папке 'отчеты' на рабочем столе.");
//     popup.exec();
// }


void PDFmanagerSecond::createPDF(QString html, QString title)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);

    QString basePath = getDesktopDir() + "/отчеты/";
    QDir folder(basePath);
    if (!folder.exists()) {
        folder.mkpath(basePath); // Создаем папку, если её нет
    }

    int index = 0;
    QString filePath;
    do {
        QString fileName = title.replace(" ", "_") + "_" + QString::number(index) + ".pdf";
        filePath = basePath + fileName;
        index++;
    } while (QFile::exists(filePath)); // Если файл существует, увеличиваем индекс

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPageSize(QPageSize::A4);
    printer.setOutputFileName(filePath);

    QTextDocument doc;
    doc.setDefaultStyleSheet(getStyleSheet());
    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::DevicePixel).size());

    doc.print(&printer);

    QApplication::restoreOverrideCursor();

    QMessageBox popup;
    popup.setTextFormat(Qt::MarkdownText);
    popup.setText("Отчет сохранен в папке 'отчеты' на рабочем столе: " + filePath);
    popup.exec();
}




//pdf не показывает другие столбцы
// void PDFmanagerSecond::exportToPDFByDays(QString title, QDate fromDate, QDate toDate, const QMap<QDate, QList<QStandardItemModel *>> &dateModels, int start)
// {
//     QString html;

//     for (QDate date = fromDate; date <= toDate; date = date.addDays(1))
//     {
//         if (!dateModels.contains(date))
//             continue;

//         html += "<div style='page-break-before: always;'>"; // Новая страница для каждого дня
//         html += getHeader(date);

//         for (QStandardItemModel *model : dateModels[date])
//             html += modelToHTML(model, start);

//         html += getFooter() + "</div>";
//     }

//     if (!html.isEmpty())
//         createPDF(html, title);
// }





// void PDFmanagerSecond::exportToPDFByDays(QString title, QMap<QDate, QStandardItemModel*> dateModels, int start)
// {
//     QString html;

//     for (auto it = dateModels.begin(); it != dateModels.end(); ++it)
//     {
//         QDate date = it.key();
//         QStandardItemModel *model = it.value();

//         html += "<div style='page-break-before: always;'>";  // Новая страница для каждой даты
//         html += "<h2 style='color: #007700;'>Данные за " + date.toString("dd.MM.yyyy") + "</h2>";
//         html += modelToHTML(model, start);
//         html += getFooter() + "</div>";
//     }

//     createPDF(html, title);
// }


void PDFmanagerSecond::exportToPDFByDays(QString title, QMap<QDate, QStandardItemModel*> dateModels, int start)
{
    QString html;

    // Проходим по каждой дате и выводим соответствующую модель
    for (auto it = dateModels.begin(); it != dateModels.end(); ++it)
    {
        QDate date = it.key();
        QStandardItemModel *model = it.value();

        html += getHeader(date);  // Заголовок с датой
        html += modelToHTML(model, start); // Выводим все данные для этой даты
        html += getFooter() + "<div style='page-break-before: always;'></div>"; // Нижний колонтитул и переход на новую страницу
    }

    createPDF(html, title);
}


// void PDFmanagerSecond::exportToPDFByDays(QString title, QMap<QDate, QList<QStandardItemModel *>> dateModels, QDate fromDate, QDate toDate, int start)
// {
//     QString html;
//     QDateTime reportTime = QDateTime::currentDateTime();  // Время создания отчета

//     // Добавляем общий заголовок отчета в начале
//     html += getHeader(reportTime, fromDate, toDate);

//     // Проходим по каждой дате и выводим все модели данных
//     for (auto it = dateModels.begin(); it != dateModels.end(); ++it)
//     {
//         QDate date = it.key();
//         QList<QStandardItemModel *> models = it.value();

//         // Добавляем заголовок для текущей даты
//         html += getHeader(reportTime, fromDate, toDate, date);  // Заголовок с датой

//         // Проходим по всем моделям данных для текущей даты
//         for (int i = 0; i < models.size(); ++i)
//         {
//             html += modelToHTML(models[i], start);  // Выводим таблицу данных
//             html += "<br>";  // Добавляем перенос строки между таблицами
//         }

//         // Добавляем нижний колонтитул и разрыв страницы после каждого дня
//         html += getFooter() + "<div style='page-break-before: always;'></div>";
//     }

//     // Создаем PDF-файл с готовым HTML-содержимым
//     createPDF(html, title);
// }




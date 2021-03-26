#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_changeFontButton_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);

    if (ok)
    {
        // the user clicked OK and font is set to the font the user selected
    }
    else
    {
        // the user canceled the dialog; font is set to the initial
        // value, in this case Helvetica [Cronyx], 10
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_submitButton_clicked()
{
    QMessageBox::information(this, tr("Submitted Message"), tr("User %1 submitted a message with a title %2. The message is %3")
                             .arg(ui->lineEditName->text())
                             .arg(ui->lineEditTitle->text())
                             .arg(ui->textEdit->toPlainText()));
}

void MainWindow::on_actionPreferences_triggered()
{
    QStringList languages;
    languages << "Chinese" << "English" << "French";

    QString lang = QInputDialog::getItem(nullptr, "Select language", "Language", languages);

    if (lang == "Chinese")
    {
        qDebug() << "Loading Translation_zh_CN.qm";
        t.load("://resources/languages/Translation_zh_CN.qm");
        guiTranslator.load("/usr/share/qt5/translations/qt_zh_CN.qm");
    }
    else if (lang == "French")
    {
        qDebug() << "Loading Translation_fr_FR.qm";
        t.load("://resources/languages/Translation_fr_FR.qm");
        guiTranslator.load("/usr/share/qt5/translations/qtbase_fr.qm");
    }

    if (lang != "English")
    {
        qApp->installTranslator(&t);
        qApp->installTranslator(&guiTranslator);
    }
}

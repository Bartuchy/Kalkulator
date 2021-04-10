#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QMessageBox>

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

void MainWindow::on_oblicz_clicked()
{
    int liczba1=ui->a->text().toInt();
    int liczba2=ui->b->text().toInt();

    int index=ui->operacje->currentIndex();

    switch (index)
    {
        case 0:
        {
            int liczba3=liczba1+liczba2;
            ui->wynik->setText(QString::number(liczba3));
            break;
        }

        case 1:
        {
            int liczba3=liczba1-liczba2;
            ui->wynik->setText(QString::number(liczba3));
            break;
        }


        case 2:
        {
            int liczba3=liczba1*liczba2;
            ui->wynik->setText(QString::number(liczba3));
            break;
        }

        case 3:
        {
            double liczba3=(liczba1*1.0)/liczba2;
            ui->wynik->setText(QString::number(liczba3));
            break;
        }
    }
}



void MainWindow::on_autor_clicked(bool arg1)
{
    if( arg1==true)
    {
        ui->WypiszAutora->setText("Bartosz Markiewicz");
    }
    else
    {
        ui->WypiszAutora->clear();
    }
}

void MainWindow::on_Kalendarz_clicked(const QDate &date)
{
    ui->WypiszKalendarz->setText(date.toString("d/M/yyyy"));
}

void MainWindow::on_horizontalScrollBar_actionTriggered(int action)
{
    action=ui->horizontalScrollBar->value();
    ui->label->setText(QString::number(action));
}

void MainWindow::on_Dodaj_clicked()
{
    QString text=ui->Nazwisko->text();
    text.append("");
    ui->Notes->setText(text);
    ui->Nazwisko->clear();
}

void MainWindow::on_Dodajv2_clicked()
{
    QString text=ui->liczba->text();
    ui->listWidget->addItem(QString::number(text.toInt()));
    ui->liczba->clear();

    ui->pozycje->setText(QString::number(ui->listWidget->count()));

    int liczba=ui->suma->text().toInt();
    liczba += text.toInt();
    ui->suma->setText(QString::number(liczba));
}

void MainWindow::on_clear_clicked()
{
    ui->listWidget->clear();
    ui->pozycje->setText("0");
    ui->suma->setText("0");
    ui->dane2->setValue(0);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString text=ui->dane2->text();
    ui->listWidget->addItem(QString::number(text.toInt()));

    ui->pozycje->setText(QString::number(ui->listWidget->count()));

    int liczba=ui->suma->text().toInt();
    liczba += text.toInt();
    ui->suma->setText(QString::number(liczba));
}

void MainWindow::on_zapis_clicked()
{
    QString filename="notes.txt";
    QFile file(filename);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"Nie mozna otworzyc pliku!";
        return;
    }

    QTextStream out(&file);
    out<<ui->Notes->toPlainText();
    file.flush();
    file.close();
    //plik tworzy sie w folderze  build-kalkulator
}

void MainWindow::on_pusty_clicked()
{
    ui->Notes->clear();
}


void MainWindow::on_odczyt_clicked()
{
    QString filename="notes.txt";
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug()<<"Nie mozna otworzyc pliku!";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line=in.readLine();
        ui->Notes->append(line);
    }
    file.close();
}

void MainWindow::on_ButtonCzerwony_clicked()
{
    ui->ButtonCzerwony->isChecked();
    MainWindow::setStyleSheet("background-color: red");
}

void MainWindow::on_ButtonZielony_clicked()
{
    ui->ButtonZielony->isChecked();
    MainWindow::setStyleSheet("background-color: green");
}

void MainWindow::on_ButtonSzary_clicked()
{
    ui->ButtonSzary->isChecked();
    MainWindow::setStyleSheet("background-color: lightgrey");
}

void MainWindow::on_actionPokaz_triggered()
{
    ui->a->setVisible(true);
    ui->b->setVisible(true);
    ui->wynik->setVisible(true);
    ui->operacje->setVisible(true);
    ui->oblicz->setVisible(true);
}

void MainWindow::on_actionUkryj_triggered()
{
    ui->a->setVisible(false);
    ui->b->setVisible(false);
    ui->wynik->setVisible(false);
    ui->operacje->setVisible(false);
    ui->oblicz->setVisible(false);
}

void MainWindow::on_actionKopiuj_triggered()
{
    QString Kopiuj=ui->Notes->toPlainText();
    schowek=Kopiuj;
}

void MainWindow::on_actionWytnij_triggered()
{
    QString Wytnij=ui->Notes->toPlainText();
    schowek=Wytnij;
    ui->Notes->clear();
}

void MainWindow::on_actionWklej_triggered()
{
    QString Wklej;
    Wklej=schowek;
    ui->Notes->setPlainText(Wklej);
}

void MainWindow::on_actionk1_triggered()
{
    QMessageBox::information(this,"Komunikat 1","Informacja", QMessageBox::Ok);
}

void MainWindow::on_actionk2_triggered()
{
    QMessageBox::warning(this, "Komunikat 2", "Ostrzezenie",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
}

void MainWindow::on_actionk3_triggered()
{
    QMessageBox::critical(this, "komunikat 3", "Critical Error", QMessageBox::Save | QMessageBox::Help);
}

void MainWindow::on_actionk4_triggered()
{
    QMessageBox::question(this, "Komunikat 4", "????", QMessageBox::Open);
}

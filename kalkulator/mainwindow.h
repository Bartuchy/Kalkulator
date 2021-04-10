#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
QString schowek;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_oblicz_clicked();

    void on_autor_clicked(bool arg);

    void on_Kalendarz_clicked(const QDate &date);

    void on_horizontalScrollBar_actionTriggered(int action);

    void on_Dodaj_clicked();

    void on_Dodajv2_clicked();

    void on_clear_clicked();

    void on_pushButton_2_clicked();

    void on_zapis_clicked();

    void on_pusty_clicked();

    void on_odczyt_clicked();

    void on_ButtonCzerwony_clicked();

    void on_ButtonZielony_clicked();

    void on_ButtonSzary_clicked();

    void on_actionPokaz_triggered();

    void on_actionUkryj_triggered();

    void on_actionKopiuj_triggered();

    void on_actionWytnij_triggered();

    void on_actionWklej_triggered();

    void on_actionk1_triggered();

    void on_actionk2_triggered();

    void on_actionk3_triggered();

    void on_actionk4_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

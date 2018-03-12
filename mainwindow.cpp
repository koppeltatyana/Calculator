#include "mainwindow.h"
#include "ui_mainwindow.h"

double num_first;//левое число

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked(bool)), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked(bool)), this, SLOT(operations()));
    connect(ui->pushButton_devide, SIGNAL(clicked(bool)), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked(bool)), this, SLOT(math_operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked(bool)), this, SLOT(math_operations()));
    connect(ui->pushButton_mult, SIGNAL(clicked(bool)), this, SLOT(math_operations()));

    connect(ui->pushButton_clear, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_dot_clicked()));

    ui->pushButton_devide->setCheckable(true);//делаем так, чтобы мы могли нажать все эти кнопки
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mult->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();//возвращает кнопку, на которую было произведено нажатие
    //теперь каким-то образом будет все зашибись

    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0") {
        new_label = ui->result_show->text()+button->text();
    } else {
        all_numbers = (ui->result_show->text()+button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                            //15 - количество чиселок, которых можно ввести
    }

    ui->result_show->setText(new_label);

}

void MainWindow::on_pushButton_dot_clicked()
{
    if(!(ui->result_show->text().contains('.')))//проверка на то, чтобы точка была всего одна
        ui->result_show->setText(ui->result_show->text()+".");
}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();//возвращает кнопку, на которую было произведено нажатие
    //теперь каким-то образом будет все зашибись
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-") {

        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * (-1);
        new_label = QString::number(all_numbers, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                                //15 - количество чиселок, которых можно ввести
        ui->result_show->setText(new_label);
    } else if(button->text() == "%") {

        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                                //15 - количество чиселок, которых можно ввести
        ui->result_show->setText(new_label);
    }
}

void MainWindow::math_operations()
{
    QPushButton *button = (QPushButton *)sender();//возвращает кнопку, на которую было произведено нажатие
    //теперь каким-то образом будет все зашибись

    num_first = ui->result_show->text().toDouble();

    ui->result_show->setText("");

    button->setChecked(true);

}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_devide->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_mult->setChecked(false);
    ui->pushButton_dot->setChecked(false);

    ui->result_show->setText("0");

}

void MainWindow::on_pushButton_equally_clicked()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = ui->result_show->text().toDouble();

    if(ui->pushButton_plus->isChecked()) {

        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                                //15 - количество чиселок, которых можно ввести
        ui->result_show->setText(new_label);
        ui->pushButton_plus->setChecked(false);

    } else if (ui->pushButton_minus->isChecked()) {

        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                                //15 - количество чиселок, которых можно ввести
        ui->result_show->setText(new_label);
        ui->pushButton_minus->setChecked(false);

    } else if (ui->pushButton_devide->isChecked()) {

        labelNumber = num_first / num_second;
        if(num_second == 0)
        {
            ui->result_show->setText("Infinity");
        } else {
            new_label = QString::number(labelNumber, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                                //15 - количество чиселок, которых можно ввести
            ui->result_show->setText(new_label);
        }

        ui->pushButton_devide->setChecked(false);

    } else if (ui->pushButton_mult->isChecked()) {

        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);//конвертация из типа double в строку, чтобы вывести в результат
                                                //15 - количество чиселок, которых можно ввести
        ui->result_show->setText(new_label);
        ui->pushButton_mult->setChecked(false);

    }
}

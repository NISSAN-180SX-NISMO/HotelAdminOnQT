//
// Created by user on 30.11.2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AppendClientDialog.h" resolved

#include "appendclientdialog.h"
#include "ui_AppendClientDialog.h"


AppendClientDialog::AppendClientDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::AppendClientDialog) {
    ui->setupUi(this);

    QRegularExpressionValidator *nameValidator = new QRegularExpressionValidator(QRegularExpression("[А-Яа-яЁё]+\\s[А-Яа-яЁё]+\\s[А-Яа-яЁё]+"));
    ui->lineEdit->setValidator(nameValidator);

    connect(this, SIGNAL(dialogChanged()), this, SLOT(updateForm()));
    // В конструкторе вашего класса
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &AppendClientDialog::updateForm);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AppendClientDialog::updateForm);
    connect(ui->appendClient_pushButton, &QPushButton::clicked, this, &AppendClientDialog::updateForm);
    connect(ui->endBookingDate_calendarWidget, &QCalendarWidget::selectionChanged, this, &AppendClientDialog::updateForm);
    connect(ui->bookingDate_calendarWidget, &QCalendarWidget::selectionChanged, this, &AppendClientDialog::updateForm);
}

AppendClientDialog::~AppendClientDialog() {
    delete ui;
}

void AppendClientDialog::updateForm() {
    HotelRoom* currentRoom = rooms->get(ui->comboBox->currentText());
    if (currentClients.size() > currentRoom->getSeats())
        while (currentClients.size() > currentRoom->getSeats())
            currentClients.pop_back();
    ui->clientCount_label->setText(QString::number(currentRoom->getSeats()));

    ui->listWidget->clear();
    for (auto client : currentClients)
        ui->listWidget->addItem(client->getName());

    ui->save_pushButton->setEnabled(formIsValid());
}

void AppendClientDialog::on_appendClient_pushButton_clicked() {
    currentClients.push_back(new Client(ui->lineEdit->text()));
    emit dialogChanged();
}

bool AppendClientDialog::formIsValid() {
    if (currentClients.empty()) return false;
    if (ui->lineEdit->text().isEmpty() && currentClients.empty()) return false;
    if (ui->comboBox->currentText().isEmpty())  return false;
    if (ui->bookingDate_calendarWidget->selectedDate() >= ui->endBookingDate_calendarWidget->selectedDate()) return false;
    return true;
}

void AppendClientDialog::on_save_pushButton_clicked() {
    BookingBuilder *builder = (new BookingBuilder())->
            setRoom(rooms->get(ui->comboBox->currentText()))->
            setBookingDate(QDateTime(ui->bookingDate_calendarWidget->selectedDate(), QTime().currentTime()))->
            setEndBookingDate(QDateTime(ui->endBookingDate_calendarWidget->selectedDate(), QTime().currentTime()));
    for (auto client : currentClients)
        builder->appendClient(client);
    clients->push(builder->getBooking());
    emit clientCreated();
    this->close();
}

void AppendClientDialog::loadRooms() {
    for (auto room : rooms->getAll())
        if (room->isAvailable())
            ui->comboBox->addItem(room->getNumber());
}

void AppendClientDialog::initShow() {
    rooms = DataBase::getRooms();
    ui->comboBox->blockSignals(true);
    ui->comboBox->clear();
    ui->comboBox->blockSignals(false);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AppendClientDialog::updateForm);
    ui->lineEdit->blockSignals(true);
    ui->lineEdit->clear();
    ui->lineEdit->blockSignals(false);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &AppendClientDialog::updateForm);
    ui->bookingDate_calendarWidget->blockSignals(true);
    ui->bookingDate_calendarWidget->setSelectedDate(QDate::currentDate());
    ui->bookingDate_calendarWidget->blockSignals(false);
    connect(ui->endBookingDate_calendarWidget, &QCalendarWidget::selectionChanged, this, &AppendClientDialog::updateForm);
    ui->endBookingDate_calendarWidget->blockSignals(true);
    ui->endBookingDate_calendarWidget->setSelectedDate(QDate::currentDate().addDays(1));
    ui->endBookingDate_calendarWidget->blockSignals(false);
    connect(ui->bookingDate_calendarWidget, &QCalendarWidget::selectionChanged, this, &AppendClientDialog::updateForm);
    clients = DataBase::getClients();
    this->currentClients.clear();
    ui->save_pushButton->setEnabled(formIsValid());
    loadRooms();
    updateForm();
    this->show();
}

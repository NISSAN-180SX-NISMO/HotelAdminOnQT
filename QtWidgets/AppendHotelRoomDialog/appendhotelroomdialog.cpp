#include <QStringListModel>
#include "appendhotelroomdialog.h"
#include "ui_AppendHotelRoomDialog.h"
#include "QRegularExpressionValidator"
#include "../../Entities/HotelRoom/Builder/HotelRoomBuilder.h"
#include "../../DataBases/HotelRoomDataBase.h"
#include "../../DataBases/DataBase.h"
#include "../../Entities/HotelRoom/Builder/HotelRoomDirector.h"


AppendHotelRoomDialog::AppendHotelRoomDialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::AppendHotelRoomDialog) {
    ui->setupUi(this);

    // Устанавливает формат ввод для номера комнаты - 3-хзначное число
    QRegularExpressionValidator *RoomNumberValidator = new QRegularExpressionValidator(QRegularExpression("[RBL][0-9]{3}"), this);
    ui->number_lineEdit->setValidator(RoomNumberValidator);

    // Установка допустимых значений для количества мест
    ui->seatsCount_spinBox->setMinimum(1);
    ui->seatsCount_spinBox->setMaximum(3);

    // Добавление строк в предлагаемый список доп оборудования
    QStringList equipmentList = {
            "Телевизор",
            "Кровать",
            "Стол письменный",
            "Кресло",
            "Ванная комната",
            "Гардеробная комната",
            "WIFI"
    };
    ui->equipments_comboBox->addItems(equipmentList);

    // Сразу добавляем в комнату кровать
    currentEquipments.append(new Equipments::Bed());

    connect(this, &AppendHotelRoomDialog::dialogChanged, this, &AppendHotelRoomDialog::updateForm);

    // Обновляем вывод списка на форму
    updateQuipmentsListView();
    connect(ui->number_lineEdit, &QLineEdit::textChanged, this, &AppendHotelRoomDialog::dialogChanged);
    connect(ui->seatsCount_spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &AppendHotelRoomDialog::dialogChanged);
    connect(ui->equipments_comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AppendHotelRoomDialog::dialogChanged);
    ui->createRoom_pushButton->setEnabled(false);
}

AppendHotelRoomDialog::~AppendHotelRoomDialog() {
    delete ui;
}

void AppendHotelRoomDialog::on_appendEquipment_pushButton_clicked() {
    addEquipmentToCurrentList(ui->equipments_comboBox->currentText());
    emit dialogChanged();
}

void AppendHotelRoomDialog::addEquipmentToCurrentList(const QString &equipment) {
    if (equipment == "Телевизор")
        currentEquipments.append(new Equipments::TV());
    else if (equipment == "Кровать")
        currentEquipments.append(new Equipments::Bed());
    else if (equipment == "Стол письменный")
        currentEquipments.append(new Equipments::Table());
    else if (equipment == "Кресло")
        currentEquipments.append(new Equipments::Armchair());
    else if (equipment == "Ванная комната")
        currentEquipments.append(new Equipments::Bathroom());
    else if (equipment == "Гардеробная комната")
        currentEquipments.append(new Equipments::DressingRoom());
    else if (equipment == "WIFI")
        currentEquipments.append(new Equipments::WIFI());
}

void AppendHotelRoomDialog::updateQuipmentsListView() {
    QStringListModel *equipmentsModel = new QStringListModel(this);
    QStringList equipmentList;
    for (const auto &equipment : currentEquipments)
        equipmentList << equipment->getInfo();
    equipmentsModel->setStringList(equipmentList);
    ui->equipments_listView->setModel(equipmentsModel);
}

void AppendHotelRoomDialog::updateForm() {
    updateQuipmentsListView();
    ui->createRoom_pushButton->setEnabled(formIsValid());
}

bool AppendHotelRoomDialog::formIsValid() {
   if (ui->number_lineEdit->text().size() != 4) return false;
   return true;
}

void AppendHotelRoomDialog::on_createRoom_pushButton_clicked() {
    HotelRoomDirector director = HotelRoomDirector(ui->number_lineEdit->text());
    HotelRoomBuilder* builder = director.getBuilder()->
            setSeats(ui->seatsCount_spinBox->value());
    for (auto equipment : currentEquipments)
        builder->appendEquipment(equipment);
    this->rooms = DataBase::getRooms();
    rooms->push(builder->getHotelRoom());
    emit roomCreated();
    this->close();
}

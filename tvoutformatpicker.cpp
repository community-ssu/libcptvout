#include "tvoutformatpicker.h"

tvoutFormatPicker::tvoutFormatPicker(QObject *parent) :
    QMaemo5AbstractPickSelector(parent),
    pickerDialog(0)
{
    tvOutFormat = new GConfItem("/system/tvout");
    tvOutFormatsList = new QListWidget();
    QListWidgetItem *palItem = new QListWidgetItem("PAL");
    palItem->setTextAlignment(Qt::AlignCenter);

    QListWidgetItem *ntscItem = new QListWidgetItem("NTSC");
    ntscItem->setTextAlignment(Qt::AlignCenter);

    tvOutFormatsList->addItem(ntscItem);
    tvOutFormatsList->addItem(palItem);

    QString currentFormat = tvOutFormat->value().toString();
    if(currentFormat == "NTSC")
        tvOutFormatsList->setCurrentRow(0);
    else if(currentFormat == "PAL")
        tvOutFormatsList->setCurrentRow(1);
}

tvoutFormatPicker::~tvoutFormatPicker() {}

void tvoutFormatPicker::updateText()
{
    emit selected(this->currentValueText());
    pickerDialog->accept();
}

QString tvoutFormatPicker::currentValueText() const
{
    return tvOutFormatsList->selectedItems().first()->text();
}

QWidget *tvoutFormatPicker::widget(QWidget *parent)
{
    pickerDialog = new QDialog(parent);
    pickerDialog->setWindowTitle("Video format");
    pickerDialog->setMaximumHeight(150);
    QVBoxLayout *layout = new QVBoxLayout(pickerDialog);
    layout->addWidget(tvOutFormatsList);
    connect(tvOutFormatsList, SIGNAL(clicked(QModelIndex)), this, SLOT(updateText()));

    return pickerDialog;
}

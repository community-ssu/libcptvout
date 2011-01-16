#include "tvoutformatpicker.h"

tvoutFormatPicker::tvoutFormatPicker(QObject *parent) :
    QMaemo5AbstractPickSelector(parent),
    pickerDialog(0)
{
    tvOutFormat = new GConfItem("/system/tvout");
    tvOutFormatsList = new QListWidget();
    palItem = new QListWidgetItem(g_dgettext("osso-tv-out", "tvou_va_tv_out_pal"));
    palItem->setData(Qt::UserRole, "PAL");
    palItem->setTextAlignment(Qt::AlignCenter);

    ntscItem = new QListWidgetItem(g_dgettext("osso-tv-out", "tvou_va_tv_out_ntsc"));
    ntscItem->setData(Qt::UserRole, "NTSC");
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
    if(this->currentValueText() == "NTSC")
        emit selected(ntscItem->text());
    else if(this->currentValueText() == "PAL")
        emit selected(palItem->text());
    pickerDialog->accept();
}

QString tvoutFormatPicker::currentValueText() const
{
    return tvOutFormatsList->selectedItems().first()->data(Qt::UserRole).toString();
}

QWidget *tvoutFormatPicker::widget(QWidget *parent)
{
    pickerDialog = new QDialog(parent);
    pickerDialog->setWindowTitle(g_dgettext("osso-tv-out", "tvou_fi_tv_out"));
    pickerDialog->setMaximumHeight(150);
    QVBoxLayout *layout = new QVBoxLayout(pickerDialog);
    layout->addWidget(tvOutFormatsList);
    connect(tvOutFormatsList, SIGNAL(clicked(QModelIndex)), this, SLOT(updateText()));

    return pickerDialog;
}

#include "tvoutdialog.h"
#include "ui_tvoutdialog.h"

tvOutDialog::tvOutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tvOutDialog)
{
    ui->setupUi(this);
    this->setWindowTitle(QString(g_dgettext("osso-tv-out", "tvou_ap_cpa")));
    formatButton = new QMaemo5ValueButton(QString(g_dgettext("osso-tv-out", "tvou_fi_tv_out")), this);
    formatButton->setValueLayout(QMaemo5ValueButton::ValueBesideText);
    formatButton->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));

    tvoutFormat = new GConfItem("/system/tvout");

    formatPicker = new tvoutFormatPicker(this);
    formatButton->setPickSelector(formatPicker);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(formatButton, 0, 1, 0, 1);
    layout->addWidget(ui->saveButton, 0, 2, 0, 1);
}

tvOutDialog::~tvOutDialog()
{
    delete ui;
}

void tvOutDialog::accept()
{
    tvoutFormat->set(formatButton->valueText());
    this->close();
}

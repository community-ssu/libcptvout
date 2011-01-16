#ifndef TVOUTDIALOG_H
#define TVOUTDIALOG_H

#include <QDialog>
#include <QMaemo5ValueButton>
#include <QMaemo5ListPickSelector>
#include <QStandardItemModel>
#include <QGridLayout>
#include <gq/GConfItem>
#include <glib.h>
#include <glib/gi18n.h>

#include "tvoutformatpicker.h"

namespace Ui {
    class tvOutDialog;
}

class tvOutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit tvOutDialog(QWidget *parent = 0);
    ~tvOutDialog();

private:
    Ui::tvOutDialog *ui;
    QMaemo5ValueButton *formatButton;
    tvoutFormatPicker *formatPicker;
    GConfItem *tvoutFormat;

private slots:
    void accept();
};

#endif // TVOUTDIALOG_H

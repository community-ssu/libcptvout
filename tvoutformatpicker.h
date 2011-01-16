#ifndef TVOUTFORMATPICKER_H
#define TVOUTFORMATPICKER_H

#include <QObject>
#include <QListWidget>
#include <QMaemo5AbstractPickSelector>
#include <gq/GConfItem>
#include <QDialog>
#include <QVBoxLayout>
#include <glib.h>
#include <glib/gi18n.h>

class tvoutFormatPicker : public QMaemo5AbstractPickSelector
{
    Q_OBJECT
public:
    explicit tvoutFormatPicker(QObject *parent = 0);
    ~tvoutFormatPicker();
    QString currentValueText() const;

signals:

public slots:

private:
    QListWidget *tvOutFormatsList;
    GConfItem *tvOutFormat;
    QDialog *pickerDialog;
    QWidget *widget(QWidget *parent);
    QListWidgetItem *palItem;
    QListWidgetItem *ntscItem;

private slots:
    void updateText();
};

#endif // TVOUTFORMATPICKER_H

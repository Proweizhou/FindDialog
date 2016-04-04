#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include "qdialog.h"
#include "ui_finddialog.h"

class QCheckBox;
class QLabel;
class QLineEdit;
class QPushButton;

class FindDialog : public QDialog
{
	Q_OBJECT

public:
	FindDialog(QWidget *parent = 0);
	~FindDialog();

signals:
	void findNext(const QString &str, Qt::CaseSensitivity cs);
	void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
	void findClicked();
	void enableFindButton(const QString &text);

private:

	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *matchCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findPushButton;
	QPushButton *closePushButton;
};

#endif // FINDDIALOG_H

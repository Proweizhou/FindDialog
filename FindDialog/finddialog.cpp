#include "finddialog.h"
#include "QtGui"
#include "qlabel.h"
#include "qlineedit.h"
#include "qpushbutton.h"
#include "qcheckbox.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

FindDialog::FindDialog(QWidget *parent)
	: QDialog(parent)
{

	label = new QLabel(tr("Find &what"));
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

	backwardCheckBox = new QCheckBox(tr("Search &back"));
	matchCheckBox = new QCheckBox(tr("Match &case"));
	
	findPushButton = new QPushButton(tr("&Find"));
	closePushButton = new QPushButton(tr("Close"));
	findPushButton->setDefault(true);
	findPushButton->setEnabled(false);

	connect(lineEdit, SIGNAL(textChanged(const QString &)),
		this, SLOT(enableFindButton(const QString &)));
	connect(findPushButton, SIGNAL(clicked()),
		this, SLOT(findClicked()));
	connect(closePushButton, SIGNAL(clicked()),
		this, SLOT(close()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout;
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(matchCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findPushButton);
	rightLayout->addWidget(closePushButton);
	rightLayout->addStretch();

	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);

	setLayout(mainLayout);
	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
}

FindDialog::~FindDialog()
{

}

void FindDialog::findClicked()
{
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = matchCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;

	if (backwardCheckBox->isChecked())
	{
		emit findNext(text, cs);
	}
	else
	{
		emit findPrevious(text, cs);
	}
}

void FindDialog::enableFindButton(const QString &text)
{
	findPushButton->setEnabled(!text.isEmpty());
}


#include "TutorialGUI.h"
#include <qmessagebox.h>
#include "RepoExc.h"
#include "TutorialVal.h"
TutorialGUI::TutorialGUI(Service serv)
    : serv{serv}
{
    ui.setupUi(this);
	this->ui.MainW->hide();
	this->ui.W3->hide();
	this->connectSignalsAndSlots();
    this->popList();
	this->popListU();

}

TutorialGUI::~TutorialGUI()
{}

void TutorialGUI::popList() {
    this->ui.MainL->clear();
    for (Tutorial t : this->serv.ListAll())
        this->ui.MainL->addItem(QString::fromStdString(t.GetTitle() + "---" + t.GetName() + "---" + t.GetDuration() + "---" + to_string(t.GetLikes()) + "---" + t.GetLink()));

}
void TutorialGUI::popListU() {
	this->ui.NextL->clear();
	for (Tutorial t : this->serv.ListAll())
		this->ui.NextL->addItem(QString::fromStdString(t.GetTitle() + "---" + t.GetName() + "---" + t.GetDuration() + "---" + to_string(t.GetLikes()) + "---" + t.GetLink()));

}

void TutorialGUI::connectSignalsAndSlots()
{
	QObject::connect(this->ui.Back1, &QPushButton::clicked, [this]() {
		this->ui.MainW->hide();
		this->ui.FirstW->show();

		});
	QObject::connect(this->ui.AdminB, &QPushButton::clicked, [this]() {
		   this->ui.FirstW->hide();
		   this->ui.MainW->show();

		});
	QObject::connect(this->ui.FilterB, &QPushButton::clicked, [this]() {
		    this->ui.FilterList->clear();
			string name = this->ui.NameEdit->text().toStdString();
			for (Tutorial t : this->serv.Filter(name))
				this->ui.FilterList->addItem(QString::fromStdString(t.GetTitle() + "---" + t.GetName() + "---" + t.GetDuration() + "---" + to_string(t.GetLikes()) + "---" + t.GetLink()));

		});
	QObject::connect(this->ui.UserB, &QPushButton::clicked, [this]() {
		this->ui.FirstW->hide();
		this->ui.W3->show();

		});
	QObject::connect(this->ui.Back2, &QPushButton::clicked, [this]() {
		this->ui.W3->hide();
		this->ui.FirstW->show();

		});
	QObject::connect(this->ui.MainL, &QListWidget::clicked, [this]() {
		int selectedIndex = getSelectedIndex();
		Tutorial t = serv.ListAll()[selectedIndex];
		this->ui.TtitleEdit->setText(QString::fromStdString(t.GetTitle()));
		this->ui.NameEdit->setText(QString::fromStdString(t.GetName()));
		this->ui.DurationEdit->setText(QString::fromStdString(t.GetDuration()));
		this->ui.LikesEdit->setText(QString::fromStdString(to_string(t.GetLikes())));
		this->ui.LinkEdit->setText(QString::fromStdString(t.GetLink()));
		});
	QObject::connect(this->ui.NextL, &QListWidget::clicked, [this]() {
		int selectedIndex = getSelectedIndexU();
		Tutorial t = serv.ListAll()[selectedIndex];
		this->serv.addToList(t);
		this->ui.TutWatchList->clear();
		this->ui.TutWatchList->addItem(QString::fromStdString(t.GetTitle() + "---" + t.GetName() + "---" + t.GetDuration() + "---" + to_string(t.GetLikes()) + "---" + t.GetLink()));
		QObject::connect(this->ui.UpdLBU, &QPushButton::clicked, [this]() {
			int selectedIndex = getSelectedIndexU();
			Tutorial t = serv.ListAll()[selectedIndex];
			string title = t.GetTitle();
			string name = t.GetName();
			this->serv.updateLikes(title, name);
			this->ui.TutWatchList->clear();
			this->ui.TutWatchList->addItem(QString::fromStdString(t.GetTitle() + "---" + t.GetName() + "---" + t.GetDuration() + "---" + to_string(t.GetLikes()) + "---" + t.GetLink()));
			});
		});

	QObject::connect(this->ui.AddB, &QPushButton::clicked, this, &TutorialGUI::addTutorialGUI);
	QObject::connect(this->ui.DeleteB, &QPushButton::clicked, this, &TutorialGUI::deleteTutorialGUI);
	QObject::connect(this->ui.UpdateB, &QPushButton::clicked, this, &TutorialGUI::updateTutorialGUI);
	QObject::connect(this->ui.NextBU, &QPushButton::clicked, this, &TutorialGUI::NextTutorialGUI);
	QObject::connect(this->ui.SaveBU, &QPushButton::clicked, [this]() {
		this->serv.SaveTutoList();
		});;
}


int TutorialGUI::getSelectedIndex()
{
	QModelIndexList indexList = this->ui.MainL->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
		return -1;
	return indexList[0].row();
}
int TutorialGUI::getSelectedIndexU()
{
	QModelIndexList indexList = this->ui.NextL->selectionModel()->selectedIndexes();
	if (indexList.size() == 0)
		return -1;
	return indexList[0].row();
}

void TutorialGUI::addTutorialGUI() {
	string title = this->ui.TtitleEdit->text().toStdString();
	string name = this->ui.NameEdit->text().toStdString();
	string duration = this->ui.DurationEdit->text().toStdString();
	string n = this->ui.LikesEdit->text().toStdString();
	int likes = stoi(n);
	string link = this->ui.LinkEdit->text().toStdString();
	try {
		serv.addTutorial(title, name, duration, likes, link);
	}
	catch (TutorialExc& ex) {
		QMessageBox::critical(this, "Error", QString::fromStdString(ex.GetErr()[0]));
	}
	catch (DuplicateSongException& ex) {
		QMessageBox::critical(this, "Error", QString::fromStdString(ex.what()));
	}

	this->popList();
}

void TutorialGUI::deleteTutorialGUI() {
	int index = getSelectedIndex();
	if (index == -1)
	{
		QMessageBox::critical(this, "Error", "No song selected!");
		return;
	}
	Tutorial t=serv.ListAll()[index];
	this->serv.removeTutorial(t.GetTitle(),t.GetName());
	this->popList();
}

void TutorialGUI::updateTutorialGUI() {
	int index = getSelectedIndex();
	if (index == -1)
	{
		QMessageBox::critical(this, "Error", "No song selected!");
		return;
	}
	string title = this->ui.TtitleEdit->text().toStdString();
	string name = this->ui.NameEdit->text().toStdString();
	string newDur = this->ui.NewDurEdit->text().toStdString();
	string N = this->ui.NewLikesEdit->text().toStdString();
	int newLikes = stoi(N);
	string NewLink = this->ui.NewLinkEdit->text().toStdString();
	this->serv.updateTutorial(title, name, newDur, newLikes, NewLink);
	this->popList();
}

void TutorialGUI::NextTutorialGUI()
{
	this->ui.TutWatchList->clear();
	this->serv.nextTutorial();
	Tutorial t = this->serv.getList()->GetCurrent();
	this->ui.TutWatchList->addItem(QString::fromStdString(t.GetTitle() + "---" + t.GetName() + "---" + t.GetDuration() + "---" + to_string(t.GetLikes()) + "---" + t.GetLink()));

}
#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TutorialGUI.h"
#include "Service.h"
class TutorialGUI : public QMainWindow
{
private:
    Service serv;

public:
    TutorialGUI(Service serv);
    ~TutorialGUI();
    void popList();
    void connectSignalsAndSlots();
    int getSelectedIndex();
    void addTutorialGUI();
    void deleteTutorialGUI();
    void updateTutorialGUI();
    void NextTutorialGUI();
    void popListU();
    int getSelectedIndexU();
private:
    Ui::TutorialGUIClass ui;
};

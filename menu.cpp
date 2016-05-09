#include <iostream>
#include "menu.h"

using namespace std;

void Menu::execute() {
    if(history.at(history_index)->evaluate() != 0) {
        this->execute();
    }
    else {
        cout << "0" << endl;
    }
}

bool Menu::initialized() {
    if(history.at(0)->evaluate() != 0) {
        return true;
    }
    else {
        return false;
    }
}

void Menu::add_command(Command* c) {
    if(history_index == history.size() - 1) {
        history.push_back(c);
        ++history_index;
    }
    else {
        Command* temp = history.at(history.size() - 1);
        for(int i = history.size() - 2; i > history_index + 1; i--) {
            history.at(i) = history.at(i + 1);
        }
        history.push_back(temp);
        history.at(history_index + 1) = c;
        ++history_index;
    }
}

Command* Menu::get_command() {
    return history.at(history_index);
    ++history_index;
}

void Menu::undo() {
    if(history_index != 0) {
        --history_index;
    }
}

void Menu::redo() {
    if(history_index + 1 < history.size()) {
        ++history_index;
    }
    history.at(history_index)->execute();
}
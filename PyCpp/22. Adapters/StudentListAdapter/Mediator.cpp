<<<<<<< HEAD
#include "Mediator.h"

//resets the listboxes and reloads the left box
void Mediator::reset() {
    wxString studnames[6] = { "Anne Green", "Barry Pye", 
        "Charlie Horse", "Darren Steal",
       "Evan Essent", "Bjorn Stroustrup" };
    listbox->Clear();
    advListBox->Clear();
    students.clear();
    advStudents.clear();

    for (int i = 0; i < 6; i++) {
        listbox->append(new Student(studnames[i]));
    }
}

//The Mediator mediates listbox and button click events 
    Mediator::Mediator(wxFrame* gframe, StudentList* glist, StudentList* advlist) {
        listbox = glist;
        advListBox = advlist;
        frame = gframe;     
        reset();
    }
    
    //left list box click comes here. 
    void Mediator::onListClick(wxCommandEvent& event) {    
        moveButton->Enable();
        restoreButton->Disable();
    }

    //right list box click comes here. 
    void Mediator::advListClick(wxCommandEvent& event) {
        int index = advListBox->GetSelection();
        moveButton->Disable();
        restoreButton->Enable();
        advListBox->Refresh();
    }
    
    //copy in button references
    void Mediator::setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clb) {
        restoreButton = rsb;
        moveButton = mvb;
        clearButton = clb;
        restoreButton->Disable();
        moveButton->Disable();
    }

    void Mediator::redraw() {       
        listbox->redraw();
        advListBox->redraw();    
    }
    //clicks on each of 3 buttons
    //move name to right
    void Mediator::moveClick() {
        int index = listbox->GetSelection(); 
        Student* stud = listbox->getSelected();       
        advListBox->append(stud);
        moveButton->Disable();  //disable until listbox clicked
        listbox->remove(index);
        redraw();
    }

    //move name to left
    void Mediator::restoreClick() {
        int index = advListBox->GetSelection();
        Student* stud = advListBox->getSelected();
        listbox->append(stud);
        advListBox->remove(index);
        restoreButton->Disable();   //disable restore button
        redraw();
    }

    //reset button states and reload list
    void Mediator::clearClick() {
        reset();
    }

=======
#include "Mediator.h"

//resets the listboxes and reloads the left box
void Mediator::reset() {
    wxString studnames[6] = { "Anne Green", "Barry Pye", 
        "Charlie Horse", "Darren Steal",
       "Evan Essent", "Bjorn Stroustrup" };
    listbox->Clear();
    advListBox->Clear();
    students.clear();
    advStudents.clear();

    for (int i = 0; i < 6; i++) {
        listbox->append(new Student(studnames[i]));
    }
}

//The Mediator mediates listbox and button click events 
    Mediator::Mediator(wxFrame* gframe, StudentList* glist, StudentList* advlist) {
        listbox = glist;
        advListBox = advlist;
        frame = gframe;     
        reset();
    }
    
    //left list box click comes here. 
    void Mediator::onListClick(wxCommandEvent& event) {    
        moveButton->Enable();
        restoreButton->Disable();
    }

    //right list box click comes here. 
    void Mediator::advListClick(wxCommandEvent& event) {
        int index = advListBox->GetSelection();
        moveButton->Disable();
        restoreButton->Enable();
        advListBox->Refresh();
    }
    
    //copy in button references
    void Mediator::setButtons(MoveButton* mvb, RestoreButton* rsb, ClearButton* clb) {
        restoreButton = rsb;
        moveButton = mvb;
        clearButton = clb;
        restoreButton->Disable();
        moveButton->Disable();
    }

    void Mediator::redraw() {       
        listbox->redraw();
        advListBox->redraw();    
    }
    //clicks on each of 3 buttons
    //move name to right
    void Mediator::moveClick() {
        int index = listbox->GetSelection(); 
        Student* stud = listbox->getSelected();       
        advListBox->append(stud);
        moveButton->Disable();  //disable until listbox clicked
        listbox->remove(index);
        redraw();
    }

    //move name to left
    void Mediator::restoreClick() {
        int index = advListBox->GetSelection();
        Student* stud = advListBox->getSelected();
        listbox->append(stud);
        advListBox->remove(index);
        restoreButton->Disable();   //disable restore button
        redraw();
    }

    //reset button states and reload list
    void Mediator::clearClick() {
        reset();
    }

>>>>>>> 788375d648c18c4339961a2476115e1a0e78bd31

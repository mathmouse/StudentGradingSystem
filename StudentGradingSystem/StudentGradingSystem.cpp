#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//*** Structure Definitions ***
struct student
{
    string firstName = "";   //holds student's first name
    string lastName = "";    //holds student's last name
    string recordNumber = "";    //holds student's record number
    string grade1 = "";  //holds grades
    string grade2 = "";
    string grade3 = "";
    string grade4 = "";
    string grade5 = "";
    string grade6 = "";
    double gradeAve = 0;    //holds grade average
    string letterGrade = ""; //holds final letter grade
};

struct studentNode
{
    student newStudent; //student structure 
    studentNode* next = NULL;   //pointer to the next node in the list
};
//*** End of Structure Definitions ***

//*** Start Prototypes ***

// Graphics and Miscellaneous
void titleScreen();
void errorScreen();
void inputScreenGraphic();
void editScreenGraphic();
void exitScreen();
void transition();

// Handle data structures
void menuScreen(studentNode *head);
studentNode* studentMenu(studentNode* head);
studentNode* populateList(studentNode *head);
void studentSearch(studentNode *head);
student inputScreen(void);
void outputScreen(student newStudent);
student editScreen(student newStudent);
void sort(studentNode* head);
studentNode* swap(studentNode* p1, studentNode* p2);
void tableOutputScreen(studentNode* head);
void printTable(studentNode* head);

//*** End Prototypes ***

/***********************************************************

Function name: main()
Purpose: Display title screen and main menu

 ***********************************************************/
int main()
{
    studentNode *head = NULL;
   
    //*** Begin Splash Screen ***
    titleScreen();
    //*** End Splash Screen ***

    //*** Begin Main Menu Screen ***
    menuScreen(head);
    //*** End Main Menu Screen ***

    return 0;

}   //end of main()


/***********************************************************

Function name: menuScreen()
Purpose: Allow user to access the secondary menu, sort and print
    the student array, or leave the program

 ***********************************************************/
void menuScreen(studentNode *head)
{
    string response = "";   //hold user menu choice
    studentNode* temp;  //temporary node to assign new head of the list

    do
    {
        cout << "                         ______________________________                         \n";
        cout << "                        | [Version         05/14/2024] |                        \n";
        cout << "                        |______________________________|                        \n";
        cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
        cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
        cout << "                        |______________________________|                        \n";
        cout << "                        |          MAIN  MENU          |                        \n";
        cout << "       _________________|______________________________|__________________      \n";
        cout << "      |   <S>TUDENT MANAGEMENT    |   <P>RINT   |   SO<R>T   |   <E>XIT   |     \n";
        cout << "      |___________________________|_____________|____________|____________|     \n";
        cout << endl;
        cout << " What would you like to do?" << endl;
        cout << " Type S - P - E: "; getline(cin, response);

        while (response.empty())    //handle an empty response
        {
            errorScreen();
            cout << "Please enter a valid answer: "; getline(cin, response);
            transition();

        }   //end of while (response.empty())

        switch (response.at(0)) //check character at position 0 to start, edit, print or exit
        {
        case 'S':
        case 's':
            system("CLS");
            temp = studentMenu(head);
            head = temp;    //new head of the list
            break;

        case 'E':
        case 'e':
            system("CLS");
            exitScreen();
            break;

        case 'P':
        case 'p':
            system("CLS");
            tableOutputScreen(head);
            break;

        case 'R':
        case 'r':
            system("CLS");
            sort(head);
            break;

        default:
            system("CLS");
            errorScreen();
            transition();

        }   //end of switch (response.at(0))

    } while ((response.at(0) != 'E') && (response.at(0) != 'e'));

}   //end of void menuScreen(studentNode *head)


/***********************************************************

Function name: studentMenu()
Purpose: allow user to input new students, search between exising
    students and edit values, or return to the main menu

 ***********************************************************/
studentNode* studentMenu(studentNode *head)
{
    string response = "";   //hold user menu choice
    studentNode* temp;  //temporary node to assign new head of the list

    do
    {
        cout << "                         ______________________________                         \n";
        cout << "                        | [Version         05/14/2024] |                        \n";
        cout << "                        |______________________________|                        \n";
        cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
        cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
        cout << "                        |______________________________|                        \n";
        cout << "                        |   STUDENT MANAGEMENT MENU    |                        \n";
        cout << "       _________________|______________________________|_________________       \n";
        cout << "      |   <N>EW STUDENT RECORD      |   <S>EARCH and EDIT   |   <E>XIT   |      \n";
        cout << "      |_____________________________|_______________________|____________|      \n";
        cout << endl;
        cout << " What would you like to do?" << endl;
        cout << " Type N - S - E: "; getline(cin, response);

        while (response.empty())    //handle an empty response
        {
            errorScreen();
            cout << "Please enter a valid answer: "; getline(cin, response);
            transition();
        }   //end of while (response.empty())

        switch (response.at(0))
        {
        case 'N':
        case 'n':
            system("CLS");
            temp = populateList(head);
            head = temp;    //new head of the list
            break;

        case 'S':
        case 's':
            system("CLS");
            studentSearch(head);
            break;

        case 'E':
        case 'e':
            system("CLS");
            break;

        default:
            system("CLS");
            errorScreen();
            transition();

        }   //end of switch (response.at(0))

    } while ((response.at(0) != 'E') && (response.at(0) != 'e'));

    return head;    //return head for main menu functionality

}   //end of studentNode* studentMenu(studentNode *head)


/***********************************************************

Function name: populate Array()
Purpose: wrap function to add new students into the student array

 ***********************************************************/
studentNode* populateList(studentNode *head)
{
    string response = "";
    studentNode* p = NULL;  //temporary node for list creation
    studentNode* q = NULL;  //temporary node for list creation

    do
    {
        system("CLS");

        //create the head node
        head = new studentNode;
        p = head;
        student add = inputScreen();
        p->newStudent = add;
        p->next = NULL;

        system("CLS");
        inputScreenGraphic();
        cout << " Do you want to add another Student Record?" << endl;
        cout << " <Y>es or <N>o: "; getline(cin, response);
        system("CLS");

        while (response.empty())    //handle an empty response
        {
            errorScreen();
            cout << "Please enter a valid answer: "; getline(cin, response);
            transition();
        }   //end of while (response.empty())

        while (response.at(0) == 'Y' || response.at(0) == 'y') //add new students
        {
            system("CLS");

            //create a new node
            q = new studentNode;
            student add = inputScreen();
            q->newStudent = add;
            q->next = NULL;
            p->next = q;
            p = p->next;

            system("CLS");
            inputScreenGraphic();
            cout << " Do you want to add another Student Record?" << endl;
            cout << " <Y>es or <N>o: "; getline(cin, response);
            system("CLS");

        }   //end of while (response.at(0) == 'Y' || response.at(0) == 'y')

    } while (response.at(0) != 'N' && response.at(0) != 'n');

    return head;    //return head for student menu functionality

}   //end of studentNode* populateList(studentNode *head)


/***********************************************************

Function name: inputScreen()
Purpose: Allow user to input data for newStudent

 ***********************************************************/
student inputScreen(void)
{
    student newStudent = { "No Data", "No Data" , "No Data" , "0" , "0" , "0" , "0" , "0" , "0" , 0, "0" };

    inputScreenGraphic();

    //Requesting student information
    cout << " Enter Student First Name: "; getline(cin, newStudent.firstName);
    cout << " Enter Student Last Name: "; getline(cin, newStudent.lastName);
    cout << " Enter Student Record Number: "; getline(cin, newStudent.recordNumber);
    while (newStudent.recordNumber.empty() || !isdigit(newStudent.recordNumber.at(0)))  //check character at position 0 is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.recordNumber);
        system("CLS");
        inputScreenGraphic();
    }   //end of while(newStudent.recordNumber.empty() || !isdigit(recordNumber.at(0)))
    cout << endl;

    //Requesting student grades
    cout << " Enter Grade 1: "; getline(cin, newStudent.grade1);
    while (newStudent.grade1.empty() || !isdigit(newStudent.grade1.at(0)))    //check character is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade1);
        system("CLS");
        inputScreenGraphic();
    }   //end of while((newStudent.grade1.empty() || !isdigit(grade1.at(0)))

    cout << " Enter Grade 2: "; getline(cin, newStudent.grade2);
    while (newStudent.grade2.empty() || !isdigit(newStudent.grade2.at(0)))    //check character is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade2);
        system("CLS");
        inputScreenGraphic();
    }   //end of while((newStudent.grade2.empty() || !isdigit(grade2.at(0)))

    cout << " Enter Grade 3: "; getline(cin, newStudent.grade3);
    while (newStudent.grade3.empty() || !isdigit(newStudent.grade3.at(0)))    //check character is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade3);
        system("CLS");
        inputScreenGraphic();
    }   //end of while((newStudent.grade3.empty() || !isdigit(grade3.at(0)))

    cout << " Enter Grade 4: "; getline(cin, newStudent.grade4);
    while (newStudent.grade4.empty() || !isdigit(newStudent.grade4.at(0)))    //check character is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade4);
        system("CLS");
        inputScreenGraphic();
    }   //end of while((newStudent.grade4.empty() || !isdigit(grade4.at(0)))

    cout << " Enter Grade 5: "; getline(cin, newStudent.grade5);
    while (newStudent.grade5.empty() || !isdigit(newStudent.grade5.at(0)))    //check character is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade5);
        system("CLS");
        inputScreenGraphic();
    }   //end of while((newStudent.grade5.empty() || !isdigit(grade5.at(0)))

    cout << " Enter Grade 6: "; getline(cin, newStudent.grade6);
    while (newStudent.grade6.empty() || !isdigit(newStudent.grade6.at(0)))    //check character is a number and not empty
    {
        errorScreen(); 
        cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade6);
        system("CLS");
        inputScreenGraphic();
    }   //end of while((newStudent.grade6.empty() || !isdigit(grade6.at(0)))
    cout << endl;

    //*** CALCULATING GRADE AVERAGE AND LETTER GRADE ***

    //Converting string grades into doubles
    double g1 = stod(newStudent.grade1);
    double g2 = stod(newStudent.grade2);
    double g3 = stod(newStudent.grade3);
    double g4 = stod(newStudent.grade4);
    double g5 = stod(newStudent.grade5);
    double g6 = stod(newStudent.grade6);

    //Calculating the grade average
    double gradeAve = (g1 + g2 + g3 + g4 + g5 + g6) / 6;
    newStudent.gradeAve = gradeAve;

    //If Else statement to assign letter grade based on average
    if (gradeAve >= 89.9) {
        newStudent.letterGrade = "A";
    }   //Assigns A for average bigger or equal to 89.9
    else if (gradeAve >= 79.9) {
        newStudent.letterGrade = "B";
    }   //Assigns B for average bigger or equal to 79.9
    else if (gradeAve >= 69.9) {
        newStudent.letterGrade = "C";
    }   //Assigns C for average bigger or equal to 69.9
    else if (gradeAve >= 59.9) {
        newStudent.letterGrade = "D";
    }   //Assigns D for average bigger or equal to 59.9
    else {
        newStudent.letterGrade = "F";
    }   //Assigns F for all other averages

    //*** END CALCULATING GRADE AVERAGE AND LETTER GRADE ***

    cout << endl;

    transition();

    return newStudent;

}   //end of student inputScreen()


/***********************************************************

Function name: inputScreenGraphic()
Purpose: Display the Input Screen graphic when necessary

 ***********************************************************/
void inputScreenGraphic(void)
{
    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
    cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |        INPUT   SCREEN        |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;
}   //end of void inputScreenGraphic()


/***********************************************************

Function name: studentSearch()
Purpose: allow user to search between existing students

 ***********************************************************/
void studentSearch(studentNode *head)  
{
    string response = "";
    string edit = "";
    studentNode* current = head;    //node used to print the list
    
    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
    cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |        SEARCH  SCREEN        |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;
    cout << " Current Students:" << endl;
    cout << endl;

    //Display student list for user selection
    while (current != NULL)
    {
        cout << " " << current->newStudent.lastName << ", " << current->newStudent.recordNumber << endl;
        current = current->next;
    }   //end of while (current != NULL)

    cout << endl;
    cout << " Which student would you like to view? " << endl;
    cout << " Please enter the Last Name or Record Number: "; getline(cin, response);

    while (response.empty())    //handle an empty response
    {
        errorScreen();
        cout << "Please enter a valid answer: "; getline(cin, response);
        transition();
    }   //end of while (response.empty())

    //reinitialize to go back to the beginning of the list
    current = head;

    while (current != NULL)
    {
        if (current->newStudent.recordNumber == response || current->newStudent.lastName == response)
        {
            system("CLS");
            outputScreen(current->newStudent);   //display the student's information
            cout << " Would you like to edit this student's information?" << endl;
            cout << " Y or N: "; getline(cin, edit);

            while (edit.empty())    //handle an empty response
            {
                errorScreen();
                cout << "Please enter a valid answer: "; getline(cin, response);
                transition();
            }   //end of while (edit.empty())

            switch (edit.at(0))
            {
            case 'Y':
            case 'y':
                system("CLS");
                current->newStudent = editScreen(current->newStudent);  //edit the chosen student
                break;

            case 'N':
            case 'n':
                transition();
                break;

            default:
                errorScreen();
                transition();
                break;

            }   //end of switch (edit.at(0))

            break;

        }   //end of if (current->newStudent.recordNumber == response || current->newStudent.lastName == response)

        current = current->next;    //move along the list

    }   //end of while (current != NULL)

    //display error screen if the student is not found
    //errorScreen();
    // cout << " Student not found!" << endl;
    //transition();

}   //end of void studentSearch(studentNode *head) 

/***********************************************************

Function name: editScreen()
Purpose: Display the student details and grades, to allow user
    to choose what details to edit

 ***********************************************************/
student editScreen(student newStudent)
{
    string responseM;
    string responseG;
    
    editScreenGraphic();
    cout << " 1) First Name: " << newStudent.firstName << endl;
    cout << " 2) Last Name: " << newStudent.lastName << endl;
    cout << " 3) Record Number: " << newStudent.recordNumber << endl;
    cout << " 4) Grades : " << newStudent.grade1 << ", " << newStudent.grade2 << ", " << newStudent.grade3
        << ", " << newStudent.grade4 << ", " << newStudent.grade5 << ", " << newStudent.grade6 << endl;
    cout << endl;
    cout << " What would you like to edit?" << endl;
    cout << " Enter 1 - 2 - 3 - 4: "; getline(cin, responseM);

    while (responseM.empty()) //handle empty response
    {
        errorScreen();
        cout << "Please enter a valid answer: "; getline(cin, responseM);
    }   //end of while (response.empty())

    switch (responseM.at(0))  //check character at position 0 for what student detail to edit
    {
    case '1':
        system("CLS");
        editScreenGraphic();
        cout << " Enter new First Name: "; getline(cin, newStudent.firstName);
        transition();
        break;

    case '2':
        system("CLS");
        editScreenGraphic();
        cout << " Enter new Last Name: "; getline(cin, newStudent.lastName);
        transition();
        break;

    case '3':
        system("CLS");
        editScreenGraphic();
        cout << " Enter new Record Number: "; getline(cin, newStudent.recordNumber);
        while (newStudent.recordNumber.empty() || !isdigit(newStudent.recordNumber.at(0)))  //check not empty and is digit
        {
            errorScreen();
            cout << " Enter a Numeric Value: "; getline(cin, newStudent.recordNumber);
            system("CLS");
        }   //end of while(newStudent.recordNumber.empty() || !isdigit(recordNumber.at(0)))
        transition();
        break;

    case '4':
        system("CLS");
        editScreenGraphic();
        cout << " Grade 1: " << newStudent.grade1 << endl;
        cout << " Grade 2: " << newStudent.grade2 << endl;
        cout << " Grade 3: " << newStudent.grade3 << endl;
        cout << " Grade 4: " << newStudent.grade4 << endl;
        cout << " Grade 5: " << newStudent.grade5 << endl;
        cout << " Grade 6: " << newStudent.grade6 << endl;
        cout << " What grade would you like to change: " << endl;
        cout << " Enter 1 - 2 - 3 - 4 - 5 - 6: "; getline(cin, responseG);

        while (responseG.empty()) //handle empty response
        {
            errorScreen();
            cout << "Please enter a valid answer: "; getline(cin, responseG);
        }   //end of while (responseG.empty())

        switch (responseG.at(0))    //separate switch to choose between grades to edit
        {
        case '1':
            system("CLS");
            editScreenGraphic();
            cout << " Enter grade 1: "; getline(cin, newStudent.grade1);
            while (newStudent.grade1.empty() || !isdigit(newStudent.grade1.at(0)))    //check grade is a digit and not empty
            {
                errorScreen();
                cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade1);
                system("CLS");
            }   //end of while((newStudent.grade1.empty() || !isdigit(grade1.at(0)))
            transition();
            break;

        case '2':
            system("CLS");
            editScreenGraphic();
            cout << " Enter grade 2: "; getline(cin, newStudent.grade2);
            while (newStudent.grade2.empty() || !isdigit(newStudent.grade2.at(0)))    //check grade is a digit and not empty
            {
                errorScreen();
                cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade2);
                system("CLS");
            }   //end of while((newStudent.grade2.empty() || !isdigit(grade2.at(0)))
            transition();
            break;

        case '3':
            system("CLS");
            editScreenGraphic();
            cout << " Enter grade 3: "; getline(cin, newStudent.grade3);
            while (newStudent.grade3.empty() || !isdigit(newStudent.grade3.at(0)))    //check grade is a digit and not empty
            {
                errorScreen();
                cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade3);
                system("CLS");
            }   //end of while((newStudent.grade3.empty() || !isdigit(grade3.at(0)))
            transition();
            break;

        case '4':
            system("CLS");
            editScreenGraphic();
            cout << " Enter grade 4: "; getline(cin, newStudent.grade4);
            while (newStudent.grade4.empty() || !isdigit(newStudent.grade4.at(0)))    //check grade is a digit and not empty
            {
                errorScreen();
                cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade4);
                system("CLS");
            }   //end of while((newStudent.grade4.empty() || !isdigit(grade4.at(0)))
            transition();
            break;

        case '5':
            system("CLS");
            editScreenGraphic();
            cout << " Enter grade 5: "; getline(cin, newStudent.grade5);
            while (newStudent.grade5.empty() || !isdigit(newStudent.grade5.at(0)))    //check grade is a digit and not empty
            {
                errorScreen();
                cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade5);
                system("CLS");
            }   //end of while((newStudent.grade5.empty() || !isdigit(grade5.at(0)))
            transition();
            break;

        case '6':
            system("CLS");
            editScreenGraphic();
            cout << " Enter grade 6: "; getline(cin, newStudent.grade6);
            while (newStudent.grade6.empty() || !isdigit(newStudent.grade6.at(0)))    //check grade is a digit and not empty
            {
                errorScreen();
                cout << " Enter a Numeric Value: "; getline(cin, newStudent.grade6);
                system("CLS");
            }   //end of while((newStudent.grade6.empty() || !isdigit(grade6.at(0)))
            transition();
            break;

        default:
            system("CLS");
            errorScreen();
            transition();
            break;
        }   //end of switch (responseG.at(0))
        break;

    default:
        system("CLS");
        errorScreen();
        transition();
        break;
    } //end of switch (responseEdit.at(0))

    return newStudent;

}   //end of student editScreen(student newStudent)


/***********************************************************

Function name: editScreenGraphic()
Purpose: Display the edit screen graphic when necessary

 ***********************************************************/
void editScreenGraphic()
{
    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
    cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |         EDIT  SCREEN         |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;
}   //end of void editScreenGraphic()


/***********************************************************

Function name: outputScreen()
Purpose: Display the student details, grade, average and
    final letter grade

 ***********************************************************/
void outputScreen(student newStudent)
{
    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
    cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       OUTPUT   SCREEN        |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;
    cout << endl;

    //Displaying student information and grades
    cout << " Student First Name: " << newStudent.firstName << endl;
    cout << " Student Last Name: " << newStudent.lastName << endl;
    cout << " Student Record Number: " << newStudent.recordNumber << endl;
    cout << endl;
    cout << " Grade 1: " << newStudent.grade1 << endl;
    cout << " Grade 2: " << newStudent.grade2 << endl;
    cout << " Grade 3: " << newStudent.grade3 << endl;
    cout << " Grade 4: " << newStudent.grade4 << endl;
    cout << " Grade 5: " << newStudent.grade5 << endl;
    cout << " Grade 6: " << newStudent.grade6 << endl;
    cout << endl;

    //Displaying grade average and final letter grade
    cout << " Grade Average: " << setprecision(2) << fixed << newStudent.gradeAve << endl; //setprecision to display only 2 decimals
    cout << " Final Grade: " << newStudent.letterGrade << endl;
    cout << endl;

}   //end of void outputScreen(student newStudent)


/***********************************************************

Function name: sort()
Purpose: Sort list alphabetically or by record number, then
    send the sorted list to be displayed in a table

 ***********************************************************/
void sort(studentNode* head)
{
    string response = "";   //holds user response
    int counter = 0;
    int i = 0;  //int to allow for sorting
    int j = 0;  //int to allow for sorting
    student newStudent; //temporary

    studentNode* current;
    current = head;

    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
    cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |     TABLE OUTPUT SCREEN      |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;

    cout << " Would you like to sort Alphabetically or by Record Number?" << endl;
    cout << " Please enter <A>lphabetically or <R>ecord Number: "; getline(cin, response);

    while (response.empty())    //handle an empty response
    {
        errorScreen();
        cout << "Please enter a valid answer: "; getline(cin, response);
        transition();
    }   //end of while (response.empty())

    switch (response.at(0)) //switch between different sorting options
    {

    case 'A':
    case 'a':
        //sort alphabetically
        while (current != NULL)
        {
            studentNode* p1 = current;
            studentNode* p2 = p1->next;
            if (p1->newStudent.lastName > p1->newStudent.lastName)
            {
                current = swap(p1, p2);
            }

            current = current->next;
        }

        system("CLS");
        //find a way to reinitialize new head of the list after swapping
        tableOutputScreen(head); //display student array in a table
        break;
        
    case 'R':
    case 'r':
        //sort by record number
        while (current != NULL)
        {
            studentNode* p1 = current;
            studentNode* p2 = p1->next;
            if (p1->newStudent.recordNumber > p1->newStudent.recordNumber)
            {
                current = swap(p1, p2);
            }

            current = current->next;
        }

        system("CLS");
        //find a way to reinitialize new head of the list after swapping
        tableOutputScreen(head); //display student array in a table
        break;

    default:
        errorScreen();
        transition();
        break;

    }   //end of switch (response.at(0))

}   //end of void sort(studentNode* head)


/***********************************************************

Function name: swap()
Purpose: Swap two nodes

 ***********************************************************/
studentNode* swap(studentNode* p1, studentNode* p2)
{
    studentNode* temp = p2->next;
    p1->next = temp;
    p2->next = p1;
    return p2;
}   //end of studentNode* swap(studentNode* p1, studentNode* p2)

/***********************************************************

Function name: tableOutputScreen()
Purpose: display student array in a table and allow for user to print it

 ***********************************************************/
void tableOutputScreen(studentNode* head)
{
    string response = "";
    studentNode* current = head;

    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |       MIRAMAR  COLLEGE       |                        \n";
    cout << "                        |   STUDENT  GRADING  SYSTEM   |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << "                        |     TABLE OUTPUT SCREEN      |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;

    while (current != NULL)
    {
        student s = current->newStudent;
        cout << " " << s.lastName << ", " << s.firstName << " - " << s.recordNumber << " | " << s.gradeAve << " " << s.letterGrade << endl;
        current = current->next;
    }   //end of while (current != NULL)

    cout << endl;
    cout << " Would you like to print this screen?" << endl;
    cout << " <Y>es or <N>o: "; getline(cin, response);

    while (response.empty())    //handle an empty response
    {
        errorScreen();
        cout << "Please enter a valid answer: "; getline(cin, response);
        transition();

    }   //end of while (response.empty())

    if (response.at(0) == 'Y' || response.at(0) == 'y')
    {
        printTable(head);
        transition();

    }   //end of if (response.at(0) == 'Y' || response.at(0) == 'y')

    else
    {
        transition();
    }   //end of else

}   //end of void tableOutputScreen(studentNode* head)


/***********************************************************

Function name: print()
Purpose: save to file the sorted student table

 ***********************************************************/
void printTable(studentNode* head)
{
    ofstream ofile;
    studentNode* current = head;
    
    ofile.open("newStudent.prn");   //opening the file

    while (current != NULL)
    {
        student s = current->newStudent;
        ofile << " " << s.lastName << ", " << s.firstName << " - " << s.recordNumber << " | " << s.gradeAve << " " << s.letterGrade << endl;
        current = current->next;
    }   //end of while (current != NULL)

    ofile.close(); //closing the file

    cout << " A copy has been saved to file." << endl;

}   //end of void printTable(studentNode* head)

/***********************************************************

Function name: transition()
Purpose: Display prompt to transition to next screen

 ***********************************************************/
void transition()
{
    string response = "";
    cout << "                          Press  <ENTER>  to  Continue"; getline(cin, response);
    system("CLS");

}   //end of void transition()


/***********************************************************

Function name: titleScreen()
Purpose: Display the Title Screen graphic

 ***********************************************************/
void titleScreen(void)
{
    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |  __________________________  |                        \n";
    cout << "                        | |                          | |                        \n";
    cout << "                        | |     MIRAMAR  COLLEGE     | |                        \n";
    cout << "                        | | STUDENT  GRADING  SYSTEM | |                        \n";
    cout << "                        | |                          | |                        \n";
    cout << "                        | |               Programmer | |                        \n";
    cout << "                        | |           Sofia De Marco | |                        \n";
    cout << "                        | |__________________________| |                        \n";
    cout << "                        |                              |                        \n";
    cout << "                        |   ____ ____ ____      ____   |                        \n";
    cout << "                        |  | 7  | 8  | 9  |    | +  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |  | 4  | 5  | 6  |    | -  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |  | 1  | 2  | 3  |    | x  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |  | .  | 0  | =  |    | /  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;
    transition();

}   //end of void titleScreen()

/***********************************************************

Function name: exitScreen()
Purpose: Display the Exit Screen graphic

 ***********************************************************/
void exitScreen(void)
{
    cout << "                         ______________________________                         \n";
    cout << "                        | [Version         05/14/2024] |                        \n";
    cout << "                        |  __________________________  |                        \n";
    cout << "                        | |                          | |                        \n";
    cout << "                        | |     MIRAMAR  COLLEGE     | |                        \n";
    cout << "                        | | STUDENT  GRADING  SYSTEM | |                        \n";
    cout << "                        | |                          | |                        \n";
    cout << "                        | |         Goodbye!         | |                        \n";
    cout << "                        | |                          | |                        \n";
    cout << "                        | |__________________________| |                        \n";
    cout << "                        |                              |                        \n";
    cout << "                        |   ____ ____ ____      ____   |                        \n";
    cout << "                        |  | 7  | 8  | 9  |    | +  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |  | 4  | 5  | 6  |    | -  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |  | 1  | 2  | 3  |    | x  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |  | .  | 0  | =  |    | /  |  |                        \n";
    cout << "                        |  |____|____|____|    |____|  |                        \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;
    transition();

}   //end of void exitScreen()


/***********************************************************

Function name: errorScreen()
Purpose: Display a generic error screen when user enters an
    invalid input

 ***********************************************************/
void errorScreen()
{
    system("CLS");
    cout << "                         ______________________________                         \n";
    cout << "         ****    ****   | [Version         05/14/2024] |   ****    ****         \n";
    cout << "         *   *  *   *   |______________________________|   *   *  *   *         \n";
    cout << "          *   **   *    |       MIRAMAR  COLLEGE       |    *   **   *          \n";
    cout << "           *      *     |   STUDENT  GRADING  SYSTEM   |     *      *           \n";
    cout << "           *      *     |______________________________|     *      *           \n";
    cout << "          *   **   *    |    **********************    |    *   **   *          \n";
    cout << "         *   *  *   *   |            ERROR!            |   *   *  *   *         \n";
    cout << "         ****    ****   |    **********************    |   ****    ****         \n";
    cout << "                        |______________________________|                        \n";
    cout << endl;

}   //end of void errorScreen()
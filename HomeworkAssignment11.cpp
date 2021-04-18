#include <iostream>
#include <cctype>

using namespace std;

class LoginSystem {

    // 2D array holding Lab#s and corresponding Computer#s
    string** labs;

    public:
        // constructor
        LoginSystem();
        // destructor
        ~LoginSystem();

/**
 * MEMBER FUNCTION NAME:
 *    showStatus
 * PURPOSE:
 *    Prints the status of all Lab#/Computer# slots
 * PARAMETER:
 *    none
 * RETURN VALUE:
 *    none
 */
        void showStatus()
        {
            cout << "STATUS" << endl;
            cout << "Lab#\tComputers" << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << i + 1 << "\t";
                for(int j = 0; j < 10; j++)
                {
                    cout << j + 1 << ": " << labs[i][j];
                    if(j < 9)
                        cout << " ";
                    else
                        cout << endl;
                }
            }
            cout << endl;
        }

/**
 * MEMBER FUNCTION NAME:
 *    showMenu
 * PURPOSE:
 *    Prints all user options: LOGIN, LOGOUT, SEARCH, QUIT
 * PARAMETER:
 *    none
 * RETURN VALUE:
 *    none
 */
        void showMenu()
        {
            cout << "SELECTION MENU" << endl;
            cout << "1. LOGIN" << endl;
            cout << "2. LOGOUT" << endl;
            cout << "3. SEARCH" << endl;
            cout << "4. QUIT" << endl;
        }

/**
 * MEMBER FUNCTION NAME:
 *    login
 * PURPOSE:
 *    1. prompts user for 5-character ID to login
 *    2. given valid ID, prompts for Lab #
 *    3. given Lab #, prompts for Computer #
 *    4. at the end, invokes showStatus() and showMenu()
 * PARAMETER:
 *    none
 * RETURN VALUE:
 *    none
 */
        void login()
        {
            // confirms valid login ID
            bool validID = true;
            string loginID;
            while (validID)
            {
                validID = false;
                cout << "Enter your 5-character ID to login: " << endl;
                cin >> loginID;
                if(loginID.length() > 5 || loginID.length() < 5)
                {
                    validID = true;
                }
                else if(loginID == "empty" || loginID == "EMPTY" || loginID == "Empty")
                {
                    validID = true;
                }
            }
            // confirms valid lab #
            bool validLab = true;
            int labNum;
            while (validLab)
            {
                validLab = false;
                cout << "Enter the Lab # (1-4): " << endl;
                // if non-integer is entered
                while(!(cin >> labNum))
                {
                    cout << "Enter the Lab # (1-4): " << endl;
                    cin.clear();
                    cin.ignore(123,'\n');
                }
                // confirm within range
                if(labNum > 4 || labNum < 1)
                    validLab = true;
            }
            // confirms valid computer #
            bool validComputer = true;
            int computerNum;
            while (validComputer)
            {
                validComputer = false;
                cout << "Enter the Computer # (1-10): " << endl;
                // if non-integer is entered
                while(!(cin >> computerNum))
                {
                    cout << "Enter the Computer # (1-10): " << endl;
                    cin.clear();
                    cin.ignore(123,'\n');
                }
                // confirm within range
                if(computerNum > 10 || computerNum < 1 || isdigit(computerNum) != 0)
                    validComputer = true;
            }
            // confirm open computer
            bool openComputer = false;
            validID = true;
            if(labs[labNum - 1][computerNum - 1] != "empty")
                cout << "ERROR, user " << labs[labNum - 1][computerNum - 1] <<" is already logged into that station." << endl;
            else
                openComputer = true;
            if(openComputer)
            {
                for(int i = 0; i < 4; i++)
                {
                    for(int j = 0; j < 10; j++)
                    {
                        if(loginID == labs[i][j])
                        {
                            cout << "User " << labs[i][j] << " is in Lab #" << i + 1 << " at Computer #" << j + 1 << endl;
                            validID = false;
                        }
                    }
                }
            }
            else
                validID = true;

            // if computer is open and userID is unique, then add to array
            if(validID == true && openComputer == true)
            {
                labs[labNum - 1][computerNum - 1] = loginID;
            }
            cout << endl;
            showStatus();
            showMenu();
        }

/**
 * MEMBER FUNCTION NAME:
 *    logout
 * PURPOSE:
 *    1. prompts user for 5-character ID to logout
 *    2. if found, prints: “User [ID] is logged out”
 *    3. at the end, invokes showStatus() and showMenu()
 * PARAMETER:
 *    none
 * RETURN VALUE:
 *    none
 */
        void logout()
        {
            // validate id input
            bool validID = true;
            string loginID;
            while (validID)
            {
                validID = false;
                cout << "Enter your 5-character ID to logout: " << endl;
                cin >> loginID;
                if(loginID.length() > 5 || loginID.length() < 5)
                {
                    validID = true;
                }
                else if(loginID == "empty" || loginID == "EMPTY" || loginID == "Empty")
                {
                    validID = true;
                }
            }

            // logout user
            int noUser;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(loginID == labs[i][j])
                    {
                        cout << "User " << labs[i][j] << " is logged out." << endl;
                        labs[i][j] = "empty";
                    }
                    else
                        ++noUser;
                }
            }
            if(noUser == 40)
                cout << "That user is not logged in." << endl;

            cout << endl;
            showStatus();
            showMenu();
        }

/**
 * MEMBER FUNCTION NAME:
 *    search
 * PURPOSE:
 *    1. prompts user for 5-character ID to login
 *    2. if found, prints:
        “User [ID] is in Lab #[LAB_NUM] at Computer #[COMP_NUM]”
 *    3. at the end, invokes showStatus() and showMenu()
 * PARAMETER:
 *    none
 * RETURN VALUE:
 *    none
 */
        void search()
        {
            // validate user ID input
            bool validID = true;
            string loginID;
            while (validID)
            {
                validID = false;
                cout << "Enter your 5-character ID to logout: " << endl;
                cin >> loginID;
                if(loginID.length() > 5 || loginID.length() < 5)
                {
                    validID = true;
                }
                else if(loginID == "empty" || loginID == "EMPTY" || loginID == "Empty")
                {
                    validID = true;
                }
            }

            // confirm if user is logged in
            int noUser;
            for(int i = 0; i < 4; i++)
            {
                for(int j = 0; j < 10; j++)
                {
                    if(loginID == labs[i][j])
                    {
                        cout << "User " << labs[i][j] << " is in Lab #" << i + 1 << " at Computer #" << j + 1 << endl;
                    }
                    else
                        ++noUser;
                }
            }
            if(noUser == 40)
                cout << "That user is not logged in." << endl;

            cout << endl;
            showStatus();
            showMenu();
        }
};
// constructor and destructor definitions
LoginSystem::LoginSystem()
{
    // generates columns
    labs = new string*[4];
    for(int i = 0; i < 4; i++)
    {
        // generates rows and adds "empty"
        labs[i] = new string[10];
        for(int j = 0; j < 10; j++)
        {
            labs[i][j] = "empty";
        }
    }
}
LoginSystem::~LoginSystem()
{
    for(int i = 3; i > 0; i--)
        delete[] labs[i];
    delete[] labs;
}

int main()
{
    LoginSystem user;
    user.showStatus();
    user.showMenu();
    bool bootSys = true;
    while (bootSys)
    {
        int selection;
        while(!(cin >> selection))
        {
            cout << endl;
            user.showStatus();
            user.showMenu();
            cin.clear();
            cin.ignore(123,'\n');
        }
        switch (selection)
        {
            case 1:
                user.login();
                break;
            case 2:
                user.logout();
                break;
            case 3:
                user.search();
                break;
            case 4:
                bootSys = false;
                break;
            default:
                user.showStatus();
                user.showMenu();
        }
    }

    return 0;
}
